cmake_minimum_required(VERSION 3.17)
project(finalYellow)

set(CMAKE_CXX_STANDARD 17)

add_executable(finalYellow main.cpp token.h condition_parser_test.cpp token.cpp condition_parser.h condition_parser.cpp test_runner.cpp test_runner.h database.cpp database.h date.cpp node.cpp node.h date.h)