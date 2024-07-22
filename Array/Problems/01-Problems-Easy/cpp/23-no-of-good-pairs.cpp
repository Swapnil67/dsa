/**
 * * Number of Good Pairs
 * * Given an array of integers nums, return the number of good pairs.
 * * A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 * * Example 1
 * * Input  : nums = [1,2,3,1,1,3]
 * * Output : 4
 * * Explanation : There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed. 
 * 
 * * Example 2
 * * Input  : nums = [1,1,1,1]
 * * Output : 6
 * * Explanation : Each pair in the array are good.

 * * Example 3
 * * Input  : nums = [1,2,3]
 * * Output : 0
 * 
 * * https://leetcode.com/problems/number-of-good-pairs/description/
*/

#include<unordered_map>
#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size(), c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if(arr[i] == arr[j]) {
        c++;
      }
    }
  }
  return c;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
int betterApproach(std::vector<int> arr) {
  int n = arr.size(), c = 0;
  // * number -> count
  std::unordered_map<int, int> countMap;
  // * O(N)
  for (int i = 0; i < n; i++) {
    countMap[arr[i]]++;
  }
  // * O(N)
  for (auto it : countMap) {
    c += (it.second * (it.second - 1)) / 2;
  }
  return c;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int numIdenticalPairs(std::vector<int> arr) {
  int n = arr.size(), c = 0;
  // * number -> count
  std::unordered_map<int, int> countMap;
  // * O(N)
  for (int i = 0; i < n; i++) {
    int cur = arr[i];
    if(countMap.find(cur) != countMap.end()) {
      // std::cout << cur << " => " << countMap[cur] << std::endl;
      c += countMap[cur];
    }
    countMap[cur]++;
  }
  return c;
}

int main() {
  std::cout << "Input Array" << std::endl;
  // * testcase 1
  std::vector<int> arr = {1, 2, 3, 1, 1, 3};
  // * testcase 2
  // std::vector<int> arr = {1, 1, 1, 1};
  // * testcase 3
  // std::vector<int> arr = {1, 2, 3};

  printArr(arr);

  // int ans = bruteForce(arr);
  // int ans = betterApproach(arr);
  int ans = numIdenticalPairs(arr);
  std::cout << "Number of Good Pairs " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 23-no-of-good-pairs.cpp -o 23-no-of-good-pairs && ./23-no-of-good-pairs