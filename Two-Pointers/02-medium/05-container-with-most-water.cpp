/*
 * Leetcode - 11
 * Container With Most Water
 * You are given an integer array height of length n. There are n vertical lines drawn such that the
 * two endpoints of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * Return the maximum amount of water a container can store.

 * Example 1
 * Input  : height = [1,8,6,2,5,4,8,3,7]
 * Output : 49
 * 
 * https://leetcode.com/problems/container-with-most-water/description/
*/

#include <vector>
#include <climits>
#include <iostream>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> height) {
  int n = height.size();
  int maxArea = INT_MIN;
  for (int i = 0; i < n; ++i)  {
    for (int j = i + 1; j < n; ++j) {
      int curArea = ((j - i) * std::min(height[i], height[j]));
      // std::cout << curArea << " ";
      maxArea = std::max(curArea, maxArea);
    }
    // std::cout << std::endl;
  }
  return maxArea;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Two pointer at start & end
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxArea(std::vector<int> height) {
  int n = height.size();
  int i = 0, j = n - 1;
  int max_area = INT_MIN;
  while (j > i) {
    int cur_area = (j - i) * std::min(height[i], height[j]);
    if (height[i] > height[j])
      j--;
    else
      i++;
    max_area = std::max(max_area, cur_area);
  }
  return max_area;
}

int main() {
  
  std::vector<int> nums = {3, 1, 2, 3};
  // std::vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  // std::vector<int> nums = {1, 1};
  printArr(nums);
  // int ans = bruteForce(nums);
  int ans = maxArea(nums);
  std::cout << "maximum amount of water a container can store : " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 05-container-with-most-water.cpp -o output && ./output
