#include <stack>
#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>

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

// * 12 - Remove All Adjacent Duplicates in String II
// std::string removeDuplicates(std::string s, int k) {
// TODO
// }

// * 13 - 132 Pattern
// bool find132pattern(std::vector<int> &nums) {
// TODO
// }

// * 13 - Sum of Subarray Minimums

int smallestNextToLeft(std::vector<int> &nums, int cur, int i) {
  int start = i;
  for (; i >= 0; --i) {
    if (cur > nums[i])
      break;
  }
  return start - i;
}

int smallestNextToRight(std::vector<int> &nums, int cur, int i) {
  int start = i;
  int n = nums.size();
  for (; i < n; ++i) {
    if (cur > nums[i])
      break;
  }
  return i - start;
}

long long sumSubarrayMins(std::vector<int> &nums) {
  int n = nums.size();
  long long ans = 0;
  for(int i = 0; i < n; ++i) { 
    int cur = nums[i];
    int a = smallestNextToLeft(nums, cur, i);
    int b = smallestNextToRight(nums, cur, i);

    ans += (a * b);
    // std::cout << a << " " << b << std::endl;
  }

  return ans;
}

int main() {
  std::vector<int> nums = {3, 1, 2, 4};
  // std::vector<int> nums = {11, 81, 94, 43, 3};

  printArr(nums);
  long long ans = sumSubarrayMins(nums);
  std::cout << "Sum of Subarray Minimums: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ -std=c++17 practice.cpp -o output && ./output