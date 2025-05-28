#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <algorithm>

template<typename T>
void printArr(std::vector<T> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
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


// * 09 - Simplify Path
// std::string simplifyPath(std::string path) {
// TODO
// }

// * 10 - Decode String
// std::string decodeString(std::string s) {
// TODO
// }

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

// * 11 - Remove k digits
// std::string removeKdigits(std::string num, int k) {
// TODO
// }

int main() {
  return 0;
}

// * Run the code
// * g++ -std=c++17 practice.cpp -o output && ./output