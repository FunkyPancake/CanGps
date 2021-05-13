cmake_minimum_required(VERSION 3.13)

set(TARGET_NAME CanGps)
set(TEST_NAME UTests)

project(${TARGET_NAME} LANGUAGES CXX C)



add_executable(${TARGET_NAME}.elf
        null.cpp)

add_subdirectory(GeneratedCode)
add_subdirectory(Application)
add_subdirectory(BaseApp)
add_subdirectory(Lib)

add_executable(${TEST_NAME} null.cpp)
target_link_libraries(${TEST_NAME} gtest gtest_main)