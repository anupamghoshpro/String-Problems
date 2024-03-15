/*
Reverse the words of a sentence in place.

e.g.
Input: “the sky is blue”
Output: “blue is sky the”
NOTE: This is NOT the same as reversing the entire string.
*/

#include <iostream>
#include <string>

void ReverseWordsInString(std::string& str)
{
    if(str.empty())
    {
        std::cout << "Empty string!!!" << std::endl;
    }
    
    size_t wordStartIndex = 0;
    size_t wordEndindex = 0;
    
    while((wordStartIndex = str.find_first_not_of(" \t", wordStartIndex)) != std::string::npos)
    {
        if((wordEndindex = str.find_first_of(" \t", wordStartIndex)) == std::string::npos)
        {
            wordEndindex = str.length();
        }
        
        std::reverse(str.begin() + wordStartIndex, str.begin() + wordEndindex);
        wordStartIndex = wordEndindex;
    }
    
    std::reverse(str.begin(), str.end());
}

int main()
{
    std::string str {"    The quick brown  fox      jumps over      the lazy  dog!    "};
    std::string str1 {"The sky is blue!"};
    ReverseWordsInString(str);
    ReverseWordsInString(str1);
    std::cout << str << std::endl;
    std::cout << str1 << std::endl;

    return 0;
}


