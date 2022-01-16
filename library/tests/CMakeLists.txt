enable_testing()

find_package(GTest REQUIRED)

add_executable(library_tests
        parameter_class_test.cpp
        )

target_link_libraries(library_tests
        library
        gtest_main
        )

include(GoogleTest)
gtest_discover_tests(library_tests)