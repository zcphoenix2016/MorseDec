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

TEST(MorseDecTestSuite, TheOutputShouldContainOneSpace)
{
    std::string l_str("101000111");
    ASSERT_EQ(".. -", MorseDec::decodeBits(l_str));
}

TEST(MorseDecTestSuite, TheOutputShouldContain3Spaces)
{
    std::string l_str("1110000000111");
    ASSERT_EQ("-   -", MorseDec::decodeBits(l_str));
}

TEST(MorseDecTestSuite, TheOutputShouldBeTwoDotsWithRate2)
{
    std::string l_str("110011");
    ASSERT_EQ("..", MorseDec::decodeBits(l_str));
}

TEST(MorseDecTestSuite, TheOutputShouldBeTwoDotsWithUselessZeros)
{
    std::string l_str("0000110011000000");
    ASSERT_EQ("..", MorseDec::decodeBits(l_str));
}

TEST(MorseDecTestSuite, SpecialTestCase1)
{
    std::string l_str("000000001111111111110000000000001111111111110000000");
    ASSERT_EQ("..", MorseDec::decodeBits(l_str));
}

TEST(MorseDecTestSuite, SpecialTestCase2)
{
    std::string l_str("11111100000000000000111111");
    ASSERT_EQ("-   -", MorseDec::decodeBits(l_str));
}

TEST(MorseDecTestSuite, TheLastTestCase)
{
   std::string l_str("1100110011001100000011000000111111001100111111001111110000000000000011001111110011111100111111000000110011001111110000001111110011001100000011");
   
   ASSERT_EQ(".... . -.--   .--- ..- -.. .", MorseDec::decodeBits(l_str));
}

