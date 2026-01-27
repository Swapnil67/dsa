/*
 * Leetcode - 516
 * Longest Palindromic Subsequence
 * 
 * Given a string s, find the longest palindromic subsequence's length in s.
 * 
 * A subsequence is a sequence that can be derived from another sequence by deleting some or no elements 
 * without changing the order of the remaining elements.
 * 
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
*/

// ! Amazon, Google, Meta, Uber, LinkedIn, Paypal

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

int main(void) {
  // * testcase 1
  string s = "bbbab";

  // * testcase 2
  // string s = "cbbd";

  

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
