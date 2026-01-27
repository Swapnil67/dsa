#include <stack>
#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

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

template <typename T>
void printStack(std::stack<T> st) {
  while (!st.empty()) {
    std::cout << st.top() << std::endl;
    st.pop();
  }
}

void reverseArr(std::vector<int> &arr, int i, int j) {
  int n = arr.size();
  while (i < j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
  }
}

// * ------------------------------------------------

// * 01 - Evaluate Reverse Polish Notation
// int evalRPN(std::vector<std::string> &tokens) {
// TODO
// }

// * 02 - Removing Stars From a String
// std::string removeStars(std::string s) {
// TODO
// }

// * 03 - Validate Stack Sequences
// bool validateStackSequences(std::vector<int> &pushed, std::vector<int> &popped) {
// TODO
// }

// * 04 - Generate Parentheses
// std::vector<std::string> generateParenthesis(int n) {
// TODO
// }

// * 05 - Asteroid Collision
// std::vector<int> asteroidCollision(std::vector<int> asteroids) {
// TODO
// }

// * 06 - Online Stock Span
// ! Solve this on leetcode platform

// * 07 - Daily Temperatures
// std::vector<int> dailyTemperatures(std::vector<int> temperatures) {
// TODO
// }

// * 08 - Car Fleet
// int carFleet(int target, std::vector<int> &position, std::vector<int> &speed) {
// TODO
// }

// * 09 - Simplify Path
// std::string simplifyPath(std::string path) {
// TODO
// }

// * 10 - Decode String
// std::string decodeString(std::string s) {
// TODO
// }

// * 11 - Remove k digits
// std::string removeKdigits(std::string num, int k) {
// TODO  
// }

// * 12 - Remove All Adjacent Duplicates in String II
// std::string removeDuplicates(std::string s, int k) {
// TODO
// }

// * 13 - 132 Pattern
// bool find132pattern(std::vector<int> &nums) {
// TODO
// }

// * 14A - Sum of Subarray Minimums
// long long sumSubarrayMins(std::vector<int> &arr) {
// TODO
// }

// * 14B - Sum of Subarray Maximums
// long long sumSubarrayMaxs(std::vector<int> arr) {
// TODO
// }

// * 15 - Reverse Substrings Between Each Pair of Parentheses
// std::string reverseParentheses(std::string s) {
// TODO
// }

// * 16 - Min Stack 
// class MinStack {
// TODO
// };

// * 17 - Maximum Width Ramp
// int maxWidthRampB(std::vector<int> nums) {
// TODO
// };

// * 18 - Flatten Nested List Iterator
// ! Solve this on leetcode platform

// * 19 - Next Greater II
// std::vector<int> nextGreaterElement(std::vector<int> arr) {
// TODO
// };

// * 20 - Minimum Add to Make Parentheses Valid
// int minAddToMakeValid(std::string s) {
// TODO
// }

// * 21 - Basic Calculator II
// int calculate(std::string s) {
// TODO
// }

// * 22 - Sum of Subarray Ranges 
// long long subArrayRanges2(std::vector<int>& nums) {
// TODO
// }

// * 23 - Find Permutation
// std::vector<int> findPermutation(std::string s) {
// TODO
// }

// * 24 - Construct Smallest Number From DI String
// std::string smallestNumber(std::string pattern) {
// TODO
// }

// * 25 - Minimum Swaps To Make Balance String
// int minSwaps(std::string s) {
// TODO
// }

// * 26 - Minimum Insertions to Balance a Parentheses String
// int minInsertions(std::string s) {
// TODO
// }

// * 27 - Minimum Remove to Make Valid Parentheses
// std::string minRemoveToMakeValid(std::string s) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output