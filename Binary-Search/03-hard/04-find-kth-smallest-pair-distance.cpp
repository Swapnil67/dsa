/*
* Leetcode - 719
* Find K-th Smallest Pair Distance

* The distance of a pair of integers a and b is defined as the absolute difference between a and b.
* Given an integer array nums and an integer k, 
* return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

* Example 1:
* Input: nums = [1,3,1], k = 1
* Output: 0
* Explanation: Here are all the pairs:
* (1,3) -> 2
* (1,1) -> 0
* (3,1) -> 2
* Then the 1st smallest distance pair is (1,1), and its distance is 0.

* Example 1:
* Input: nums = [1,6,1], k = 3
* Output: 5

* https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// ! TLE
// * TIME COMPLEXITY O(N^2) + O(slog(s))
// * SPACE COMPLEXITY O(N)
int bruteForce(std::vector<int>& nums, int k) {
  int n = nums.size();

  // * 1. Create a vector of abs diff of pairs O(N^2)
  std::vector<int> distanceVec;
  for (int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      distanceVec.push_back(std::abs(nums[j] - nums[i]));
    }
  }

  // * 2. Sort the distanceVec in Ascenting O(slog(s))
  std::sort(distanceVec.begin(), distanceVec.end());

  // * 3. return the kth smallest distance
  return distanceVec[k - 1];
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------`
// ! TLE
// * kth Smallest = Max Heap
// * TIME COMPLEXITY O(N^2 * log(k))
// * SPACE COMPLEXITY O(k)
int betterApproach(std::vector<int>& nums, int k) {
  int n = nums.size();

  // * 1. Create a max heap (Sorted in Descending Order)
  std::priority_queue<int> heap;

  // * 2. Push all the abs diff of pairs into heap
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      heap.push(std::abs(nums[j] - nums[i]));  // * O(log(k))
      // * If heap size gets greater than k then pop from top
      if (heap.size() > k)
        heap.pop();
    }
  }

  // * 3. Since our heap size it 'k' then top most element will contain kth smallest element
  return heap.top();
}

// * ------------------------- APPROACH 3A: Optimal APPROACH -------------------------`
// * Using C++ SDL (nth_element)
// * TIME COMPLEXITY O(N^2) + O(maxEle)
// * SPACE COMPLEXITY O(maxEle)
int smallestDistancePair2(std::vector<int> &nums, int k) {
  int n = nums.size();

  // * 1. Create a vector of size max pairs possible for 'n' size array
  int maxPairs = (n * (n - 1) / 2);
  std::vector<int> pairsDiff(maxPairs);

  // * 2. Save the pairs abs diff to pairsDiff vector
  int idx = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      pairsDiff[idx] = std::abs(nums[i] - nums[j]);
      idx++;
    }
  }

  // * 3. Use nth_element to find the k - 1 element 
  std::nth_element(begin(pairsDiff), begin(pairsDiff) + (k - 1), end(pairsDiff));

  return pairsDiff[k - 1];
}

// * ------------------------- APPROACH 3B: Optimal APPROACH -------------------------`
// * Count every possible abs diff of pair in a vector
// * Eg: Nums = {1,6,1} & k = 3, therefore pairsCnt = {0: 1, 1: 0, 2: 0, 3: 0, 4: 0, 5: 2, 6: 0}
// * TIME COMPLEXITY O(N^2) + O(maxEle)
// * SPACE COMPLEXITY O(maxEle)
int smallestDistancePair(std::vector<int> &nums, int k) {
  int n = nums.size();

  // * 1. Create a vector of size max element from nums vector
  int maxEle = *std::max_element(nums.begin(), nums.end());
  std::vector<int> pairsCnt(maxEle + 1, 0);

  // * 2. Count abs diff pairs using pairsCnt vector
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      pairsCnt[std::abs(nums[j] - nums[i])]++;
    }
  }

  // * 3. Find till what distance k > 0 
  for (int d = 0; d < maxEle + 1; ++d) {
    k -= pairsCnt[d];
    if (k <= 0)
      return d;
  }

  return -1;
}

// * ------------------------- APPROACH 3C: Most Optimal APPROACH -------------------------`

// * Find how many pairs are possible with abs diff less than or equal to maxDist
// * Sliding window
bool isPossible(std::vector<int> &nums, int k, int maxDist) {
  int n = nums.size();
  int curPairs = 0;
  int i = 0, j = 1;
  while (j < n) {  
    while (nums[j] - nums[i] > maxDist) {
      i++;
    }
    curPairs += (j - i);
    j++;
  }

  // std::cout << "dist: " << maxDist << ", pairs " << curPairs << std::endl;

  return curPairs >= k;
}

// * Sliding Window + Binary Search
// * TIME COMPLEXITY O(n*log(n)) + O(n*log(r))
// * SPACE COMPLEXITY O(1)
int smallestDistancePair3(std::vector<int> &nums, int k) {
  int n = nums.size();

  // * Sort the nums array O(n*log(n))
  std::sort(nums.begin(), nums.end());

  // * Binary Search on pairs difference
  int l = 0, r = nums[n - 1] - nums[0];
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
  // int k = 1;
  // std::vector<int> nums = {1, 3, 1};

  // int k = 3;
  // std::vector<int> nums = {1, 6, 1};

  int k = 2;
  std::vector<int> nums = {1, 5, 4, 10};

  std::cout << "Nums: " << std::endl;
  printArr(nums);

  // int ans = bruteForce(nums, k);
  // int ans = betterApproach(nums, k);
  // int ans = smallestDistancePair(nums, k);
  // int ans = smallestDistancePair2(nums, k);
  int ans = smallestDistancePair3(nums, k);
  std::cout << "Kth smallest distance " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 04-find-kth-smallest-pair-distance.cpp -o output && ./output