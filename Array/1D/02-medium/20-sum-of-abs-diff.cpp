/*
 * Sum of Absolute Differences in a Sorted Array
 * Build and return an integer array result with the same length as nums such that result[i] is equal 
 * to the summation of absolute differences between nums[i] and all the other elements in the array.

 * Given array/list can contain duplicate elements.
 * 
 * (arr[i],arr[j]) and (arr[j],arr[i]) are considered same.
 * 
 * Example 1:
 * Input: nums = [2,3,5]
 * Output: [4,3,5]
 * Explanation: Assuming the arrays are 0-indexed, then
 * result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
 * result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
 * result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.

 * https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/
 * https://www.naukri.com/code360/problems/absolute-ninja_1462468
*/
#include <iostream>
#include <numeric>
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
  cout << " ]" << "\n";
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Nested loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
vector<int> bruteForce(vector<int> arr) {
  int n = arr.size();
  vector<int> ans;

  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      sum += abs(arr[i] - arr[j]);
    }
    ans.push_back(sum);
  }

  return ans;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Prefix sum array
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
vector<int> betterApproach(vector<int>& nums) {
  int n = nums.size();
  vector<int> prefix_arr, ans;

  int prefix = 0;
  for (int i = 0; i < n; ++i) {
    prefix += nums[i];
    prefix_arr.push_back(prefix);
  }

  // printArr(prefix_arr);

  for (int i = 0; i < n; ++i) {
    int left_sum = prefix_arr[i] - nums[i];           // * left sum => 0 to i-1 ka sum
    int right_sum = prefix_arr[n - 1] - prefix_arr[i]; // * right sum => i+1 to n-1 ka sum
    // cout << left_sum << " " << right_sum << endl;

    // * val = ((nums[i] * i) - (0 to i - 1 ka sum) + ((i + 1 to n - 1 ka sum) - (nums[i] * (n - i - 1)))  
    int val = ((nums[i] * i) - left_sum) + (right_sum - (nums[i] * (n - i - 1)));
    ans.push_back(val);

  }

  return ans;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * Prefix sum without prefix Array
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
  int n = nums.size();
  vector<int> prefixArr, ans;

  int total = accumulate(nums.begin(), nums.end(), 0);

  int prefix_sum = 0;
  for (int i = 0; i < n; ++i) {
    prefix_sum += nums[i];
    int left_sum = prefix_sum - nums[i];       // * left sum => 0 to i-1 ka sum
    int right_sum = total - prefix_sum;        // * right sum => i+1 to n-1 ka sum
    // cout << left_sum << " " << right_sum << endl;

    // * val = ((nums[i] * i) - (0 to i - 1 ka sum) + ((i + 1 to n - 1 ka sum) - (nums[i] * (n - i - 1)))
    int val = ((nums[i] * i) - left_sum) + (right_sum - (nums[i] * (n - i - 1)));
    ans.push_back(val);
  }

  return ans;
}

int main() {
  // vector<int> arr = {2, 3, 5};
  vector<int> arr = {1, 4, 6, 8, 10};
  printArr(arr);
  vector<int> ans = getSumAbsoluteDifferences(arr);
  printArr(ans);

  return 0;
}

// * run the code
// * g++ --std=c++17 20-sum-of-abs-diff.cpp -o output && ./output