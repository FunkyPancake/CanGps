set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION   1)
set(CMAKE_SYSTEM_PROCESSOR arm)

list(APPEND CMAKE_PROGRAM_PATH  "C:/tools/NXP/MCUXpressoIDE_11.2.1_4149/ide/plugins/com.nxp.mcuxpresso.tools.win32_11.2.0.202008311134/tools/bin")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_LINKER arm-none-eabi-ld)
set(CMAKE_FORCE_C_COMPILER arm-none-eabi-gcc)
SET(CMAKE_FORCE_CXX_COMPILER arm-none-eabi-g++)

set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)

