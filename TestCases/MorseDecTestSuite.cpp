#include <gtest/gtest.h>
#include <string>
#include "../Include/MorseDec.hpp"

TEST(MorseDecTestSuite, TheOutputShouldBeOneDot)
{
    std::string l_str("1");
    
    ASSERT_EQ(".", MorseDec::decodeBits(l_str));
}

TEST(MorseDecTestSuite, TheOutputShouldBeTwoDots)
{
    std::string l_str("101");
    
    ASSERT_EQ("..", MorseDec::decodeBits(l_str));
}

TEST(MorseDecTestSuite, TheOutputShouldBeDashAndDot)
{
    std::string l_str("11101");
    
    ASSERT_EQ("-.", MorseDec::decodeBits(l_str));
}

TEST(MorseDecTestSuite, TheOutputShouldBe2Dashs)
{
    std::string l_str("1110111");
    ASSERT_EQ("--", MorseDec::decodeBits(l_str));
}

TEST(MorseDecTestSuite, TheOutputShouldBeOneSpace)
{
    std::string l_str("111000111");
    ASSERT_EQ("- -", MorseDec::decodeBits(l_str));
}