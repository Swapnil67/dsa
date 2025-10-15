/*
 * Leetcode - 2597
 * The Number of Beautiful Subsets
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

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

std::vector<int> solve(std::string expr) {
  std::vector<int> result;

  for (int i = 0; i < expr.size(); ++i) {
    if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
      std::vector<int> left_result = solve(expr.substr(0, i));
      std::vector<int> right_result = solve(expr.substr(i + 1, expr.size() - 1));

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
    result.push_back(std::stoi(expr));
  }

  return result;
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(2^n * n)
// * SPACE COMPLEXITY O(n)
std::vector<int> diffWaysToCompute(std::string expression) {
  return solve(expression);
}

int main(void) {
  // * testcase 1
  // std::string expression = "2-1-1";
  
  // * testcase 2
  std::string expression = "2*3-4*5";

  std::cout << "Expression: " << expression << std::endl;

  std::cout << "Expression Values: ";
  std::vector<int> ans = diffWaysToCompute(expression);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 22-different-ways-to-add-parentheses.cpp -o output && ./output