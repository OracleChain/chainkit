#ifndef TRANSACTIONHEADER_H
#define TRANSACTIONHEADER_H

#include "chainbase.h"
#include <string>

class TransactionHeader : public ISerializer, public IFormater
{
public:
    TransactionHeader();
    virtual ~TransactionHeader() {}

    virtual void serialize(EOSByteWriter* writer) const;
    virtual QJsonValue toJson() const;
    virtual void fromJson(const QJsonValue& value);

    void setExpiration(const std::string& expiration);
    void setReferenceBlock(const std::string& ref);
    void setNetUsageWords(LONG net_usage);
    void setKcpuUsage(LONG kcpu);

private:
    std::string expiration;
    int ref_block_num;
    LONG ref_block_prefix;
    LONG max_net_usage_words;
    LONG max_cpu_usage_ms;
    LONG delay_seconds;

private:
    const static int EXPIRATION_SEC = 30;
};

#endif // TRANSACTIONHEADER_H
