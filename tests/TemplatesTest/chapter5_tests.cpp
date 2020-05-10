//
// Created by HEJ on 10/05/2020.
//

#include "gtest/gtest.h"
#include "../../CPlusPlusTemplates/Chapter5.h"

TEST( Chapter5, printcoll)
{
    std::vector l {0,1,2,3,4,5,6,7,8,9};

    printcoll(l);

    ASSERT_EQ(l.size(), 10);
}