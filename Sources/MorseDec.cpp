#include "../Include/MorseDec.hpp"
#include <algorithm>


std::string MorseDec::processContinuousOnes(auto p_iterOne, auto p_iterZero)
{
    if((p_iterZero - p_iterOne)/calcRate() == 3)
    {
        return "-";
    }
    if((p_iterZero - p_iterOne)/calcRate() == 1)
    {
        return ".";
    }
    
    return "";
}

std::string MorseDec::processContinuousZeros(auto p_iterOne, auto p_iterZero)
{
    if((p_iterOne - p_iterZero)/calcRate() == 3)
    {
        return " ";
    }
    if((p_iterOne - p_iterZero)/calcRate() == 7)
    {
        return "   ";
    }
    
    return "";
}

std::string MorseDec::decodeBits(const std::string& p_str)
{
    std::string l_result;
    int l_rate = 1;
    auto l_point2One = std::find(p_str.begin(), p_str.end(), '1');
    auto l_point2Zero = l_point2One;

    while(l_point2One !=  p_str.end())
    {
        l_point2Zero = std::find(l_point2One, p_str.end(), '0');
        l_result += processContinuousOnes(l_point2One, l_point2Zero);

        l_point2One = std::find(l_point2Zero, p_str.end(), '1');
        l_result += processContinuousZeros(l_point2One, l_point2Zero);       
    }
    return l_result;
}