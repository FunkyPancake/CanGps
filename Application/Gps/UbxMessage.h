//
// Created by PC on 26.05.2021.
//

#ifndef CANGPS_APPLICATION_GPS_UBXMESSAGE_H
#define CANGPS_APPLICATION_GPS_UBXMESSAGE_H

#include <array>
#include <cstdint>
#include <vector>

class UbxMessage
{
private:
    bool CheckChecksum(std::vector<uint8_t> &data);
    std::array<uint8_t, 2> CalcChecksum(std::vector<uint8_t> &data);

public:
    enum MsgClassEnum
    {
        NAV = 0x01,
        RXM = 0x02,
        INF = 0x04,
        ACK = 0x05,
        CFG = 0x06,
        MON = 0x0A,
        AID = 0x0B,
        TIM = 0x0D,
        ESF = 0x10,
        MGA = 0x13,
        LOG = 0x21,
        SEC = 0x027,
        HNR = 0x28
    };
    MsgClassEnum MsgClass;
    uint8_t MsgSubclass;
    std::vector<uint8_t> Payload;
    UbxMessage();
    UbxMessage(MsgClassEnum msgClass, uint8_t msgSubclass, std::vector<uint8_t> payload);
    std::vector<uint8_t> Serialize();
    bool Deserialize(std::vector<uint8_t> data);
};

#endif//CANGPS_APPLICATION_GPS_UBXMESSAGE_H
