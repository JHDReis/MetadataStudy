set(gtest_SOURCE_DIR lib/googletest/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(run_testStudy1Test unitTest1.cpp unitTest2.cpp metadataStudyUnitTest1.cpp metadataStudy3UnitTest.cpp)

target_link_libraries(run_testStudy1Test gtest gtest_main)
target_link_libraries(run_testStudy1Test metadataLib)