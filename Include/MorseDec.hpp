#pragma once

#include <string>

class MorseDec
{
public:
    static std::string decodeBits(const std::string&);

private:
    static std::string processContinuousOnes(auto p_iterOne, auto p_iterZero);
    static std::string processContinuousZeros(auto p_iterOne, auto p_iterZero);
    
    static unsigned int calcRate()
    {
        return 1;
    }
};
