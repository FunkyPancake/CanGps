cmake_minimum_required(VERSION 3.13)


project(Application LANGUAGES CXX C)

add_subdirectory(Gps)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_sources(${TARGET_NAME}.elf
        PRIVATE
        EmuCan/EmuCan.cpp
        SyvecsCan/SyvecsCan.cpp
        App.cpp
        Imu/Imu.cpp
        main.cpp
        )

    target_include_directories(
        ${TARGET_NAME}.elf
        PUBLIC
        .
        Imu
        EmuCan
        SyvecsCan
    )
elseif (CMAKE_BUILD_TYPE MATCHES Test)

endif ()


