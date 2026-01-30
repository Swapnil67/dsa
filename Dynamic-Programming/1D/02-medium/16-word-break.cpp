/*
 * Leetcode - 139
 * Word Break
 * 
 * Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a
 * space-separated sequence of one or more dictionary words.
 * 
 * Note that the same word in the dictionary may be reused multiple times in the segmentation.
 * 
 * Example 1:
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 * 
 * Example 2:
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 * 
 * Example 3:
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 * 
 * https://leetcode.com/problems/word-break/description/
*/

// ! Amazon, Google, IBM, MAQ Software, Microsoft, Walmart, Zoho

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * Recursion Without Memoization
bool solve(int i, string &s, vector<string> &wordDict) {
  if (i == s.size())
    return true;

  for (auto &w : wordDict) {
    if (i + w.length() <= s.length() && s.substr(i, w.length()) == w) {
      if (solve(i + w.length(), s, wordDict))
        return true;
    }
  }
  return false;
}

// * Recursion With Memoization
bool solve(int i, string &s, vector<string> &wordDict, unordered_map<int, bool> &memo) {
  if (memo.find(i) != memo.end())
    return memo[i];

  for (auto &w : wordDict) {
    if (i + w.length() <= s.length() && s.substr(i, w.length()) == w) {
      if (solve(i + w.length(), s, wordDict)) {
        memo[i] = true;
        return true;
      }
    }
  }
  return memo[i] = false;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * 'n' - length of string, 'm' -  no. of words in wordDict
// * TIME COMPLEXITY O(t * m^n)
// * SPACE COMPLEXITY O(n)
bool bruteForce(string s, vector<string> &wordDict) {
  return solve(0, s, wordDict);
}

// * ------------------------- Approach 2: Brute Force Approach -------------------------
// * 'n' - length of string, 'm' -  no. of words in wordDict
// * Dynamic Programming (Top-Down)
// * TIME COMPLEXITY O(t * m * n)
// * SPACE COMPLEXITY O(n)  
bool wordBreak(string s, vector<string> &wordDict) {
  unordered_map<int, bool> memo;
  memo[s.length()] = true;
  return solve(0, s, wordDict, memo);
}

int main(void) {
  // * testcase 1
  string s = "leetcode";
  vector<string> wordDict = {"leet", "code"};
  
  // * testcase 2
  // string s = "applepenapple";
  // vector<string> wordDict = {"apple", "pen"};

  // * testcase 3
  // string s = "catsandog";
  // vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

  // bool ans = bruteForce(s, wordDict);
  bool ans = wordBreak(s, wordDict);

  std::cout << "Input String: " << s << std::endl;
  std::cout << "wordDict: ";
  printArr(wordDict);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 16-word-break.cpp -o output && ./output
