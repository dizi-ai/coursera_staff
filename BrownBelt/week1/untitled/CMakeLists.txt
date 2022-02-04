cmake_minimum_required(VERSION 3.17)
project(untitled)

find_package(Td 1.7.8 REQUIRED)
target_link_libraries(YourTarget PRIVATE Td::TdStatic)

set(CMAKE_CXX_STANDARD 14)
find_package(Td 1.7.8 REQUIRED)
target_link_libraries(YourTarget PRIVATE Td::TdStatic)
add_executable(untitled main.cpp)
