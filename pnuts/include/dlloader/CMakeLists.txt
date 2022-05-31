cmake_minimum_required(VERSION 3.22.2)
project(dlloader VERSION 1.0.0)

add_library(dlloader_lib INTERFACE) 
target_link_libraries(dlloader_lib INTERFACE ${CMAKE_DL_LIBS})
target_include_directories( dlloader_lib INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> )
