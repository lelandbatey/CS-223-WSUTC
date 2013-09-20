#include <iostream>

int charCheck(std::string someText){
    unsigned int i = 0;

    for(i = 0; i < someText.length(); i++)
    {
        if (isdigit(someText[i]) || someText[i] == '-')
        {
            
        } else {
            return 1;
        }
    }
    return 0;
}



