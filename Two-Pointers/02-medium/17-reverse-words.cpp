/*
 * Leetcode - 151
 * Reverse Words in a String

 * Example 1
 * Input  : s = "I am zoro"
 * Output : "zoro am I"
 * 
 * Example 2
 * Input  : s = "   Roronoa Zoro   "
 * Output : "Zoro Roronoa" 
 * 
 * Example 3
 * Input  : s = "the sky is blue"
 * Output : "blue is sky the"

 * https://leetcode.com/problems/reverse-words-in-a-string/ 
 * https://www.naukri.com/code360/problems/reverse-words_696444
*/

#include <sstream>
#include <iostream>
#include <algorithm>

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Using stringstream
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
std::string bruteForce(std::string &s) {
  int n = s.size();
  std::stringstream ss(s);
  
  std::string token = "", result = "";
  while(ss >> token) {
    result = token + " " + result;
  }
  return result;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using Two Pointers
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::string reverseWords(std::string &s) {
  int n = s.size();

  // * Reverse complete string
  reverse(s.begin(), s.end());

  int i = 0;
  // * Declare Two pointers
  int l = 0, r = 0;
  while (i < n) {
    // * put the char from 'i' to 'r'
    while (i < n && !isspace(s[i])) {
      s[r] = s[i];
      i++;
      r++;
    }

    // * Reverse l to r
    if (l < r) {
      // std::cout << l << " " << r << std::endl;
      std::reverse(s.begin() + l, s.begin() + r);
      s[r] = ' '; // * Add a space
      r++;        // * Incr the r ptr
      l = r;      // * Bring l to r
    }
    i++;
  }

  return s.substr(0, r - 1);
}

int main() {
  // std::string s = "I am zoro";
  // std::string s = "   Roronoa      Zoro     ";
  // std::string s = "  hello world  ";
  std::string s = "blue is sky the";
  std::cout << s << std::endl;
  
  // std::string ans = bruteForce(s);
  std::string ans = reverseWords(s);
  std::cout << ans << std::endl;
}

// * Run the code
// * g++ --std=c++17 17-reverse-words.cpp -o output && ./output


// * Dry Run

// * put s[r] = s[i]

// * Roro zoro
// *         i 
// * o r o z   o r o R
// * l
// *         r

// * reverse from l to r

// *           i 
// * z o r o   o r o R
// *           l
// *           r

// *                   i 
// * z o r o   o r o R
// *           l
// *                 r

// *                   i 
// * z o r o   R o r o
// *                 l
// *                 r
 
