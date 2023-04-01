cmake_minimum_required(VERSION 3.22.2)
project(pnuts VERSION 1.0.0)

add_subdirectory(pnuts_engine)
add_executable(entry_point src/entry_point.cpp) # src/log.cpp)
target_link_libraries(entry_point PUBLIC pnuts_engine)
