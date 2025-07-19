/**
 * * Leetcode - 1438
 * * Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

 * * Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such 
 * * that the absolute difference between any two elements of this subarray is less than or equal to limit.
 * 
 * * Example 1
 * * Input  : nums = [8,2,4,7], limit = 4
 * * Output : 2
 * * Explanation: 
 * * Maximum absolute difference
 * * 8             |8 - 8| = 0
 * * 8, 2,         |8 - 2| = 6
 * * 8, 2, 4,      |8 - 2| = 6
 * * 8, 2, 4, 7,   |8 - 2| = 6

 * * 
 * * 2             |2 - 2| = 0
 * * 2, 4,         |2 - 4| = 2
 * * 2, 4, 7       |2 - 7| = 5

 * * 
 * * 4             |4 - 4| = 0
 * * 4, 7          |4 - 7| = 3  (Answer = [4, 7])
 * * 
 * * 7             |7 - 7| = 0

 * * https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/
*/

#include <set>
#include <queue>
#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> nums, int limit) {
  int n = nums.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur_max_abs_diff = -1;
    for (int j = i; j < n; ++j) {
      cur_max_abs_diff = std::max(cur_max_abs_diff, std::abs(nums[i] - nums[j]));
      if (cur_max_abs_diff <= limit) {
        ans = std::max(ans, j - i + 1);
      }
    }
  }
  return ans;
}


// * ------------------------- APPROACH 2A: Optimal APPROACH -------------------------`
// * Using Min Heap & Max Heap
// * Min Heap = To find min element in subarray
// * Max Heap = To find max element in subarray

// * TIME COMPLEXITY O(n * log(n))
// * SPACE COMPLEXITY O(N + N)
int longestSubarray(std::vector<int> &nums, int limit) {
  int n = nums.size();

  typedef std::pair<int, int> P;
  std::priority_queue<P, std::vector<P>> maxPq;                  // * Max Heap
  std::priority_queue<P, std::vector<P>, std::greater<P>> minPq; // * Min Heap
  
  int i = 0, j = 0, ans = 0;

  while(j < n) { // * O(n * log(n))

    maxPq.push({nums[j], j});   // * Max ele will be at top of heap
    minPq.push({nums[j], j});   // * Min ele will be at top of heap

    // * If the diff in largest & smallest element of current subarray is greater than limit
    // * then shrink window
    while (maxPq.top().first - minPq.top().first > limit) {
      // * Find the next position for 'i'
      i = std::min(maxPq.top().second, minPq.top().second) + 1;

      // * Remove all index less than 'i' from 'maxPq'
      while (i > maxPq.top().second) {
        maxPq.pop(); // * log(n)
      }
      
      // * Remove all index less than 'i' from 'minPq'
      while (i > minPq.top().second) {
        minPq.pop(); // * log(n)
      }
    }

    ans = std::max(ans, j - i + 1);
    j++;
  }

  return ans;
}

// * ------------------------- APPROACH 2B: Optimal APPROACH -------------------------`
// ! Use this approach (more easy) 
/*
 * Use a sliding window [left, right] and maintain:
 *  maxDeque: decreasing deque for tracking maximum
 *  minDeque: increasing deque for tracking minimum
 *  At each step:
 *   1. Expand right
 *   2. Shrink left if the difference between max and min exceeds limit
 *   3. Track max length of valid window
*/
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(2N)
int longestSubarray2(std::vector<int> &nums, int limit) {
  int n = nums.size();
  std::deque<int> minDq, maxDq;
  int i = 0, ans = 0;
  for (int j = 0; j < n; ++j) {
    // * Maintain minDq (increasing)
    while(!minDq.empty() && nums[j] < minDq.back()) {
      minDq.pop_back();
    }
    minDq.push_back(nums[j]);

    // * Maintain maxDq (decreasing)
    while(!maxDq.empty() && nums[j] > maxDq.back()) {
      maxDq.pop_back();
    }
    maxDq.push_back(nums[j]);

    // * Shrink window if limit exceeded
    while(maxDq.front() - minDq.front() > limit) {
      if(maxDq.front() == nums[i]) {
        maxDq.pop_front();
      }
      if(minDq.front() == nums[i]) {
        minDq.pop_front();
      }
      i++;
    }

    ans = std::max(ans, j - i + 1);
  } 
  return ans;
}


// * ------------------------- APPROACH 2C: Optimal APPROACH -------------------------`
// * Using multiset data-structure
// * TIME COMPLEXITY O(n * log(n))
// * SPACE COMPLEXITY O(N)
int longestSubarray3(std::vector<int> &nums, int limit) {
  int n = nums.size();
  
  int i = 0, j = 0, ans = 0;
  std::multiset<int> ms;

  while (j < n) { // * (n * log(n))
    ms.insert(nums[j]);

    while (*ms.rbegin() - *ms.begin() > limit) {
      ms.erase(ms.find(nums[i])); // * log(n)
      i++;
    }

    ans = std::max(ans, j - i + 1);
    j++;
  }

  return ans;
}

int main() {
  // * testcase 1
  int limit = 4;
  std::vector<int> nums = {8, 2, 4, 7};
  
  // * testcase 2
  // int limit = 5;
  // std::vector<int> nums = {10, 1, 2, 4, 7, 2};
  
  // * testcase 3
  // int limit = 0;
  // std::vector<int> nums = {4, 2, 2, 2, 4, 4, 2, 2};

  printArr(nums);

  // int ans = bruteForce(nums, limit);
  // int ans = longestSubarray(nums, limit);
  int ans = longestSubarray2(nums, limit);
  std::cout << "Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 29-longest-subarr-with-abs-diff-less-than-limit.cpp -o output && ./output


// * DRY RUN

// * limit = 5
// * 10, 1, 2, 4, 7, 2


// * 0   1  2  3  4  5 
// *        i
// * 10, 1, 2, 4, 7, 2
// *                 j 

// * ans = 0, 1, 2, 3, 4

/*
*  max heap  |  min heap 
*  (7, 4)    |  (2, 2) 
*  (4, 3)    |  (4, 3) 
*  (2, 2)    |  (7, 4) 
*  (1, 1)    |  (10, 0) 
*  (1, 1)    |  
*  (1, 1)    |  
*            | 
*/