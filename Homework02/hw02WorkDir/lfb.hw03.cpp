#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "lfbLib.h"
#include "readAnimalCsv.cpp"
#include "animals_c.h"


void printZoo(std::vector<animals_c*> zoo) {
    std::cout <<" Size of ZOO! vector: '" << zoo.size() << "'" << std::endl;
    for (unsigned int i = 0; i < zoo.size(); ++i)
    {
        // Prints out the variables, as well as what the type of each is. Done to verify that the types had been corectly converted.
        std::cout <<"Name         : '"<< zoo[i]->getName()     << "' : " << typeid( zoo[i]->getName()     ).name() << std::endl;
        std::cout <<"Type         : '"<< zoo[i]->getType()     << "' : " << typeid( zoo[i]->getType()     ).name() << std::endl;
        std::cout <<"Age          : '"<< zoo[i]->getAge()      << "' : " << typeid( zoo[i]->getAge()      ).name() << std::endl;
        std::cout <<"Friendliness : '"<< zoo[i]->getFriendly() << "' : " << typeid( zoo[i]->getFriendly() ).name() << std::endl;
        std::cout <<"Weight       : '"<< zoo[i]->getWeight()   << "' : " << typeid( zoo[i]->getWeight()   ).name() << std::endl;
        std::cout <<"Hunger       : '"<< zoo[i]->getHunger()   << "' : " << typeid( zoo[i]->getHunger()   ).name() << std::endl << std::endl;
    }
}


int main(int argc, char const *argv[])
{
    if (argc < 2){ // If they didn't pass in a second argument (the file name)
        std::cout << "Yall didn't put in a file name :P" << std::endl;
        return 0;
    }


    int doneFlag = 0;
    double feedAmnt;


    std::string spaceDelim = " ";
    std::string fileName = std::string(argv[1]);
    std::vector<animal_ts> animals = getAnimals(fileName); // Builds a vector of pointers to animals
    std::string input;


    if (DEBUG_FLAG) {
        std::cout <<" Size of animals vector: '" << animals.size() << "'" << std::endl;
        for (int i = 0; i < actualAnimals(animals); ++i)
        {
            std::cout <<"Type         : "<< animals[i].type << std::endl;
            std::cout <<"Name         : "<< animals[i].name << std::endl;
            std::cout <<"Age          : "<< animals[i].age << std::endl;
            std::cout <<"Friendliness : "<< animals[i].friendliness << std::endl;
            std::cout <<"Weight       : "<< animals[i].weight << std::endl;
            std::cout <<"Hunger       : "<< animals[i].hunger << std::endl << std::endl;
        }
    }

    // OH SNAP I HOPE THIS WORKS!?!
    // SPOILER ALERT: it totally does! : )
    std::vector<animals_c*> zoo = buildZoo( animals );



    if (DEBUG_FLAG) {
        printZoo(zoo);
    }



/*  Check the values to make sure they're valid:
        1. Weight cannot be a negative value
        2. Age cannot be a negative value
            NOTE: 0 is not a negative (or positive) value. So weight and age cannot be less than 0.
*/
    for (unsigned int i = 0; i < zoo.size(); ++i) {
        if (zoo[i]->getAge() < 0) {
            std::cout << "Incorrect Weight Found" << std::endl;
            doneFlag = TRUE;
            break;
        } else if (zoo[i]->getWeight() < 0) {
            std::cout << "Incorrect Age Found" << std::endl;
            doneFlag = TRUE;
            break; // We don't want to print out "incorrect <thing> found" every time we find a negative value. So, we break out of the loop the first time."
        }
    }

    if (doneFlag){
        return 1; // Indicates there was some kind of an error.
    }


    
    // Get input loop and execute commands

    while (!doneFlag) {
        input = "";
        std::cin >> input;
        input = strUpper(input);

        if (input == "EXIT") {
            
            std::cout << "THANK YOU COME AGAIN!" << std::endl;
            return 0;

        } else if (input.find("FEED") != std::string::npos) { // If "FEED" is a substring of input
            
            // get the number that comes after "FEED"
            // feedAmnt = strToDub(getAfter(input,spaceDelim));
            std::cin >> feedAmnt; // Boom, we got the amount to feed our dudes by.
            feedAll(zoo, feedAmnt);
            zoo = sortZooWeight(zoo);
            
            if (DEBUG_FLAG) {
                printZoo(zoo);
            }


        } else if ( input == "PET") {
            petAll(zoo);
            zoo = sortZooFriendly(zoo);

            if (DEBUG_FLAG) {
                printZoo(zoo);
            }
        } else if ( input == "SPEAK") {
            // Print out our animals in the order they're represented in the vector.
            // Here we use "std::cout.width" to set the width of each feild.
            for (unsigned int i = 0; i < zoo.size(); ++i) {
                zoo[i]->print();
            }
        }


    }


    return 0;
}

