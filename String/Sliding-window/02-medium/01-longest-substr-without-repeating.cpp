/**
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

 * * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * * https://www.naukri.com/code360/problems/longest-substring-without-repeating-characters_758894
*/

#include<map>
#include<iostream>

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
    // std::cout << max_len << " ";
    std::vector<int> frequency(256);
    for (int j = i; j < n; ++j) {
      if(frequency[s[j]] == 1) {
        break;
      }
      max_len = std::max(max_len, j - i + 1);
      frequency[s[j]] = 1;
    }
  }
  return max_len;
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Keep the map of character positions & using sliding window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(256)
int lengthOfLongestSubstring(std::string s) {
  int n = s.size();
  std::map<char, int> char_index_map;
  int i = 0, j = 0, max_len = 0;
  while(j < n) {
    // * check if cur char is already seen
    if(char_index_map.count(s[j])) {
      // * checks if the char is found b/w i & j
      if (char_index_map[s[j]] >= i) {
        i = char_index_map[s[j]] + 1;
      }
    }

    // * update the length of substring
    max_len = std::max(max_len, (j - i));

    // * update the index of char in map
    char_index_map[s[j]] = j;

    j++;
  }

  return max_len;
}

int main() {
  std::string s = "abcabcbb";
  // std::string s = "abba";
  // std::string s = "tmmzuxt";
  std::cout << "Input String: " << s << std::endl;

  // int ans = bruteForce(s);
  int ans = lengthOfLongestSubstring(s);
  std::cout << "Longest Substring Without Repeating Characters: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 01-longest-substr-without-repeating.cpp -o output && ./output
