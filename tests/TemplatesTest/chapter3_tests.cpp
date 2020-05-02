//
// Created by Joao Henriques David Dos Reis on 01/05/2020.
//

#include "gtest/gtest.h"
#include "../../CPlusPlusTemplates/Chapter3.h"



TEST(Chapter3, intStack)
{
    Stack<int> intStack;

    intStack.push(7);

    ASSERT_EQ(intStack.top(),7);
}

TEST(Chapter3, stringStack)
{
    Stack<std::string> intStack;

    intStack.push("seven");

    ASSERT_EQ(intStack.top(),"seven");
}

TEST(Chapter3, stringStack_empty)
{
    Stack<std::string> intStack;

    intStack.push("seven");

    ASSERT_EQ(intStack.top(),"seven");

    intStack.pop();

    ASSERT_THROW(intStack.pop(), std::out_of_range);
}

TEST(Chapter3, stringStack_CopyConstructor)
{
    Stack<std::string> intStack;
    intStack.push("seven");

    ASSERT_EQ(intStack.top(),"seven");

    Stack a(intStack);

    ASSERT_EQ(a.top(), intStack.top());
}

TEST(Chapter3, partial_specialization)
{
    MyClass<int,int> a;

    auto b = a.sum(1,1);

    ASSERT_EQ(b,2);
}

TEST(Chapter3, partial_specialization_float)
{
    MyClass<int,float> a;

    auto b = a.sum(1,1.1);

    ASSERT_FLOAT_EQ(b,3.2);
}