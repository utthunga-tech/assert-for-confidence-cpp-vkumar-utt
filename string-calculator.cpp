#include <iostream>
#include <vector>
#include <sstream>
#include <assert.h>
#include <cstring>

using namespace std;

static vector<string> delimiter = {"\n",","};
static bool emptyDelim = false;

void printExpMessage(string message, int num)
{
    cout<<message<<":"<<num<<"\n";
}

bool isNumberAboveThousand(int num)
{
    if(num>1000)
        return true;

    return false;
}

bool isNumberPositive(int num)
{
    if(num>=0)
       return true;

    throw invalid_argument("negatives not allowed");
}

bool isNumberValid(int num, void (*fp)(string s, int n))
{
    bool isThousand = isNumberAboveThousand(num);

    bool isPositive=false;
    try {
        isPositive = isNumberPositive(num);
    } catch (invalid_argument& invalid) {
        fp(invalid.what(), num);
    }

    if((!isThousand)&&(isPositive))
        return true;

    return false;
}

int convertStringtoNumber(string strnum)
{
    return atoi(strnum.c_str());;
}

vector<string> splitStringMultiDelimit(string inputString)
{
    string const delims{ "\n," };

    vector<string> strNums;

    size_t beg, pos = 0;
    while ((beg = inputString.find_first_not_of(delims, pos)) != std::string::npos)
    {
        pos = inputString.find_first_of(delims, beg + 1);
        string strnum = inputString.substr(beg, pos - beg);

        strNums.push_back(strnum);
    }

    return strNums;
}

size_t findDelimiterPos(string s, size_t& len)
{
    size_t pos = 0;

    size_t prevpos = s.find(delimiter[0]);
    len = delimiter[0].length();

    for(size_t i=0; i<delimiter.size(); i++)
    {
        pos = s.find(delimiter[i]);
        if(pos<prevpos)
        {
            prevpos = pos;
            len = delimiter[i].length();
        }
    }

    return prevpos;
}

void getMultiDelimiter(string inputString)
{
    size_t pos = 0;

    size_t beg= 0;
    while ((beg = inputString.find_first_not_of(']', pos)) != std::string::npos)
    {
        pos = inputString.find_first_of(']', beg + 1);
        string strdelim = inputString.substr(beg+1, pos - beg-1);

        if(strdelim.length()>0)
        {
            delimiter.push_back(strdelim);
        }
        else {
            emptyDelim = true;
        }
    }
}

void getDelimiterFromInputStr(string& inputstr)
{
    string substr = inputstr.substr(0,2);

    size_t pos = 0;

    if(substr.compare("//") == 0)
    {
        inputstr.erase(0, 2);
        pos = inputstr.find('\n', 0);
        string delim = inputstr.substr(0, pos);
        inputstr.erase(0, pos+1);
        pos = delim.find("]");

        if(pos != std::string::npos)
            getMultiDelimiter(delim);
        else
            delimiter.push_back(delim);
    }
}


void splitMultidigitStr(string numbers, vector<string>& nums)
{

    if(numbers.length()>1)
    {
        for (size_t i=0;i<numbers.length();i++) {
            nums.push_back(string(1, numbers[i]));
        }
    }
    else {
        nums.push_back(numbers);
    }
}

void splitWithEmptyDelim(string numbers, vector<string>& nums)
{
    if(emptyDelim)
    {
        splitMultidigitStr(numbers, nums);
    }
    else {
        nums.push_back(numbers);
    }
}

vector<string> splitInputStr(string numbers)
{
    vector<string> nums;
    getDelimiterFromInputStr(numbers); //remove delimiters from numbers

    size_t len;
    size_t pos = 0;
    string token;
    while ( (pos=findDelimiterPos(numbers, len))!= std::string::npos) {
        token = numbers.substr(0, pos);
        numbers.erase(0, pos + len);       

        splitWithEmptyDelim(token, nums);

    }

    splitWithEmptyDelim(numbers, nums);

    return nums;
}


int Add(string numbers)
{
    emptyDelim = false;

    int result =0;
    vector<string> strnumbers = splitInputStr(numbers);
    vector<string>::iterator ptr;

    for (ptr = strnumbers.begin(); ptr < strnumbers.end(); ptr++)
    {
        string strnum = *ptr;
        int i = convertStringtoNumber(strnum.c_str());

        void (*fp)(string s, int n);
        fp = printExpMessage;

        bool valid = isNumberValid(i,fp);

        if(valid)
            result = result + i;
    }

    return result;
}
