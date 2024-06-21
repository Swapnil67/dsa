/**
 * * Length of Last Word
 * * Given a string s consisting of words and spaces, return the length of the last word in the string.

 * * Example 1
 * * Input : str = "Hello World"
 * * Output : 5
 * * Explanation: The last word is "World" with length 5.

 * * Example 2
 * * Input : str = "   fly me   to   the moon  "
 * * Output : 4
 * * Explanation: The last word is "moon" with length 4.

 * * https://leetcode.com/problems/length-of-last-word/description/
*/

#include<string>
#include<iostream>

int main() {
  std::string str = "luffy is still joyboy";
  std::cout << str << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 02-length-of-last-word.cpp -o 02-length-of-last-word && ./02-length-of-last-word