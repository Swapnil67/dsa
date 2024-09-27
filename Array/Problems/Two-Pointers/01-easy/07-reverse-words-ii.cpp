/*
 * Sort Array By Parity 
 * Given an integer array nums, move all the even integers at the beginning of the array followed 
 * by all the odd integers.
 * Return any array that satisfies this condition.

 * Example 1
 * Input  : s = "I am zoro"
 * Output : "zoro am I"
 * 
 * Example 2
 * Input  : s = "Roronoa Zoro"
 * Output : "Zoro Roronoa" 

 * https://www.naukri.com/code360/problems/reverse-words_696444
*/

#include<iostream>

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::string reverseWords(std::string s) {
  int n = s.size();
  int c = n - 1;
  std::string ans = "";
  for (int i = n - 1; i >= 0; --i) {
    if(isspace(s[i])) {
      std::string t = s.substr(i + 1, c - i);
      // std::cout << i + 1 << " to " << c << " => " << s.substr(i + 1, c - i) << std::endl;
      c = i - 1;
      ans += t;
      ans += " ";
      while(isspace(s[i--])) {
        i -= 1;
      }
    }

  }

  int i = 0;
  std::string t = "";
  while(i <= c) {
    t += s[i];
    i++;
  }
  ans += t;
  return ans;
}

int main() {
  // std::string s = "I am zoro";
  std::string s = "Roronoa      Zoro     ";
  std::cout << s << std::endl;
  std::string ans = reverseWords(s);
  std::cout << ans << std::endl;
}

// * Run the code
// * g++ --std=c++17 07-reverse-words-ii.cpp -o output && ./output