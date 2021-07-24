//
// Created by PC on 24.05.2021.
//

#pragma once


#include <vector>
#include <cstdint>
#include <GpsUbx.h>
#include <ICom.h>

class NeoM9N : public GpsUbx, public Gps
{
private:
    static uint32_t GetU32Value(const uint8_t *rawData);
public:
    explicit NeoM9N(ICom *com);
    bool GetData();
    void Config();
};

