/*
 * Leetcode - 347
 * Top K Frequent Elements
 * 
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

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(N) + O(N) + O(N) = O(3N)
// * SPACE COMPLEXITY O(N) + O(N) 
vector<int> approach2(vector<int> nums, int k) {
  int n = nums.size();

  // * O(N)
  // * Create a hashmap of number of occurence of each ele
  unordered_map<int, int> freq_map;
  for (int i = 0; i < n; ++i) {
    freq_map[nums[i]]++;
  }
  // * Map
  // * { 1 : 3, 2 : 2, 3 : 1 }

  // * O(N) -> Worst Case
  // * Create a frequency vector from above hashmap
  vector<vector<int>> freqVector(n);
  for (auto it : freq_map) {
    freqVector[it.second].push_back(it.first);
  }
  // * frequency vector
  // * [[3],[2],[1],[],[],[]]

  // * O(N) -> Worst Case
  // * Loop through the frequency vector
  vector<int> ans;
  for (int i = n; i >= 0; --i) {
    if (!freqVector[i].size()) {
      continue;
    }

    vector<int> temp(freqVector[i].begin(), freqVector[i].end());
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
vector<int> topKFrequent(vector<int> &nums, int k) {
  int n = nums.size();

  // * count freq of every element in nums array
  unordered_map<int, int> freq_map;
  for (auto &x: nums) {
    freq_map[x]++;
  }

  // * Push freq of each elements to min_heap
  // * keep the size of min_heap to 'k'
  typedef pair<int, int> P;
  priority_queue<P, vector<P>, greater<>> min_heap;
  for (auto &[num, freq] : freq_map) {
    min_heap.push({freq, num});
    if (min_heap.size() > k)
      min_heap.pop();
  }

  vector<int> ans;
  while (k--) {
    ans.push_back(min_heap.top().second);
    min_heap.pop();
  }

  return ans;
}

int main() {
  // * testcase 1
  int k = 2;
  vector<int> nums = {1, 1, 1, 2, 2, 3};

  // int k = 2;
  // vector<int> nums = {1, 2, 2, 3, 3};

  // int k = 2;
  // vector<int> nums = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};

  // int k = 1;
  // vector<int> nums = {1};

  printArr(nums);

  vector<int> ans = topKFrequent(nums, k);

  cout<<"Top k frequent elements "<<endl;
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 11-top-k-frequent-ele.cpp -o output && ./output