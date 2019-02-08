cmake_minimum_required(VERSION 2.8)
project(project2)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Customer.cpp Customer.h Event.cpp Event.h main.cpp Simulation0.cpp Simulation0.h Simulation1.cpp Simulation1.h)
add_executable(project2 ${SOURCE_FILES})


