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

#include <iostream>
#include <algorithm>

using namespace std;

// * Inplace Reverse
string reverseWords(string s) {
  int n = s.size();
  int i = 0, j = 0;
  while (j < n) {
    while (j < n && !isspace(s[j])) {
      j++;
    }
    reverse(s.begin() + i, s.begin() + j);
    j += 1;
    i = j;
  }
  return s;
}

int main(void) {
  // * testcase 1
  // string s = "Let's take LeetCode contest";

  // * testcase 2
  // string s = "Roronoa Zoro";

  // * testcase 3
  string s = "Mr Ding";

  cout << s << endl;
  string ans = reverseWords(s);
  cout << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 07-reverse-words-i.cpp -o output && ./output