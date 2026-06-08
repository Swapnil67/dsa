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
#include <unordered_map>

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

vector<int> dfs(string expr, unordered_map<string, vector<int>> &memo) {
  vector<int> res;
  int n = expr.size();

  // * 1. Check the cache first
  if (memo.find(expr) != memo.end())
    return memo[expr];

  for (int i = 0; i < n; ++i) {
    if (expr[i] == '-' || expr[i] == '+' || expr[i] == '*') {
      // * 2. Compute left and right subproblems using the memoized function
      vector<int> left_res = dfs(expr.substr(0, i), memo);
      vector<int> right_res = dfs(expr.substr(i + 1, n - 1), memo);

      for (auto &l : left_res) {
        for (auto &r : right_res) {
          if (expr[i] == '+') {
            res.push_back(l + r);
          }
          else if (expr[i] == '-') {
            res.push_back(l - r);
          }
          else if (expr[i] == '*') {
            res.push_back(l * r);
          }
        }
      }
    }
  }

  if (res.empty()) {
    res.push_back(stoi(expr));
  }

  return memo[expr] = res;
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Divide And Conquer
// * TIME COMPLEXITY O(2^n * n)
// * SPACE COMPLEXITY O(2^n)
vector<int> bruteForce(string expr) {
  vector<int> result;
  
  for (int i = 0; i < expr.size(); ++i) {
    if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
      vector<int> left_result = bruteForce(expr.substr(0, i));
      vector<int> right_result = bruteForce(expr.substr(i + 1, expr.size() - 1));
      cout << expr[i] << endl;
      printArr(left_result);
      printArr(right_result);
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

// * ------------------------- Approach: Optimal Approach -------------------------
// * Divide And Conquer [Memoization]
// * TIME COMPLEXITY O(n^3 * n)
// * SPACE COMPLEXITY O(n)
vector<int> diffWaysToCompute(string expr) {
  unordered_map<string, vector<int>> memo;
  return dfs(expr, memo);
}

int main(void) {
  // * testcase 1
  // string expression = "2-1-1";
  
  // * testcase 2
  string expression = "2*3-4*5";

  cout << "Expression: " << expression << endl;

  cout << "Expression Values: ";
  // vector<int> ans = bruteForce(expression);
  vector<int> ans = diffWaysToCompute(expression);

  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++17 22-different-ways-to-add-parentheses.cpp -o output && ./output