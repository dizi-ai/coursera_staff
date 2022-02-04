cmake_minimum_required(VERSION 3.17)
project(webserver)

set(CMAKE_CXX_STANDARD 17)

add_executable(webserver main.cpp http_request.h stats.h stats.cpp)