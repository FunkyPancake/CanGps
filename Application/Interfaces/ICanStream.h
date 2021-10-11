//
// Created by PC on 11.10.2021.
//

#ifndef ICANSTREAM_H
#define ICANSTREAM_H

#include <cstdint>
#include <array>
#include <algorithm>
#include "Gps.h"
#include "ICan.h"

class ICanStream
{
protected:
    uint32_t _baseId;
    ICan *_can;
    template<typename T> T SwapBytes(T data)
    {
        std::array<uint8_t, sizeof(T)> tmp{};
        *(T *) tmp.data() = data;
        std::reverse(tmp.begin(), tmp.end());
        return *(T *) tmp.data();
    }
public:
    virtual void SendFrames()=0;
};

#endif //ICANSTREAM_H
