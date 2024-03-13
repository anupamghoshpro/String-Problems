## Description
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

Examples:

    Input: "++*{5} jtggggg"
    Output: true

    Input: "+++++* abcdehhhhhh"
    Output: false

    Input: "$**+*{2} 9mmmrrrkbb"
    Output: true
