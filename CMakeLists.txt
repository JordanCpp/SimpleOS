
cmake_minimum_required(VERSION 3.20)

project(SimpleOS CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) 

add_executable(HostMain 

"HAL/HalAllocator.ixx"
"HAL/HalConfig.ixx"
"HAL/HalConsole.ixx"
"HAL/HalKeyboard.ixx"
"HAL/HalPmm.ixx"

"Host/BaseAddress.ixx"
"Host/Console.ixx"
"Host/Keyboard.ixx"
"Host/Platform.ixx"

"OS/String.ixx"
"OS/BumpAllocator.ixx"
"OS/ExtNew.ixx"
"OS/Kernel.ixx"
"OS/Pmm.ixx"

"HostMain.cpp")

if(MSVC)
    target_compile_options(HostMain PRIVATE "/std:c++20")
endif()