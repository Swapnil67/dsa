/*
* Capacity To Ship Packages Within D Days
* You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. 
* The weights of the packages are given in an array 'weights'.
* The packages must be shipped within 'd' days.
* Find out the least-weight capacity so that you can ship all the packages within 'd' days.

* Example 1:
* Input: nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] days = 5
* Output: least-weight = 15

* Example 2:
* Input: nums = [5, 4, 5, 2, 3, 4, 5, 6], days = 5
* Output: least-weight = 9

* https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
* https://www.codingninjas.com/studio/problems/capacity-to-ship-packages-within-d-days_1229379

*/

#include<map>
#include<iostream>
using namespace std;

// * ------------------------- Utility Function -------------------------`

map<string, int> findMaxWeight(vector<int>weights) {
  int maxWeight = 0, totalWeight = 0;
  for(int i=0; i<weights.size(); i++) {
    totalWeight += weights[i];
    maxWeight = max(maxWeight, weights[i]);
  }
  map<string, int> ans;
  ans["maxWeight"] = maxWeight;
  ans["totalWeight"] = totalWeight;
  return ans;
}

int findRequiredDays(vector<int>weights, int capacity) {
  int days = 1, load = 0;
  for(int i=0; i<weights.size(); i++) {
    if(load + weights[i] > capacity) {
      days = days+1;
      load = weights[i];
    }
    else {
      load = load + weights[i];
    }
  }
  return days;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------

// * TIME COMPLEXITY O((sum-max)+1) * O(N) = O(N^2) 
// * O((sum-max)+1) => [findRequiredDays] 
// * O(N) => [weights array] 
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> weights, int days) {
  map<string, int> ans = findMaxWeight(weights);
  int maxWeight = ans["maxWeight"];
  int totalWeight = ans["totalWeight"];
  
  for(int i=maxWeight; i<=totalWeight; i++) {
    int capacity = i;
    int findDays = findRequiredDays(weights, capacity);
    if(findDays <= days) {
      return capacity;
    }
  }
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY log((sum-max)+1) * O(N)
// * log((sum-max)+1) => [findRequiredDays] 
// * O(N) => [weights array] 

int optimalApproach(vector<int> weights, int days) {
  map<string, int> ans = findMaxWeight(weights);
  int maxWeight = ans["maxWeight"];
  int totalWeight = ans["totalWeight"];

  int low = maxWeight, high = totalWeight;
  int leastCapacity = maxWeight;
  while(low <= high)  {
    int mid = low + (high - low)/2;
    int findDays = findRequiredDays(weights, mid);
    if(findDays <= days) {
      leastCapacity = mid;
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  return leastCapacity;
}


int main() {
  vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int days = 5;
  // int leastCapacity = bruteForce(weights, days);
  int leastCapacity = optimalApproach(weights, days);
  cout<<"leastCapacity Weight: "<<leastCapacity<<endl;
  return 0;
}