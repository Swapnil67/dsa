/*
 * Leetcode - 2615
 * Sum of Distances
 * You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, 
 * where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i.
 * If there is no such j, set arr[i] to be 0.

 * Example 1
 * Input  : nums = [1,3,1,1,2]
 * Output : [5,0,3,4,0]

 * Example 2
 * Input  : nums = [0,5,3]
 * Output : [0,0,0]

 * https://leetcode.com/problems/sum-of-distances/description/
*/

// Note: This question is the same as 2121: Intervals Between Identical Elements.

#include <vector>
#include <iostream>
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


// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N*N)
// * SPACE COMPLEXITY O(N)
std::vector<long long> bruteForce(std::vector<int> &nums) {
  int n = nums.size();
  // * Save all the indexs of same elements into an array
  std::unordered_map<int, std::vector<int>> idx_mp;
  for (int i = 0; i < n; ++i) {
    idx_mp[nums[i]].push_back(i);
  }

  // * Find the diff b/w index and sum those.
  std::vector<long long> ans;
  for (int i = 0; i < n; ++i) {
    int cur = nums[i];
    long long sum = 0;
    for (auto &idx : idx_mp[cur]) {
      sum += (long long)abs(idx - i);
    }
    ans.push_back(sum);
  }

  return ans;
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using Prefix Sum Variable
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::vector<long long> distance(std::vector<int> nums)
{
  int n = nums.size();
  std::unordered_map<int, std::vector<int>> idx_mp;
  for (int i = 0; i < n; ++i) {
    idx_mp[nums[i]].push_back(i);
  }

  std::vector<long long> ans(n);
  for (auto &it : idx_mp) {
    int num = it.first;
    std::vector<int> indexes = it.second;
    long long total_sum = 0;

    for (auto &x : indexes)
      total_sum += (x * 1ll);

    long long pre_idx_sum = 0;
    for (int i = 0; i < indexes.size(); ++i)
    {
      int index = indexes[i];
      // * sum1 = (index * prev_same_idx_cnt) - sum of prev indexes
      long long prev_same_idx_cnt = i * 1ll;
      long long sum1 = (index * prev_same_idx_cnt) - pre_idx_sum;

      // * sum2 = (index * post_same_idx_cnt) - (sum of post indexes)
      long long post_idx_sum = total_sum - pre_idx_sum - index;
      long long post_same_idx_cnt = indexes.size() - 1 - i * 1ll;
      long long sum2 = (index * post_same_idx_cnt) - post_idx_sum;

      ans[index] += (abs(sum1) + abs(sum2));
      pre_idx_sum += index;
    }
  }

  return ans;
}

int main() {
  // * testcase 1
  std::vector<int> nums = {1, 3, 1, 1, 2};

  // * testcase 2
  // std::vector<int> nums = {1, 0, 1, 1, 0, 1};

  std::cout << "Input nums: ";
  printArr(nums);

  std::vector<long long> ans = bruteForce(nums);
  // std::vector<long long> ans = distance(nums);
  
  std::cout << "Answer: ";
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ -std=c++20 17-sum-of-distances.cpp -o output && ./output
