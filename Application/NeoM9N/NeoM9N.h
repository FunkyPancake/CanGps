//
// Created by PC on 24.05.2021.
//

#pragma once


#include <vector>
#include <cstdint>
#include <GpsUbx.h>
#include <ICom.h>
#include <LpUart.h>

class NeoM9N : public GpsUbx
{
private:
    LpUart *_com;
public:
//    NeoM9N(ICom* comIf);
    NeoM9N(LpUart *com);
    bool GetData();
    void Config();
};

