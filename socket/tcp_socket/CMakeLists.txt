cmake_minimum_required(VERSION 3.13)
project(multi_process)

set(CMAKE_CXX_STANDARD 98)
add_executable(server server.cpp)
add_executable(client client.cpp)
