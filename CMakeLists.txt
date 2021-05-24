cmake_minimum_required(VERSION 3.13)

set(TARGET_NAME CanGps)
set(TEST_NAME UTests)

project(${TARGET_NAME} LANGUAGES CXX C)


add_executable(${TARGET_NAME}
    null.cpp)

add_subdirectory(GeneratedCode)
add_subdirectory(Application)
add_subdirectory(KeCommon)

target_link_libraries(${TARGET_NAME} KeCommon)

target_compile_options(${TARGET_NAME} PRIVATE
    -O0 -fno-common -g3 -Wall -c -ffunction-sections -fno-rtti -fdata-sections -ffreestanding
    -fno-builtin -fno-exceptions -fmerge-constants -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
    -mthumb -fstack-usage -specs=nano.specs)

target_compile_definitions(${TARGET_NAME}
    PRIVATE
    CPU_MKE16F256VLH16
    CPU_MKE16F256VLH16_cm4
    FSL_RTOS_FREE_RTOS
    SDK_OS_FREE_RTOS
    SDK_DEBUGCONSOLE=1
    __MCUXPRESSO
    __USE_CMSIS
    DEBUG
    __NEWLIB__
    )

target_link_options(${TARGET_NAME} PUBLIC -Wl,-print-memory-usage,--sort-section=alignment,--gc-sections,--cref,-M=${TARGET_NAME}.map -nostdlib -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb) #-T BaseKe16_Debug.ld)

#add_executable(${TEST_NAME} null.cpp)
#target_link_libraries(${TEST_NAME} gtest gtest_main)