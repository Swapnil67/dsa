/*
 * 132 Pattern
 * Given an array of n integers nums, a 132 pattern is a subsequence of three integers
 * nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
 * 
 * * Example 1
 * * Input  : nums = [1,2,3,4]
 * * Output : false
 * 
 * * Example 2
 * * Input  : nums = [3,1,4,2]
 * * Output : true
 * 
 * * Example 2
 * * Input  : nums = [-1,3,2,0]
 * * Output : true

* https://leetcode.com/problems/132-pattern/
*/


#include <iostream>
#include <vector>
#include <stack>
#include <climits>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * Brute Force
bool bruteForce(std::vector<int> nums) {
  int n = nums.size();
  for(int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      if (nums[i] < nums[j]) {
        for(int k = j + 1; k < n; ++k) {
          if (nums[i] < nums[k] && nums[k] < nums[j]) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

// * Using Monotonic Stack
bool find132pattern(std::vector<int> nums) {
  int n = nums.size();
  int num3 = INT_MIN;
  std::stack<int> st;
  for (int i = n - 1; i > 0; --i) {
    if(nums[i] < num3) {
      return true;
    }

    while(!st.empty() && st.top() < nums[i]) {
      num3 = st.top();
      st.pop();
    }

    st.push(nums[i]);
  }

  return false;
}

int main() {
  // std::vector<int> nums = {1, 2, 3, 4};
  // std::vector<int> nums = {3, 1, 4, 2};
  std::vector<int> nums = {-1, 3, 2, 0};
  printArr(nums);

  bool ans = bruteForce(nums);
  std::cout << "132 Pattern: " << ans << std::endl;
  return 0;  
}

// * run the code
// * $CXX --std=c++17 13-132-pattern.cpp -o output && ./output