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

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * Check if string 'p' is subsequence of string 's'
int isSubsequence(std::string s, std::string p, std::vector<int> removable) {
  int i = 0, j = 0;
  int n1 = s.size(), n2 = p.size();
  while (i < n1 && j < n2) {
    if (!std::count(removable.begin(), removable.end(), i) && s[i] == p[j]) {
      j++;
    }
    i++;
  }

  // std::cout << "Remove following indexes" << std::endl;
  // printArr(removable);
  // std::cout << "isSubsequence " << (j == n2) << std::endl;
  return j == n2;
}

int bruteForce(std::string s, std::string p, std::vector<int> removable) {
  int n = removable.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    std::vector<int> temp(removable.begin(), removable.begin() + i);
    if (isSubsequence(s, p, temp))
      ans = i;
  }

  return ans;
}

int isSubsequence2(std::string s, std::string p, std::vector<int> &removable, int k) {
  // * Create an array and set the removed indexs to '1'
  int rm[100001] = {};
  for (int i = 0; i < k; ++i)
    rm[removable[i]] = 1;

  int i = 0, j = 0;
  int n1 = s.size(), n2 = p.size();
  while (i < n1 && j < n2) {
    // * this character is removed, skip
    if (rm[i] == 1) {
      i++;
      continue;
    }

    if (s[i] == p[j])
      j++;
    i++;
  }
  std::cout << "k " << k << std::endl;
  // std::cout << j << " " << n2 << std::endl;
  return j == n2;
}

int maximumRemovals(std::string s, std::string p, std::vector<int> removable) {
  int n = removable.size();
  int ans = 0;
  int l = 0, r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (isSubsequence2(s, p, removable, m)) {
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
  // std::string s = "abcacb", p = "ab";
  // std::vector<int> removable = {3, 1, 0};

  // * testcase 2
  // std::string s = "abcbddddd", p = "abcd";
  // std::vector<int> removable = {3, 2, 1, 4, 5, 6};

  // * testcase 3
  std::string s = "abcab", p = "abc";
  std::vector<int> removable = {0, 1, 2, 3, 4};

  std::cout << "s: " << s << " p: " << p << std::endl;
  printArr(removable);

  // int ans = bruteForce(s, p, removable);
  int ans = maximumRemovals(s, p, removable);
  std::cout << "Maximum Number of Removable Characters: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 22-max-no-of-removable-char.cpp -o output && ./output

