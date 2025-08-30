cmake_minimum_required(VERSION 3.27)
project(
    vectors_class
    VERSION 0.0.1
    DESCRIPTION "Pypind practice"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Python COMPONENTS Interpreter Development REQUIRED)

add_subdirectory(libs/pybind11)


pybind11_add_module(vectors_class src/main.cpp )


#set(CMAKE_BUILD_TYPE Debug)

#add_executable(practice9)



#target_sources(practice9 PRIVATE ${sources})