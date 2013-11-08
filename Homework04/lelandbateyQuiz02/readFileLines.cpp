#include <vector>


// Returns array of std::strings, with each 
std::vector<std::string> getNames(std::string fileName){

    int totalLines = getLines(fileName);


    if (DEBUG) {
        std::cout << "\tTotal lines in the file: " << totalLines << std::endl;
    }

    std::ifstream input(fileName.c_str());
    std::string line;
    std::vector<std::string> strVect(totalLines+10); // Sets up vector of size totalLines + 10
    
    int x = 0;
    while (x < totalLines) {
        getline(input, line, '\n');
        strVect[x] = line;
        x++;
    }

    return strVect;


}



