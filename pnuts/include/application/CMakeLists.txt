cmake_minimum_required(VERSION 3.22.2)

add_library(app_interface_lib INTERFACE) 
target_link_libraries(app_interface_lib INTERFACE ${CMAKE_DL_LIBS})
target_include_directories( app_interface_lib INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> )
