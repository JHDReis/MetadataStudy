cmake_minimum_required(VERSION 3.10)
message("gtest_SOURCE_DIR ${gtest_SOURCE_DIR}")

include_directories(../../CPlusPlusTemplates)

add_executable(run_metadata_test
        chapter2_tests.cpp
        chapter3_tests.cpp
        chapter4_tests.cpp
        chapter5_tests.cpp)

target_link_libraries(run_metadata_test gtest gtest_main templatesGuide)