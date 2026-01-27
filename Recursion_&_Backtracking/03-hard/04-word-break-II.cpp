/*
 * Leetcode - 140
 * Word Break II
 * 
 * Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word 
 * is a valid dictionary word. Return all such possible sentences in any order.
 * 
 * Note that the same word in the dictionary may be reused multiple times in the segmentation.

 * Example 1
 * input  : s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * output : ["cats and dog","cat sand dog"]
 * 
 * Example 2
 * input  : s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
 * output : ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * 
 * Example 3
 * input  : s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * output : []
 * 
 * https://leetcode.com/problems/word-break-ii/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

void solve(std::string &s, std::string &cur,
           std::unordered_map<std::string, int> &dict_map,
           int i,
           std::vector<std::string> &result)
{
  // * base case
  if (i >= s.length()) {
    // std::cout << cur.length() << " -> " << cur << std::endl;
    result.push_back(cur);
    return;
  }

  for (int j = i; j < s.size(); ++j) {
    std::string word = s.substr(i, (j - i + 1));
    if (dict_map[word]) {
      // std::cout <<  cur << " ->: " << j << std::endl;
      std::string temp_cur = cur;
      if (!cur.empty())
        cur += " ";

      cur += word; // * take word
      solve(s, cur, dict_map, j + 1, result);
      cur = temp_cur; // * remove word
    }
  }

}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(2^n)
std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
  // * save all the words from wordDict to map
  std::unordered_map<std::string, int> dict_map;
  for (auto &word : wordDict)
    dict_map[word]++;

  std::vector<std::string> result;
  std::string cur = "";
  solve(s, cur, dict_map, 0, result);
  return result;
}

int main(void) {
  // * testcase 1
  std::string s = "catsanddog";
  std::vector<std::string> wordDict = {"cat", "cats", "and", "sand", "dog"};

  // * testcase 2
  // std::string s = "pineapplepenapple";
  // std::vector<std::string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};

  // * testcase 3
  // std::string s = "catsandog";
  // std::vector<std::string> wordDict = {"cats", "dog", "sand", "and", "cat"};

  std::cout << "s: " << s << std::endl;
  std::cout << "Input dict: ";
  printArr(wordDict);
  
  std::vector<std::string> ans = wordBreak(s, wordDict);
  printArr(ans);

  return 0;
}


// * Run the code
// * g++ --std=c++20 04-word-break-II.cpp -o output && ./output