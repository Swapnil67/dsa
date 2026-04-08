/*
 * Leetcode - 131
 * Palindrome Partitioning
 * 
 * Given a string s, partition s such that every substring of the partition is a palindrome. 
 * Return all possible palindrome partitioning of s.

 * Example 1
 * input  : s = "aab"
 * output : [["a","a","b"],["aa","b"]]

 * Example 2
 * input  : s = "a"
 * output : [["a"]]
 * 
 * https://leetcode.com/problems/palindrome-partitioning/description/
*/

// ! Amazon, Google, Meta, Microsoft, Adobe, Apple, Uber

#include <vector>
#include <iostream>

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

bool check_palindrome(string &s, int i, int j) {
  while (i <= j) {
    if (s[i] != s[j]) 
      return false;
    i++;
    j--;
  }
  return true;
}

void dfs(
    int i,
    string &s,
    vector<string> cur,
    vector<vector<string>> &ans)
{
  // * Base case
  if (i == s.size()) {
    ans.push_back(cur);
    return;
  }

  for (int j = i; j < s.size(); ++j) {
    // cout << s.substr(i, j - i + 1) << endl;
    if (check_palindrome(s, i, j)) {
      cur.push_back(s.substr(i, j - i + 1));
      dfs(j + 1, s, cur, ans);
      cur.pop_back();
    }
  }
}

void dfs(int i, string s, vector<string> &parts, vector<vector<bool>> &t,
         vector<vector<string>> &ans) {
  if (i == s.size()) {
    ans.push_back(parts);
    return;
  }

  for (int j = i; j < s.length(); ++j) {
    if (t[i][j] == true) {
      parts.push_back(s.substr(i, j - i + 1));
      dfs(j + 1, s, parts, t, ans);
      parts.pop_back();
    }
  }
}

// * ------------------------- Optimal Approach -------------------------`
// * Top Down
// * N = length of substring
// * TIME COMPLEXITY O(2^n * n)
// * SPACE COMPLEXITY O(n)
vector<vector<string>> partition(string s) {
  vector<string> cur;
  vector<vector<string>> ans;
  dfs(0, s, cur, ans);
  return ans;
}

// * ------------------------- Optimal Approach -------------------------
// * Bottom Up
// * if t[i][j] = true  (This means s[i..j] is a palindrome)
// * if t[i][j] = false (This means s[i..j] is not a palindrome)
// * N = length of substring
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
vector<vector<string>> partition2(string s) {
  int n = s.length();
  vector<vector<bool>> t(n, vector<bool>(n, false));
  for (int L = 1; L <= n; ++L) {
    for (int i = 0; (i + L - 1) < n; ++i) {
      int j = i + L - 1;
      if (i == j) { // * diagnol
        t[i][i] = true; // * Single characters are palindrome.
      }
      else if (i + 1 == j) {
        t[i][j] = s[i] == s[j]; // * Strings of 2 Length
      }
      else { // * Strings of length > 2
        t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]);
      }
    }
  }

  // * For Debugging
  // for (auto &vec : t)
  //   printArr(vec);

  vector<vector<string>> ans;
  vector<string> parts;
  dfs(0, s, parts, t, ans);
  return ans;
}

int main(void) {
  string s = "aab";
  cout << "Input string: " << s << endl;

  // vector<vector<string>> ans = partition(s);
  vector<vector<string>> ans = partition2(s);
  cout << "Palindrome Partitioning: " << endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 08-palindrome-partitioning.cpp -o output && ./output