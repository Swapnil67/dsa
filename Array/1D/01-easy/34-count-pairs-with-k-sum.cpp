/*
 * Leetcode - 532
 * Count pairs with sum k.
 * 
 * Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
 * 
 * A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
 * 
 * 0 <= i, j < nums.length
 * i != j
 * |nums[i] + nums[j]| == k
 *
 * Example 1    :
 * Input        : nums = [3,1,4,1,5], k = 4
 * Output       : 3
 * Explanation  : There are two 2-diff pairs in the array, (3, 1) and (3, 1).
 *
 * Example 2    :
 * Input        : nums = [1,2,3,4,5], k = 1
 * Output       : 4
 * Explanation  : There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
 *
 * Example 3    :
 * Input        : nums = [1,3,1,5,4], k = 0
 * Output       : 1
 * Explanation  : There is one 0-diff pair in the array, (1, 1).
 *
 * https://www.geeksforgeeks.org/problems/key-pair5616/1
 */

#include <vector>
#include <iostream>
#include <algorithm>
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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(N^2) + O(slog(s))
// * SPACE COMPLEXITY O(N)
int bruteForce(vector<int> &nums, int k) {
  int n = nums.size();
  int pairs = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (nums[i] + nums[j] == k)
        pairs += 1;
    }
  }
  return pairs;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------
// * Sorting + Two Pointer 
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
int betterApproach(vector<int> &nums, int k) {
  sort(begin(nums), end(nums));
  int i = 0, j = nums.size() - 1;

  int pairs = 0;
  while (i < j) {
    int sum = nums[i] + nums[j];
    cout << sum << endl;
    if (sum == k) {
      pairs += 1;
      i++;
    } else if (sum > k) {
      j--;
    } else {
      i++;
    }
  }
  
  return pairs;
}

// * ------------------------- APPROACH 2: Most Optimal APPROACH -------------------------
// * Hashmap
// * nums[i] + nums[j] = k
// * nums[i] = k - nums[j]
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int findPairs(vector<int> &nums, int k) {
  int n = nums.size();
  int pairs = 0;

  // * {element, freq}
  unordered_map<int, int> mp;
  for (int j = 0; j < n; ++j) {
    int check = k - nums[j];

    if (mp.count(check))
      pairs += mp[check];

    mp[nums[j]]++;
  }

  return pairs;
}

int main(void) {
  // * testcase 1
  int k = 4;
  vector<int> nums = {3, 2, 1, 2, 5};

  cout << "k: " << k << endl;
  cout << "Input Nums: ";
  printArr(nums);

  // int ans = bruteForce(nums, k);
  int ans = betterApproach(nums, k);
  // int ans = findPairs(nums, k);

  cout << "Answer: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 28-count-pairs-with-k-sum.cpp -o output && ./output
