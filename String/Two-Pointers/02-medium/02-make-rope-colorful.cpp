/*
 * Minimum Time to Make Rope Colorful
 * Given an integer array nums, move all the even integers at the beginning of the array followed 
 * by all the odd integers.
 * Return any array that satisfies this condition.

 * Example 1
 * Input  : s = "I am zoro"
 * Output : "zoro am I"
 * 
 * Example 2
 * Input  : s = "Roronoa Zoro"
 * Output : "Zoro Roronoa" 

 * https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int minCost(std::string colors, std::vector<int> neededTime) {
  int n = colors.size();
  int time = 0, prev = 0;
  for (int i = 0; i < n; ++i) {
    int cur_time = neededTime[i];
    if (i > 0 && colors[i] != colors[i - 1]) {
      prev = 0;
    }
    time = time + std::min(prev, neededTime[i]);
    prev = std::max(prev, cur_time);
  }
  return time;
}

int main() {
  // * testcase 1
  // std::string colors = "abaac";
  // std::vector<int> neededTime = {1, 2, 3, 4, 5};
  // * testcase 2
  // std::string colors = "abc";
  // std::vector<int> neededTime = {1, 2, 3};
  // * testcase 3
  // std::string colors = "aabaa";
  // std::vector<int> neededTime = {1, 2, 3, 4, 1};
  // * testcase 4
  std::string colors = "aaabbbabbbb";
  std::vector<int> neededTime = {3, 5, 10, 7, 5, 3, 5, 5, 4, 8, 1};
  std::cout << colors << std::endl;
  printArr(neededTime);
  int time = minCost(colors, neededTime);
  std::cout << time << std::endl;
}

// * Run the code
// * g++ --std=c++17 02-make-rope-colorful.cpp -o output && ./output