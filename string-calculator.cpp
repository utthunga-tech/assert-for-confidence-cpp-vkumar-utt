#include "string-calculator.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

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
        //cout <<strnum  <<"\n";

        strNums.push_back(strnum);
    }

    return strNums;
}

void showException(int num)
{
    cout<<"negatives not allowed : "<<num<<"\n";
}

bool isValid(int num)
{
    if(num>=0)
        return true;

    showException(num);
    return false;
}

int Add(string numbers){

    int result =0;

    vector<string> strnumbers = splitStringMultiDelimit(numbers);
    vector<string>::iterator ptr;

    for (ptr = strnumbers.begin(); ptr < strnumbers.end(); ptr++)
    {
        string strnum = *ptr;
        int i = atoi(strnum.c_str());
        bool valid = isValid(i);

        if(valid)
            result = result + i;
        //result = result + i;
    }

    return result;
}
