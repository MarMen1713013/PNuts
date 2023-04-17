cmake_minimum_required(VERSION 3.22.2)
project(pnuts_engine VERSION 1.0.0)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

#required for unit testing + modules
include(CTest)
enable_testing()
include(ExternalProject)

add_subdirectory(pnuts)
add_subdirectory(sandbox)
