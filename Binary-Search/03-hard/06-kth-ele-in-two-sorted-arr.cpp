/*
* K-th Element of Two Sorted Arrays
* Given two sorted arrays nums1 and nums2 of size m and n respectively,
* return the kth element.

* Example 1:
* Input: nums1 = [2, 3, 45], nums2 = [4, 6, 7, 8]
* Output: 6

* https://www.naukri.com/code360/problems/k-th-element-of-2-sorted-array_1164159
*/

#include <vector>
#include <iostream>

// * ------------------------- Utility Functions -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Merge two sorted arrays
// * TIME COMPLEXITY O(n1 + n2)
// * SPACE COMPLEXITY O(n1 + n2)
int bruteForce(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
  int n1 = nums1.size(), n2 = nums2.size();
  if (k > n1 + n2)
    return -1;

  std::vector<int> mergedVec;
  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    if (nums1[i] < nums2[j]) {
      mergedVec.push_back(nums1[i]);
      i++;
    } else {
      mergedVec.push_back(nums2[j]);
      j++;
    }
  }

  while (i < n1) {
    mergedVec.push_back(nums1[i]);
    i++; 
  }

  while (j < n2) {
    mergedVec.push_back(nums2[j]);
    j++;
  }

  // printArr(mergedVec);

  return mergedVec[k - 1];
}


// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * Not using extra array (Merged Array)
// * TIME COMPLEXITY O(n1 + n2)
// * SPACE COMPLEXITY O(1)
int kthElement(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
  int n1 = nums1.size(), n2 = nums2.size();
  if (k > n1 + n2)
    return -1;

  int cnt = 1;
  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    if (nums1[i] < nums2[j]) {
      if (cnt == k)
        return nums1[i];
      i++;
    } else {
      if (cnt == k)
        return nums2[j];
      j++;
    }
    cnt++;
  }

  while (i < n1) {
    if (cnt == k)
      return nums1[i];
    i++; 
    cnt++;
  }

  while (j < n2) {
    if (cnt == k)
      return nums2[j];
    j++;
    cnt++;
  }

  return -1;
}

int main(void) {
  int k = 4;
  std::vector<int> nums1 = {2, 3, 45}, nums2 = {4, 6, 7, 8};

  std::cout << "First Array" << std::endl;
  printArr(nums1);
  std::cout << "Second Array" << std::endl;
  printArr(nums2);

  // int ans = bruteForce(nums1, nums2, k);
  int ans = kthElement(nums1, nums2, k);
  std::cout << "Kth element: " << ans << std::endl;
  
  return 0;
}


// * Run the code
// * g++ --std=c++20 06-kth-ele-in-two-sorted-arr.cpp -o output && ./output
