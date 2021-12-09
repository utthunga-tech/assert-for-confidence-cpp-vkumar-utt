#include "string-calculator.h"
#include <stdio.h>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;

vector<string> splitStringMultiDelimit(string inputString)
{
    string delimiters("\n,");
    vector<string> strNums;
    boost::split(strNums, inputString, boost::is_any_of(delimiters));

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
