cmake_minimum_required(VERSION 3.9)
project(MetadataStudy)

set(CMAKE_CXX_STANDARD 17)

add_executable(metadata_run main.cpp)

include_directories(metadata)

add_subdirectory(metadata)
add_subdirectory(tests)
