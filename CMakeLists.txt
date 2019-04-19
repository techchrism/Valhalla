cmake_minimum_required(VERSION 3.13)
project(Valhalla2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(Valhalla2 main.cpp structures/StackNode.h structures/Stack.h)