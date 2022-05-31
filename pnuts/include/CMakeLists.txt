cmake_minimum_required(VERSION 3.22.2)
project(pnuts VERSION 1.0.0)

add_subdirectory(dlloader)
add_subdirectory(application)

add_library(pnuts INTERFACE)
target_link_libraries(pnuts INTERFACE dlloader_lib app_interface_lib)
target_include_directories(pnuts INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> )

