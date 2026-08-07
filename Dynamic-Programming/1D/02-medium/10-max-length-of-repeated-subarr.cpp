/*
* Leetcode - 718
* Maximum Length of Repeated Subarray

* Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

* Example 1 
* Input        : nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
* Output       : 3
* Explanation  : The repeated subarray with maximum length is [3,2,1].

* Example 2
* Input   : nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
* Output  : 5
* Explanation  : The repeated subarray with maximum length is [0,0,0,0,0].

* https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
*/

#include <vector>
#include <iostream>

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

bool check_subarray_exists(vector<int> &subarr, vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    if (subarr[i] == nums[i]) {
      while (i < subarr.size()) {
        if (subarr[i] == nums[i]) 
          i++;
        else 
          return false;
      }
      break;
    }
  }
  return true;
}

int findLength(vector<int> &nums1, vector<int> &nums2) {
  int n1 = nums1.size();
  int ans = 0;
  for (int i = 0; i < n1; ++i) {
    vector<int> temp;
    for (int j = i; j < n1; ++j) {
      temp.push_back(nums1[j]);
      if (check_subarray_exists(temp, nums2)) {
        printArr(temp);
        cout << j - i << endl;
        ans = max(ans, (j - i));
      }
    }
  }
  return ans;
}

int dfs(int i, int j, int &ans, vector<int> &nums1, vector<int> &nums2) {
  if (i >= nums1.size() || j >= nums2.size())
    return 0;
  dfs(i + 1, j, ans, nums1, nums2);
  dfs(i, j + 1, ans, nums1, nums2);
  int common =
      (nums1[i] == nums2[j]) ? 1 + dfs(i + 1, j + 1, ans, nums1, nums2) : 0;
  ans = max(ans, common);
  return common;
}

int dfs(int i, int j, int &ans, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp) {
  if (i >= nums1.size() || j >= nums2.size())
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  dfs(i + 1, j, ans, nums1, nums2);
  dfs(i, j + 1, ans, nums1, nums2);
  int common =
      (nums1[i] == nums2[j]) ? 1 + dfs(i + 1, j + 1, ans, nums1, nums2) : 0;
  ans = max(ans, common);
  return dp[i][j] = common;
}


// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down approach
// * TIME COMPLEXITY O(2^(n + m))
// * SPACE COMPLEXITY O(n + m) 
int bruteForce(vector<int> &nums1, vector<int> &nums2) {
  int ans = 0;
  dfs(0, 0, ans, nums1, nums2);
  return ans;
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Top Down approach with memoization
// * TIME COMPLEXITY O(n x m)
// * SPACE COMPLEXITY O(n x m) 
int findLength(vector<int> &nums1, vector<int> &nums2) {
  int ans = 0;
  vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
  dfs(0, 0, ans, nums1, nums2, dp);
  return ans;
}


int main(void) {
  // * testcase 1
  // vector<int> nums1 = {1, 2, 3, 2, 1};
  // vector<int> nums2 = {3, 2, 1, 4, 7};

  // * testcase 2
  vector<int> nums1 = {0, 0, 0, 0, 0};
  vector<int> nums2 = {0, 0, 0, 0, 0};

  cout << "nums1: ";
  printArr(nums1);

  cout << "nums2: ";
  printArr(nums2);

  int ans = findLength(nums1, nums2);
  cout << "Ans: " << ans << endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++17 34-max-length-of-repeated-subarr.cpp -o output && ./output
