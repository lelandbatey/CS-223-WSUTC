#include <vector>
#include "lfblib.h"
#include "kd_point.h"


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

kd_point** getPointList(std::string fileName){
    int totalLines = getLines(fileName);
    std::cout << "Filename: " << fileName << std::endl;
    std::cout << "gets past getLines" << std::endl;

    if (DEBUG) {
        std::cout << "\tTotal lines in the file: " << totalLines << std::endl;
    }

    std::cout << "totalLines: " << totalLines << std::endl;

    // std::vector<kd_point*> pntList;
    kd_point** pntList = new kd_point*[totalLines];


    // Gets each line of the file

    std::ifstream input(fileName.c_str());
    std::string line;
    std::vector<std::string> strVect(totalLines+10); // Sets up vector of size totalLines + 10
    
    getline(input, line, '\n'); // "Eats" the first line, which is just a csv header

    int x = 0;
    while (x < totalLines) {
        getline(input, line, '\n');
        // std::cout << line << std::endl; 
        strVect[x] = line;
        x++;
    }

    std::vector<std::string> brokeLine;// Will hold the two elemenst from our split string.

    std::string delims = ",";    

    for (unsigned int i = 0; i < strVect.size(); ++i){
        brokeLine = split(strVect[i],',');
        if (brokeLine.size() > 1) {
            std::cout << brokeLine[0] << " " << brokeLine[1] << std::endl;
            pntList[i] = new kd_point( brokeLine[0], strToDub(brokeLine[1]));
        } else {
            std::cout << "found odd line: " << strVect[i] << std::endl;
            std::cout << "  Line #: " << i << std::endl;
        }
    }

    std::cout << "Done messing with list" << std::endl;

    return pntList;

}


