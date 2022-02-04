cmake_minimum_required(VERSION 3.17)
project(busstopdec)

set(CMAKE_CXX_STANDARD 17)

add_executable(busstopdec main.cpp query.h query.cpp "responses.h"responses.cpp "bus_manager.h" "bus_manager.cpp")