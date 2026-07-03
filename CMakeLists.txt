cmake_minimum_required(VERSION 4.3)

project(MyCalc)

add_executable(MyCalc)

target_sources(MyCalc PRIVATE src/main.cpp)

add_library(Exceptions)

target_sources(Exceptions
    PRIVATE 
        src/custom-exceptions.cpp

    PUBLIC 
        FILE_SET HEADERS
        FILES src/custom-exceptions.hpp
)

target_link_libraries(MyCalc PRIVATE Exceptions)