/*
 * 
 * Find First Palindromic String in the Array
 * Given an array of strings words, return the first palindromic string in the array. 
 * If there is no such string, return an empty string "".

 * Example 1
 * Input  : words = ["abc","car","ada","racecar","cool"]
 * Output : "ada"
 * 
 * Example 2
 * Input  : words = ["notapalindrome","racecar"]
 * Output : "racecar"

 * * https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
*/

#include<iostream>

void printVectorString(std::vector<std::string> strs) {
  int n = strs.size();
  std::cout << "[ "; 
  for (std::string s : strs) {
    std::cout << s << ", ";
  }
  std::cout << "]" << std::endl;
}

bool checkPalindrome(std::string str) {
  int n = str.size();
  int l = 0, r = n - 1;
  while (l < r) {
    if (str[l++] != str[r--])
      return false;
    
  }
  return true;
}

// * TIME COMPLEXITY O(n * m)
// * m -> size of the largest string
// * SPACE COMPLEXITY O(1)
std::string firstPalindrome(std::vector<std::string> &words) {
  int n = words.size();
  for (std::string str : words) {
    bool is_palindrome = checkPalindrome(str);
    if (is_palindrome)
      return str;
  }
  return "";
}

int main() {
  std::vector<std::string> words = {"notapalindrome", "racecar"};
  printVectorString(words);
  std::string ans = firstPalindrome(words);
  std::cout << ans << std::endl;
}

// * Run the code
// * g++ --std=c++17 05-first-palindromic-str.cpp -o output && ./output