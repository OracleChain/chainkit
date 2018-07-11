#ifndef CHAINMANAGER_H
#define CHAINMANAGER_H

#include "signedtransaction.h"
#include "eosnewaccount.h"
#include <QByteArray>


namespace ChainManager {
    SignedTransaction createTransaction(const std::string& contract, const std::string& actionName,
                                               const std::string& hexData, const std::vector<std::string>& permissions, const QByteArray& info);

    void setTransactionHeaderInfo(SignedTransaction& signedTrx, const QByteArray& info);

    void addAction(SignedTransaction& signedTrx, const std::string& contract, const std::string& actionName, const std::string& hexData, const std::vector<std::string>& permissions);

    std::vector<std::string> getActivePermission(const std::string& accountName);

    void ValidateSignature(const std::string& raw, const std::string& signature, const std::string& pubKey, const std::string& chain_id, std::string& result);
}

#endif // CHAINMANAGER_H
