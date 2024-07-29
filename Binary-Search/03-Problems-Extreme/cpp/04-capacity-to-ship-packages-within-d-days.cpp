/*
* Capacity To Ship Packages Within D Days
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

* https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
* https://www.naukri.com/code360/problems/capacity-to-ship-packages-within-d-days_1229379

*/

#include<map>
#include<iostream>


// * ------------------------- Utility Functions -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * Returns the max and sum
std::map<std::string, int> findMaxWeight(std::vector<int> &weights) {
  std::map<std::string, int> ans;
  int maxW = 0, sumWeights = 0;
  for (int i = 0; i < weights.size(); i++) {
    sumWeights += weights[i];
    maxW = std::max(maxW, weights[i]);
  }
  ans["maxW"] = maxW;
  ans["sumWeights"] = sumWeights;
  return ans;
}

// * O(N) 
bool findIsLeastPossibleWeight(std::vector<int> weights, int maximumDays, long long capacity) {  
  int daysTook = 1, totalWeight = 0;
  for (int i = 0; i < weights.size(); i++) {
    // std::cout << "totalWeight " << totalWeight << std::endl;
    if(totalWeight + weights[i] > capacity) {
      daysTook++;
      totalWeight = weights[i];
    }
    else {
      totalWeight += weights[i];
    }
  }
  if(daysTook <= maximumDays) return true;
  return false;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(total - max) * O(N) 
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> weights, int maximumDays) {
  std::map<std::string, int> ans = findMaxWeight(weights);
  long long maxWeight = ans["maxW"]; 
  long long totalWeight = ans["sumWeights"]; 
  for(int i=maxWeight; i<=totalWeight; i++) {
    bool isLeastPossibleWeight = findIsLeastPossibleWeight(weights, maximumDays, i);
    if(isLeastPossibleWeight) return i;
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Search Space [MaxWeight, SumOfWeights]
// * TIME COMPLEXITY O(log(total - max)) * O(N) 
// * SPACE COMPLEXITY O(1)
int findLeastPossileWeight(std::vector<int> weights, int maximumDays) {
  std::map<std::string, int> ans = findMaxWeight(weights);
  long long maxWeight = ans["maxW"]; 
  long long totalWeight = ans["sumWeights"]; 
  long long l = maxWeight, r = totalWeight;
  // * O(log(total - max))
  while(l <= r) {
    long long m = l + (r - l) / 2;
    bool isLeastPossibleWeight = findIsLeastPossibleWeight(weights, maximumDays, m);
    if(isLeastPossibleWeight) {
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return l;
} 

int main() {
  // * testcase 1
  std::vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int days = 5;
  // * testcase 2
  // std::vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
  // int days = 5;

  printArr(weights);
  // int leastWeight = bruteForce(weights, days);
  int leastWeight = findLeastPossileWeight(weights, days);
  std::cout << "Ship should take atleast " << leastWeight << " weights to transfer all weights in " << days << " days." << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-capacity-to-ship-packages-within-d-days.cpp -o 04-capacity-to-ship-packages-within-d-days && ./04-capacity-to-ship-packages-within-d-days