/*
 * Longest Substring with At Most Two Distinct Characters
 * 
 * You are given a string s, return the length of the longest substring that contains at most two distinct characters.
 * 
 * Note: A substring is a contiguous non-empty sequence of characters within a string.
 * 
 * Example 1
 * Input  : s = "eceba"
 * Output : 3
 * Explanation: The substring is "ece" which its length is 3.

 * Example 2
 * Input  : s = "ccaabbb"
 * Output : 5
 * Explanation: The substring is "aabbb" which its length is 5.

 * https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/
 * https://neetcode.io/problems/longest-substring-with-at-most-two-distinct-characters/question?list=neetcode250
 * https://www.naukri.com/code360/problems/longest-substring-with-at-most-two-distinct-characters_3125863
*/

// ! Google, Tiktok, Meta, Oracle, flipkart

#include <vector>
#include <iostream>
#include <unordered_map>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Check all possible substrings
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(256)
int bruteForce(std::string s) {
  int n = s.size();
  int max_len = 0;
  for (int i = 0; i < n; ++i) {
    // * All ASCII characters [0-255]
    std::unordered_map<char, int> freq_mp;
    int j = i;
    for (; j < n; ++j) {
      freq_mp[s[j]]++;
      if (freq_mp.size() > 2) {
        break;
      }
    }
    max_len = std::max(max_len, j - i);
  }
  return max_len;
}

// * ------------------------- APPROACH 2B: Optimal Approach -------------------------`
// * Keep the map of character positions & using sliding window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int lengthOfLongestSubstringTwoDistinct(std::string s) {
  int n = s.size();
  std::unordered_map<char, int> freq_mp;

  int ans = 0;
  int i = 0, j = 0;
  while (j < n) {
    freq_mp[s[j]]++;
    
    // * Shrink the window
    while (i <= j && freq_mp.size() > 2) {
      freq_mp[s[i]]--;
      if (freq_mp[s[i]] == 0) {
        freq_mp.erase(s[i]);
      }
      i++;
    }

    ans = std::max(ans, j - i + 1);
    j++;
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // std::string s = "eceba";

  // * testcase 2
  std::string s = "ccaabbb";

  std::cout << "Input String: " << s << std::endl;

  int ans = bruteForce(s);
  // int ans = lengthOfLongestSubstringTwoDistinct(s);
  std::cout << "Longest Substring with At Most Two Distinct Characters: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 35-longest-substring-with-at-most-two-distinct-characters.cpp -o output && ./output
