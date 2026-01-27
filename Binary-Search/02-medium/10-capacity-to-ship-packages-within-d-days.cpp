/*
* Leetcode - 1011
* Capacity To Ship Packages Within D Days
*
* You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. 
* The weights of the packages are given in an array 'weights'.
* The packages must be shipped within 'd' days.
* Find out the least-weight capacity so that you can ship all the packages within 'd' days.

* Example 1:
* Input: weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] days = 5
* Output: least-weight = 15

* Example 2:
* Input: weights = [5, 4, 5, 2, 3, 4, 5, 6], days = 5
* Output: least-weight = 9

* Example 3:
* Input: weights = [1, 2, 3, 1, 1], days = 4
* Output: least-weight = 3

* https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
* https://www.naukri.com/code360/problems/capacity-to-ship-packages-within-d-days_1229379

*/

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

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

// * O(N) 
bool findIsLeastPossibleWeight(std::vector<int> weights, int maximumDays, long long capacity) {
  int daysTook = 1, totalWeight = 0;
  for (auto &w : weights) {
    // std::cout << "totalWeight " << totalWeight << std::endl;
    if (totalWeight + w > capacity) {
      daysTook++;
      totalWeight = w;
    } else {
      totalWeight += w;
    }
  }
  return daysTook <= maximumDays;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(total - max) * O(N) 
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> weights, int maximumDays) {
  long long maxWeight = *std::max_element(begin(weights), end(weights));
  long long totalWeight = accumulate(weights.begin(), weights.end(), 0);

  for (int i = maxWeight; i <= totalWeight; i++) {
    bool isLeastPossibleWeight = findIsLeastPossibleWeight(weights, maximumDays, i);
    if (isLeastPossibleWeight)
      return i;
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Search Space [MaxWeight, SumOfWeights]
// * TIME COMPLEXITY O(log(total - max)) * O(N) 
// * SPACE COMPLEXITY O(1)
int findLeastPossileWeight(std::vector<int> weights, int maximumDays) {
  long long maxWeight = *std::max_element(begin(weights), end(weights));
  long long totalWeight = accumulate(weights.begin(), weights.end(), 0);

  long long l = maxWeight, r = totalWeight;
  // * O(log(total - max))
  while(l <= r) {
    long long m = l + (r - l) / 2;
    bool isLeastPossibleWeight = findIsLeastPossibleWeight(weights, maximumDays, m);
    if(isLeastPossibleWeight) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return l;
} 

int main() {
  // * testcase 1
  // int days = 5;
  // std::vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  // * testcase 2
  // int days = 5;
  // std::vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
  
  // * testcase 3
  int days = 4;
  std::vector<int> weights = {1, 2, 3, 1, 1};

  std::cout << "days: " << days << std::endl;
  std::cout << "Weights: ";
  printArr(weights);

  // int leastWeight = bruteForce(weights, days);
  int leastWeight = findLeastPossileWeight(weights, days);
  std::cout << "Ship should take atleast " << leastWeight << " weights to transfer all weights in " << days << " days." << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-capacity-to-ship-packages-within-d-days.cpp -o output && ./output