cmake_minimum_required(VERSION 3.13)


project(GeneratedCode LANGUAGES CXX C)


add_subdirectory(board)
add_subdirectory(freertos)
add_subdirectory(drivers)

target_sources(
    ${TARGET_NAME}
    PRIVATE
    source/cpp_config.cpp
    source/main.cpp
    source/semihost_hardfault.c
)

target_include_directories(
        ${TARGET_NAME}
        PUBLIC
        CMSIS
        source
        device
)