//
// Created by Joao Henriques David Dos Reis on 01/04/2018.
//

#include "gtest/gtest.h"
#include "metadataStudy1.h"


TEST(unitTest1, testBinary){
    int result = BITS_SET<15>::RESULT;
    ASSERT_EQ(4, result);
}

TEST(unitTest1, test_another_char) {
    const unsigned char byte = 'A';
    int result;
    result = BITS_SET<byte>::RESULT;
    ASSERT_EQ(2, result);
}


