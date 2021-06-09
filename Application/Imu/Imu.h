//
// Created by PC on 23.05.2021.
//

#pragma once


class Imu
{
public:
    float Xacc, Yacc, Zacc;
    float Xyaw, Yyaw, Zyaw;
    void GetData();
    void Config();
};
