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



// * ------------------------------------------------------------------

// * 01 - Find Minimum in Rotated Sorted Array II
// int findMinimum(vector<int> arr) {
// TODO
// }

// * 02 - Split Array Largest Sgum
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

// ! Ignore this problem [Too Difficult]
// * 10 - Maximum Fruits Harvested After at Most K Steps
// int maxTotalFruits(vector<vector<int>> &fruits, int start_pos, int k) {
// TODO
// }

// * 11 - Number of Flowers in Full Bloom
// vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people) {
// TODO
// }

// * 12 - Divide Chocolate  
// int maximizeSweetness(vector<int> &sweetness, int k) {
// TODO
// }

// * 13 - Kth Smallest Product of Two Sorted Arrays
// ll kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, ll k) {
// TODO
// }

// * 14 - Minimize Max Distance to Gas Station 
// long double gasStation(vector<int> gasStations, int k) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

