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

#include<map>
#include<queue>
#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1 -------------------------`
// * Use Priority Queue
// * TIME COMPLEXITY O(N) + O(N) + O(k) = O(2N) + O(k)
// * SPACE COMPLEXITY O(N) + O(N) 
std::vector<int> approach1(std::vector<int> nums, int k) {
  int n = nums.size();

  // * O(N)
  // * Create a hashmap of number of occurence of each ele
  std::map<int, int> occurenceMap;
  for(int i=0; i<n; i++) {
    occurenceMap[nums[i]]++;
  }

  // * O(N)
  // * Push to priority queue 
  std::priority_queue<std::pair<int,int>> pq;
  for(auto it: occurenceMap) {
    pq.push({ it.second, it.first });
  }

  // * O(k)
  // * Get the most frequent elements from top of priority queue
  std::vector<int> ans;
  while(k--) {
    ans.push_back(pq.top().second);
    pq.pop();
  }

  return ans;

}

// * ------------------------- APPROACH 2 -------------------------`
// * TIME COMPLEXITY O(N) + O(N) + O(N) = O(3N)
// * SPACE COMPLEXITY O(N) + O(N) 
std::vector<int> approach2(std::vector<int> nums, int k) {
  int n = nums.size();

  // * O(N)
  // * Create a hashmap of number of occurence of each ele
  std::map<int, int> occurenceMap;
  for(int i=0; i<n; i++) {
    occurenceMap[nums[i]]++;
  }

  // * O(N) -> Worst Case
  // * Create a frequency vector from above hashmap
  std::vector<std::vector<int>> freqVector(n);
  for(auto it: occurenceMap) {
    freqVector[it.second].push_back(it.first);
  }

  // * O(N) -> Worst Case
  // * Loop through the frequency vector
  std::vector<int> ans;
  for (int i = n; i >= 0; i--) {
    // std::cout << freqVector[i].size() << std::endl;
    if(freqVector[i].size()) {
      std::vector<int> temp(freqVector[i].begin(), freqVector[i].end());
      for(int i=0; i<temp.size(); i++) {
        ans.push_back(temp[i]);
        k--;
        if(k == 0) break;
      }
    }
    if(k == 0) break;
  }

  return ans;

}

int main() {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  // std::vector<int> nums = {1, 2, 2, 3, 3};
  // int k = 2;

  // std::vector<int> ans = approach1(nums, k);
  std::vector<int> ans = approach2(nums, k);

  std::cout<<"Top k frequent elements "<<std::endl;
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++17 11-top-k-frequent-ele.cpp -o 11-top-k-frequent-ele && ./11-top-k-frequent-ele