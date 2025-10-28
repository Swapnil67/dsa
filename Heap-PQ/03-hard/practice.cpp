#include <queue>
#include <stack>
#include <vector>
#include <math.h>
#include <cfloat>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * -----------------------------------------------------------------------------

// * 01 - Find Median from Data Stream
// class MedianFinder {
// public:
//   MedianFinder() {
//   }
//   void addNum(int num) {
//   }
//   double findMedian() {
//   }
// };

// * 02 - Minimize Deviation in Array
// int minimumDeviation(std::vector<int> &nums) {
// TODO
// }

// * 03 - Maximum Performance of a Team
// int maxPerformance(int n,
//                    std::vector<int> &speed,
//                    std::vector<int> &efficiency, int k)
// {
// TODO 
// }

// * 04 - IPO
// int findMaximizedCapital(int k, int w,
//                          std::vector<int> &profits,
//                          std::vector<int> &capital)
// {
// TODO
// }

// * 05 - Minimum Cost to Hire K Workers
// double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
// TODO  
// }

// * 06 - Number of Flowers in Full Bloom
// std::vector<int> fullBloomFlowers(std::vector<std::vector<int>> &flowers, std::vector<int> &people) {
// TODO
// }

// * 07 - Constrained Subsequence Sum
// int constrainedSubsetSum(std::vector<int>& nums, int k) {
// TODO
// }

// * 08 - Find Building Where Alice and Bob Can Meet
// std::vector<int> leftmostBuildingQueries(
//     std::vector<int> &heights,
//     std::vector<std::vector<int>> &queries)
// {
// TODO
// }

// * 09 - Sliding Window Median
std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) { 
}

int main(void) {
  // * testcase 1
  int k = 3;
  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  
  // * testcase 2
  // int k = 3;
  // std::vector<int> nums = {1, 2, 3, 4, 2, 3, 1, 4, 2};

  std::cout << "Nums: ";
  printArr(nums);

  std::vector<double> ans = medianSlidingWindow(nums, k);
  std::cout << "Sliding Window Median: ";
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output