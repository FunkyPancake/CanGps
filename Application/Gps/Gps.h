//
// Created by PC on 15.05.2021.
//

#ifndef CANGPS_GPS_H
#define CANGPS_GPS_H


#include <cstdint>

class Gps {
public:
    float Latitude;
    float Longitude;
    float Speed;
    float Altitude;
    float Course;
    uint8_t Noise;
    uint8_t SateliteNumber;
    uint8_t Status;
};


#endif //CANGPS_GPS_H
