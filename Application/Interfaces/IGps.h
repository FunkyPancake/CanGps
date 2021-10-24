//
// Created by PC on 15.05.2021.
//

#pragma once

#include <cstdint>

class IGps
{
public:
    float Latitude_deg;
    float Longitude_deg;
    float Speed_mps;
    float Altitude_m;
    float Course_deg;
    uint8_t Noise;
    uint8_t SateliteNumber;
    uint8_t Status;
    
    virtual void GetData() = 0;
};

