/*
 * Leetcode - 557
 * Reverse Words in a String III
 * Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace
 * and initial word order.
 * 
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
  // * testcase 1
  std::string s = "Let's take LeetCode contest";
  // * testcase 2
  // std::string s = "Roronoa Zoro";
  // * testcase 3
  // std::string s = "Mr Ding";

  std::cout << s << std::endl;
  std::string ans = reverseWords(s);
  std::cout << ans << std::endl;
}

// * Run the code
// * g++ --std=c++17 07-reverse-words-i.cpp -o output && ./output