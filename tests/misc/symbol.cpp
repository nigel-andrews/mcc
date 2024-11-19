#include "misc/symbol.h"

#include <gtest/gtest.h>
#include <sstream>

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

TEST(symbol, stream)
{
    misc::symbol sym = "yeet";
    std::stringstream sstr;
    sstr << sym;

    ASSERT_EQ(sstr.str(), sym.get());
}
