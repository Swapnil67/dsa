/*
* Leetcode - 718
* Maximum Length of Repeated Subarray

* Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

* Example 1 
* Input        : nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
* Output       : 3
* Explanation  : The repeated subarray with maximum length is [3,2,1].

* Example 2
* Input   : nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
* Output  : 5
* Explanation  : The repeated subarray with maximum length is [0,0,0,0,0].

* https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
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

bool check_subarray_exists(std::vector<int> &subarr, std::vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    if (subarr[i] == nums[i]) {
      while (i < subarr.size()) {
        if (subarr[i] == nums[i]) 
          i++;
        else 
          return false;
      }
      break;
    }
  }
  return true;
}

int findLength(std::vector<int> &nums1, std::vector<int> &nums2) {
  int n1 = nums1.size();
  int ans = 0;
  for (int i = 0; i < n1; ++i) {
    std::vector<int> temp;
    for (int j = i; j < n1; ++j) {
      temp.push_back(nums1[j]);
      if (check_subarray_exists(temp, nums2)) {
        printArr(temp);
        std::cout << j - i << std::endl;
        ans = std::max(ans, (j - i));
      }
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // std::vector<int> nums1 = {1, 2, 3, 2, 1};
  // std::vector<int> nums2 = {3, 2, 1, 4, 7};

  // * testcase 2
  std::vector<int> nums1 = {0, 0, 0, 0, 0};
  std::vector<int> nums2 = {0, 0, 0, 0, 0};

  std::cout << "nums1: ";
  printArr(nums1);

  std::cout << "nums2: ";
  printArr(nums2);

  int ans = findLength(nums1, nums2);
  std::cout << "Ans: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 34-max-length-of-repeated-subarr.cpp -o output && ./output
