cmake_minimum_required(VERSION 3.15)
project(AlgorithmCourse)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000")

add_executable(AlgorithmCourse main.cpp recursive/ChessboardOverlay.cpp recursive/ChessboardOverlay.h)