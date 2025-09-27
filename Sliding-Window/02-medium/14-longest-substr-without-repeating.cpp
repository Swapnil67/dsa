/**
 * * Leetcode 3
 * * Longest Substring Without Repeating Characters
 * * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * * Example 1
 * * Input  : s = "abcabcbb"
 * * Output : 3
 * * Explanation: The answer is "abc", with the length of 3

 * * Example 2
 * * Input  : s = "bbbbb"
 * * Output : 1
 * * Explanation: The answer is "b", with the length of 1.

 * * Example 3
 * * Input  : s = "tmmzuxt"
 * * Output : 5
 * * Explanation: The answer is "mzuxt", with the length of 5.

 * * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * * https://www.naukri.com/code360/problems/longest-substring-without-repeating-characters_758894
*/

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
    std::vector<int> frequency(256);
    int j = i;
    for (; j < n; ++j) {
      if (frequency[s[j]] == 1) {
        break;
      }
      frequency[s[j]] = 1;
    }
    max_len = std::max(max_len, j - i);
  }
  return max_len;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Keep the map of character positions & using sliding window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(256)
int lengthOfLongestSubstring(std::string s) {
  int n = s.size();
  std::unordered_map<char, int> hash;
  int i = 0, j = 0, max_len = 0;
  while (j < n) {
    // * check if cur char is already seen
    if (hash.count(s[j])) {
      // * This is becoz to prevent 'i' assigning a previous index than current 'i'
      if (hash[s[j]] >= i) {
        i = hash[s[j]] + 1;
      }
    }

    // * update the length of substring
    max_len = std::max(max_len, (j - i + 1));

    // * update the index of char in map
    hash[s[j]] = j;

    j++;
  }

  return max_len;
}

// * ------------------------- APPROACH 2B: Optimal Approach -------------------------`
// * Keep the map of character positions & using sliding window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(256)
int lengthOfLongestSubstring2(std::string s) {
  int n = s.size();
  std::unordered_map<char, int> charFreq;

  int ans = 0;
  int i = 0, j = 0;
  while (j < n) {
    charFreq[s[j]]++;

    // * Shrink the window
    while (charFreq[s[j]] > 1) {
      charFreq[s[i]]--;
      if (charFreq[s[i]] == 0) {
        charFreq.erase(s[i]);
      }
      i++;
    }

    ans = std::max(ans, j - i + 1);
    j++;
  }

  return ans;
}

int main(void) {
  // std::string s = "abcabcbb";
  // std::string s = "abba";
  std::string s = "tmmzuxt";

  std::cout << "Input String: " << s << std::endl;

  int ans = bruteForce(s);
  // int ans = lengthOfLongestSubstring(s);
  std::cout << "Longest Substring Without Repeating Characters: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 14-longest-substr-without-repeating.cpp -o output && ./output
