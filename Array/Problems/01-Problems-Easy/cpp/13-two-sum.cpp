/**
 * * Two Sum
 * * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * * You may assume that each input would have exactly one solution, and you may not use the same element twice.

 * * Example 1
 * * Input  : target = 5, nums = [4, 1, 2, 3, 1] 
 * * Output : 3

 * * https://leetcode.com/problems/two-sum/description/
 * * https://www.naukri.com/code360/problems/reading_6845742
*/

#include<map>
#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<int>arr, int target) {
  int n = arr.size();
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      if(i == j) continue;
      if(arr[i] + arr[j] == target) {
        // std::cout << "i " << i << " j " << j << " = " << arr[i] + arr[j] << std::endl;
        return { i, j }
      }
    }
  }
  return {};
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Optimal Approach for index of array
// * Map Data Structure
// * TIME COMPLEXITY O(NlogN) [Ordered Map]
// * TIME COMPLEXITY O(N) [Best Case UnOrderd Map] or O(N^2) [Worst Case UnOrdered Map]
// * SPACE COMPLEXITY O(N)
std::vector<int> betterApproach(std::vector<int> arr, int target) {
  std::vector<int> ans;
  int n = arr.size();
  std::map<int, int> eleMap;
  for (int i = 0; i < n; i++) {
    int rem = target - arr[i];
    if (eleMap.find(rem) != eleMap.end()) {
      // * Found the sum 
      // std::cout<<"i "<<eleMap[rem]<<", j "<<i<<" = "<<arr[i] + eleMap[rem]<<std::endl;
      return {hash[rem], i};
    }
    eleMap[arr[i]] = i;
  }
  return {-1, -1};
}


// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * Optimal Approach for return true|false is sum exists in array
// * Two Pointer
// * TIME COMPLEXITY O(N) + O(NlogN) [Sorting]
// * SPACE COMPLEXITY O(1)
bool optimalApproach(std::vector<int> arr, int target) {
  sort(arr.begin(), arr.end());
  std::vector<int> ans;

  printArr(arr);
  int l = 0, r = arr.size() - 1;

  while(l <= r) {
    int sum = arr[l] + arr[r];
    if(sum == target) {
      return true;
    }
    if(sum > target) {
      r--;
    }
    else {
      l++;
    }

  }
  return false;
}


int main() {
  int target = 9;
  // std::vector<int> arr = {2, 15, 11, 4};
  std::vector<int> arr = {2, 15, 11, 7};

  // std::vector<int> ans = bruteForce(arr, target);
  // std::vector<int> ans = betterApproach(arr, target);
  // printArr(ans);

  // * Note that this does not returs the index  
  // bool ans = optimalApproach(arr, target);
  // std::cout<<"Sum found "<<ans<<std::endl;


  return 0;
}

// * Run the code
// * g++ --std=c++17 13-two-sum.cpp -o 13-two-sum && ./13-two-sum