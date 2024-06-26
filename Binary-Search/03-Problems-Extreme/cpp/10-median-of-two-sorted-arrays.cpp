/*
* Given two sorted arrays nums1 and nums2 of size m and n respectively,
* return the median of the two sorted arrays.

* Example 1:
* Input: nums1 = [1,2], nums2 = [3,4]
* Output: 2.5
* Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5

* Example 2:
* Input: nums1 = [1, 3, 4, 7, 10, 12], nums2 = [2, 3, 6, 15]
* Output: 5
* Explanation: merged array = [1,2,3,3,4,6,7,10,12,15] and median is (6 + 4) / 2 = 5

* https://leetcode.com/problems/median-of-two-sorted-arrays/description/ 

*/

#include<iostream>

// * ------------------------- Utility Functions -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

std::vector<int> mergeTwoSortedArrays(std::vector<int> arr1, std::vector<int> arr2) {
  int n1 = arr1.size(), n2 = arr2.size();
  std::vector<int> ans;
  int i = 0, j = 0;
  while(i < n1 && j < n2) {
    if(arr1[i] <= arr2[j])
      ans.push_back(arr1[i++]);
    else
      ans.push_back(arr2[j++]);
  }

  // * Put the remaining elements for arr1 
  while(i < n1) {
    ans.push_back(arr1[i++]);
  }

  // * Put the remaining elements for arr2
  while(j < n2) {
    ans.push_back(arr2[j++]);
  }

  return ans;
}

std::vector<int> returnMedianPositions(std::vector<int> arr1, std::vector<int> arr2) {
  int n1 = arr1.size(), n2 = arr2.size();
  int i = 0, j = 0, cnt = 0;
  int idx1 = (n1 + n2) / 2, idx2 = (n1 + n2 - 1) / 2;
  int ele1 = -1, ele2 = -1;
  while(i < n1 && j < n2) {
    if(arr1[i] < arr2[j]) {
      if(cnt == idx1) ele1 = arr1[i];
      if(cnt == idx2) ele2 = arr1[i];
      cnt++;
      i++;
    }
    else {
      if(cnt == idx1) ele1 = arr2[j];
      if(cnt == idx2) ele2 = arr2[j];
      cnt++;
      j++;
    }
  }

  while(i < n1) {
    if(cnt == idx1) ele1 = arr1[i];
    if(cnt == idx2) ele2 = arr1[i];
    cnt++;
    i++; 
  }

  while(j < n2) {
    if(cnt == idx1) ele1 = arr2[j];
    if(cnt == idx2) ele2 = arr2[j];
    cnt++;
    j++;
  }
  return { ele1, ele2 };
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Merge two sorted arrays
// * TIME COMPLEXITY O(n1 + n2)
// * SPACE COMPLEXITY O(n1 + n2)
double bruteForce(std::vector<int> arr1, std::vector<int> arr2) {
  std::vector<int> mergedArr = mergeTwoSortedArrays(arr1, arr2);
  int mergedSize = mergedArr.size();
  if (mergedSize % 2 == 1) {
    // * Even Arr
    return mergedArr[mergedSize / 2];
  }
  else {
    // * Odd Arr
    return (double)((double)mergedArr[mergedSize / 2] + double(mergedArr[mergedSize / 2 - 1])) / 2.0;
  }
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * Not using extra array (Merged Array)
// * TIME COMPLEXITY O(n1+n1) * O(N) 
// * SPACE COMPLEXITY O(1)
double betterApproach(std::vector<int> arr1, std::vector<int> arr2) {
  int n1 = arr1.size(), n2 = arr2.size();
  int n = n1+n2;

  std::vector<int> values = returnMedianPositions(arr1, arr2);
  int ele1 = values[0], ele2 = values[1];

  if(n % 2 == 1) {
    return ele1;
  }
  return (double)((double)(ele1 + ele2) / 2.0);
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * Find Valid Symmetry
double findMedian(std::vector<int> arr1, std::vector<int> arr2) {
  int n1 = arr1.size(), n2 = arr2.size();
  if(n1 > n2) findMedian(arr2, arr1);
  int left = (n1 + n2 + 1) / 2;
  int n = n1 + n2;
  // std::cout << " left " << left << std::endl;
  // std::cout << " n1 " << n1 << " n2 " << n2 << std::endl;

  int l = 0, r = n1;
  while(l <= r) {
    int m1 = (l + r) >> 2;
    int m2 = left - m1;
    std::cout << " m1 " << m1 << " m2 " << m2 << std::endl;

    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;
    if (m1 - 1 >= 0)
      l1 = arr1[m1 - 1];
    if (m2 - 1 >= 0)
      l2 = arr2[m2 - 1];
    if (m1 < n1)
      r1 = arr1[m1];
    if(m2 < n2)
      r2 = arr2[m2];

    if (l1 <= r2 && l2 <= r1) {
      if(n % 2 == 1) {
        return std::max(l1, l2);
      }
      else {
        // std::cout << " l1 " << l1 << " l2 " << l2 << std::endl;
        // std::cout << " r1 " << r1 << " r2 " << r2 << std::endl;
        return ((double)(std::max(l1, l2) + std::min(r1, r2))) / 2.0;
      }
    }
    else if(l1 > r2) {
      r = m1 - 1;
    }
    else {
      l = m1 + 1;
    }
  }
  return 0;
}

int main() {
  std::vector<int> nums1 = {1, 3, 4, 7, 10, 12}, nums2 = {2, 3, 6, 15};
  // std::vector<int> nums1 = {7, 12, 14, 15}, nums2 = {1, 2, 3, 4, 9, 11};
  // std::vector<int> nums1 = {1, 2}, nums2 = {3, 4};
  std::cout << "First Array" << std::endl;
  printArr(nums1);
  std::cout << "Second Array" << std::endl;
  printArr(nums2);


  // double median = bruteForce(nums1, nums2);
  // double median = betterApproach(nums1, nums2);
  double median = findMedian(nums1, nums2);
  std::cout << "Median of two sorted array is " << median << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 10-median-of-two-sorted-arrays.cpp -o 10-median-of-two-sorted-arrays && ./10-median-of-two-sorted-arrays