#include "../Include/MorseDec.hpp"
#include <algorithm>


std::string MorseDec::decodeBits(const std::string& p_str)
{
    std::string l_result;
    
    
    
/*    for(int i = 0;i < p_str.size();i++)
    {
       
       if('1' == p_str[i])
       {
           l_result+= p_str[i];
       }
       
       
           
    }*/
    int l_rate = 1;
    auto l_point2One = p_str.begin();
    l_point2One = std::find(p_str.begin(), p_str.end(), '1');
    auto l_point2Zero = l_point2One;
     
    while(l_point2One !=  p_str.end())
    {
        l_point2Zero = std::find(l_point2One, p_str.end(), '0');
        if((l_point2Zero - l_point2One)/l_rate == 3)
        {
            l_result += "-";
        }
        if((l_point2Zero - l_point2One)/l_rate == 1)
        {
            l_result += ".";
        }

        l_point2One = std::find(l_point2Zero, p_str.end(), '1');
    }
    return l_result;
}