
cmake_minimum_required(VERSION 3.12)

project(SimpleOS)

set(CMAKE_CXX_STANDARD 17)

include_directories("include")
include_directories("source")
include_directories("source/Host")

add_executable(HostMain 
"HostMain.cpp"

"source/Host/SimpleOS/Platform.cpp" 
"source/Host/SimpleOS/Console.cpp"
"source/Host/SimpleOS/BaseAddress.cpp" 
"source/Host/SimpleOS/Keyboard.cpp" 
"source/Host/SimpleOS/Context.cpp"

"source/SimpleOS/Pmm.cpp"
"source/SimpleOS/Kernel.cpp" 
"source/SimpleOS/BumpAllocator.cpp" 
"source/SimpleOS/ExtNew.cpp")


include_directories("source/x86")
add_executable(PicManagerTest 
"source/x86/SimpleOS/PicManager.cpp"
"tests/PicManagerTest.cpp")
