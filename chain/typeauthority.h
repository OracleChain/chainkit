#ifndef TYPEAUTHORITY_H
#define TYPEAUTHORITY_H

#include "typeaccountpermissionweight.h"
#include "typekeypermissionweight.h"
#include "typewaitweight.h"
#include <vector>

class TypeAuthority : public ISerializer
{
public:
    TypeAuthority();
    TypeAuthority(int threshold, const TypeKeyPermissionWeight& key);
    TypeAuthority(int threshold, const TypeAccountPermissionWeight& permission);
    TypeAuthority(int threshold, const TypeKeyPermissionWeight& key, const TypeAccountPermissionWeight& permission);
    TypeAuthority(int threshold, const std::string& pubKey, const std::string& permission);
    TypeAuthority(const std::string& key, uint32_t delay_sec = 0);
    TypeAuthority(uint32_t t, std::vector<TypeKeyPermissionWeight> k, std::vector<TypeAccountPermissionWeight> p = {}, std::vector<TypeWaitWeight> w = {});

    virtual void serialize(EOSByteWriter *writer) const;

private:
    int threshold;
    std::vector<TypeKeyPermissionWeight> keys;
    std::vector<TypeAccountPermissionWeight> accounts;
    std::vector<TypeWaitWeight> waits;
};

#endif // TYPEAUTHORITY_H
