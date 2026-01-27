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

#include <vector>
#include <iostream>

void printArr(std::vector<std::string> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

bool check_palindrome(std::string &s, int i, int j) {
  while (i <= j) {
    if (s[i] != s[j]) 
      return false;
    i++;
    j--;
  }
  return true;
}

void solve(std::string &s,
           int idx,
           std::vector<std::string> cur,
           std::vector<std::vector<std::string>> &ans) {

  // * Base case
  if (idx == s.size()) {
    ans.push_back(cur);
    return;
  }

  for (int i = idx; i < s.size(); ++i) {
    // std::cout << s.substr(idx, i - idx + 1) << std::endl;
    if (check_palindrome(s, idx, i)) {
      cur.push_back(s.substr(idx, i - idx + 1));
      solve(s, i + 1, cur, ans);
      cur.pop_back();
    }
  }
}

// * ------------------------- Optimal Approach -------------------------`
// * N = length of substring
// * TIME COMPLEXITY O(2^n * n)
// * SPACE COMPLEXITY O(n)
std::vector<std::vector<std::string>> partition(std::string s) {
  std::vector<std::string> cur;
  std::vector<std::vector<std::string>> ans;
  solve(s, 0, cur, ans);
  return ans;
}

int main(void) {
  std::string s = "aab";
  std::cout << "Input string: " << s << std::endl;

  std::vector<std::vector<std::string>> ans = partition(s);
  std::cout << "Palindrome Partitioning: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 08-palindrome-partitioning.cpp -o output && ./output