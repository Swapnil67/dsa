/*
 * Leetcode - 1578
 * Minimum Time to Make Rope Colorful
 * Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
 * Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color,
 * so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. 
 * You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob 
 * needs to remove the ith balloon from the rope.
 * Return the minimum time Bob needs to make the rope colorful.

 * Example 1
 * Input  : colors = "abaac", neededTime = [1, 2, 3, 4, 5]
 * Output : 3
 * 
 * Example 2
 * Input  : colors = "abc", neededTime = [1, 2, 3]
 * Output : 0
 * 
 * Example 3
 * Input  : colors = "aabaa", neededTime = [1, 2, 3, 4, 1]
 * Output : 2

 * https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/
*/

#include <vector>
#include <iostream>

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