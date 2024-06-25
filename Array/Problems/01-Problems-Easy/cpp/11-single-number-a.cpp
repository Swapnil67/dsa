/**
 * * Single Number
 * * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

 * * Example 1
 * * Input  : 'arr' = [7, 3, 5, 4, 5, 3, 4]
 * * Output : 7

 * * Example 2
 * * Input  : 'arr' = [5, 6, 9, 6, 1, 9, 1, 5, 3]
 * * Output : 4
 * 
 * * Example 3
 * * Input  : 'arr' = [1]
 * * Output : 1

 * * https://leetcode.com/problems/single-number/description/
 * * https://www.naukri.com/code360/problems/occurs-once_1214969
*/

// ! Array is not sorted

#include<map>
#include<iostream>

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int numCount = 0, num = arr[i];
    for (int j = 0; j < n; j++) {
      if(arr[j] == num) {
        numCount++;
      }
    }
    if(numCount == 1) {
      return num;
    }
  }
  return 0;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * Map Data Structure
// * TIME COMPLEXITY O(NlogM) + O(N/2)+1
// * M = size of the map
// * SPACE COMPLEXITY O(N/2)+1
int betterApproach(std::vector<int> arr) {
  std::map<int, int> numMap;
  int n = arr.size();
  // * O(NlogM)
  for(int i=0; i<n; i++) {
    numMap[arr[i]]++;
  }

  // * O(N/2) + 1
  for(auto it: numMap) {
    if(it.second == 1) return it.first;
  }

  return 0;
}

// * ------------------------- APPROACH 3: Optimal A APPROACH -------------------------`
// * XOR Method [For UnSorted Array] with duplicates existing only twice
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int optimalApproach(std::vector<int> arr) {
  int xr = 0;
  for(int i=0; i<arr.size(); i++) {
    xr = xr ^ arr[i];
    // std::cout<<"xr "<<xr<<std::endl;
  }
  return xr;
}


int main() {
  // std::vector<int> arr = {5, 6, 9, 6, 1, 9, 1, 5, 3};
  std::vector<int> arr = {7, 3, 5, 4, 5, 3, 4};
  // int singleNumber = bruteForce(arr);
  // int singleNumber = betterApproach(arr);
  int singleNumber = optimalApproach(arr);
  std::cout<<"Single Number "<<singleNumber<<std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 11-single-number-a.cpp -o 11-single-number-a && ./11-single-number-a