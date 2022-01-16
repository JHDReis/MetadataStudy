#include <gtest/gtest.h>
#include "parameter_class.h"
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

