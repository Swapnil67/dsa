/*
 * Leetcode - 1415
 * The k-th Lexicographical String of All Happy Strings of Length n
 * 
 * A happy string is a string that:
 * - consists only of letters of the set ['a', 'b', 'c'].
 * - s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
 * 
 * - For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc"
 * are not happy strings.
 * 
 * Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
 * 
 * Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

 * Example 1
 * input       : n = 1, k = 3
 * output      : "c"
 * Explanation : The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

 * Example 2
 * input       : n = 1, k = 4
 * output      : ""
 * Explanation : There are only 3 happy strings of length 1.

 * Example 3
 * input       : n = 1, k = 9
 * output      : "cab"
 * Explanation : There are 12 different happy string of length 3 
 *               ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. 
 *               You will find the 9th string = "cab"
 * 
 * https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/
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

std::vector<std::string> strings;
void solveBrute(std::string &str, int &n) {
  if (str.size() == n) {
    strings.push_back(str);
    return;
  }

  for (char ch = 'a'; ch <= 'c'; ch++) {
    // * Adjacent char should not be duplicate
    if (str.size() > 0 && str.back() == ch)
      continue;

    str.push_back(ch);

    solveBrute(str, n);

    str.pop_back();
  }
}

void solve(std::string &str, std::string &ans, int &cnt, int k, int &n) {
  if (str.size() == n) {
    cnt++;
    if (cnt == k)
      ans = str;
    return;
  }

  for (char ch = 'a'; ch <= 'c'; ch++) {
    // * Adjacent char should not be duplicate
    if (str.size() > 0 && str.back() == ch)
      continue;

    str.push_back(ch);

    solve(str, ans, cnt, k, n);

    str.pop_back();
  }
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------`
// * Generate all possible 'n' length strings
// * TIME COMPLEXITY O(n * 2^n)
// * SPACE COMPLEXITY O(n * 2^n)
std::string bruteForce(int n, int k) {
  std::string str = "";
  solveBrute(str, n);
  
  if (strings.size() < k) {
      return "";
  }
  return strings[k - 1];
}

// * ------------------------- Approach 2: Optimal Approach -------------------------`
// * Count all possible 'n' length strings 
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
std::string getHappyString(int n, int k) {
  int count = 0;
  std::string str = "", ans = "";
  solve(str, ans, count, k, n);
  return ans;
}

int main(void) {
  // * testcase 1
  // int n = 1, k = 3;
  
  // * testcase 2
  // int n = 1, k = 4;
  
  // * testcase 3
  int n = 3, k = 9;

  std::cout << "n: " << n << ", k: " << k << std::endl;

  // std::string ans = bruteForce(n, k);
  std::string ans = getHappyString(n, k);
  std::cout << "kth happy string: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 13-kth-happy-string.cpp -o output && ./output