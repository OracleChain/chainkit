#include "typeauthority.h"
#include "eosbytewriter.h"

TypeAuthority::TypeAuthority()
{

}

TypeAuthority::TypeAuthority(int threshold, const TypeKeyPermissionWeight &key)
{
    this->threshold = threshold;
    this->keys.push_back(key);
}

TypeAuthority::TypeAuthority(int threshold, const TypeAccountPermissionWeight &permission)
{
    this->threshold = threshold;
    this->accounts.push_back(permission);
}

TypeAuthority::TypeAuthority(int threshold, const TypeKeyPermissionWeight& key, const TypeAccountPermissionWeight& permission)
{
    this->threshold = threshold;
    this->keys.push_back(key);
    this->accounts.push_back(permission);
}

TypeAuthority::TypeAuthority(int threshold, const std::string &pubKey, const std::string &permission)
{
    this->threshold = threshold;
    if (!pubKey.empty()) {
        this->keys.push_back(TypeKeyPermissionWeight(pubKey, 1));
    }
    if (!permission.empty()) {
        this->accounts.push_back(TypeAccountPermissionWeight(permission));
    }
}

TypeAuthority::TypeAuthority(const std::string &key, uint32_t delay_sec)
{
    this->threshold = 1;
    if (!key.empty()) {
        this->keys.push_back(TypeKeyPermissionWeight(key, 1));
    }
    if (delay_sec > 0) {
        this->threshold = 2;
        waits.push_back(TypeWaitWeight(delay_sec, 1));
    }
}

TypeAuthority::TypeAuthority(uint32_t t, std::vector<TypeKeyPermissionWeight> k, std::vector<TypeAccountPermissionWeight> p, std::vector<TypeWaitWeight> w)
{
    this->threshold = t;
    this->keys = std::move(k);
    this->accounts = std::move(p);
    this->waits = std::move(w);
}

void TypeAuthority::serialize(EOSByteWriter *writer) const
{
    if (writer) {
        writer->putIntLE(threshold);
        SerializeCollection<TypeKeyPermissionWeight>(keys, writer);
        SerializeCollection<TypeAccountPermissionWeight>(accounts, writer);
        SerializeCollection<TypeWaitWeight>(waits, writer);
    }
}
