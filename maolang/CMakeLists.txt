cmake_minimum_required(VERSION 3.3)
project(maolang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c tree.c tree.h parser.c parser.h stack.c stack.h utils.c utils.h exception.c exception.h)
add_executable(maolang ${SOURCE_FILES})