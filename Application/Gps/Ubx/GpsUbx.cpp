//
// Created by PC on 22.05.2021.
//

#include <vector>
#include "GpsUbx.h"

//void GpsUbx::ParseMessage(std::vector<uint8_t> message) {
//        if (CheckHeader(message) && CheckChecksum(message))
//            ParsePayload(message);
//}

bool GpsUbx::CheckHeader(std::vector<uint8_t> &message) {
    return message[0] == 0xB5 && message[1] == 0x62;
}

bool GpsUbx::CheckChecksum(std::vector<uint8_t> &message) {
    uint8_t cka = 0, ckb = 0;
    auto len = message.size();
    for (unsigned int i = 2; len - 2 > i; i++) {
        cka += message[i];
        ckb += cka;
    }
    return cka == message[len - 2] && ckb == message[len - 1];
}

void GpsUbx::ParsePayload(std::vector<uint8_t> &message) {
    auto msgClass = message[2];
    auto msgSubClass = message[3];
    auto len = (message[4] << 8) + message[5];
    switch (msgClass) {
        case ACK:
            break;
        case NAV:
            break;
        case RXM:
        case INF:
        case CFG:
        case MON:
        case AID:
        case TIM:
        case ESF:
        case MGA:
        case LOG:
        case SEC:
        case HNR:
        default:
            break;
    };
}

std::vector<uint8_t>
GpsUbx::BuildMessage(GpsUbx::MsgClass msgClass, uint8_t subClass, uint16_t length, std::vector<uint8_t> payload) {
    std::vector<uint8_t> a={0xB5,0x62,static_cast<uint8_t>(msgClass),subClass };
    CalcChecksum(payload);
    return a;
}

uint16_t GpsUbx::CalcChecksum(std::vector<uint8_t> &payload)
{
    auto cka =0, ckb = 0;
    for(auto b:payload){
        cka+=b;
        ckb=+cka;
    }
    return (cka <<8) + ckb;
}

