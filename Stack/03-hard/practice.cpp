#include <map>
#include <stack>
#include <vector>
#include <numeric>
#include <climits>
#include <iostream>
#include <algorithm>
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

void printStack(stack<int> st) {
  stack<int> temp = st;
  while(!temp.empty()) {
    cout << temp.top() << endl;
    temp.pop();
  }
}

// * 08 - Parsing A Boolean Expression
// bool parseBoolExpr(string &expression) {
// TODO
// }

// * 09 - Number of Atoms
// string countOfAtoms(string formula) {
// TODO
// }

// * ------------------------------------------------------------------------------------

// * 01 - Maximum Frequency Stack
// class FreqStack {
// public:
// FreqStack() {}
// void push(int val) {}
// int pop() {}
// };

// * 02 - Robot Collisions
// vector<int> survivedRobotsHealths(
//     vector<int> &positions,
//     vector<int> &healths,
//     string directions)
// {
// TODO
// }

// * 03 - Largest Rectangle in Histogram
// int largestRectangleArea(vector<int> &heights) {
// TODO
// }

// * 04 - Maximal Rectangle
// int maximalRectangle(vector<vector<char>> &matrix) {
// TODO
// }

// * 05 - Shortest Subarray with Sum at Least K
// int shortestSubarray(vector<int> &nums, int k) {
// TODO
// }

// * 06 - Basic Calculator
// int calculate(string s) {
// TODO
// }

// * 07 - Number of Visible People in a Queue
// vector<int> canSeePersonsCount(vector<int>& heights) {
// TODO
// }

int main(void) {
  return 0;
}

// * run the code
// * g++ --std=c++20 -g practice.cpp -o output && ./output

