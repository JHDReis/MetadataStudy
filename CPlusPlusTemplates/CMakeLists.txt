cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)

project(templatesGuide C CXX)

message("PROJECT_NAME : ${PROJECT_NAME} ")

add_library(${PROJECT_NAME}
        Chapter2.h
        Chapter3.h
        Chapter2.cpp
        Chapter3.cpp
        Chapter4.h
        Chapter5.h)