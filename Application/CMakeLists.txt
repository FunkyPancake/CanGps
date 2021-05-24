cmake_minimum_required(VERSION 3.13)


project(Application LANGUAGES CXX C)

add_subdirectory(Gps)

target_sources(${TARGET_NAME}
        PRIVATE
        EmuCan.cpp
        App.cpp
        Imu/Imu.cpp
        NeoM9N/NeoM9N.cpp
        main.cpp
        )

target_include_directories(
        ${TARGET_NAME}
        PUBLIC
        .
        Imu
        NeoM9N
)

