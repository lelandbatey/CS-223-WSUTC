#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "animals_c.h"
#include "readAnimalCsv.cpp"



int main(int argc, char const *argv[])
{
    if (argc < 2){
        std::cout << "Yall didn't put in a file name :P" << std::endl;
        return 0;
    }
    std::string fileName = std::string(argv[1]);
    animal_ts* animals = getAnimals(fileName);
    // prnt("We're back from getting animals!");
    std::cout <<" Size of animals struct: '" << sizeof(animals) << "'" << std::endl;
    for (unsigned int i = 0; i < sizeof(animals); ++i)
    {
        std::cout <<"Type         : "<< animals[i].type << std::endl;
        std::cout <<"Name         : "<< animals[i].name << std::endl;
        std::cout <<"Age          : "<< animals[i].age << std::endl;
        std::cout <<"Friendliness : "<< animals[i].friendliness << std::endl;
        std::cout <<"Weight       : "<< animals[i].weight << std::endl;
        std::cout <<"Hunger       : "<< animals[i].hunger << std::endl << std::endl;
    }

    std::string thing = "abcdefg";
    std::cout << thing.substr(0, 2) << std::endl;

    return 0;
}