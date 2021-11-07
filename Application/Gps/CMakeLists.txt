cmake_minimum_required(VERSION 3.13)

project(Gps LANGUAGES CXX C)

if (CMAKE_BUILD_TYPE MATCHES Debug)

    target_sources(${TARGET_NAME}
        PRIVATE
        Ubx/UbxCfg.cpp
        Ubx/UbxTp.cpp
        NeoM9N/NeoM9N.cpp
        Ubx/UbxNavPvt.cpp
        )


    target_include_directories(
        ${TARGET_NAME}
        PUBLIC
        .
        Ubx
        NeoM9N
    )
elseif (CMAKE_BUILD_TYPE MATCHES Test)
    target_sources(Utest
        PRIVATE
        Test/TestUbxTp.cpp
        Test/TestGpsUbx.cpp
        Test/TestNeoM9N.cpp
        Ubx/UbxCfg.cpp
        Ubx/UbxTp.cpp
        Ubx/UbxNavPvt.cpp
        NeoM9N/NeoM9N.cpp
        )


    target_include_directories(
        Utest
        PUBLIC
        .
        Ubx
        NeoM9N
    )
endif ()

