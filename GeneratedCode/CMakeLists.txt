cmake_minimum_required(VERSION 3.13)


project(GeneratedCode LANGUAGES CXX C)


add_subdirectory(board)
#add_subdirectory(../KeCommon/freertos)
#add_subdirectory(../KeCommon/drivers)

target_sources(
    ${TARGET_NAME}
    PRIVATE
        ../KeCommon/source/cpp_config.cpp
        ../Application/main.cpp
        ../KeCommon/source/semihost_hardfault.c
)

target_include_directories(
        ${TARGET_NAME}
        PUBLIC
        ../KeCommon/CMSIS
        ../KeCommon/source
        ../KeCommon/device
)