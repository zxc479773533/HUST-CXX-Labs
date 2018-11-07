cmake_minimum_required(VERSION 3.9)

project(HUST_CXX_Labs)

# Build lab01
add_library(cmdparser ./lab01/cmd_parser.cpp)
add_library(stack ./lab01/stack.cpp)
add_executable(lab01 ./lab01/main.cpp)
target_link_libraries(lab01 stack cmdparser)