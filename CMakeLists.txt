cmake_minimum_required(VERSION 3.9)
project(MetadataStudy)

set(CMAKE_CXX_STANDARD 17)

# include the cmake modules directory
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})

add_subdirectory(metadata)
add_subdirectory(CPlusPlusTemplates)
add_subdirectory(tests)


add_executable(metadata_run main.cpp)

link_libraries(metadata_run metadataLib)


