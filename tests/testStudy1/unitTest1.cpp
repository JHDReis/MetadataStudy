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


//Factorial tests
TEST(unitTest1, factor_1_should_be_1){
    int result = FACTOR<1>::RESULT;
    ASSERT_EQ(1,result);
}


TEST(unitTest1, factor_2_should_be_1){
    int result = FACTOR<2>::RESULT;
    ASSERT_EQ(2,result);
}

TEST(unitTest1, factor_3_should_be_6){
    int result = FACTOR<3>::RESULT;
    ASSERT_EQ(6,result);
}

TEST(unitTest1, factor_4_should_be_32){
    const int res = 4;
    int result = FACTOR<res>::RESULT;
    ASSERT_EQ(24,result);
}


//Fibonacci Tests
TEST(unitTest1, fib_of_0_should_be_1){
    const unsigned long n = 0;
    int result = FIBONACCI<n>::RESULT;
    ASSERT_EQ(0,result);
}


TEST(unitTest1, fib_of_1_should_be_1){
    const unsigned long n = 1;
    int result = FIBONACCI<n>::RESULT;
    ASSERT_EQ(1,result);
}


TEST(unitTest1, fib_of_2_should_be_1) {
    const unsigned long n = 2;
    int result = FIBONACCI<n>::RESULT;
    ASSERT_EQ(1,result);
}


TEST(unitTest1, fib_of_3_should_be_2) {
    const unsigned long n = 3;
    int result = FIBONACCI<n>::RESULT;
    ASSERT_EQ(2,result);
}


TEST(unitTest1, fib_of_4_should_be_3) {
    const unsigned long n = 4;
    int result = FIBONACCI<n>::RESULT;
    ASSERT_EQ(3,result);
}


TEST(unitTest1, fib_of_5_should_be_3) {
    const unsigned long n = 5;
    int result = FIBONACCI<n>::RESULT;
    ASSERT_EQ(5,result);
}


TEST(unitTest1, fib_of_11_should_be_89) {
    const unsigned long n = 11;
    int result = FIBONACCI<n>::RESULT;
    ASSERT_EQ(89,result);
}


TEST(unitTest1, fib_of_20_should_be_6765) {
    const unsigned long n = 20;
    int result = FIBONACCI<n>::RESULT;
    ASSERT_EQ(6765,result);
}


TEST(unitTest1, fib_of_150_should_be_67650) {
    const unsigned long n = 150;
    int result = FIBONACCI<n>::RESULT;
    ASSERT_EQ(626779336,result);
}
