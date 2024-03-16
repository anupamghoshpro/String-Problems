/*
Reverse the words of a sentence in place.

e.g.
Input: "    The quick brown  fox      jumps over      the lazy  dog!       "
Output: "       !dog  lazy the      over jumps      fox  brown quick The    "

Input: “The sky is blue.”
Output: “.blue is sky The”

Input: "     Does this     program work?  "
Output: "  ?work program     this Does     "

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
    std::string punctuations = " \t,;.!?";
    
    while((wordStartIndex = str.find_first_not_of(punctuations, wordStartIndex)) != std::string::npos)
    {
        if((wordEndindex = str.find_first_of(punctuations, wordStartIndex)) == std::string::npos)
        {
            wordEndindex = str.length() - 1;
        }
        
        std::reverse(str.begin() + wordStartIndex, str.begin() + wordEndindex);
        wordStartIndex = wordEndindex;
    }
    
    std::reverse(str.begin(), str.end());
}

int main()
{
    std::string str {"    The quick brown  fox      jumps over      the lazy  dog!       "};
    std::string str1 {"The sky is blue."};
    std::string str2 {"Does this     program work?  "};
    ReverseWordsInString(str);
    //ReverseWordsInString(str1);
    //ReverseWordsInString(str2);
    std::cout << str << std::endl;
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;

    return 0;
}
