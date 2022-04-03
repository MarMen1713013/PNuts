cmake_minimum_required(VERSION 3.22.2)
project(pnuts_engine VERSION 1.0.0)

add_subdirectory(pnuts)
add_executable( sandbox sandbox/test.cpp )
target_link_libraries(sandbox PUBLIC pnuts_engine)
