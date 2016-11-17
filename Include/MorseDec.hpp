#pragma once

#include <string>

class MorseDec
{
public:
    static std::string decodeBits(const std::string&);

private:
    static std::string processContinuousOnes(auto p_iterOne, auto p_iterZero, 
    unsigned int p_rate);
    static std::string processContinuousZeros(auto p_iterOne, auto p_iterZero,
    unsigned int p_rate);
    
    static unsigned int calcRate(const std::string&);
};
