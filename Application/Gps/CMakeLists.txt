cmake_minimum_required(VERSION 3.13)

project(Gps LANGUAGES CXX C)

if (CMAKE_BUILD_TYPE MATCHES Debug)

    target_sources(${TARGET_NAME}
        PRIVATE
        Gps.cpp
        Ubx/GpsUbx.cpp
        Ubx/UbxMessage.cpp
        )


    target_include_directories(
        ${TARGET_NAME}
        PUBLIC
        .
        Ubx
    )
elseif (CMAKE_BUILD_TYPE MATCHES Test)
    target_sources(Utest
        PRIVATE
        Test/TestUbxMessage.cpp
        Test/TestUbx.cpp
        Gps.cpp
        Ubx/GpsUbx.cpp
        ubx/UbxMessage.cpp
        )


    target_include_directories(
        Utest
        PUBLIC
        .
        Ubx
    )
endif ()

