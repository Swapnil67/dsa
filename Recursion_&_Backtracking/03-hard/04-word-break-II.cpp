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
 * https://leetcode.com/problems/word-break-ii/
*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

unordered_set<string> st;

void solve(string &s, string &cur,
           int i,
           vector<string> &result)
{
  // * base case
  if (i >= s.length()) {
    // cout << cur.length() << " -> " << cur << endl;
    result.push_back(cur);
    return;
  }

  for (int j = i; j < s.size(); ++j) {
    string word = s.substr(i, (j - i + 1));
    if (st.count(word)) {
      // cout <<  cur << " ->: " << j << std::endl;
      string temp_cur = cur;
      if (!cur.empty())
        cur += " ";

      cur += word; // * take word
      solve(s, cur, j + 1, result);
      cur = temp_cur; // * remove word
    }
  }
}

vector<string> dfs(int i, string &s, unordered_map<int, vector<string>> &memo) {
  int n = s.length();
  if (i >= n) {
    return {""};
  }

  if (memo.count(i))
    return memo[i];

  vector<string> valid_sentences;
  for (int j = i; j < n; ++j) {
    string word = s.substr(i, (j - i + 1));
    if (st.count(word)) {
      vector<string> suffixes = dfs(j + 1, s, memo);
      for (auto &suffix : suffixes) {
        if (suffix.empty()) {
          valid_sentences.push_back(suffix);
        } else {
          valid_sentences.push_back(word + " " + suffix);
        }
      }
    }
  }

  return memo[i] = valid_sentences;
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(2^n)
vector<string> wordBreak(string s, vector<string>& wordDict) {
  st.insert(begin(wordDict), end(wordDict));

  string cur = "";
  vector<string> result;
  solve(s, cur, 0, result);
  return result;
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(2^n)
vector<string> wordBreak(string s, vector<string>& wordDict) {
  unordered_map<int, vector<string>> memo;
  st.insert(begin(wordDict), end(wordDict));
  return dfs(0, s, memo);
}

int main(void) {
  // * testcase 1
  string s = "catsanddog";
  vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

  // * testcase 2
  // string s = "pineapplepenapple";
  // vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};

  // * testcase 3
  // string s = "catsandog";
  // vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

  cout << "s: " << s << endl;
  cout << "Input dict: ";
  printArr(wordDict);
  
  vector<string> ans = wordBreak(s, wordDict);
  printArr(ans);

  return 0;
}


// * Run the code
// * g++ --std=c++20 04-word-break-II.cpp -o output && ./output


/*
* Recursion Tree Diagram
*
*                                  dfs(i=0, cur="")
*                                   /            \
*                       "cat" (j=2)/              \"cats" (j=3)
*                                 /                \
*                     dfs(i=3, cur="cat")       dfs(i=4, cur="cats")
*                            /                           \
*               "sand" (j=6)/                             \"and" (j=6)
*                          /                               \
*               dfs(i=7, cur="cat sand")              dfs(i=7, cur="cats and")
*                        /                                   /
*            "dog" (j=9)/                         "dog" (j=9)/
*                      /                                   /
*         dfs(i=10, cur="cat sand dog")       dfs(i=10, cur="cats and dog")
*
*                      |                                   |
*                (i == n) SUCCESS                    (i == n) SUCCESS
*             [Added to result]                   [Added to result]
*
*/