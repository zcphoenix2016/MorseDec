#include <gtest/gtest.h>
#include <string>
#include "../Include/MorseDec.hpp"

TEST(MorseDecTestSuite, TheOutputShouldBeDotWithOneBit)
{
    std::string l_str("1");
    
    ASSERT_EQ(".", MorseDec::decodeBits(l_str));
}

TEST(MorseDecTestSuite, TheOutputShouldBeTwoDotsWithTreeBits)
{
    std::string l_str("101");
    
    ASSERT_EQ("..", MorseDec::decodeBits(l_str));
}
