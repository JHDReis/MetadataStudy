//
// Created by Joao Henriques David Dos Reis on 02/04/2018.
//

#include "gtest/gtest.h"
#include "metadataStudy2.h"

TEST(unitTest2, test_the_Int) {
    Int<1> UM;
    const int result = UM.value;
    ASSERT_EQ(1,result);
}

typedef Lst< Int<1>, Lst<Int<2>, Lst< Int<3> > > > OneTwoThree;

TEST(unitTest2, test_a_list_first) {
    auto result = OneTwoThree::Head::value;
    ASSERT_EQ(1, result);
}

TEST(unitTest2, test_a_list_second) {
    auto result = OneTwoThree::Tail::Head::value;
    ASSERT_EQ(2, result);
}

TEST(unitTest2, test_a_list_third) {
    auto result = OneTwoThree::Tail::Tail::Head::value;
    ASSERT_EQ(3, result);
}

TEST(unitTest2, test_a_list_length) {
    int result = Length<OneTwoThree>::result;
    ASSERT_EQ(3, result);
}

TEST(unitTest2, get_from_list_2nd_element) {
    const int index = 1;
    int result = Nth<OneTwoThree, index>::result::value;
    ASSERT_EQ(2, result);
}

TEST(unitTest2, get_from_list_3rd_element) {
    const int index = 2;
    int result = Nth<OneTwoThree, index>::result::value;
    ASSERT_EQ(3, result);
}