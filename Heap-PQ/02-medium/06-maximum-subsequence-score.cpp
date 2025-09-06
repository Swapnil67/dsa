/*
 * Leetcode - 2542
 * Maximum Subsequence Score
 * 
 * You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. 
 * You must choose a subsequence of indices from nums1 of length k.

 * For chosen indices i0, i1, ..., ik - 1, your score is defined as:

 * - The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
 * - It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , 
 *   nums2[i1], ... ,nums2[ik - 1]).
 * 
 * Return the maximum possible score.

 * Example 1
 * input       : nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
 * output      : 12
 * Explanation : 
 *  - We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
 *  - We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
 *  - We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
 *  - We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
 * Therefore, we return the max score, which is 12.
 * 
 * https://leetcode.com/problems/maximum-subsequence-score/description/
*/

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

typedef std::priority_queue<long long, std::vector<long long>, std::greater<long long>> Min_Heap;

void remove_from_heap(Min_Heap &min_heap, int num) {
  std::vector<int> temp;
  while (!min_heap.empty()) {
    int x = min_heap.top();
    min_heap.pop();
    if (x == num)
      break;
    temp.push_back(x);
  }

  for (int &x : temp) {
    min_heap.push(x);
  }
}

long long solve(std::vector<int> &nums1,
                std::vector<int> &nums2,
                Min_Heap &min_heap,
                int i, int sum, int cur_min,
                int count, int &k)
{
  if (count == k) {
    std::cout << sum << " * " << cur_min << " = " << sum * cur_min << std::endl;
    return sum * cur_min;
  }

  if (i >= nums1.size())
    return 0;

  min_heap.push(nums2[i]);
  long long take_i = solve(nums1, nums2, min_heap, i + 1, sum += nums1[i], min_heap.top(), count + 1, k);
  
  remove_from_heap(min_heap, nums2[i]);
  long long not_take_i = solve(nums1, nums2, min_heap, i + 1, sum -= nums1[i], cur_min, count, k);

  return (long long)std::max(take_i, not_take_i);
}

// * ------------------------- Brute Force Approach -------------------------`
// * Recursion & Backtracking
// * TIME COMPLEXITY O(2^n * nlogn)
// * SPACE COMPLEXITY O(n)
long long bruteForce(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
  Min_Heap min_heap;
  return solve(nums1, nums2, min_heap, 0, 0, INT_MAX, 0, k);
}

// * ------------------------- Optimal Approach -------------------------`
// * TIME COMPLEXITY O(nlogn + nlogk) ~ O(nlogn)
// * SPACE COMPLEXITY O(n)
long long maxScore(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
  int n = nums1.size();

  // * Create a pairs of vec
  std::vector<std::pair<int, int>> pairs(n);
  for (int i = 0; i < n; ++i) {
    pairs[i] = {nums1[i], nums2[i]};
  }

  // * Sort the pairs in DESC by 2nd element in pair
  std::sort(begin(pairs), end(pairs), [](const auto &a, const auto &b) {
    return a.second > b.second;
  });
  // for (auto &it : pairs) {
  //   std::cout << it.second << " " << it.first << std::endl;
  // }

  Min_Heap min_heap;
  long long k_sum = 0, result = 0;

  for (auto &pair: pairs) {
    k_sum += pair.first;
    min_heap.push(pair.first);
    
    // * remove the min from sum of prev subsequence using `min_heap`
    if (min_heap.size() > k) {
      k_sum -= min_heap.top();
      min_heap.pop();
    }
    
    if (min_heap.size() == k) {
      result = std::max(result, k_sum * (long long)pair.second);
    }
    // std::cout << "k_sum: " << k_sum << ", result: " << result << std::endl;
  }

  return result;
}

int main(void) {
  // * testcase 1
  int k = 3;
  std::vector<int> nums1 = {1, 3, 3, 2};
  std::vector<int> nums2 = {2, 1, 3, 4};

  // * testcase 2
  // int k = 1;
  // std::vector<int> nums1 = {4, 2, 3, 1, 1};
  // std::vector<int> nums2 = {7, 5, 10, 9, 6};

  std::cout << "k: " << k << std::endl;
  std::cout << "nums1: ";
  printArr(nums1);
  std::cout << "nums2: ";
  printArr(nums2);

  // long long ans = bruteForce(nums1, nums2, k);
  long long ans = maxScore(nums1, nums2, k);

  std::cout << "Maximum Subsequence Score " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-maximum-subsequence-score.cpp -o output && ./output


// * Input Arrays
// * 1 3 3 2 
// * 1 2 3 4

// * Sort the nums2 and map nums1 to it using pairs of vector


// * DRY RUN
// * --------------------

// *     k
// * 2 3 1 3 
// * 4 3 2 1

// * k_sum = 6
// * min_heap = [3, 2, 1]
// * result = k_sum * (pair[k-1].second)
// * result = 6 * 2 = 12

// * --------------------

// *       k
// * 2 3 1 3 
// * 4 3 2 1

// * k_sum = 8
// * min_heap = [3, 3, 2]
// * result = k_sum * (pair[k-1].second)
// * result = 8 * 1 = 8

// * --------------------

// * Max from all results = 12

