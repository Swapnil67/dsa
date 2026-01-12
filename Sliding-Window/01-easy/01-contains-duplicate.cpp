/**
 * * Leetcode - 219
 * * Contains Duplicate II
 * * Given an integer array nums and an integer k, return true if there are two distinct 
 * * indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
 * 
 * * Example 1
 * * Input  : nums = [1,2,3,1], k = 3
 * * Output : true

 * * Example 2
 * * Input  : nums = [1,0,1,1], k = 1
 * * Output : true

 * * Example 3
 * * Input  : nums = [1,2,3,1,2,3], k = 2
 * * Output : false

 * * https://leetcode.com/problems/contains-duplicate-ii/description/
 * * https://www.naukri.com/code360/problems/check-duplicate_763405
*/

// ! Amazon, Google, Meta, Microsoft, Apple, Adobe

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Keep the hashmap of occurences of elements
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
bool bruteForce(std::vector<int> &arr, int &k) {
  int n = arr.size();
  std::unordered_map<int, int> hash_map;
  for (int i = 0; i < n; i++) {
    int val = arr[i];
    // * check if value already seen
    if (hash_map.count(val)) {
      // * Check the condition valid within window of 'k'
      if (std::abs(i - hash_map[val]) <= k)
        return true;
    }
    // * update the index of value
    hash_map[val] = i;
  }
  return false;
} 

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------`
// * Sliding window Approach
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
bool containsNearbyDuplicate(std::vector<int> &arr, int &k) {
  int n = arr.size(), i = 0, j = 0;
  std::unordered_set<int> st;
  while (j < n) {
    // * Check is in window
    if (std::abs(i - j) > k) {
        st.erase(arr[i]);
        i++;
    }
    
    // * Check if we have already seen ele in past
    if (st.count(arr[j])) {
      return true;
    }

    // * Add the element to set
    st.insert(arr[j]);
    j++;
  }
  return false;
}

// bool containsNearbyDuplicate(std::vector<int> &arr, int k) {
//   int n = arr.size();
//   int i = 0, j = 0;
//   while (j < n) {
//     if (j != i && arr[i] == arr[j])
//       return true;
//     if (j - i + 1 > k) {
//       i++;
//     }
//     j++;
//   }
//   return false;
// }

int main() {
  int k = 3;
  std::vector<int> arr = {1, 2, 3, 1};

  // int k = 2;
  // std::vector<int> arr = {1, 2, 3, 1, 2, 3};

  // int k = 1;
  // std::vector<int> arr = {1, 0, 1, 1};

  std::cout << "k: " << k << std::endl;
  std::cout << "Input Array: ";
  printArr(arr);

  // bool is_duplicate = bruteForce(arr, k);
  bool is_duplicate = containsNearbyDuplicate(arr, k);

  std::cout << "Does array contains duplicate " << is_duplicate << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 01-contains-duplicate.cpp -o output && ./output