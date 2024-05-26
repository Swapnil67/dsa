/**
 * * Single Number
 * * Array is sorted
 * * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

 * * Example 1
 * * Input  : 'arr' = [3,3,7,7,10,11,11]
 * * Output : 10

 * * Example 2
 * * Input  : 'arr' = [1,1,2,3,3,4,4,8,8]
 * * Output : 2
 * 
 * * Example 3
 * * Input  : 'arr' = [1]
 * * Output : 1

 * * https://leetcode.com/problems/single-element-in-a-sorted-array/
 * * https://www.naukri.com/code360/problems/find-the-single-element_6680465
*/

#include<map>
#include<iostream>

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) {
    int numCount = 0, num = arr[i];
    for(int j = 0; j<n; j++) {
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

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * Binary Search [For Sorted Array]
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int optimalApproach(std::vector<int> arr) {
  int l = 0, r = arr.size()-1;

  // * Boundary Cases
  if(r == 0)
    return arr[0];
  else if(arr[0] != arr[1]) 
    return arr[0];
  else if(arr[r] != arr[r-1])
    return arr[r];
  
  while(l <= r) {
    int mid = l+(r-l)/2;
    // * Unique Element
    if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]) {
      return arr[mid];
    }

    // * Check which side to exclude
    if(((mid%2 == 0) && arr[mid] == arr[mid+1]) || ((mid%2 == 1) && arr[mid] == arr[mid-1])) { 
      l = mid+1;
    }
    else {
      r = mid-1;
    }
  }
  return 0;
}


int main() {
  std::vector<int> arr = { 1, 1, 2, 3, 3, 4, 4 };
  // std::vector<int> arr = { 1, 1, 2, 2, 3, 3, 6, 6, 7, 9, 9 };
  // int singleNumber = bruteForce(arr);
  // int singleNumber = betterApproach(arr);
  int singleNumber = optimalApproach(arr);
  std::cout<<"Single Number "<<singleNumber<<std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 11-single-number-b.cpp -o 11-single-number-b && ./11-single-number-b