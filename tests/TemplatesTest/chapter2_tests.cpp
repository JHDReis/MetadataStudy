//
// Created by Joao Henriques David Dos Reis on 01/05/2020.
//

#include "gtest/gtest.h"
#include "../../CPlusPlusTemplates/Chapter2.h"

TEST(Template, testit)
{
    int a = 0;
    int b = 1;

    int m = max<int>(a,b);

    ASSERT_TRUE(m == b);
}

TEST(Template, test_strings)
{
    auto a = "1234";
    auto b = "12345";

    auto m = max(a,b);

    ASSERT_TRUE(m == b);
}

TEST(Template, testit2)
{
    auto a = 0;
    auto b = 1;
    auto c = 3;

    auto m = max(a,b,c);

    ASSERT_TRUE(m == c);
}




