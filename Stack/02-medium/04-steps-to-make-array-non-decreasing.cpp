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
*/

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
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
    int cnt = 0;
    while (!st.empty() && nums[i] > st.top().first) {
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
  // std::vector<int> nums = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};

  // * testcase 2
  std::vector<int> nums = {4, 5, 7, 7, 13};

  std::cout << "Input nums: ";
  printArr(nums);

  int ans = totalSteps(nums);
  std::cout << "Total Steps: " << ans << std::endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 04-steps-to-make-array-non-decreasing.cpp -o output && ./output
