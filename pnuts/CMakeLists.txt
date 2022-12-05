cmake_minimum_required(VERSION 3.22.2)
project(pnuts VERSION 1.0.0)

add_library(pnuts INTERFACE)
set_target_properties(
    pnuts PROPERTIES
    CXX_STANDARD 17
)
target_link_libraries(pnuts INTERFACE ${CMAKE_DL_LIBS})
target_include_directories(pnuts INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include)

add_executable(entry_point src/entry_point.cpp src/log.cpp)
set_target_properties(
    entry_point PROPERTIES
    CXX_STANDARD 17
)
target_link_libraries(entry_point PUBLIC pnuts sandbox)
