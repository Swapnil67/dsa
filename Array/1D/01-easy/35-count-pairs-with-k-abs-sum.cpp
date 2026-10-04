/*
 * Count Number of Pairs With k absolute Sum 

 * Given an array of integers nums and an integer k, return the number of k-sum pairs in the array.
 * 
 * A k-sum pair is an integer pair (nums[i], nums[j]), where the following are true:
 * 
 * 0 <= i, j < nums.length
 * i != j
 * |nums[i] + nums[j]| == k
 *
 * Example 1    :
 * Input        : nums = [10,5,1,3,1], k = 2
 * Output       : 1
 * Explanation  : [1,1]
 *
 * Example 2    :
 * Input        : nums = [10, 5, 1, 3, 1, 1], k = 2
 * Output       : 3
 *
 * https://drive.google.com/file/d/1QOnTu4o4kxp6XGfaI-2ne_WdUvwJo91T/view
*/

// ! Duplicates pairs are allowed

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
      if (abs(nums[j] + nums[i]) == k) { // * if it follows criteria
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
  int n = nums.size();

  unordered_map<int, int> mp;
  int pairs = 0;
  for (int j = 0; j < n; ++j) {
    int r1 = k - nums[j];
    int r2 = -k - nums[j];

    if (k == 0) {
      // * r1 == r2, so count only once
      pairs += mp[r1];
    } else {
      pairs += mp[r1];
      pairs += mp[r2];
    }

    mp[nums[j]]++;
  }

  return pairs;
}

int main(void) {
  // * testcase 1
  int k = 2;
  vector<int> nums = {10, 5, 1, 3, 1, 1};

  cout << "k: " << k << endl;
  cout << "Input Nums: ";
  printArr(nums);

  int ans = findPairs(nums, k);
  cout << "Answer: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-count-pairs-with-k-abs-sum.cpp -o output && ./output
