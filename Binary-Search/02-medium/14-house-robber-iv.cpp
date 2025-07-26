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
  printArr(nums);

  int ans = minCapability(nums, k);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 14-house-robber-iv.cpp -o output && ./output

