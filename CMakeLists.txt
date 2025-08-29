cmake_minimum_required(VERSION 3.27)
project(
    practice9
    VERSION 0.0
    DESCRIPTION "First edition"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

add_executable(practice9)

set(sources
    src/main.cpp    

    src/vector3d.cpp
    src/vector3d.h

    
)

target_sources(practice9 PRIVATE ${sources})