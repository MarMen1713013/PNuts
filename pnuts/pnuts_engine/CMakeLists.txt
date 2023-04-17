cmake_minimum_required(VERSION 3.22.2)
project(pnuts_engine VERSION 1.0.0)

add_subdirectory(libs)

add_library(pnuts_engine INTERFACE)

target_link_libraries(pnuts_engine INTERFACE ${CMAKE_DL_LIBS})
target_include_directories( pnuts_engine 
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/spdlog/include
)

