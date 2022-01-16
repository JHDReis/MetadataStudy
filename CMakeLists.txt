cmake_minimum_required(VERSION 3.20.0)
project(MetadataStudy)

set(CMAKE_CXX_STANDARD 17)

# include the cmake modules directory
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(metadata)
add_subdirectory(CPlusPlusTemplates)
add_subdirectory(tests)
add_subdirectory(library)

add_executable(metadata_run main.cpp)

link_libraries(metadata_run metadataLib)


