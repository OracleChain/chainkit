#include "typechainid.h"
#include "../utility/utils.h"

#include <string.h>

TypeChainId::TypeChainId()
{
    memset(id, 0, sizeof(id));
}

void *TypeChainId::getBytes()
{
    return (void*)id;
}

void TypeChainId::setBytes(unsigned char *bytes)
{
    memcpy(id, bytes, 32);
}

const unsigned char *TypeChainId::chainId() const
{
    return id;
}

TypeChainId TypeChainId::fromHex(const std::string& strHex)
{
    TypeChainId cid;
    if (strHex.empty()) {
        return cid;
    }

    //assert(strHex.size() == 64);
    std::vector<unsigned char> vec(strHex.begin(), strHex.end());
    std::vector<unsigned char> bytes = Utils::convertHexStrToBytes(vec);

    cid.setBytes(bytes.data());
    return cid;
}
