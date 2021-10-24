//
// Created by PC on 25.10.2021.
//

#ifndef CANGPS_APPLICATION_GPS_UBX_UBXNAVPVT_H
#define CANGPS_APPLICATION_GPS_UBX_UBXNAVPVT_H

#include <ICom.h>

class UbxNavPvt
{
private:
    const uint8_t MsgClass = 0x01;
    const uint8_t MsgSubclass = 0x07;
    ICom * _com;
    uint32_t GetU32Value(const uint8_t *rawData);
public:
    float Latitude_deg;
    float Longitude_deg;
    float Speed_mps;
    float Altitude_m;
    float Course_deg;
    uint8_t Noise;
    uint8_t SateliteNumber;
    uint8_t Status;
    explicit UbxNavPvt(ICom *pCom);
    bool GetFrame();
};

#endif //CANGPS_APPLICATION_GPS_UBX_UBXNAVPVT_H
