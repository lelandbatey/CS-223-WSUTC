#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <math.h>
#include "lfbLib.h"




int main(int argc, char const *argv[])
{
    std::string tempStr;
    char* tempChr;
    tempChr = new char[4];

    for (int i = 65; i < 91; ++i)
    {
        for (int x = 65; x < 91; ++x)
        {
            for (int n = 65; n < 91; ++n)
            {
                // std::cout << i << x << n << std::endl;
                tempChr[0] = char(i);
                tempChr[1] = char(x);
                tempChr[2] = char(n);
                tempChr[3] = char(n);


                std::cout <<  char(i) << char(x) << char(n) << std::endl;
                // std::cout << "  i       : '" <<   i     << "'" << std::endl;
                // std::cout << "  x       : '" <<   x     << "'" << std::endl;
                // std::cout << "  n       : '" <<   n     << "'" << std::endl;
                // std::cout << "  char i  : '" <<   char(i)     << "'" << std::endl;
                // std::cout << "  char x  : '" <<   char(x)     << "'" << std::endl;
                // std::cout << "  char n  : '" <<   char(n)     << "'" << std::endl;
                
                // std::cout << "  tempChr : '" << tempChr << "'" << std::endl;

                std::cout << "  "<< deriveNumericName(std::string( tempChr ) ) << std::endl;
                
                
            }
        }
    }

    return 0;
}
