cmake_minimum_required(VERSION 3.0)
project(std_thread)
set(CMAKE_BUILD_TYPE Debug)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)     

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)     

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")

add_executable(hello_wordl 0_std_thread_hello_world.cpp)
