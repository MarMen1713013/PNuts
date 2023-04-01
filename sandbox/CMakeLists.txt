cmake_minimum_required(VERSION 3.22.2)
project(sandbox VERSION 1.0.0)

add_library(sandbox SHARED Application.cpp)
target_link_libraries(sandbox PUBLIC pnuts_engine)
