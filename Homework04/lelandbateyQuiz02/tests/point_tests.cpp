#include <string>
#include <iostream>
#include "../kd_point.h"

int main(int argc, char const *argv[])
{
    
    kd_point pnt1(std::string("AGGVGGK"),double(0.149476528));

    // AGGVGGK,0.149476528    

    std::cout << pnt1.mass << std::endl;
    std::cout << pnt1.NET << std::endl;
    std::cout << pnt1.peptide << std::endl;

    return 0;
}
