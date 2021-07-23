cmake_minimum_required(VERSION 3.13)


project(Application LANGUAGES CXX C)

add_subdirectory(Gps)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_sources(${TARGET_NAME}
        PRIVATE
        EmuCan/EmuCan.cpp
        App.cpp
        Imu/Imu.cpp
        main.cpp
        )

    target_include_directories(
        ${TARGET_NAME}
        PUBLIC
        .
        Imu
        EmuCan
    )
elseif (CMAKE_BUILD_TYPE MATCHES Test)

endif ()


