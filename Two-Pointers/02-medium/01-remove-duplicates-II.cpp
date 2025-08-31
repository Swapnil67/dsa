/*
 * Leetcode - 80
 * Remove Duplicates from Sorted Array II
 * Here each unique element must appear atmost twice. The relative order of the elements should be kept the same.
 * 
 * Example 1
 * Input  : nums = [1,1,1,2,2,3]
 * Output : 5, nums = [1,1,2,2,3,_]
 * 
 * Example 2
 * Input  : nums = [0,0,1,1,1,1,2,3,3]
 * Output : 7, nums = [0,0,1,1,2,3,3,_,_]

 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Map Data Structure
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int bruteForce(std::vector<int> &arr) {
  int n = arr.size(), c = 0;
  std::unordered_map<int, int> countMap;
  
  for (int i = 0; i < n; ++i) {
    int val = arr[i];
    if (countMap.count(val) && countMap[val] >= 2) {
      // * ignore element
      continue;
    }
    else {
      arr[c] = val;
      c++;
      countMap[val]++;
    }
  }

  // * For debugging
  // for(auto it: cmap) {
  //   std::cout << it.first << " " << it.second << std::endl;
  // }
  return c;
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * count the duplicates & loop over duplicates
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int removeDuplicates(std::vector<int> &arr) {
  int n = arr.size();
  int i = 0, j = 0;

  while(j < n) {
    int c = 1;
    // * count the duplicates
    while ((j + 1) < n && arr[j] == arr[j + 1]) {
        c++;
        j++;
    }

    // * loop over duplicates
    for (int k = 0; k < std::min(2, c); ++k) {
        arr[i] = arr[j];
        i++;
    }
    j++;
  }
  return i;
}

int main() {
  // std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  std::vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  // std::vector<int> nums = {1, 1};
  // std::vector<int> nums = {1, 2, 2};
  
  printArr(nums);
  // int ans = bruteForce(nums);
  int ans = removeDuplicates(nums);
  std::cout << ans << std::endl;
  printArr(nums);
  return 0;
}

// * Run the code
// * g++ --std=c++17 01-remove-duplicates-II.cpp -o output && ./output