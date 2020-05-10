//
// Created by Joao Henriques David Dos Reis on 07/05/2020.
//

#include "gtest/gtest.h"
#include "../../CPlusPlusTemplates/Chapter4.h"
#include <algorithm>

using namespace chapter4;

TEST(Chapter4, pushNotFullStack)
{
    Stack<int,4> s{};
    s.push(1);
    s.push(2);
    s.push(3);
    ASSERT_FALSE(s.full());
}

TEST(Chapter4, pushFullStack)
{
    Stack<int,4> s{};
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    ASSERT_TRUE(s.full());
}

TEST(Chapter4, pushMoreFullStack)
{
    Stack<int,4> s{};
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    ASSERT_THROW(s.push(5), std::out_of_range);
}

TEST(Chapter4, stringtest)
{
    Stack<std::string, 40> stringStack;
    int N = 40;

    while(N--)
    {
        stringStack.push("Hello");
    }

    ASSERT_TRUE(stringStack.full());
}

TEST( Chapter4, AddValue)
{
    std::vector<int> source {1,2,3,4,5};

    std::transform( source.begin(), source.end(), source.begin(), AddValue < int, 5 > );

    ASSERT_EQ(*source.begin(), 6);
    ASSERT_EQ(*(source.begin() + 1), 7);
    ASSERT_EQ(*(source.begin() + 2), 8);
    ASSERT_EQ(*(source.begin() + 3), 9);
    ASSERT_EQ(*(source.begin() + 4), 10);
}