//
// Created by PC on 24.05.2021.
//

#ifndef CANGPS_NEOM9N_H
#define CANGPS_NEOM9N_H


#include <vector>
#include <cstdint>

class NeoM9N {
public:
    std::vector<uint8_t> GetData();
    void Config();
};


#endif //CANGPS_NEOM9N_H
