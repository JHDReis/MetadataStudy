//
// Created by Joao Henriques David Dos Reis on 07/05/2020.
//

#include "gtest/gtest.h"
#include "../../CPlusPlusTemplates/Chapter4.h"

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