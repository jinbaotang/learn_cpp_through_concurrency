cmake_minimum_required(VERSION 3.0)
project(std_thread)
set(CMAKE_BUILD_TYPE Debug)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)     

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)     

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")

add_executable(hello_wordl 0_std_thread_hello_world.cpp)

add_executable(std_thread_use 5_std_thread_use_more.cpp)

add_executable(std_ref_use 2_std_ref_use.cpp)
add_executable(std_bind_use 3_std_bind_use.cpp)
add_executable(std_bind_use3_1 3_1_std_bind_use.cpp)
add_executable(std_move_use 4_std_move_use.cpp)
add_executable(std_time_mutex 6_std_time_mutex.cpp)
add_executable(std_promise_future 7_std_promise_future.cpp)
add_executable(std_condition_variavle 8_std_condition_variavle.cpp)