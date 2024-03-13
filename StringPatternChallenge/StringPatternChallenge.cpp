/*
Have the function StringChallenge(str) read str which will contain two strings separated by a space . 
The first string will consist of the following sets of characters: +, *, $ and {N} which is optional. 
- The plus (+) character represents a single alphabetic character
- the $ character represents a number between 1-9 
- the asterisk * character represents sequence of the same character of length 3 unless 
  it is followed by {N} which represents how many characters should appear in the sequence
  where N will be at least 1. You goal is to determine if the second string exactly matches 
  the pattern of the first string in the input.

For example ifstr is "++*{5} jtggggg" then the second string does match the first one, so the function should return the string true. If the second string doesn't match the pattern the program should return the string false.

Write the code in python. Please write an efficient code in terms of time complexity and that works. Please.

Us the following starting code and don't change the function signature:

bool StringChallenge(strParam)
{
	// your code goes here
	
	return false;
}

Please use the latest version of C++ to solve this problem.

Please use the most optimal time & space complexity.

time complexity: The time complexity of the provided code is O(n+m), where n is the length of the pattern string and 
m is the length of the input string. This is because the code iterates through both strings once, comparing characters 
and performing checks along the way.

*/

#include <iostream>
#include <string>

using namespace std;

bool matchSequence(const string& str, size_t& pos, char c, int repeat) 
{
    while (repeat--) 
    {
        if (str[pos++] != c)
            return false;
    }
    return true;
}

bool matchPattern(const string& pattern, const string& str) 
{
    size_t i = 0, j = 0;
    while (i < pattern.length() && j < str.length()) 
    {
        switch (pattern[i]) 
        {
            case '+':
                if (!isalpha(str[j]))
                    return false;
                ++i;
                ++j;
                break;
                
            case '$':
                if (!isdigit(str[j]) || str[j] == '0')
                    return false;
                ++i;
                ++j;
                break;
                
            case '*':
                if (i + 1 < pattern.length() && pattern[i + 1] == '{') 
                {
                    size_t end_index = pattern.find('}', i);
                    if (end_index == string::npos)
                    {
                        return false;
                    }
                    
                    int repeat_count = stoi(pattern.substr(i + 2, end_index - i - 2));
                    //cout << "i + 2: " << i + 2 << endl;
                    //cout << "end_index - i - 2: " << end_index - i - 2 << endl;
                    //cout << "repeat_count: " << repeat_count << endl;
                    if (j + repeat_count > str.length())
                    {
                        return false;
                    }
                        
                    if (!matchSequence(str, j, str[j], repeat_count))
                    {
                        return false;
                    }
                        
                    i = end_index + 1;
                } 
                else 
                {
                    if (((j + 2) >= str.length()) || (str[j] != str[j + 1]) || (str[j] != str[j + 2]))
                        return false;
                    j += 3;
                    ++i;
                }
                break;
                
            default:
                break;
        }
    }
    
    return i == pattern.length() && j == str.length();
}

bool StringChallenge(string strParam) 
{
    string pattern, str;
    size_t space_pos = strParam.find(' ');
    //cout << "space_pos: " << space_pos << endl;
    
    if (space_pos != string::npos) 
    {
        pattern = strParam.substr(0, space_pos);
        str = strParam.substr(space_pos + 1);
        
        //cout << "pattern: " << pattern << endl;
        //cout << "str: " << str << endl;
    }
    return matchPattern(pattern, str);
}

int main() 
{
    cout << boolalpha;
    cout << StringChallenge("++*{5} jtggggg") << endl;  /* Output: true */
    cout << StringChallenge("+++++* abcdehhhhhh") << endl;  /* Output: false */
    cout << StringChallenge("$**+*{2} 9mmmrrrkbb") << endl; /* Output: true */
    return 0;
}
