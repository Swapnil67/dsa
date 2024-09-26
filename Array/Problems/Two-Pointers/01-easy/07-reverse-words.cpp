/*
 * Sort Array By Parity 
 * Given an integer array nums, move all the even integers at the beginning of the array followed 
 * by all the odd integers.
 * Return any array that satisfies this condition.

 * Example 1
 * Input  : s = "Let's take LeetCode contest"
 * Output : "s'teL ekat edoCteeL tsetnoc"
 * 
 * Example 2
 * Input  : s = "Mr Ding"
 * Output : "rM gniD" 

 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
*/

#include<iostream>

void swap(char& a, char& b) {
  char temp = a;
  a = b;
  b = temp;
}

std::string reverseString(std::string s) {
  int n = s.size();
  int l = 0, r = n - 1;
  while (l < r) {
      swap(s[l++], s[r--]);
  }
  return s;
}

// * TIME COMPLEXITY (N)
// * SPACE COMPLEXITY O(1)
std::string reverseWords(std::string s) {
  int n = s.size();
  int c = 0;
  std::string ans = "";
  for (int i = 0; i < n; ++i) {
    if(isspace(s[i])) {
      std::string t = reverseString(s.substr(c, i - c));
      // std::cout << c << " to " << i - 1 << " => " << ans << std::endl;
      c = i + 1;
      ans += t;
      ans += " ";
    }
  }

  std::string t = reverseString(s.substr(c, n - c));
  ans += t;
  return ans;
}

int main() {
  std::string s = "Let's take LeetCode contest";
  std::cout << s << std::endl;
  std::string ans = reverseWords(s);
  std::cout << ans << std::endl;
}

// * Run the code
// * g++ --std=c++17 07-reverse-words.cpp -o output && ./output