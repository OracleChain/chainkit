#ifndef TYPECHAINID_H
#define TYPECHAINID_H

#include <string>

class TypeChainId
{
public:
    TypeChainId();

    void *getBytes();
    void setBytes(unsigned char *bytes);
    const unsigned char *chainId() const;

    int size () const { return sizeof(id); }

    static TypeChainId fromHex(const std::string& strHex);

private:
    unsigned char id[32];
};

#endif // TYPECHAINID_H
