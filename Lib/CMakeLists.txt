cmake_minimum_required(VERSION 3.13)

project(Lib)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
#target_link_libraries(${TEST_NAME} gtest gtest_main)