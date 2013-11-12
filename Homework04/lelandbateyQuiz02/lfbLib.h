
// lfbLib.h
//
// All the random one-off functions I build for things I do often.
//
// I have a feeling this is going to slowly morph into "all the awesome
// functions python has, now implemented (poorly) in C++!"

// Generally, this stuff is called by things above it, but if not, then uncomment these lines.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

// A non-standard but very well supported way to make sure that something only
// gets included once.
#pragma once

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
    unsigned long long i;

    i = input.find_first_of(delimiter);

    if (i == std::string::npos) {
        return input;
    } else {
        return input.substr(i+1, std::string::npos);
    } 
}

// Returns everything that comes "before" a delimiter. If the delimiter isn't
// present, it returns the input string.
std::string getBefore(std::string input, std::string delimiter) {
    unsigned long long i;
    i = input.find_first_of(delimiter);

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

// Converts std::string to double
int strToInt(std::string str){
    int result;
    std::stringstream convert(str);

    if (!(convert >> result))
        result = 0;

    return result;
}

// Converts double to std::string
std::string dubToStr(double dub) {
    std::ostringstream temp;

    temp << dub;
    
    std::string result(temp.str());
    return result; 
}

bool strToBool(std::string str){
    return str.size() != 0;
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


// Originally taken from here: http://stackoverflow.com/a/217605
// trim from start
static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}


// Two functions for splitting a string. The first uses a pre-constructed
// vector, the second returns a new vector.
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
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


// Convenience function that uppercases strings
std::string strFlog(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), upper); // Make it uppercase
    str = trim(str);
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




