cmake_minimum_required(VERSION 3.9)

project(HUST_CXX_Labs)

# Build lab01
add_library(cmdparser1 ./lab01/cmd_parser.cpp)
add_library(stack_c ./lab01/stack.cpp)
add_executable(lab01 ./lab01/main.cpp)
target_link_libraries(lab01 stack_c cmdparser1)

# Build lab02
add_library(cmdparser2 ./lab02/cmd_parser.cpp)
add_library(stack_cxx ./lab02/stack.cpp)
add_executable(lab02 ./lab02/main.cpp)
target_link_libraries(lab02 stack_cxx cmdparser2)

# Build lab03
add_library(cmdparser3 ./lab03/cmd_parser.cpp)
add_library(stack_cxx_virtual ./lab03/stack.cpp)
add_executable(lab03 ./lab03/main.cpp)
target_link_libraries(lab03 stack_cxx_virtual cmdparser3)

# Build lab04
add_library(cmdparser4 ./lab04/cmd_parser.cpp)
add_library(stack_cxx_base ./lab04/stack.cpp)
add_library(queue ./lab04/queue.cpp)
add_executable(lab04 ./lab04/main.cpp)
target_link_libraries(lab04 queue stack_cxx_base cmdparser4)