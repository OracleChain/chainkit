#include "sha256.h"
#include <string.h>

extern "C"
{
#include "../Crypto/sha2.h"
}

sha256::sha256()
{
    memset(_hash, 0, sizeof(_hash));
}

sha256 sha256::hash(const char *d, uint32_t dlen)
{
    sha256 h;
    SHA256_CTX ctx;
    sha256_Init(&ctx);
    sha256_Update(&ctx, (const uint8_t*)d, dlen);
    sha256_Final(&ctx, (uint8_t*)&(h._hash[0]));
    return h;
}

sha256 sha256::hash(const std::string &str)
{
    return hash(str.c_str(), str.size());
}
