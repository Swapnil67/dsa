/**
 * * Leetcode - 217
 * * Contains Duplicate
 * * Given an integer array nums, return true if any value appears at least twice in the array, and return false if
 * * every element is distinct.

 * * Example 1
 * * Input  : nums = [1,2,3,1]
 * * Output : true

 * * Example 2
 * * Input  : nums = [1,2,3,4]
 * * Output : false

 * * https://leetcode.com/problems/contains-duplicate/description/
*/

#include <set>
#include <vector>
#include <iostream>
#include <unordered_map>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Hashmap to Count
// * TIME COMPLEXITY O(N) + O(N)
// * SPACE COMPLEXITY O(N)
bool bruteForce(std::vector<int> &nums) {
  std::unordered_map<int, int> countMap;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    countMap[nums[i]]++;
  }

  // * loop over count map
  for(auto it : countMap) {
    if(it.second > 1) {
      return true;
    }
  }
  return false;
} 

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------`
// * Set Data Structure
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
bool containsDuplicate(std::vector<int> &nums) {
  std::set<int> st;
  for (int i = 0; i < nums.size(); i++) {
    if (st.find(nums[i]) != st.end()) {
      return true;
    }
    st.insert(nums[i]);
  }
  return false;
}

int main() {
  // std::vector<int> arr = {1, 2, 3, 4};
  std::vector<int> arr = {1, 2, 3, 1};
  std::cout<<"Input Array "<<std::endl;
  printArr(arr);
  bool isDuplicate = bruteForce(arr);
  // bool isDuplicate = containsDuplicate(arr);
  std::cout<<"Does array contains duplicate "<<isDuplicate<<std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 14-contains-duplicate.cpp -o 14-contains-duplicate && ./14-contains-duplicate