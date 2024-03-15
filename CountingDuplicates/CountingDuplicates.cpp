/*
Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.

Example
"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

#include <cctype>

std::size_t duplicateCount(const std::string& in) 
{
  std::unordered_map<char, unsigned> occuranceCount;
  
  for (char c : in) 
  {
    occuranceCount[tolower(c)]++;
  }

  /* 
  If there is no duplicate the string length 
  and the map size will be same.
  */
  if(in.length() == occuranceCount.size())
  {
      return 0;
  }
  
  return std::count_if(occuranceCount.begin(), occuranceCount.end(), [](const auto &occuranceCount){return occuranceCount.second > 1;});
}


int main()
{
    std::cout << duplicateCount("asdfghjkl54") << std::endl;
    std::cout << duplicateCount("abcdeaa") << std::endl;
    std::cout << duplicateCount("93917949902") << std::endl;
    std::cout << duplicateCount("Indivisibility") << std::endl;
    std::cout << duplicateCount("ABCDEFGHIJKLMNOPQRSTUVWXYZ") << std::endl;
    std::cout << duplicateCount("asdfghjkl55") << std::endl;
    std::cout << duplicateCount("aabBcde") << std::endl;
    std::cout << duplicateCount("aaaA11bbcde") << std::endl;
    
    return 0;
}
