/*
 * Leetcode - 2289
 * Steps to Make Array Non-decreasing
 * 
 * Example 1    :
 * Input        : nums = [5,3,4,4,7,3,6,11,8,5,11]
 * Output       : 3
 * Explanation  : 
 * 
 * Example 2    :
 * Input        : nums = [4, 5, 7, 7, 13]
 * Output       : 0
 * Explanation  : 
 * 
 * https://leetcode.com/problems/steps-to-make-array-non-decreasing
*/

#include <stack>
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

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * Monotonic Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int totalSteps(vector<int> &nums) {
  int n = nums.size();
  
  // * pair = { val , cnt }
  stack<pair<int, int>> st;
  int max_cnt = 0;

  for (int i = n - 1; i >= 0; --i) {
    int cnt = 0; // * Tracks the no of steps needed to remove elements smaller than nums[i]

    while (!st.empty() && nums[i] > st.top().first) {
      // * If the element at the top takes 'st.top().second' steps to clear out its own right side,
      // * nums[i] has to wait out those steps, plus 1 more step to consume that element itself.
      // * We take the maximum because elements can be removed in parallel rounds.
      cnt = max(cnt + 1, st.top().second);
      st.pop();
    }

    max_cnt = max(max_cnt, cnt);
    st.push({nums[i], cnt});
  }

  return max_cnt;
}

int main(void) {
  // * testcase 1
  // vector<int> nums = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};

  // * testcase 2
  // vector<int> nums = {4, 5, 7, 7, 13};

  // * testcase 3
  vector<int> nums = {7, 14, 4, 14, 13, 2, 6, 13};

  cout << "Input nums: ";
  printArr(nums);

  int ans = totalSteps(nums);
  cout << "Total Steps: " << ans << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 04-steps-to-make-array-non-decreasing.cpp -o output && ./output
