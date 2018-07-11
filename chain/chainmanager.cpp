#include "chainmanager.h"
#include "action.h"
#include "signedtransaction.h"
#include "../ec/eos_key_encode.h"

namespace ChainManager {

SignedTransaction createTransaction(const std::string &contract, const std::string &actionName, const std::string &hexData, const std::vector<std::string> &permissions, const QByteArray &info)
{
    SignedTransaction txn;
    addAction(txn, contract, actionName, hexData, permissions);
    setTransactionHeaderInfo(txn, info);

    return txn;
}

std::vector<std::string> getActivePermission(const std::string &accountName)
{
    std::vector<std::string> permissions;
    permissions.push_back(accountName + "@active");

    return permissions;
}

void ValidateSignature(const std::string &raw, const std::string &signature, const std::string &pubKey, const std::string &chain_id, std::string &result)
{
    result = "unknown error";

    QJsonValue value = QJsonValue(QJsonDocument::fromJson(QByteArray::fromStdString(raw)).object());
    if (value.isNull()) {
        return;
    }

    std::vector<unsigned char> pub = eos_key::get_public_key_by_eos_pub(pubKey);
    std::vector<unsigned char> signatureHex(signature.begin(), signature.end());

    SignedTransaction sigedTxn;
    sigedTxn.fromJson(value);

    if (sigedTxn.signTest(signatureHex, pub, TypeChainId::fromHex(chain_id))) {
        result = "Passed, signature and raw action match the public key!";
    } else {
        result = "Failed, signature and raw action do not match the public key!";
    }
}

void addAction(SignedTransaction &signedTrx, const std::string &contract, const std::string &actionName, const std::string &hexData, const std::vector<std::string> &permissions)
{
    Action action(contract, actionName);
    action.setAuthorization(permissions);
    action.setData(hexData);

    signedTrx.addAction(action);
}

void setTransactionHeaderInfo(SignedTransaction &signedTrx, const QByteArray &info)
{
    if (!info.isEmpty() && !info.isNull()) {
        QJsonDocument doc = QJsonDocument::fromJson(info);
        QJsonObject obj = doc.object();
        std::string headBlockId = obj.value("head_block_id").toString().toStdString();
        std::string expiration = obj.value("head_block_time").toString().toStdString();

        signedTrx.setReferenceBlock(headBlockId);
        signedTrx.setExpiration(expiration);
    }
}

}

