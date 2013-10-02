#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include "lfbLib.h"
#include "readAnimalCsv.cpp"
#include "animals_c.h"
#include "tree_t.h"

//     ____  _________    ____  __  _________
//    / __ \/ ____/   |  / __ \/  |/  / ____/
//   / /_/ / __/ / /| | / / / / /|_/ / __/   
//  / _, _/ /___/ ___ |/ /_/ / /  / / /___   
// /_/ |_/_____/_/  |_/_____/_/  /_/_____/   
                                          
// Yeah, I'mma just put this right at the top.

// I've put enough comments in this thing to not *necessarily* need to put a
// ton of words here, so I think I'm good in that respect. However, there's
// basically just ONE THING I want known here from the beginning:

// ### 32-bit vs. 64-bit nearly killed me. ###

// Seriously. I wrote this ENTIRE THING in a 32-bit environment and in a
// 32-bit environment an unsigned int is JUST as big as an unsigned long. The
// very common "std::string::npos" is technically an unsigned long, but all
// the compiler warnings just said to make sure I was comparing "unsigned
// types" so I made all my variables for comparison against std::string::npos
// of the type unsigned int.
//
// Then, when I went to run this thing on elec, suddenly *NOTHING WORKED*
// because the comparisons to see if things were equal to std::string::npos
// (to check if we'd hit the end of the string) didn't work at all and I
// couldn't figure out why. That was honestly the most frightening coding
// experience I've ever had.

// __)   __)
// (0)   (0)
//    ___


// Additionally, there's a bug that happens when an animal with the name
// "someName romanNumeral" is already in the CSV. I assumed that since names
// that are read out of the CSV file should pretty much not be changed aside
// from appending, it can occur where you'll end up with something like a
// "fido II" and a "fido II II". However, this only happens under some very
// particular circumstances, and is done intentionally to preserve the data.
// You can read more about it in the "animals_c.h" file, where I describe the
// bug and the reasons for it existing in greater detail.

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
        std::cout <<"Hunger       : '"<< zoo[i]->getHunger()   << "' : " << typeid( zoo[i]->getHunger()   ).name() << std::endl;
        std::cout <<"Base Name    : '"<< zoo[i]->getBaseName() << "' : " << std::endl;
        std::cout <<"Numeric Name : '"<< zoo[i]->getNumName()  << "' : " << std::endl << std::endl; 
    }
}


int main(int argc, char const *argv[])
{
    if (argc < 2){ // If they didn't pass in a second argument (the file name)
        std::cout << "Yall didn't put in a file name :P" << std::endl;
        // I just want this here for the record: the specification does NOT
        // specify what should be printed in the case of no file name being
        // provided as an argument. So, I'm printing what I want.
        return 0;
    }


    int doneFlag = 0;
    double feedAmnt;


    std::string spaceDelim = " ";
    std::string fileName = std::string(argv[1]);
    std::vector<animal_ts> animals = getAnimals(fileName); // Builds a vector of pointers to animals
    std::string input;
    std::string otherIn;


    // Since we only do this once, we're just gonna hard code it in (instead
    // of breaking it out into it's own fuction like "printZoo").
    if (DEBUG) {
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



    if (DEBUG) {
        printZoo(zoo);
    }



/*  Check the values to make sure they're valid:
        1. Weight cannot be a negative value
        2. Age cannot be a negative value
            NOTE: 0 is not a negative (or positive) value. So weight and age cannot be less than 0.
*/
    for (unsigned int i = 0; i < zoo.size(); ++i) {
        if (zoo[i]->getAge() < 1) {
            std::cout << "Incorrect Weight Found" << std::endl;
            doneFlag = TRUE;
            break;
        } else if (zoo[i]->getWeight() < 1) {
            std::cout << "Incorrect Age Found" << std::endl;
            doneFlag = TRUE;
            break; // We don't want to print out "incorrect <thing> found" 
                   // every time we find a negative value. So, we break out of
                   // the loop the first time."
        }
    }

    if (doneFlag){
        return 1; // Indicates there was some kind of an error.
    }


    // Set's up our binary search tree!
    tree_t<animals_c*> bst; 
    bst.setEqFunc(&fixSameName);
    // Build the BST!
    for (unsigned int i = 0; i < zoo.size(); i++) {
        bst.add(zoo[i]);
    }
    bst.setFindEqFunc(&compareStrToAnimal);


    // Get input loop and execute commands

    while (!doneFlag) {
        input = "";

        // So, you may ask, why is it that we're not just using good ol'
        // "std::cin >> somevar" to get what we need right here?
        //
        // I'll tell you why: because doing it that way for anything but the
        // most trivial of input sucks giant purple donkey dicks. Seriously,
        // though, we get the whole line so we can break it up all nice and
        // neet however we want. In this case, we want everything before the
        // first space on the line of input to be the "command" verb, and
        // everything after that (if anything) to be modifiers to that command
        // verb.
        std::getline(std::cin, input);
        otherIn = getAfter(input," "); // The command verb
        input = getBefore(input," "); // the command modifiers

        input = strUpper(input);
        otherIn = strUpper(otherIn);

        if (DEBUG){
            std::cout << "Input  : '" << input << "'" << std::endl;
            std::cout << "OtherIn: '" << otherIn << "'" << std::endl;
        }

        if (input == "EXIT") {
            
            std::cout << "THANK YOU COME AGAIN!" << std::endl;
            return 0;

        } else if (input.find("FEED") != std::string::npos) { // If "FEED" is a substring of input
            
            feedAmnt = strToDub(otherIn);
            feedAll(zoo, feedAmnt);
            zoo = sortZooWeight(zoo);
            
            if (DEBUG) {
                printZoo(zoo);
            }


        } else if ( input == "PET") {
            petAll(zoo);
            zoo = sortZooFriendly(zoo);

            if (DEBUG) {
                printZoo(zoo);
            }
        } else if ( input == "SPEAK") {
            // Print out our animals in the order they're represented in the vector.
            // Here we use "std::cout.width" to set the width of each feild.
            for (unsigned int i = 0; i < zoo.size(); ++i) {
                zoo[i]->print();
            }
        } else if ( input == "FIND") {

            bst.find(otherIn);

        } else if ( input == "PRINT"){ // HOLY SHARK BAIT BATMAN, EXTRA FEATURES?!?!
            input = strUpper(input);

            
            bst.print();
        }


    }



    return 0;
}

