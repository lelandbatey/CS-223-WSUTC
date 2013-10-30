



// Returns array of std::strings, with each 
std::vector<std::string> getNames(std::string fileName){

    int totalLines = getLines(fileName);


    if (DEBUG) {
        std::cout << "\tTotal lines in the file: " << totalLines << std::endl;
    }

    std::ifstream input(fileName.c_str());
    std::string line;
    std::vector<std::string> strVect(totalLines+10); // Sets up vector of size totalLines + 10
    // strList = new std::string [totalLines+10*sizeof(std::string)]; // BOOM, now we have a properly sized array of std::strings!

    // std::cout << "Size allocated: " << (totalLines+10*sizeof(std::string)) << std::endl;
    // std::cout << "Size of str   : " << sizeof(std::string) << std::endl;

    // std::cout << "Size of strVect: " << sizeof(strVect) << std::endl;
    // std::cout << "Size of strVect: " << strVect.size() << std::endl;

    int x = 0;
    while (x < totalLines) {
        getline(input, line, '\n');
        // std::cout << "does this work?" << std::endl;
        strVect[x] = line;
        // std::cout << strVect[x] << std::endl;
        x++;
    }

    return strVect;


}



