#include "../Include/MorseDec.hpp"
#include <algorithm>

unsigned int my_gcd(unsigned int m,unsigned n)
{
    int a,b,r;
    if( m > n)
    {
        a = m; b = n;
    }
    else
    {
        a = n; b = m;
    }
    
    r = b;
    while(r != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    
    return a;
}
std::string MorseDec::processContinuousOnes(auto p_iterOne, auto p_iterZero, 
                                            unsigned int p_rate)
{
    if((p_iterZero - p_iterOne)/p_rate == 3)
    {
        return "-";
    }
    if((p_iterZero - p_iterOne)/p_rate == 1)
    {
        return ".";
    }
    
    return "";
}

std::string MorseDec::processContinuousZeros(auto p_iterOne, auto p_iterZero,
                                            unsigned int p_rate)
{
    if((p_iterOne - p_iterZero)/p_rate == 3)
    {
        return " ";
    }
    if((p_iterOne - p_iterZero)/p_rate == 7)
    {
        return "   ";
    }
    
    return "";
}

unsigned int MorseDec::calcRate(const std::string& p_str)
{   
    unsigned int l_rate;
    unsigned int l_distanceofone = p_str.length() ,l_distanceofzero = p_str.length();


    auto l_point2One = std::find(p_str.begin(), p_str.end(), '1');   
    auto l_point2Zero = l_point2One;
    while(l_point2One !=  p_str.end())
    {
        l_point2Zero = std::find(l_point2One, p_str.end(), '0');
        l_rate = l_point2Zero - l_point2One;
        if(l_distanceofone > l_rate)
        {
            l_distanceofone = l_rate;
        }       

        l_point2One = std::find(l_point2Zero, p_str.end(), '1');
        l_rate = l_point2One - l_point2Zero;
        if( l_distanceofzero > l_rate && 0 != l_rate )
        {
            l_distanceofzero = l_rate;
        }          
    }
    
    l_rate = my_gcd(l_distanceofzero, l_distanceofone);
    
    return l_rate;
    
}

std::string MorseDec::decodeBits(std::string p_str)
{
    p_str.erase(0, p_str.find('1'));
    p_str.erase(p_str.rfind('1') + 1);
    
    std::string l_result;
    unsigned int l_rate = calcRate(p_str);
    auto l_point2One = std::find(p_str.begin(), p_str.end(), '1');
    auto l_point2Zero = l_point2One;

    while(l_point2One !=  p_str.end())
    {
        l_point2Zero = std::find(l_point2One, p_str.end(), '0');
        l_result += processContinuousOnes(l_point2One, l_point2Zero, l_rate);

        l_point2One = std::find(l_point2Zero, p_str.end(), '1');
        l_result += processContinuousZeros(l_point2One, l_point2Zero, l_rate);       
    }
    return l_result;
}