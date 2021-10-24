//
// Created by PC on 24.05.2021.
//

#pragma once


#include <vector>
#include <cstdint>
#include <UbxCfg.h>
#include <ICom.h>
#include "../../Interfaces/IGps.h"

class NeoM9N : public UbxCfg, public IGps
{
public:
    explicit NeoM9N(ICom *com);
    void GetData();
    void Config();
};

