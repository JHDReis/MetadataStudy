//
// Created by Joao Henriques David Dos Reis on 09/07/2018.
//

#include "gtest/gtest.h"
#include "metadataStudy3.h"

TEST(incrementalType, int_is_incremental) {
    bool result = is_incrementable<int>::value;

    ASSERT_EQ(true, result);
}

TEST(incrementalType, string_is_not_incremental) {
    bool result = is_incrementable<std::string>::value;

    ASSERT_EQ(false, result);
}

TEST(incrementalType, float_is_not_incremental) {
    bool result = is_incrementable<float>::value;

    ASSERT_EQ(true, result);
}