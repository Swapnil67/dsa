/*
* Leetcode - 719
* Find K-th Smallest Pair Distance
*
* The distance of a pair of integers a and b is defined as the absolute difference between a and b.
* Given an integer array nums and an integer k, 
* return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
*
* Example 1:
* Input: nums = [1,3,1], k = 1
* Output: 0
* Explanation: Here are all the pairs:
* (1,3) -> 2
* (1,1) -> 0
* (3,1) -> 2
* Then the 1st smallest distance pair is (1,1), and its distance is 0.
*
* Example 1:
* Input: nums = [1,6,1], k = 3
* Output: 5
*
* https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArr(vector<T> &nums) {
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}
// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// ! TLE
// * TIME COMPLEXITY O(N^2) + O(slog(s))
// * SPACE COMPLEXITY O(N)
int bruteForce(vector<int>& nums, int k) {
  int n = nums.size();

  // * 1. Create a vector of abs diff of pairs O(N^2)
  vector<int> diff_vec;
  for (int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      diff_vec.push_back(abs(nums[j] - nums[i]));
    }
  }

  // * 2. Sort the diff_vec in Ascenting O(slog(s))
  sort(diff_vec.begin(), diff_vec.end());

  // * 3. return the kth smallest distance
  return diff_vec[k - 1];
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------
// ! TLE
// * kth Smallest = Max Heap
// * TIME COMPLEXITY O(N^2 * log(k))
// * SPACE COMPLEXITY O(k)
int betterApproach(vector<int>& nums, int k) {
  int n = nums.size();

  // * 1. Create a max heap (Sorted in Descending Order)
  priority_queue<int> heap;

  // * 2. Push all the abs diff of pairs into heap
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      heap.push(abs(nums[j] - nums[i]));  // * O(log(k))
      // * If heap size gets greater than k then pop from top
      if (heap.size() > k)
        heap.pop();
    }
  }

  // * 3. Since our heap size it 'k' then top most element will contain kth smallest element
  return heap.top();
}

// * ------------------------- APPROACH 3C: Most Optimal APPROACH -------------------------
// * Find how many pairs are possible with abs diff less than or equal to maxDist
// * Sliding window
bool isPossible(vector<int> &nums, int max_pairs, int maxDist) {
  int n = nums.size();
  int pairs = 0;
  int i = 0, j = 1;
  while (j < n) {  
    while (nums[j] - nums[i] > maxDist) {
      i++;
    }
    pairs += (j - i);
    j++;
  }
  cout << "dist: " << maxDist << ", pairs " << pairs << endl;
  return pairs >= max_pairs;
}

// * Sliding Window + Binary Search
// * TIME COMPLEXITY O(n*log(n)) + O(n*log(r))
// * SPACE COMPLEXITY O(1)
int smallestDistancePair(vector<int> &nums, int k) {
  int n = nums.size();

  // * Sort the nums array O(n*log(n))
  sort(nums.begin(), nums.end());

  // * Binary Search on pairs difference
  int l = 0, r = nums[n - 1] - nums[0]; // * range of answers
  int ans = 0;
  while (l <= r) { // * O(log(r))
    int m = l + (r - l) / 2;
    if (isPossible(nums, k, m)) { // * O(n)
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}

int main(void) {
  // * testcase 1 (Answer 0)
  // int k = 1;
  // vector<int> nums = {1, 3, 1};
  
  // * testcase 2 (Answer 5)
  // int k = 3; 
  // vector<int> nums = {1, 6, 1};
  
  // * testcase 3 (Answer 3)
  int k = 2;
  vector<int> nums = {1, 5, 4, 10};

  cout << "Nums: " << endl;
  printArr(nums);

  // int ans = bruteForce(nums, k);
  // int ans = betterApproach(nums, k);
  int ans = smallestDistancePair(nums, k);

  cout << "Kth smallest distance " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 04-find-kth-smallest-pair-distance.cpp -o output && ./output