#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

template <typename T>
void printStack(std::stack<T> st) {
  while (!st.empty()) {
    std::cout << st.top() << std::endl;
    st.pop();
  }
}

// * 04
// bool isValidParenthesis(std::string s) {
// TODO
// }

// * 05 - Insert at the end
// void insertAtEnd(std::stack<int> &st, int val) {
// TODO
// }

// * 08 - Check Redundant brackets
// bool checkRedundantBrackets(std::string s) {
// TODO
// }

// * 09 - Min cost to make string valid
// bool findMinimumCost(std::string s) {
// TODO Understanding
// }

// * 10 - Baseball Game
// int calPoints(std::vector<std::string> operations) {
// TODO
// }
  
// * 11 - Make The String Great
// std::string makeGood(std::string s) {
// TODO
// }
  
// * 12 - Clear Digits
// std::string clearDigits(std::string s) {
// TODO
// }

// * 13 - Crawler Log Folder
// int minOperations(std::vector<std::string> logs) {
// TODO
// }

// * 14 - Final Prices With a Special Discount in a Shop
// std::vector<int> finalPrices(std::vector<int> &prices) {
// TODO
// }

int main() {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output