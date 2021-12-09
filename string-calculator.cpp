#include "string-calculator.h"
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<string> splitStringMultiDelimit(string inputString)
{
    std::string const delims{ "\n," };

    vector<string> strNums;

    size_t beg, pos = 0;
    while ((beg = inputString.find_first_not_of(delims, pos)) != std::string::npos)
    {
        pos = inputString.find_first_of(delims, beg + 1);
        string strnum = inputString.substr(beg, pos - beg);
        std::cout <<strnum  << std::endl;

        strNums.push_back(strnum);
    }

    return strNums;
}


int Add(string numbers){

    int result =0;

    vector<string> strnumbers = splitStringMultiDelimit(numbers);
    vector<string>::iterator ptr;

    for (ptr = strnumbers.begin(); ptr < strnumbers.end(); ptr++)
    {
        string strnum = *ptr;
        int i = atoi(strnum.c_str());
        result = result + i;
    }

    return result;
}
