#include "misc/symbol.h"

#include <gtest/gtest.h>

TEST(symbol, basic)
{
    misc::symbol s1("test");
    misc::symbol s2("test");

    ASSERT_EQ(&s1.get(), &s2.get());
}

TEST(symbol, conversion)
{
    std::string s = "toto";
    misc::symbol s1(s);

    ASSERT_EQ(s1, s);
}

TEST(symbol, get)
{
    std::string s("toto");
    misc::symbol sym(s);

    ASSERT_EQ(sym.get(), s);
}
