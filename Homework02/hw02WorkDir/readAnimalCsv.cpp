#include <fstream>
#include <iostream>
#include <string>

// Will return a struct of type "animal" with string fields for all it's data.

// Flag used for printing debug messages.
#ifndef DEBUG_FLAG
#define DEBUG_FLAG 1
#endif

// Used to convert strings to uppercase.
// Snippet taken from here: 
// http://www.dreamincode.net/forums/topic/15095-convert-string-to-uppercase-in-c/
int upper(int c)
{
  return std::toupper((unsigned char)c);
}
// Example of how to use it:
// std::transform(s.begin(), s.end(), s.begin(), upper);

// Strip whitespace
std::string whiteStrip(std::string str) {
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    return str;
}


typedef struct {
    std::string type, name, age, friendliness, weight, hunger;
} animal_ts;

// Convenience function for simple printing of strings (a la Python)
void prnt(const char* c) {
    std::cout << c << std::endl;
}

int getLines(std::string fileName) {
    int totalLines = 0;
    std::string line;
    std::ifstream inFile(fileName.c_str());

    while (std::getline(inFile, line)) {
        totalLines++;
    }
    return totalLines;
}


// Returns a pointer to an array of animal_ts structs. This series of structs is serialized into the correct formats elsewhere.
animal_ts* getAnimals(std::string fileName){
    
    int totalLines = getLines(fileName);
    std::ifstream input(fileName.c_str());
    std::string delims = ","; // We're assuming that the CSV will have spaces with it's commas.
    std::string line;

    unsigned int next; // Needs to be unsigned to stop warning when later compared with std::string::
    int count, current, i;
    count = current = next = i = 0;


    animal_ts* animalArray;
    animalArray = new animal_ts[totalLines];
    // Set aside memory for as many animals as there are lines in the file.
    // Now, the file will have more lines than animals, but it's just a couple
    // bytes extra, so whatever.

    std::cout << sizeof(animalArray) << std::endl;
    getline(input, line, '\n');
    while (i < totalLines){
        getline(input, line, '\n'); // Get the line (the whole line)
        
        if (DEBUG_FLAG) {
            std::cout << line << std::endl;
        }

        // Gotta zero this out for each re-loop, otherwise it won't read any but the first lines.
        count = current = next = 0;

        while(next != std::string::npos){
            
            if (count > 0) {
                current = next+1;
                
            }

            next = line.find_first_of(delims, current);

            if (DEBUG_FLAG) {
                std::cout << "  Count   : '"<<  count  << "'" << std::endl;
                std::cout << "  Current : '"<< current << "'" << std::endl;
                std::cout << "  Next    : '"<<   next  << "'" << std::endl << std::endl;
            }

            count++; // Counts for each separate field, but that's on the same line.


            // Here we actually do all the assigning to the various fields. I
            // realize that I'm flying FLAGRANTLY in the face of the
            // guidelines for "clean, maintainable code". This is kinda dirty,
            // and it's super *not* portable. However, I'm not in any kind of
            // corporate environment, so if I have to deal with this again,
            // it'll be just me, and it'll be this semester. So THERE!

            //    Notes on The "Magic Numbers" below:
            //
            // If you look down, you'll see that each substr operation has
            // some number (either a -1 or a +1) on the end of it. Those exist
            // to trim what we'd otherwise get from the substr. You'll notice
            // that the first one has a it's addition and subtraction
            // switched. That substr gets the first field, which is just after
            // a newline. Because of that, it's got nothing that comes before
            // it. The algorithm would otherwise trim it's first char, but
            // this way that doesn't happen.
            switch (count) {
            case 1:
                animalArray[i].type = line.substr(current, next-current);
                std::transform(animalArray[i].type.begin(), animalArray[i].type.end(), animalArray[i].type.begin(), upper); // Convert to uppercase
                break;
            case 2:
                animalArray[i].name = line.substr(current+1, next-current-1);
                std::transform(animalArray[i].name.begin(), animalArray[i].name.end(), animalArray[i].name.begin(), upper);
                break;
            case 3:
                animalArray[i].age = line.substr(current+1, next - current-1);
                break;
            case 4:
                animalArray[i].friendliness = line.substr(current+1, next - current-1);
                break;
            case 5:
                animalArray[i].weight = line.substr(current+1, next - current-1);
                break;
            case 6:
                animalArray[i].hunger = line.substr(current+1, next - current-1);
            }

        }
        i++;
    }

    return animalArray;
}

// std::string getField()