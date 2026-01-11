/*
 * Leetcode - 845
 * Longest Mountain in Array
 * 
 * You may recall that an array arr is a mountain array if and only if:
 * - arr.length >= 3
 * There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
 * -- arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 * -- arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 * 
 * 
 * Given an integer array arr, return the length of the longest subarray, which is a mountain. 
 * Return 0 if there is no mountain subarray.
 *
 * https://leetcode.com/problems/longest-mountain-in-array/
 * https://www.naukri.com/code360/problems/longest-mountain-subarray_893069
*/

#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Find the peak element and then count on left & right elements
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int longestMountain(std::vector<int> &arr) {
  int n = arr.size();
  int ans = 0;

  // * 1 to n - 2 (only possible peak elements)
  for (int i = 1; i <= n - 2;) {
    // * Greater than both the neighbours
    if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
      int cnt = 1; // * for the peak element

      // * count left of mountain
      int j = i;
      while (j > 0 && arr[j] > arr[j - 1]) {
        j--;
        cnt++;
      }

      // * count right of mountain
      while (i < n - 1 && arr[i] > arr[i + 1]) {
        i++;
        cnt++;
      }
      ans = std::max(ans, cnt);
    }
    else {
      i++;
    }
  }
  
  return ans;
}

int main(void) {
  // * testcase 1
  std::vector<int> nums = {2, 1, 4, 7, 3, 2, 5};

  // * testcase 2
  // std::vector<int> nums = {2, 2, 2, 2};

  std::cout << "Input Array: ";
  printArr(nums);

  int ans = longestMountain(nums);
  std::cout << "Longest Mountain: " << ans << std::endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 23-longest-mountain-in-array.cpp -o output && ./output
