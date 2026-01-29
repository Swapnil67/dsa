/*
 * Leetcode - 1048 
 * Longest String Chain 
 * 
 * You are given an array of words where each word consists of lowercase English letters.
 * 
 * wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA 
 * without changing the order of the other characters to make it equal to wordB.
 * 
 * - For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
 * 
 * A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor 
 * of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
 * 
 * Return the length of the longest possible word chain with words chosen from the given list of words.
 * 
 * Example 1     :
 * Input         : words = ["a","b","ba","bca","bda","bdca"]
 * Output        : 4
 * Explanation   : One of the longest word chains is ["a","ba","bda","bdca"].
 * 
 * Example 2     :
 * Input         : words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 * Output        : 5
 * Explanation   : All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
 * 
 * Example 3    :
 * Input        : words = ["abcd","dbqca"]
 * Output       : 1
 * Explanation  : The trivial word chain ["abcd"] is one of the longest word chains.
 *                ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 * 
 * https://leetcode.com/problems/longest-string-chain/
*/

// ! Google

#include <vector>
#include <iostream>
#include <algorithm>

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

bool is_predecessor(string s, string t) {
  int n1 = s.size(), n2 = t.size();
  // std::cout << s << " " << t << std::endl;
  if (n1 > n2 || n2 - n1 != 1)
    return false;

  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    if (s[i] == t[j]) {
      i++;
    }
    j++;
  }
  return i == n1;
}


int solve_brute(int i, int prev_idx, vector<string> &words) {
  if (i >= words.size())
    return 0;

  int take = 0;
  if (prev_idx == -1 || is_predecessor(words[prev_idx], words[i])) {
    // if (prev_idx != -1) {
    //   std::cout << words[prev_idx] << " " << words[i] << std::endl;
    // }
    take = 1 + solve_brute(i + 1, i, words);
  }

  int skip = solve_brute(i + 1, prev_idx, words);
  return max(take, skip);
}


int solve(int i, int prev_idx, vector<string> &words, vector<vector<int>> &dp) {
  if (i >= words.size())
    return 0;

  if (prev_idx != -1 && dp[i][prev_idx] != -1) {
    return dp[i][prev_idx];
  }

  int take = 0;
  if (prev_idx == -1 || is_predecessor(words[prev_idx], words[i])) {
    // if (prev_idx != -1) {
    //   std::cout << words[prev_idx] << " " << words[i] << std::endl;
    // }
    take = 1 + solve(i + 1, i, words, dp);
  }
  int skip = solve(i + 1, prev_idx, words, dp);
  if (prev_idx != -1) {
    dp[i][prev_idx] = max(take, skip);
  }

  return max(take, skip);
}

static bool sortBy(string &s1, string &s2) {
  return s1.length() < s2.length();
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * Generate All the subsequences
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(2^n) 
int bruteForce(std::vector<std::string> words) {
  int n = words.size();
  // * Sort the input string by length
  std::sort(begin(words), end(words), sortBy);
  return solve_brute(0, -1, words);
}

// * ------------------------- Approach 2: Better Approach -------------------------
// * Recursion + Memoization (Top Down)
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2) 
int betterApproach(std::vector<std::string> words) {
  int n = words.size();
  // * Sort the input string by length
  std::sort(begin(words), end(words), sortBy);
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1));
  return solve(0, -1, words, dp);
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2) 
int longestStrChain(std::vector<std::string> words) {
  int n = words.size();
  std::vector<int> t(n + 1, 1);

  // * Sort the input string by length
  std::sort(begin(words), end(words), sortBy);

  int max_len = 1;
  for (int i = 0; i < n; ++i) {
    string cur = words[i];
    for (int j = 0; j < i; ++j) {
      if (is_predecessor(words[j], cur)) {
        // cout << words[j] << " " << cur << endl;
        t[i] = max(t[i], t[j] + 1);
        max_len = max(max_len, t[i]);
      }
    }
  }

  printArr(t);
  return max_len;
}

int main(void) {
  // * testcase 1
  // std::vector<std::string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

  // * testcase 2
  // std::vector<std::string> words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};

  // * testcase 3
  // std::vector<std::string> words = {"abcd", "dbqca"};

  // * testcase 4
  std::vector<std::string> words = {"a", "b", "ba", "abc", "abd", "bdca"};

  std::cout << "Input Words: ";
  printArr(words);

  // int ans = bruteForce(words);
  // int ans = betterApproach(words);
  int ans = longestStrChain(words);
  std::cout << "Longest String Chain: " << ans << std::endl;


  return 0;
}
 
// * Run the code
// * g++ --std=c++20 11-longest-string-chain.cpp -o output && ./output
