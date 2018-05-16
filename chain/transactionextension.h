#ifndef TRANSACTIONEXTENSION_H
#define TRANSACTIONEXTENSION_H

#include "chainbase.h"

class TransactionExtension : public ISerializer
{
public:
    TransactionExtension();

    virtual void serialize(EOSByteWriter* writer) const;

private:
    std::pair<uint16_t,std::vector<char>> extensions;
};

#endif // TRANSACTIONEXTENSION_H
