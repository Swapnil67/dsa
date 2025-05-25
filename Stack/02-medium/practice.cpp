#include <string>
#include <vector>
#include <stack>
#include <iostream>
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
//  TODO
// };
  
// * 07 - Daily Temperatures
// std::vector<int> dailyTemperatures(std::vector<int> temperatures) {
// TODO
// }
  
// * 07 - Daily Temperatures
// std::vector<int> dailyTemperatures(std::vector<int> temperatures) {
// TODO
// }

// * 08 - Daily Temperatures
int carFleet(int target, std::vector<int> position, std::vector<int> speed) {
  int n = position.size();

  // * Pairs of <position, speed>
  std::vector<std::pair<float, float>> cars(n);
  for (int i = 0; i < n; ++i) {
    cars[i] = {(float)position[i], (float)speed[i]};
  }
  std::sort(cars.begin(), cars.end(), std::greater<std::pair<float, float>>());

  // * For debug information
  for (int i = 0; i < n; ++i) {
    printf("(%f %f)\n", cars[i].first, cars[i].second);
  }
  printf("\n");
  
  std::stack<int> st;
  for (int i = 0; i < n; ++i) {
    float t = ((float) target - cars[i].first) / cars[i].second;
    std::cout << t << std::endl;
    if (!st.empty() && st.top() >= t) {
      st.pop();
    }
    st.push(t);
  }
  return st.size();
}

int main() {
  // int target = 12;
  // std::vector<int> position = {10, 8, 0, 5, 3}, speed = {2, 4, 1, 1, 3};

  int target = 10;
  std::vector<int> position = {0, 4, 2}, speed = {2, 1, 3};

  // int target = 10;
  // std::vector<int> position = {1, 3, 6}, speed = {2, 3, 1};

  printf("Target: %d\n", target);
  printf("Car positions: \n");
  printArr(position);
  printf("Car speeds: \n");
  printArr(speed);
  int fleets = carFleet(target, position, speed);
  std::cout << "Car Fleets: " << fleets << std::endl;
  return 0;
}

// * Run the code
// * g++ -std=c++17 practice.cpp -o output && ./output
