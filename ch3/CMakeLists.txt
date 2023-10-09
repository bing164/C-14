cmake_minimum_required(VERSION 3.21)
project(ch3)

set(CMAKE_CXX_STANDARD 14)

add_executable(derivative derivative.cpp)
add_executable(accumulate_functor_example accumulate_functor_example.cpp)
add_executable(lambda lambda.cpp)