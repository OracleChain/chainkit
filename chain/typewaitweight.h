#ifndef TYPEWAITWEIGHT_H
#define TYPEWAITWEIGHT_H

#include "chainbase.h"
#include <tuple>

class TypeWaitWeight : public ISerializer
{
public:
    TypeWaitWeight(uint32_t delay_sec, uint16_t weight);

    virtual void serialize(EOSByteWriter *writer) const;

    friend bool operator ==(const TypeWaitWeight& lhs, const TypeWaitWeight& rhs) {
        return std::tie(lhs.wait_sec, lhs.weight) == std::tie(rhs.wait_sec, rhs.weight);
    }

private:
    uint32_t wait_sec;
    uint16_t weight;
};

#endif // TYPEWAITWEIGHT_H
