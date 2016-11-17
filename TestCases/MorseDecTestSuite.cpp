#include <gtest/gtest.h>
#include <string>
#include "../Include/MorseDec.hpp"

TEST(MorseDecTestSuite, TheOutputShouldBeDotWithBitOne)
{
    std::string l_str("1");
    
    ASSERT_EQ(".", MorseDec::decodeBits(l_str));
}
