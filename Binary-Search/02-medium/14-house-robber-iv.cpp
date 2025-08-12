/*
  * Leetcode - 2560
  * House Robber IV
  * There are several consecutive houses along a street, each of which has some money inside. 
  * There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

  * The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.
  * You are given an integer array nums representing how much money is stashed in each house. 
  * More formally, the ith house from the left has nums[i] dollars.
  * 
  * You are also given an integer k, representing the minimum number of houses the robber will steal from. 
  * It is always possible to steal at least k houses.
  * 
  * Return the minimum capability of the robber out of all the possible ways to steal at least k houses.
  * 
  * Example 1:
  * Input: nums = [2,3,5,9], k = 2
  * Output: 5

  * Example 2:
  * Input: nums = [2,7,9,3,1], k = 2
  * Output: 2
  * 
  * https://leetcode.com/problems/house-robber-iv/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// ! Binary Search on Answers

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Dynamic Programming & Backtracking
// TODO



// * Checks if roober can rob from 'minHouses' which contains atleast 'amount' money
bool isValidCapability(std::vector<int> &nums, int &amount, int minHouses) {
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    // * If current house money is less than or equal than amount then we can rob this house.
    if (minHouses > 0 && nums[i] <= amount) {
      minHouses--;
      i++; // * skip the adjacent house
    }

    // * We have robbed the desired number of homes
    if (minHouses == 0)
      return true;
  }
  return false;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Binary Search on Answers
int minCapability(std::vector<int> &nums, int k) {
  int l = *std::min_element(nums.begin(), nums.end());
  int r = *std::max_element(nums.begin(), nums.end());
  int ans = l;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (isValidCapability(nums, m, k)) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

int main(void) {
  // int k = 2;
  // std::vector<int> nums = {2, 3, 5, 9};

  int k = 2;
  std::vector<int> nums = {2, 7, 9, 3, 1};

  std::cout << "Houses" << std::endl;
  printArr(nums);

  int ans = minCapability(nums, k);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 14-house-robber-iv.cpp -o output && ./output

