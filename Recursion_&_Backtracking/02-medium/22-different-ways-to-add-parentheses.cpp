/*
 * Leetcode - 2597
 * Different Ways to Add Parentheses
 * 
 * Given an integer array nums and an integer k, return true if it is possible to divide this array into 
 * k non-empty subsets whose sums are all equal.

 * Return the maximum possible length of s.
 
 * A subsequence is an array that can be derived from another array by deleting some or no elements without
 * changing the order of the remaining elements.

 * Example 1
 * input       : nums = [4,3,2,3,5,2,1], k = 4
 * output      : true

 * Example 1
 * input       : nums = [1,2,3,4], k = 3
 * output      : false

 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets
*/

#include <vector>
#include <iostream>

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

// * ------------------------- Approach: Optimal Approach -------------------------
// * TIME COMPLEXITY O(2^n * n)
// * SPACE COMPLEXITY O(n)
vector<int> diffWaysToCompute(string expr) {
  vector<int> result;
  
  for (int i = 0; i < expr.size(); ++i) {
    if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
      vector<int> left_result = diffWaysToCompute(expr.substr(0, i));
      vector<int> right_result = diffWaysToCompute(expr.substr(i + 1, expr.size() - 1));
  
      for (int &x: left_result) {
        for (int &y : right_result) {
          if (expr[i] == '+') {
            result.push_back(x + y);
          }
          else if (expr[i] == '-') {
            result.push_back(x - y);
          }
          else if (expr[i] == '*') {
            result.push_back(x * y);
          }
        }
      }
    }
  }
  
  if (result.empty()) {
    result.push_back(stoi(expr));
  }
  
  return result;
}

int main(void) {
  // * testcase 1
  // string expression = "2-1-1";
  
  // * testcase 2
  string expression = "2*3-4*5";

  cout << "Expression: " << expression << endl;

  cout << "Expression Values: ";
  vector<int> ans = diffWaysToCompute(expression);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 22-different-ways-to-add-parentheses.cpp -o output && ./output