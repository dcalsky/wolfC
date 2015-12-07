cmake_minimum_required(VERSION 3.3)
project(maolang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c tree.c tree.h parser.c parser.h compute.c compute.h)
add_executable(maolang ${SOURCE_FILES})