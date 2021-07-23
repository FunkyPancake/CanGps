//
// Created by PC on 22.05.2021.
//

#include <algorithm>
#include "GpsUbx.h"
#include <array>




GpsUbx::GpsUbx(ICom *com)
{
    _com = com;
}

bool GpsUbx::CheckAck(UbxTp &msg, uint8_t msgClass, uint8_t msgSubclass)
{
    return msg.GetPackedData() == std::vector<uint8_t>{0x05, 0x01, msgClass, msgSubclass};
}
