/*
 * Leetcode - 345
 * Reverse Vowels of a String
 * Given a string s, reverse only all the vowels in the string and return it.
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 * Example 1
 * Input  : s = "IceCreAm"
 * Output : "AceCreIm"

 * Example 2
 * Input  : s = "leetcode"
 * Output : "leotcede"

 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
*/

#include <iostream>
#include <unordered_set>

void swap(char &a, char &b) {
  char temp = a;
  a = b;
  b = temp;
}

std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                   'A', 'E', 'I', 'O', 'U'};
bool isVowel(char ch) {
  return (vowels.count(ch) != 0);
}

std::string reverseVowels(std::string s) {
  int n = s.size();
  int i = 0, j = n - 1;

  while (i < j) {
    if (isVowel(s[i]) && isVowel(s[j])) {
      swap(s[i], s[j]);
      i++;
      j--;
    }
    if (!isVowel(s[i]))
      i++;

    if (!isVowel(s[j]))
      j--;
  }

  return s;
}

int main(void) {
  std::string s = "IceCreAm";
  std::cout << "Input String" << std::endl;
  std::cout << s << std::endl;
  
  std::string ans = reverseVowels(s);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ -std=c++17 11-reverse-vowels-of-a-str.cpp -o output && ./output
