/**
 * * Leetcode - 1898
 * * Maximum Number of Removable Characters
 * * You are given two strings s and p where p is a subsequence of s. You are also given a 
 * * distinct 0-indexed integer array removable containing a subset of indices of s (s is also 0-indexed).
 * 
 * * You want to choose an integer k (0 <= k <= removable.length) such that, after removing k characters 
 * * from s using the first k indices in removable, p is still a subsequence of s. 
 * * More formally, you will mark the character at s[removable[i]] for each 0 <= i < k, 
 * * then remove all marked characters and check if p is still a subsequence.
 * 
 * * Return the maximum k you can choose such that p is still a subsequence of s after the removals.
 * 
 * * Example 1:
 * * Input       : s = "abcacb", p = "ab", removable = [3,1,0]
 * * Output      : 2
 * * Explanation : After removing the characters at indices 3 and 1, "abcacb" becomes "accb".
 * 
 * * Example 2:
 * * Input       : s = "abcbddddd", p = "abcd", removable = [3,2,1,4,5,6]
 * * Output      : 1
 * * Explanation : After removing the character at index 3, "abcbddddd" becomes "abcddddd".
 * 
 * * https://leetcode.com/problems/maximum-number-of-removable-characters/description/
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArr(vector<T> &nums) {
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * Check if string 'p' is subsequence of string 's'
int isSubsequence(string s, string p, vector<int> removable) {
  int i = 0, j = 0;
  int n1 = s.size(), n2 = p.size();
  while (i < n1 && j < n2) {
    if (!count(begin(removable), end(removable), i) && s[i] == p[j]) {
      j++;
    }
    i++;
  }
  // cout << "Remove following indexes" << endl;
  // printArr(removable);
  // cout << "isSubsequence " << (j == n2) << endl;
  return j == n2;
}

int isSubsequence2(string &s, string &p) {
  int i = 0, j = 0;
  int n1 = s.size(), n2 = p.size();
  while (i < n1 && j < n2) {
    if (s[i] == p[j])
      j++;
    i++;
  }
  return j == n2;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(string s, string p, vector<int> removable) {
  int n = removable.size();
  int ans = 0;
  for (int k = 0; k < n; ++k) {
    vector<int> temp(removable.begin(), removable.begin() + k);
    if (isSubsequence(s, p, temp))
      ans = k;
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O((n1 * n2) * log(n))
// * SPACE COMPLEXITY O(n)
int maximumRemovals(string s, string p, vector<int> removable) {
  int n = removable.size();
  int ans = 0;
  int l = 0, r = n;
  while (l <= r) {
    int m = l + (r - l) / 2;
    
    // * Replace all the indexes with '#'
    string removed = s;
    for (int i = 0; i < m; ++i)
      removed[removable[i]] = '#';

    if (isSubsequence2(removed, p)) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return ans;
}

int main(void) {
  // * testcase 1
  string s = "abcacb", p = "ab";
  vector<int> removable = {3, 1, 0};

  // * testcase 2
  // string s = "abcbddddd", p = "abcd";
  // vector<int> removable = {3, 2, 1, 4, 5, 6};

  // * testcase 3
  // string s = "abcab", p = "abc";
  // vector<int> removable = {0, 1, 2, 3, 4};

  cout << "s: " << s << " p: " << p << endl;
  printArr(removable);

  // int ans = bruteForce(s, p, removable);
  int ans = maximumRemovals(s, p, removable);
  cout << "Maximum Number of Removable Characters: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 22-max-no-of-removable-char.cpp -o output && ./output

