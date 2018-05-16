#ifndef SHA256_H
#define SHA256_H

#include <string>

class sha256
{
public:
    sha256();

    static sha256 hash(const char *d, uint32_t dlen);
    static sha256 hash(const std::string& str);
    //static sha256 hash(const sha256& sha);

    char* data() const { return (char*)&_hash[0]; }
    size_t data_size() const { return 256 / 8; }

    uint64_t _hash[4];
};

#endif // SHA256_H
