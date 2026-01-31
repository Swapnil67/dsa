/*
 * Leetcode - 140
 * Word Break II
 * 
 * Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where 
 * each word is a valid dictionary word. Return all such possible sentences in any order.
 * 
 * Note that the same word in the dictionary may be reused multiple times in the segmentation.
 * 
 * Example 1:
 * Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * Output: ["cats and dog","cat sand dog"]
 * 
 * Example 2:
 * Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
 * Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * 
 * Example 3:
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: []
 * 
 * https://leetcode.com/problems/word-break-ii/
*/

// ! Amazon, Google, Meta, Dropbox, Oracle, Microsoft, Walmart, Uber

#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_set>
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

string join(const vector<string> &words) {
  ostringstream oss;
  for (int i = 0; i < words.size(); ++i) {
    if (i > 0)
      oss << " ";
    oss << words[i];
  }
  return oss.str();
}

// * Recursion Without Memoization
void solve(int i, string &s, vector<string> &cur, vector<string> &res, unordered_set<string> &st) {
  if (i == s.length()) {
    res.push_back(join(cur));
    // printArr(cur);
    return;
  }

  for (int j = i; j < s.length(); ++j) {
    string w = s.substr(i, j - i + 1);
    if (st.count(w)) {
      // std::cout << w << std::endl;
      cur.push_back(w);
      solve(j + 1, s, cur, res, st);
      cur.pop_back();
    }
  }
}

// * Recursion With Memoization
vector<string> solve(int i, string &s,
                     unordered_set<string> &st,
                     unordered_map<int, vector<string>> &cache)
{
  if (i == s.length())
    return {""};

  if (cache.count(i))
    return cache[i];

  vector<string> res;
  for (int j = i; j < s.length(); ++j) {
    string w = s.substr(i, j - i + 1);
    if (!st.count(w))
      continue;

    vector<string> strings = solve(j + 1, s, st, cache);
    for (auto &str: strings) {
      string sentence = w;
      if (str != "")
        sentence += (" " + str);
      res.push_back(sentence);
    } 
  }

  return cache[i] = res;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * 'n' - length of string, 'm' -  sum of length of words in wordDict
// * TIME COMPLEXITY O(m * n * 2^n)
// * SPACE COMPLEXITY O(m + 2^n)
vector<string> bruteForce(string s, vector<string> &wordDict) {
  unordered_set<string> st(begin(wordDict), end(wordDict));
  vector<string> cur;
  vector<string> res;
  solve(0, s, cur, res, st);
  return res;
}

// * ------------------------- Approach 2: Optimal Approach -------------------------
// * 'n' - length of string, 'm' -  no. of words in wordDict
// * Dynamic Programming (Top-Down)
// * TIME COMPLEXITY O(m * n * 2^n)
// * SPACE COMPLEXITY O(m * n * 2^n)
vector<string> wordBreak(string s, vector<string> &wordDict) {
  unordered_map<int, vector<string>> cache;
  unordered_set<string> st(begin(wordDict), end(wordDict));
  return solve(0, s, st, cache);
}

int main(void) {
  // * testcase 1
  // string s = "leetcode";
  // vector<string> wordDict = {"leet", "code"};
  
  // * testcase 2
  // string s = "applepenapple";
  // vector<string> wordDict = {"apple", "pen"};

  // * testcase 3
  string s = "catsanddog";
  vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

  // std::vector<std::string> ans = bruteForce(s, wordDict);
  std::vector<std::string> ans = wordBreak(s, wordDict);

  std::cout << "Input String: " << s << std::endl;
  std::cout << "wordDict: ";
  printArr(wordDict);
  std::cout << "Answer: ";
  printArr(ans);
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 17-word-break-ii.cpp -o output && ./output
