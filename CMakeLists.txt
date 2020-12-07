cmake_minimum_required(VERSION 3.17)

project(INT_Wrapper)

set(CMAKE_CXX_STANDARD 17)
file(GLOB SRC src/*.cpp src/*.h)

add_executable(INT_Wrapper Test.cpp ${SRC})