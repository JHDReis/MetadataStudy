#include <gtest/gtest.h>
#include "parameter_class.h"
#include "helpers.h"
#include "test_classes.h"
#include <iostream>

using namespace library;
// Demonstrate some basic assertions.
TEST(PARAMETERCLASS, TEST1) {

    Bar bar;

    auto const a = bar.a();
    auto const b = library::Bar::b();
    auto const ea = EnableFeatureA::apply(&bar);
    auto const eb = EnableFeatureB::apply(&bar);

    EXPECT_EQ(a, ea);
    EXPECT_EQ(b, eb);
}

TEST(HELPERS, TEST2) {

    tests::TestA<int> a{2};
    tests::TestB<char> b{'R'};

    auto result = details::IsBuffered<details::Buffered<double>>();
    auto result1 = details::is_instance<tests::TestA<int>, tests::TestA>();

    using type = details::IsBuffered<details::Buffered<double>>::ValueType ;
    using type1 = details::is_instance<tests::TestA<int>, tests::TestA>::ValueType;

    EXPECT_TRUE(result);
    EXPECT_TRUE(result1);
    EXPECT_TRUE(std::is_floating_point_v<type>);
    EXPECT_TRUE(std::is_integral_v<type1>);
}
