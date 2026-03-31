#include <queue>
#include <vector>
#include <climits>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArr(vector<T> &nums) {
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

typedef long long ll;

// * 01 - Find Minimum in Rotated Sorted Array II
// int findMinimum(vector<int> arr) {
// TODO
// }

// * 02 - Split Array Largest Sum
// int splitArray(vector<int> &nums, int k) {
// TODO
// }

// * 03 - Painter's Partition Problem
// int findMinTimeToPaintBoards(vector<int> &boards, int painters) {
// TODO
// }
  
// * 04 - Find K-th Smallest Pair Distance
// int smallestDistancePair(vector<int> &nums, int k) {
// TODO
// }
  
// * 05 - Median of Two Sorted Arrays
// double findMedian(vector<int> &nums1, vector<int> &nums2) {
// TODO
// }

// * 06 - K-th Element of Two Sorted Arrays
// int kthElement(vector<int> &nums1, vector<int> &nums2, int k) {
// TODO
// }

// * 07 - Find in Mountain Array
// int findInMountainArray(int target, MountainArray &mountainArr) {
// TODO Solve this on leetcode
// }

// * 09 - Kth Smallest Product of Two Sorted Arrays
// ll kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, ll k) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

