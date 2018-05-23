#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;

const QString chain_func_base = "/v1/chain";
const QString get_info_func = chain_func_base + "/get_info";
const QString push_txn_func = chain_func_base + "/push_transaction";
const QString push_txns_func = chain_func_base + "/push_transactions";
const QString json_to_bin_func = chain_func_base + "/abi_json_to_bin";
const QString get_block_func = chain_func_base + "/get_block";
const QString get_account_func = chain_func_base + "/get_account";
const QString get_table_func = chain_func_base + "/get_table_rows";
const QString get_code_func = chain_func_base + "/get_code";
const QString get_currency_balance_func = chain_func_base + "/get_currency_balance";
const QString get_currency_stats_func = chain_func_base + "/get_currency_stats";
const QString get_required_keys_func = chain_func_base + "/get_required_keys";

const QString history_func_base = "/v1/history";
const QString get_actions_func = history_func_base + "/get_actions";
const QString get_transaction_func = history_func_base + "/get_transaction";
const QString get_key_accounts_func = history_func_base + "/get_key_accounts";
const QString get_controlled_accounts_func = history_func_base + "/get_controlled_accounts";

const QString content_type_application_json = "application/json";

const QString eos_account_regex = "([.1-5a-z]{3,12}$)";

QString make_url(const QString& api_url);

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = 0);
    ~HttpClient();

    void get_info();
    void push_transaction(const QByteArray& content);
    void push_transactions(const QByteArray& content);
    void get_account(const QByteArray& content);
    void get_transaction(const QByteArray& content);
    void get_controlled_accounts(const QByteArray& content);
    void abi_json_to_bin(const QByteArray& content);
    void get_required_keys(const QByteArray& content);
    void get_table(const QByteArray& content);
    void get_block(const QByteArray& content);

private:
    void MakeRequest(const QString& url, const QString& contentType = "", const QByteArray& param = "");

signals:
    void responseData(const QByteArray& );

private slots:
    void slotReadAll();

private:
    QNetworkAccessManager *qnam;
    QNetworkReply *reply;
};

#endif // HTTPCLIENT_H
