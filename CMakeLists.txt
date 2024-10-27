cmake_minimum_required(VERSION 3.29)
project(Task_3___Vole_Machine)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task_3___Vole_Machine main.cpp
        course/complexNumber.cpp
        course/complexNumber.h
        course/stack.cpp
        course/stack.h
        CPU.cpp
        CPU.h)
target_link_libraries(Task_3___Vole_Machine -static)