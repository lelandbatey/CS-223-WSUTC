// #include <fstream>
// #include <iostream>
// #include <string>

// Will return a struct of type "animal" with string fields for all it's data.



typedef struct {
    std::string type, name, age, friendliness, weight, hunger;
} animal_ts;

// This struct is just a convenient storage place to stick the things we read
// out of the csv file. Later, we do actually convert all the data to the
// proper type and what-not. But for now, we just stick it in a struct :/



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
    if (DEBUG){
        std::cout << "\tTotal Lines in the file: " << totalLines << std::endl;
    }


    std::ifstream input(fileName.c_str());
    std::string delims = ",";
    std::string line;

    unsigned int next; // Needs to be unsigned to stop warning when later compared with std::string
    int count, current, i;
    count = current = next = i = 0;


    std::vector<animal_ts> animalArray(totalLines);
    if (DEBUG){
        std::cout << "  Size of animalArray: " << sizeof(animalArray) << std::endl;
    }


    // This getline is here just to "eat" the first line of the CSV so that we
    // don't accidentally parse the header
    getline(input, line, '\n');
    
    while (i < totalLines){
        getline(input, line, '\n'); // Get the line (the whole line)
        
        if (DEBUG) {
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

            if (DEBUG) {
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
            switch (count) {
            case 1:
                animalArray[i].type      =    strFlog( line.substr(current, next-current) );
                break;
            case 2:
                animalArray[i].name      =    strFlog(line.substr(current, next-current));
                break;
            case 3:
                animalArray[i].age       =    strFlog(line.substr(current, next - current));
                break;
            case 4:
                animalArray[i].friendliness = strFlog(line.substr(current, next - current));
                break;
            case 5:
                animalArray[i].weight    =    strFlog(line.substr(current, next - current));
                break;
            case 6:
                animalArray[i].hunger    =    strFlog(line.substr(current, next - current));
            }

        }
        i++;
    }

    return animalArray;
}

