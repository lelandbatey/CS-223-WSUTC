#include <vector>
#include "lfbLib.h"
#include "kd_point.h"


// Returns a list of pointers.
// Is used only for getting points from the peptide-database
kd_point** getPointList(std::string fileName, int* plSize){
    int totalLines = getLines(fileName);
    
    if (DEBUG) {
        std::cout << "\tTotal lines in the file: " << totalLines << std::endl;
    }
    
    kd_point** pntList = new kd_point*[totalLines];

    std::ifstream input(fileName.c_str());
    std::string line;
    std::vector<std::string> strVect(totalLines+10); // Sets up vector of size totalLines + 10
    std::vector<std::string> brokeLine;// Will hold the two elemenst from our split string.
    std::string delims = ",";
    
    // Gets each line of the file
    
    getline(input, line, '\n'); // "Eats" the first line, which is just a csv header

    int x = 0;
    while (x < totalLines) {
        getline(input, line, '\n'); 
        strVect[x] = line;
        x++;
    }

    for (unsigned int i = 0; i < strVect.size(); ++i){
        brokeLine = split(strVect[i],',');
        if (brokeLine.size() > 1) {
            pntList[i] = new kd_point( brokeLine[0], strToDub(brokeLine[1]));
            (*plSize)++;
        } else {
        }
    }

    return pntList;
}

kd_point** getObservedList(std::string fileName, int* olSize){
    // This is intended to read the observed list and translate it into a list
    // of points. Because the observed list has a different format than the
    // peptide database file, we have to manipulate the data a little bit
    // differently.

    int totalLines = getLines(fileName);
    if (DEBUG) {
        std::cout << "\tTotal lines in the file: " << totalLines << std::endl;
    }
    
    kd_point** pntList = new kd_point*[totalLines];
    std::ifstream input(fileName.c_str());
    std::string line;
    std::vector<std::string> brokeLine;// Will hold the two elemenst from our split string.

    getline(input, line, '\n'); // "Eats" the first line, which is just a csv header

    int x = 0;
    while (x < totalLines){
        getline(input, line, '\n');
        brokeLine = split(line,',');
        if (brokeLine.size() >2){
            pntList[x] = new kd_point();
            (*pntList[x]).setObservedMass(strToDub(brokeLine[2]));
            (*pntList[x]).setObservedNET(strToDub(brokeLine[1]));
            (*pntList[x]).setID(strToInt(brokeLine[0]));
            (*olSize)++;
        }
        x++;
    }

    return pntList;


}

