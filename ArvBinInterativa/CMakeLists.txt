cmake_minimum_required(VERSION 3.21)
project(testando C)

set(CMAKE_C_STANDARD 99)

add_executable(testando main.c ArvBin_Int.c ArvBin_Int.h)
