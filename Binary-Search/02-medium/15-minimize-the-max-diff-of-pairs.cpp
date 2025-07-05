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

// * A function to check abs difference of how many pairs is equal to pairDiff
// * return true if we found no. of pairs greater than maxPairs
bool isValid(std::vector<int> &nums, int maxPairs, int pairDiff) {
  int n = nums.size();
  int curPairs = 0;
  int i = 0;
  while (i < n - 1) {
    if (curPairs >= maxPairs)
      return true;
    int curDiff = nums[i + 1] - nums[i];
    if(curDiff <= pairDiff) {
      i += 2;
      curPairs++;
    } else {
      i += 1;
    }
  }

  // std::cout << curPairs << " " << maxPairs << std::endl;
  return curPairs >= maxPairs;
}

// * ------------------------- APPROACH : Optimal APPROACH -------------------------
// * TIME COMPLEXITY n * O(logm)
// * SPACE COMPLEXITY O(1)
int minimizeMax(std::vector<int> &nums, int p) {
  int n = nums.size();
  
  // * sort the nums to get min diff b/w pairs
  std::sort(nums.begin(), nums.end());
  int l = 0, r = nums[n - 1] - nums[0];

  int ans = 0;
  while (l <= r) {           // * O(logm) 'm' = nums[n - 1] - nums[0]
    int m = l + (r - l) / 2;
    if(isValid(nums, p, m)) {   // * O(N)
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
  // * testcase 1
  int p = 2;
  std::vector<int> nums = {10, 1, 2, 7, 1, 3};
  
  // * testcase 2
  // int p = 1;
  // std::vector<int> nums = {4, 2, 1, 2};

  printArr(nums);

  int ans = minimizeMax(nums, p);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 15-minimize-the-max-diff-of-pairs.cpp -o output && ./output

