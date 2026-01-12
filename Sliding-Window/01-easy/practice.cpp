// * Sliding Window Easy

#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

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
  
// * -------------------------------------------------------------------------------------------

// * 01 - Contains Duplicate II
// bool containsNearbyDuplicate(std::vector<int> &arr, int k) {
// TODO
// }

// * 02 - Max Sum Subarray of size K
// int maxSumOfKSubarray(std::vector<int> &arr, int k) {
// TODO
// }

// * 03 - Minimum Recolors to Get K Consecutive Black Blocks
// int minimumRecolors(std::string blocks, int k) {
// TODO
// }

// * 04 - Defuse the Bomb
// std::vector<int> decrypt(std::vector<int> &code, int k) {
// TODO
// }

// * 05 - Minimum Difference Between Highest and Lowest of K Scores
// int minimumDifference(std::vector<int> &nums, int k) {
// TODO
// }

// * 06 - Chocolate Distribution Problem
// int minimumDifference(std::vector<int> &nums, int k) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o output && ./output