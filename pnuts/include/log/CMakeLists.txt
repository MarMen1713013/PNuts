cmake_minimum_required(VERSION 3.22.2)

add_library(log_lib src/log.cpp)
target_link_libraries(log_lib PRIVATE spdlog)
target_include_directories(log_lib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
