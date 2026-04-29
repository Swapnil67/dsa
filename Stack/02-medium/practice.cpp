// ! Stack Medium Practice 

#include <stack>
#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

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

template <typename T>
void printStack(stack<T> st) {
  while (!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }
}

void reverseArr(vector<int> &arr, int i, int j) {
  int n = arr.size();
  while (i < j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++, j--;
  }
}



// * 27 - Minimum Remove to Make Valid Parentheses
// string minRemoveToMakeValid(string s) {
// TODO
// }

// * ------------------------------------------------

// * 01 - Evaluate Reverse Polish Notation
// int evalRPN(vector<string> &tokens) {
// TODO
// }

// * 02 - Removing Stars From a String
// string removeStars(string s) {
// TODO
// }

// * 03 - Validate Stack Sequences
// bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
// TODO
// }

// * 04 - Steps to Make Array Non-decreasing
// int totalSteps(vector<int> &nums) {
// TODO
// }

// * 05 - Asteroid Collision
// vector<int> asteroidCollision(vector<int> asteroids) {
// TODO
// }

// * 06 - Online Stock Span
// ! Solve this on leetcode platform

// * 07 - Daily Temperatures
// vector<int> dailyTemperatures(vector<int> temperatures) {
// TODO
// }

// * 08 - Car Fleet
// int carFleet(int target, vector<int> &position, vector<int> &speed) {
// TODO
// }

// * 09 - Simplify Path
// string simplifyPath(string path) {
// TODO
// }

// * 10 - Decode String
// string decodeString(string s) {
// TODO
// }

// * 11 - Remove k digits
// string removeKdigits(string num, int k) {
// TODO  
// }

// * 12 - Remove All Adjacent Duplicates in String II
// string removeDuplicates(string s, int k) {
// TODO
// }

// * 13 - 132 Pattern
// bool find132pattern(vector<int> &nums) {
// TODO
// }

// * 14A - Sum of Subarray Minimums
// long long sumSubarrayMins(vector<int> &arr) {
// TODO
// }

// * 14B - Sum of Subarray Maximums
// long long sumSubarrayMaxs(vector<int> arr) {
// TODO
// }

// * 15 - Reverse Substrings Between Each Pair of Parentheses
// string reverseParentheses(string s) {
// TODO
// }

// * 16 - Min Stack 
// class MinStack {
// TODO
// };

// * 17 - Maximum Width Ramp
// int maxWidthRampB(vector<int> nums) {
// TODO
// }

// * 18 - Flatten Nested List Iterator
// ! Solve this on leetcode platform

// * 19 - Next Greater II
// vector<int> nextGreaterElement(vector<int> arr) {
// TODO
// };

// * 20 - Minimum Add to Make Parentheses Valid
// int minAddToMakeValid(string s) {
// TODO
// }

// * 21 - Basic Calculator II
// int calculate(string s) {
// TODO
// }

// * 22 - Sum of Subarray Ranges 
// long long subArrayRanges2(vector<int>& nums) {
// TODO
// }

// * 23 - Find Permutation
// vector<int> findPermutation(string s) {
// TODO
// }

// * 24 - Construct Smallest Number From DI String
// string smallestNumber(string pattern) {
// TODO
// }

// * 25 - Minimum Swaps To Make Balance String
// int minSwaps(string s) {
// TODO
// }

// * 26 - Minimum Insertions to Balance a Parentheses String
// int minInsertions(string s) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
