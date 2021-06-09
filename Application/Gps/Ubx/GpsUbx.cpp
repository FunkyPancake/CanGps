//
// Created by PC on 22.05.2021.
//

#include "GpsUbx.h"
#include "UbxMessage.h"


bool GpsUbx::ParseMessage(std::vector<uint8_t> message)
{
    auto msg = UbxMessage().Deserialize(message);
    return false;
}

