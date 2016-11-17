#include "../Include/MorseDec.hpp"

std::string MorseDec::decodeBits(const std::string& p_str)
{
    std::string l_result;
    for(int i = 0;i < p_str.size();i++)
    {
       if('1' == p_str[i])
       {
           l_result+='.';
       }
           
    }
    return l_result;
}