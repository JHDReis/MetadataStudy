project(library
        VERSION 1.0.0
        DESCRIPTION "template library helper")

set(CMAKE_CXX_STANDARD 17)

add_library(library SHARED
        include/parameter_class.h
        parameter_class.cpp)

set_target_properties(library PROPERTIES SOVERSION 1)

target_include_directories(library PUBLIC include)
target_include_directories(library PRIVATE .)

add_subdirectory(tests)