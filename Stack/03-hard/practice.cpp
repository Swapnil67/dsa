#include <map>
#include <stack>
#include <vector>
#include <numeric>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  printf("\n");
}

void printStack(std::stack<int> st) {
  std::stack<int> temp = st;
  while(!temp.empty()) {
    std::cout << temp.top() << std::endl;
    temp.pop();
  }
}

// * 01 - Maximum Frequency Stack
// class FreqStack {
// public:
// FreqStack() {}
// void push(int val) {}
// int pop() {}
// };

// * 02 - Robot Collisions
// std::vector<int> survivedRobotsHealths(std::vector<int> &positions,
//                                        std::vector<int> &healths,
//                                        std::string directions)
// {
// TODO
// }

// * 03 - Largest Rectangle in Histogram
// int largestRectangleArea(std::vector<int> &heights) {
// TODO
// }

// * 04 - Maximal Rectangle
// int maximalRectangle(std::vector<std::vector<char>> &matrix) {
// TODO
// }

// * 05 - Shortest Subarray with Sum at Least K
// int shortestSubarray(std::vector<int> &nums, int k) {
// TODO
// }

// * 06 - Basic Calculator
// int calculate(std::string s) {
// TODO
// }

// * 07 - Number of Visible People in a Queue
// std::vector<int> canSeePersonsCount(std::vector<int> &heights) {
// TODO
// }

// * 08 - Parsing A Boolean Expression
// bool parseBoolExpr(std::string expression) {
// TODO
// }

// * 09 - Number of Atoms
// std::string countOfAtoms(std::string formula) {
// TODO
// }

int main(void) {
  return 0;
}

// * run the code
// * g++ --std=c++20 -g practice.cpp -o output && ./output
