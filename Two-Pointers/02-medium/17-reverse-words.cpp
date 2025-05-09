/*
 TODO

 * Example 1
 * Input  : s = "I am zoro"
 * Output : "zoro am I"
 * 
 * Example 2
 * Input  : s = "Roronoa Zoro"
 * Output : "Zoro Roronoa" 

 * https://www.naukri.com/code360/problems/reverse-words_696444
 * https://leetcode.com/problems/reverse-words-in-a-string/ 
*/

#include <iostream>
#include <algorithm>

std::string reverseWords(std::string &s) {
  int n = s.size();

  // * Reverse complete string
  reverse(s.begin(), s.end());

  int i = 0;
  // * Declare Two pointers
  int l = 0, r = 0;
  while(i < n) {
    while(i < n && s[i] != ' ') {
      s[r++] = s[i++];
    }

    // * Reverse l to r
    if(l < r) {
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

// * My Implementation (little easy to grasp)

void reverseString(std::string &s, int l, int r) {
  while (isspace(s[r]))
    r -= 1;
  while(l < r) {
    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
    l += 1;
    r -= 1;
  }
}

std::string reverseWords2(std::string s) {
  int n = s.size();
  
  // * Reverse complete string
  int l = 0, r = n - 1;
  reverseString(s, l, r);
  std::cout << "Full Reverse: " << s << std::endl;

  int i = 0;
  l = 0, r = 0;

  while (i < n) {
    // * move i till you hit space character
    if (!isspace(s[i])) {
      i += 1;
    } else {
      // printf("%d %d %d\n", i, l, r);
      r = i;
      reverseString(s, l, r);
      r += 1;
      l = r;
      // * move i to first character of next word
      while (isspace(s[i]))
        i += 1;
    }
  }
  return s;
}

int main() {
  // std::string s = "I am zoro";
  std::string s = "   Roronoa      Zoro     ";
  std::cout << s << std::endl;
  // std::string ans = reverseWords(s);
  std::string ans = reverseWords2(s);
  std::cout << ans << std::endl;
}

// * Run the code
// * g++ --std=c++17 17-reverse-words.cpp -o output && ./output


// * Dry Run


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
 
