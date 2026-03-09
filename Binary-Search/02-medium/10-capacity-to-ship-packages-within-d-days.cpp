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

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * O(N) 
bool findIsLeastPossibleWeight(vector<int> weights, int maximumDays, long long capacity) {
  int daysTook = 1, totalWeight = 0;
  for (auto &w : weights) {
    // cout << "totalWeight " << totalWeight << endl;
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
int bruteForce(vector<int> weights, int maximumDays) {
  long long maxWeight = *max_element(begin(weights), end(weights));
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
int findLeastPossileWeight(vector<int> weights, int maximumDays) {
  long long l = *max_element(begin(weights), end(weights));
  long long r = accumulate(weights.begin(), weights.end(), 0);
  // * O(log(total - max))
  int ans = r;
  while (l <= r) {
    long long m = l + (r - l) / 2;
    bool is_valid = findIsLeastPossibleWeight(weights, maximumDays, m);
    if (is_valid) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
} 

int main() {
  // * testcase 1
  // int days = 5;
  // vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  // * testcase 2
  int days = 5;
  vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
  
  // * testcase 3
  // int days = 4;
  // vector<int> weights = {1, 2, 3, 1, 1};

  cout << "days: " << days << endl;
  cout << "Weights: ";
  printArr(weights);

  // int leastWeight = bruteForce(weights, days);
  int leastWeight = findLeastPossileWeight(weights, days);
  cout << "Ship should take atleast " << leastWeight << " weights to transfer all weights in " << days << " days." << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-capacity-to-ship-packages-within-d-days.cpp -o output && ./output