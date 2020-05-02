//
// Created by Joao Henriques David Dos Reis on 29/06/2018.
//

#include "gtest/gtest.h"
#include "metadataStudy1.h"


class myFrakFixture: public::testing::Test {
public:
    myFrakFixture( ) {
        // initialization code here
    }

    void SetUp( ) {
        // code here will execute just before the test ensues
    }

    void TearDown( ) {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
    }

    ~myFrakFixture( )  {
        // cleanup any pending stuff, but no exceptions allowed
    }

    // put in any custom data members that you need
};



TEST_F(myFrakFixture, Fraktion){

    typedef Frak<1,2> one_half;

    int den = one_half::Den;
    int num = one_half::Num;

    ASSERT_EQ(2, den);
    ASSERT_EQ(1, num);
}



TEST_F(myFrakFixture, ScalarMultiplication){

    typedef Frak<1,2> one_half;

    typedef ScalarMultiplication<2,one_half> multi;
    auto den = multi::result::Den;
    auto num = multi::result::Num;

    ASSERT_EQ(4, den);
    ASSERT_EQ(2, num);
}

TEST_F(myFrakFixture, Simplification_1Step){

    typedef MCD<4,2> deno;

    int com = deno::result;

    ASSERT_EQ(2, com);
}


TEST_F(myFrakFixture, Simplification_2Step){

    typedef Frak<2,4> two_quarters;

    typedef Simpl<two_quarters> simp;

    int num = simp::result::Num;
    int den = simp::result::Den;

    ASSERT_EQ(2, den);
    ASSERT_EQ(1, num);
}


TEST_F(myFrakFixture, SameBase){

    typedef Frak<2,4> two_quarters;
    typedef Frak<1,3> one_half;

    typedef SameBase<two_quarters, one_half> sameBase;

    typedef sameBase::X x;
    typedef sameBase::Y y;

    int x_num = x::Num;
    int x_den = x::Den;

    int y_num = y::Num;
    int y_den = y::Den;

    ASSERT_EQ(6, x_num);
    ASSERT_EQ(12, x_den);

    ASSERT_EQ(4, y_num);
    ASSERT_EQ(12, y_den);
}

TEST_F(myFrakFixture, Sum){

    typedef Frak<2,4> two_quarters;
    typedef Frak<1,3> one_half;

    typedef Sum<two_quarters, one_half> sumResult;

    int num = sumResult::Num;
    int den = sumResult::Den;

    ASSERT_EQ(10, num);
    ASSERT_EQ(12, den);

}


TEST_F(myFrakFixture, Factorial_of_1){

    typedef Frak<2,4> two_quarters;
    typedef Frak<1,3> one_half;

    typedef E<1> fractal;

    int num = fractal::result::Num;
    int den = fractal::result::Den;

    ASSERT_EQ(2, num);
    ASSERT_EQ(1, den);
}


TEST_F(myFrakFixture, Factorial_of_2){

    typedef Frak<2,4> two_quarters;
    typedef Frak<1,3> one_half;

    typedef E<2> fractal;

    int num = fractal::result::Num;
    int den = fractal::result::Den;

    ASSERT_EQ(5, num);
    ASSERT_EQ(2, den);
}

TEST_F(myFrakFixture, Factorial_of_3){

    typedef Frak<2,4> two_quarters;
    typedef Frak<1,3> one_half;

    typedef E<3> fractal;

    int num = fractal::result::Num;
    int den = fractal::result::Den;

    ASSERT_EQ(8, num);
    ASSERT_EQ(3, den);
}


