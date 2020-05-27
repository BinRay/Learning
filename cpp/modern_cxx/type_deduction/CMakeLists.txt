cmake_minimum_required(VERSION 3.13)
project(type_deduction)
set(CMAKE_CXX_STANDARD, 14)
add_executable(type_deduction main.cpp auto.cpp decltype.cpp)