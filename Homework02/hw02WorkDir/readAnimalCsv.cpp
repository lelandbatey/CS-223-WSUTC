// #include <fstream>
// #include <iostream>
// #include <string>

// Will return a struct of type "animal" with string fields for all it's data.

// Flag used for printing debug messages.
#ifndef DEBUG_FLAG
#define DEBUG_FLAG 1
#endif



typedef struct {
    std::string type, name, age, friendliness, weight, hunger;
} animal_ts;


int actualAnimals(std::vector<animal_ts> animals){
    // Roughly calculates how many VALID animals there actually are in the
    // vector. This is based off of whether they have a name that exists, but
    // this largely just tells us whether there's *something* but not whether
    // all values are actually valid.
    int totalAnimals = 0;
    for (unsigned int i = 0; i < animals.size(); ++i) {
        if (animals[i].name.size()) {
            totalAnimals++;
        }
    }
    return totalAnimals;
}


// Returns a vector of animal_ts structs to be serialized by something else
// later.
std::vector<animal_ts> getAnimals(std::string fileName){
    
    int totalLines = getLines(fileName);
    if (DEBUG_FLAG){
        std::cout << "\tTotal Lines in the file: " << totalLines << std::endl;
    }


    std::ifstream input(fileName.c_str());
    std::string delims = ","; // We're assuming that the CSV will have spaces with it's commas.
    std::string line;

    unsigned int next; // Needs to be unsigned to stop warning when later compared with std::string
    int count, current, i;
    count = current = next = i = 0;


    std::vector<animal_ts> animalArray(totalLines);
    if (DEBUG_FLAG){
        std::cout << "  Size of animalArray: " << sizeof(animalArray) << std::endl;
    }


    // This getline is here just to "eat" the first line of the CSV so that we
    // don't accidentally parse the header
    getline(input, line, '\n');
    
    while (i < totalLines){
        getline(input, line, '\n'); // Get the line (the whole line)
        
        if (DEBUG_FLAG) {
            std::cout << line << std::endl;
        }

        // Gotta zero this out for each re-loop, otherwise it won't read any
        // but the first lines.
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
                animalArray[i].type = strFlog( line.substr(current, next-current) );
                break;
            case 2:
                animalArray[i].name = strFlog(line.substr(current+1, next-current-1));
                break;
            case 3:
                animalArray[i].age = strFlog(line.substr(current+1, next - current-1));
                break;
            case 4:
                animalArray[i].friendliness = strFlog(line.substr(current+1, next - current-1));
                break;
            case 5:
                animalArray[i].weight = strFlog(line.substr(current+1, next - current-1));
                break;
            case 6:
                animalArray[i].hunger = strFlog(line.substr(current+1, next - current-1));
            }

        }
        i++;
    }

    return animalArray;
}

// std::string getField()