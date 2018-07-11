#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;

const QString chain_func_base = "/v1/chain";
const QString history_func_base = "/v1/history";
const QString content_type_application_json = "application/json";
const QString eos_account_regex = "([.1-5a-z]{3,12}$)";

QString make_url(const QString& api_url);

enum class FunctionID {
    get_info = 0,
    push_transaction,
    push_transactions,
    get_account,
    get_transaction,
    get_controlled_accounts,
    abi_json_to_bin,
    get_required_keys,
    get_table,
    get_block,
    get_abi
};

struct func_ctx {
    FunctionID fid;
    QString func_url;
};

static func_ctx FunctionURLMap[] = {
    { FunctionID::get_info, chain_func_base + "/get_info" },
    { FunctionID::push_transaction, chain_func_base + "/push_transaction" },
    { FunctionID::push_transactions, chain_func_base + "/push_transactions" },
    { FunctionID::get_account, chain_func_base + "/get_account" },
    { FunctionID::abi_json_to_bin, chain_func_base + "/abi_json_to_bin" },
    { FunctionID::get_required_keys, chain_func_base + "/get_required_keys" },
    { FunctionID::get_table, chain_func_base + "/get_table_rows" },
    { FunctionID::get_block, chain_func_base + "/get_block" },
    { FunctionID::get_abi, chain_func_base + "/get_abi"},

    { FunctionID::get_transaction, history_func_base + "/get_transaction" },
    { FunctionID::get_controlled_accounts, history_func_base + "/get_controlled_accounts" },
};

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = 0);
    ~HttpClient();

    void request(FunctionID id, const QByteArray& content = "");

private:
    void _make_request(const QString& url, const QString& contentType = "", const QByteArray& param = "");

signals:
    void responseData(const QByteArray& );

private slots:
    void slotReadAll();

private:
    QNetworkAccessManager *qnam;
    QNetworkReply *reply;
};

#endif // HTTPCLIENT_H
