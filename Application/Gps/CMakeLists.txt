cmake_minimum_required(VERSION 3.13)

project(Gps LANGUAGES CXX C)


target_sources(${TARGET_NAME}
        PRIVATE
        Gps.cpp
        Ubx/GpsUbx.cpp
        )


target_include_directories(
        ${TARGET_NAME}
        PUBLIC
        .
        Ubx
)