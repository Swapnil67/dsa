/*
 * Leetcode - 395
 * Longest Substring with At Least K Repeating Characters
 * 
 * Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each 
 * character in this substring is greater than or equal to k.
 * 
 * if no such substring exists, return 0.
 * 
 * Input           : s = "aaabb", k = 3
 * Output          : 3
 * Explanation     : The longest substring is "aaa", as 'a' is repeated 3 times.
 * 
 * Input           : s = "ababbc", k = 2
 * Output          : 5
 * Explanation     : The longest substring is "ababb"
 * 
 * Input           : s = "bbaaacbd", k = 3
 * Output          : 3
 * Explanation     : The longest substring is "aaa"
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
*/

#include <iostream>
#include <unordered_map>

int longestSubstring(std::string s, int k) {
  int n = s.length();
  if (n == 0 || n < k) // Edge Cases
    return 0;

  if (k <= 1) // * Since each char has atleast 1 freq
    return n;

  // * Save the freq of each characters
  std::unordered_map<char, int> freq_mp;
  for (char c : s)
    freq_mp[c]++;

  int l = 0;
  while (l < n && freq_mp[s[l]] >= k)
    l++;

  if (l >= n - 1) // * Complete string is valid
    return l;

  // * Count Left Str
  int left_str_len = longestSubstring(s.substr(0, l), k);

  // * Ignore all the char whose freq is less than k
  while (l < n && freq_mp[s[l]] < k)
    l++;

  // * Count Right Str
  int right_str_len = (l < n) ? longestSubstring(s.substr(l), k) : 0;

  return std::max(left_str_len, right_str_len);
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 39-longest-substring-with-at-least-k-repeating-char.cpp -o output && ./output
