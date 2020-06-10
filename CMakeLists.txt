cmake_minimum_required(VERSION 3.15)
project(AlgorithmCourse)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000")

add_executable(AlgorithmCourse main.cpp recursive/ChessboardOverlay.cpp recursive/ChessboardOverlay.h recursive/FastMul.cpp recursive/FastMul.h recursive/topk.cpp recursive/topk.h to-do-list.cpp dp/MatrixMuls.cpp dp/MatrixMuls.h dp/LCS.cpp dp/LCS.h dp/MSP.cpp dp/MSP.h utils/base.cpp utils/base.h dp/ImageComparision.cpp dp/ImageComparision.h dp/backpack.cpp dp/backpack.h greedy/count_ascii.cpp greedy/count_ascii.h)