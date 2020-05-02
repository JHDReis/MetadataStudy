
message("gtest_SOURCE_DIR ${gtest_SOURCE_DIR}")

add_executable(run_metadata_test chapter2_tests.cpp)
target_link_libraries(run_metadata_test gtest gtest_main templatesGuide)