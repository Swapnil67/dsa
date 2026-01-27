/*
 * Top K Frequent Elements
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 * It is guaranteed that the answer is unique.
 * 
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]

 * https://leetcode.com/problems/top-k-frequent-elements/description/
 * https://www.naukri.com/code360/problems/k-most-frequent-elements_3167808
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

void printArr(std::vector<int> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(N) + O(N) + O(N) = O(3N)
// * SPACE COMPLEXITY O(N) + O(N) 
std::vector<int> approach2(std::vector<int> nums, int k) {
  int n = nums.size();

  // * O(N)
  // * Create a hashmap of number of occurence of each ele
  std::unordered_map<int, int> freq_map;
  for (int i = 0; i < n; ++i) {
    freq_map[nums[i]]++;
  }
  // * Map
  // * { 1 : 3, 2 : 2, 3 : 1 }

  // * O(N) -> Worst Case
  // * Create a frequency vector from above hashmap
  std::vector<std::vector<int>> freqVector(n);
  for (auto it : freq_map) {
    freqVector[it.second].push_back(it.first);
  }
  // * frequency vector
  // * [[3],[2],[1],[],[],[]]

  // * O(N) -> Worst Case
  // * Loop through the frequency vector
  std::vector<int> ans;
  for (int i = n; i >= 0; --i) {
    if (!freqVector[i].size()) {
      continue;
    }

    std::vector<int> temp(freqVector[i].begin(), freqVector[i].end());
    for (int i = 0; i < temp.size(); ++i) {
      ans.push_back(temp[i]);
      k--;
      if (k == 0)
        break;
    }
    
    if (k == 0)
      break;
  }

  return ans;
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Much easier
// * Use Priority Queue
// * TIME COMPLEXITY O(N) + O(N) + O(k) = O(2N) + O(k)
// * SPACE COMPLEXITY O(N) + O(N) 
std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
  int n = nums.size();

  // * count freq of every element in nums array
  std::unordered_map<int, int> freq_map;
  for (auto &x: nums) {
    freq_map[x]++;
  }

  std::priority_queue<std::pair<int, int>> min_heap;
  // * Push freq of each elements to min_heap
  // * keep the size of min_heap to 'k'
  for (auto &p: freq_map) {
    min_heap.push({p.second, p.first});
  }

  std::vector<int> ans;
  while (k--) {
    ans.push_back(min_heap.top().second);
    min_heap.pop();
  }

  return ans;
}

int main() {
  // * testcase 1
  int k = 2;
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};

  // int k = 2;
  // std::vector<int> nums = {1, 2, 2, 3, 3};

  // int k = 2;
  // std::vector<int> nums = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};

  // int k = 1;
  // std::vector<int> nums = {1};

  printArr(nums);

  std::vector<int> ans = topKFrequent(nums, k);

  std::cout<<"Top k frequent elements "<<std::endl;
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 11-top-k-frequent-ele.cpp -o output && ./output