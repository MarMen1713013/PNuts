cmake_minimum_required(VERSION 3.22.2)
project(pnuts VERSION 1.0.0)

add_library(pnuts_engine src/test.cpp )
target_include_directories( pnuts_engine PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> )
