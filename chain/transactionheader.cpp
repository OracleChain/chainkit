#include "transactionheader.h"
#include "eosbytewriter.h"
#include "../utility/utils.h"

#include <QDateTime>
#include <QVariant>

TransactionHeader::TransactionHeader()
{
    ref_block_num = 0;
    ref_block_prefix = 0;
    max_net_usage_words = 0;
    max_cpu_usage_ms = 0;
    delay_seconds = 0;
}

void TransactionHeader::serialize(EOSByteWriter *writer) const
{
   if (writer) {
       QDateTime date = QDateTime::fromString(QString::fromStdString(expiration), Qt::ISODate);
       writer->putIntLE((int)(date.toMSecsSinceEpoch() / 1000 + date.offsetFromUtc() + EXPIRATION_SEC));
       writer->putShortLE((short)ref_block_num & 0xFFFF);
       writer->putIntLE((int)(ref_block_prefix & 0xFFFFFFFF));
       writer->putVariableUInt(max_net_usage_words);
       writer->putVariableUInt(max_cpu_usage_ms);
       writer->putVariableUInt(delay_seconds);
   }
}

QJsonValue TransactionHeader::toJson() const
{
    QJsonObject obj;
    QDateTime date = QDateTime::fromString(QString::fromStdString(expiration), Qt::ISODate);
    date = date.addSecs(EXPIRATION_SEC+ date.offsetFromUtc());

    obj.insert("expiration", QJsonValue(date.toString(Qt::ISODate)));
    obj.insert("ref_block_num", QJsonValue((int)ref_block_num));
    obj.insert("ref_block_prefix", QJsonValue::fromVariant(QVariant((uint)ref_block_prefix)));
    obj.insert("max_net_usage_words", QJsonValue((int)max_net_usage_words));
    obj.insert("max_cpu_usage_ms", QJsonValue((int)max_cpu_usage_ms));
    obj.insert("delay_sec", QJsonValue((int)delay_seconds));

    return QJsonValue(obj);
}

void TransactionHeader::fromJson(const QJsonValue &value)
{
    QJsonObject obj = value.toObject();
    if (obj.isEmpty()) {
        return;
    }

    expiration = obj.value("expiration").toString().toStdString();
    ref_block_num = obj.value("ref_block_num").toInt();
    ref_block_prefix = obj.value("ref_block_prefix").toVariant().toUInt();
    max_net_usage_words = obj.value("max_net_usage_words").toInt();
    max_cpu_usage_ms = obj.value("max_cpu_usage_ms").toInt();
    delay_seconds = obj.value("delay_sec").toInt();
}

void TransactionHeader::setExpiration(const std::string &expiration)
{
    this->expiration = expiration;
}

void TransactionHeader::setReferenceBlock(const std::string &ref)
{
    QString ref_block = QString::fromStdString(ref);
    ref_block_num = ref_block.left(8).toInt(nullptr, 16);
    ref_block_prefix = Utils::convertEndian(ref_block.mid(16, 8).toUInt(nullptr, 16));
}

void TransactionHeader::setNetUsageWords(long long net_usage)
{
    max_net_usage_words = net_usage;
}

void TransactionHeader::setKcpuUsage(long long kcpu)
{
    max_cpu_usage_ms = kcpu;
}
