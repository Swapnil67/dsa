#include <stack>
#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void printStack(std::stack<T> st) {
  while (!st.empty()) {
    std::cout << st.top() << std::endl;
    st.pop();
  }
}

void reverseArr(std::vector<int> &arr, int i, int j)
{
  int n = arr.size();
  while (i < j)
  {
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
// std::string removeStars2(std::string s) {
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
// class StockSpanner {
// TODO
// };

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
// 

// * 13 - 132 Pattern
// bool find132pattern(std::vector<int> &nums) {
// TODO
// }}

int main() {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output