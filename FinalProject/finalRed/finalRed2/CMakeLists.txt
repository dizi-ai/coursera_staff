cmake_minimum_required(VERSION 3.17)
project(finalRed2)

set(CMAKE_CXX_STANDARD 17)

add_executable(finalRed2 main.cpp search_server.h search_server.cpp parse.cpp parse.h iterator_range.h synchronized.h)