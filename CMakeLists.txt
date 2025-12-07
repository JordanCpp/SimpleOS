
cmake_minimum_required(VERSION 3.12)

project(SimpleOS)

set(CMAKE_CXX_STANDARD 17)

include_directories("include")
include_directories("source")
include_directories("source/Demo")

add_executable(DemoMain 
"DemoMain.cpp"
"source/Demo/SimpleOS/Platform.cpp" 
"source/Demo/SimpleOS/Console.cpp"
"source/Demo/SimpleOS/BaseAddress.cpp" 
"source/SimpleOS/Pmm.cpp"
"source/SimpleOS/Kernel.cpp" 
"source/SimpleOS/BumpAllocator.cpp" 
"source/SimpleOS/ExtNew.cpp" "source/Demo/SimpleOS/Keyboard.cpp")
