
// lfbLib.h
//
// All the random one-off functions I build for things I do often.
//
// I have a feeling this is going to slowly morph into "all the awesome
// functions python has, now implemented (poorly) in C++!"

// Generally, this stuff is called by things above it, but if not, then uncomment these lines.
// #include <algorithm>
// #include <iostream>
// #include <sstream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <math.h>

// Debug. Very important, since tons of stuff is set to print if this is set
// to "1". Don't touch unless you want to get TMI'd by this thing.
#ifndef DEBUG
#define DEBUG 0
#endif


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

// Returns everything in a string that comes after a delimiter. If the
// delimiter isn't present, it just returns the input string.
std::string getAfter(std::string input, std::string delimiter) {
    unsigned int i;

    i = input.find_first_of(delimiter);

    // if (DEBUG){
    //     std::cout << " i is        : " << i << std::endl;
    //     std::cout << " delimiter is: '" << delimiter << "'" << std::endl;
    //     std::cout << " input is    : '" << input << "'" << std::endl;
    // }

    if (i == std::string::npos) {
        return input;
    } else {
        return input.substr(i+1, std::string::npos);
    } 
}

// Returns everything that comes "before" a delimiter. If the delimiter isn't
// present, it returns the input string.
std::string getBefore(std::string input, std::string delimiter) {
    unsigned int i;
    i = input.find_first_of(delimiter);

    // if (DEBUG){
    //     std::cout << " i is        : " << i << std::endl;
    //     std::cout << " delimiter is: '" << delimiter << "'" << std::endl;
    //     std::cout << " input is    : '" << input << "'" << std::endl;
    // }

    if (i == std::string::npos) {
        return input;
    } else {
        return input.substr(0,i);
    }

}

// Used to check if a string represents a number or whether it represents a digit.
int charCheck(std::string someText){
    unsigned int i = 0;

    for(i = 0; i < someText.length(); i++) {
        if (isdigit(someText[i]) || someText[i] == '-')
        {
            
        } else {
            return 1;
        }
    }
    return 0;

}

// Converts std::string to double
double strToDub(std::string str){
    double result;
    std::stringstream convert(str);

    if (!(convert >> result))
        result = 0;

    return result;
}


// Returns number of lines in a file.
int getLines(std::string fileName) {
    int totalLines = 0;
    std::string line;
    std::ifstream inFile(fileName.c_str());

    while (std::getline(inFile, line)) {
        totalLines++;
    }
    return totalLines;
}

// Convenience function for simple printing of strings (a la Python)
void prnt(const char* c) {
    std::cout << c << std::endl;
}

// Strip whitespace
// From here: http://stackoverflow.com/a/83481
std::string whiteStrip(std::string str) {
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    return str;
}

// Used to convert strings to uppercase.
// Snippet taken from here: 
// http://www.dreamincode.net/forums/topic/15095-convert-string-to-uppercase-in-c/
int upper(int c)
{
  return std::toupper((unsigned char)c);
}
// Example of how to use it:
// std::transform(s.begin(), s.end(), s.begin(), upper);


// Convenience function that uppercases strings and removes whitespace (spaces)
std::string strFlog(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), upper); // Make it uppercase
    str = whiteStrip(str);

    return str;
}

// EXCLUSIVELY upercases a std::string
std::string strUpper(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), upper); // Make it uppercase

    return str;
}

std::string iToRoman(int i) {
    // Given a number, returns a the roman numeral representation of that 
    // string as an integer.
    //
    // Only works from 1 to 10

    switch (i) {
    case 1:
        return std::string(" I");
    case 2:
        return std::string(" II");
    case 3:
        return std::string(" III");
    case 4:
        return std::string(" IV");
    case 5:
        return std::string(" V");
    case 6:
        return std::string(" VI");
    case 7:
        return std::string(" VII");
    case 8:
        return std::string(" VIII");
    case 9:
        return std::string(" IX");
    case 10:
        return std::string(" X");
    }

    return std::string("");


}


// Returns a *relatively* unique representation of a given string
//
// Basically, for each character in a std::string, it takes the ascii number
// for that char, subtracts 31 from it to make it a little smaller, then
// squares that number. This large value is then added to all the sum of all
// the previous process for each char. Once all that's been done, it
// multiplies the total by the length of the string.
//
// It won't make numbers to large to fit in an int (at least for relatively
// small strings), but they'll be at least *close* to unique.
int deriveNumericName(std::string name) {
    int numericName = 0;
    int temp = 0;

    for (unsigned int i = 0; i < name.length(); ++i) {
        
        temp = int(name.c_str()[i]) - 31;

        temp = pow(temp,2); // Square temp

        numericName = numericName + temp;
    }

    numericName = numericName * name.length();

    return numericName;

}



