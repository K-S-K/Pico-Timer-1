cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT DEFINED ENV{PICO_SDK_PATH})
    message(FATAL_ERROR "PICO_SDK_PATH environment variable not set!")
endif()

if(NOT DEFINED ENV{FREERTOS_KERNEL_ORIG_PATH})
    message(FATAL_ERROR "FREERTOS_KERNEL_ORIG_PATH environment variable not set!")
endif()

# Set the executable name (this will be the name of the output binary)
set(NAME pico-timer)

# Pull in SDK (must be before project)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Pull in FreeRTOS
include($ENV{FREERTOS_KERNEL_ORIG_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)


project(app C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Add the project executable
add_executable(${NAME}
    application/main.c
)

# target_include_directories(blink PRIVATE ${CMAKE_CURRENT_LIST_DIR})
# Add include directory (for FreeRTOSConfig.h and any other headers in blink/)
target_include_directories(${NAME} PRIVATE
    application
)

# Link necessary libraries
target_link_libraries(${NAME}
    pico_stdlib
    FreeRTOS-Kernel
    FreeRTOS-Kernel-Heap4
)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(${NAME})

