/*
 * Leetcode - 518
 * Coin Change II
 * 
 * You are given an integer array coins representing coins of different denominations and an integer 
 * amount representing a total amount of money.
 * 
 * Return the number of combinations that make up that amount. 
 * If that amount of money cannot be made up by any combination of the coins, return 0.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * The answer is guaranteed to fit into a signed 32-bit integer.
 * 
 * Example 1
 * input            : amount = 5, coins = [1,2,5]
 * output           : 4
 * Explanation      : there are four ways to make up the amount:
 *                    5=5
 *                    5=2+2+1
 *                    5=2+1+1+1
 *                    5=1+1+1+1+1
 *
 * Example 2
 * input            : amount = 3, coins = [2]
 * output           : 0
 * Explanation      : the amount of 3 cannot be made up just with coins of 2.
 * 
 * Example 3
 * input            : amount = 10, coins = [10]
 * output           : 1
 * 
 * https://leetcode.com/problems/coin-change-ii
 */

#include <vector>
#include <iostream>
#include <algorithm>

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

string findLCS(string &s1, string &s2) {
}

int main(void) {
  // * testcase 1
  string s1 = "abcde", s2 = "ace";

  // * testcase 2
  // string s1 = "abc", s2 = "abc";

  // * testcase 3
  // string s1 = "abc", s2 = "def";

  cout << "s1: " << s1 << ", s2: " << s2 << endl;
  string ans = findLCS(s1, s2);
  cout << "Longest Common Subsequence: " << ans << endl;
}

// * Run the code
// * g++ --std=c++17 02-print-longest-common-subsequence.cpp -o output && ./output

