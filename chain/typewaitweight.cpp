#include "typewaitweight.h"
#include "eosbytewriter.h"

TypeWaitWeight::TypeWaitWeight(uint32_t delay_sec, uint16_t weight)
{
    this->wait_sec = delay_sec;
    this->weight = weight;
}

void TypeWaitWeight::serialize(EOSByteWriter *writer) const
{
    if (writer) {
        writer->putIntLE(wait_sec);
        writer->putShortLE(weight);
    }
}
