#include <vector>
#include <climits>
#include <numeric>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * 01 - Find Minimum in Rotated Sorted Array II
// int findMinimum(std::vector<int> arr) {
// TODO
// }

// * 02 - Split Array Largest Sum
// int splitArray(std::vector<int> &nums, int k) {
// TODO
// }

// * 03 - Painter's Partition Problem
// int findMinTimeToPaintBoards(std::vector<int> &boards, int painters) {
// TODO
// }

void mergeSort(std::vector<int> &nums1, std::vector<int> &nums2,
               int &idx1, int &idx2,
               int &ele1, int &ele2)
{
  int n1 = nums1.size(), n2 = nums2.size();
  int i = 0, j = 0;
  int cnt = 0;
  while(i < n1 && j < n2) {
    if (nums1[i] < nums2[j]) {
      if (cnt == idx1) ele1 = nums1[i];
      if (cnt == idx2) ele2 = nums1[i];
      i++;
    } else {
      if (cnt == idx1) ele1 = nums2[j];
      if (cnt == idx2) ele2 = nums2[j];
      j++;
    }
    cnt++;
  }
  
  while (i < n1) {
    if (cnt == idx1) ele1 = nums1[i];
    if (cnt == idx2) ele2 = nums1[i];
    i++;
    cnt++;
  }
  
  while (j < n2) {
    if (cnt == idx1) ele1 = nums2[j];
    if (cnt == idx2) ele2 = nums2[j];
    j++;
    cnt++;
  }

}

double findMedian(std::vector<int> &nums1, std::vector<int> &nums2) {
  int ele1 = -1, ele2 = -1;
  int n1 = nums1.size(), n2 = nums2.size();
  int n = n1 + n2;
  int idx1 = (n - 1) / 2, idx2 = n / 2;
  mergeSort(nums1, nums2, idx1, idx2, ele1, ele2);

  if (n % 2 == 1) {
    return ele2 / 2;
  }

  std::cout << idx1 << " " << idx2 << std::endl;
  std::cout << ele1 << " " << ele2 << std::endl;

  return (ele1 + ele2) / (double)2;
}

int main(void) {
  // std::vector<int> nums1 = {1, 3, 4, 7, 10, 12}, nums2 = {2, 3, 6, 15};
  // std::vector<int> nums1 = {7, 12, 14, 15}, nums2 = {1, 2, 3, 4, 9, 11};
  std::vector<int> nums1 = {1, 2}, nums2 = {3, 4};

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
// * g++ --std=c++17 practice.cpp -o output && ./output