/*
 * Leetcode - 1481
 * Least Number of Unique Integers after K Removals
 * 
 * Given an array of integers arr and an integer k. Find the least number of unique integers after removing 
 * exactly k elements.

 * Example 1
 * input  : arr = [5,5,4], k = 1
 * output : 1

 * Example 2
 * input  : arr = [4,3,1,1,3,3,2], k = 3
 * output : 2
 * 
 * https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Using sorting
// * TIME COMPLEXITY O(n + nlogn)
// * SPACE COMPLEXITY O(n)
int bruteForce(std::vector<int> &arr, int k) {
  // * 1. Find the freq of each number
  std::unordered_map<int, int> freq_mp;
  for (auto &x : arr) {
    freq_mp[x]++;
  }

  // * 2. Add the freq of each number to `temp` vector
  std::vector<int> temp;
  for (auto &[key, freq] : freq_mp) {
    temp.push_back(freq);
  } 

  // * 3. sort the temp vector in ASC
  std::sort(temp.begin(), temp.end());

  // * 4. Start removing first 'k' elements with least frequency
  int n = temp.size();
  for (int i = 0; i < n; ++i) {
    k -= temp[i];
    if (k < 0) {
      return n - i;
    }
  }

  return 0;
}


// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Using min_heap for freq
// * TIME COMPLEXITY O(n + nlogk)
// * SPACE COMPLEXITY O(n)
int findLeastNumOfUniqueInts(std::vector<int> &arr, int k) {
  int n = arr.size();

  // * 1. Find the freq of each number
  std::unordered_map<int, int> freq_map;
  for (auto &x : arr) {
    freq_map[x]++;
  }

  // * 2. Add the freq of each number to `min_heap`
  std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;
  for (auto &[key, freq] : freq_map) {
    min_heap.push(freq);
  }

  // * 3. Remove the k elements with least freq using min_heap
  while (k && min_heap.size()) { // * O(nlogk)
    // * remove the number with least freq
    int cur_freq = min_heap.top();
    cur_freq--;
    min_heap.pop();

    // * If number still have freq > 0 then add to `min_heap` again
    if (cur_freq > 0)
      min_heap.push(cur_freq);

    k--;
  }

  return min_heap.size();
}

int main(void) {
  // * testcase 1
  int k = 1;
  std::vector<int> arr = {5, 5, 4};
  
  // * testcase 2
  // int k = 3;
  // std::vector<int> arr = {4, 3, 1, 1, 3, 3, 2};
  
  std::cout << "k: " << k << std::endl;
  std::cout << "Input Array: ";
  printArr(arr);

  int ans = bruteForce(arr, k);
  // int ans = findLeastNumOfUniqueInts(arr, k);
  std::cout << "Unique Integers after K Removals " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-least-no-unique-int-after-k-removals.cpp -o output && ./output