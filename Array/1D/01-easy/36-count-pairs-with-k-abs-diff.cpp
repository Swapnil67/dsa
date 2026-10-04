/*
 * Leetcode - 532
 * Count Number of Pairs With k absolute Difference 
 * 
 * Given an array of integers nums and an integer k, return the number of unique/distinct
 * k-diff pairs in the array.
 * 
 * A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
 * 
 * 0 <= i, j < nums.length
 * i != j
 * |nums[i] - nums[j]| == k
 *
 * Example 1    :
 * Input        : nums = [3,1,4,1,5], k = 2
 * Output       : 2
 * Explanation  : There are two 2-diff pairs in the array, (1, 3) and (3, 5).
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
 * https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
 * https://www.geeksforgeeks.org/problems/pairs-with-difference-k1713/1
 * https://www.geeksforgeeks.org/problems/count-distinct-pairs-with-difference-k1233/1
*/

// ! Duplicates pairs are not allowed

#include <map>
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


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(N^2) + O(slog(s))
// * SPACE COMPLEXITY O(N)
int bruteForce(vector<int> &nums, int k) {
  int n = nums.size();
  sort(begin(nums), end(nums));
  map<pair<int, int>, int> pairs_mp;
  int pairs = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (abs(nums[j] - nums[i]) == k) { // * if it follows criteria
        pair<int,int> p = {nums[i], nums[j]};
        if (pairs_mp.find(p) == pairs_mp.end()) {
          pairs += 1;
          pairs_mp[p]++;
        }
      }
    }
  }
  return pairs;
}

// * ------------------------- APPROACH 2: Most Optimal APPROACH -------------------------
// * Hashmap
// * |a| - |b| = k
// * |a| = |b| + k 
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int findPairs(vector<int> &nums, int k) {
  unordered_map<int, int> mp;
  for (auto &num : nums) {
    mp[num]++;
  }

  // * For Debug
  for (auto &it : mp)
    cout << it.first << " " << it.second << endl;

  int pairs = 0;
  if (k != 0) {
    for (auto &it: mp) {
      if (mp.find(it.first + k) != mp.end()) 
        pairs += 1;
    }
  } else {
    for (auto &it: mp) {
      if (it.second > 1) 
        pairs += 1;
    }
  }

  return pairs;
}

int main(void) {
  // * testcase 1
  // int k = 2;
  // vector<int> nums = {3, 1, 4, 1, 5};
  
  // * testcase 2
  int k = 1;
  vector<int> nums = {1, 2, 3, 4, 5};

  // * testcase 3
  // int k = 0;
  // vector<int> nums = {1, 5, 1, 5, 5, 4};

  cout << "k: " << k << endl;
  cout << "Input Nums: ";
  printArr(nums);

  int ans = findPairs(nums, k);
  cout << "Answer: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-count-pairs-with-k-abs-diff.cpp -o output && ./output
