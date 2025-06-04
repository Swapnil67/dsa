/*
 * 132 Pattern
 * Leetcode - 456
 * Given an array of n integers nums, a 132 pattern is a subsequence of three integers
 * nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
 * 
 * Example 1
 * * Input  : nums = [1,2,3,4]
 * * Output : false
 * 
 * Example 2
 * * Input  : nums = [3,1,4,2]
 * * Output : true
 *
 * Example 3
 * * Input  : nums = [-1,3,2,0]
 * * Output : true

 * https://leetcode.com/problems/132-pattern/
*/

// ! Monotonic Stack

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

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^3)
// * SPACE COMPLEXITY O(1)
bool bruteForce(std::vector<int> nums) {
  int n = nums.size();
  for(int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      // * Only search if nums[i] < nums[j]
      if (nums[i] < nums[j]) {
        for (int k = j + 1; k < n; ++k) {
          if (nums[i] < nums[k] && nums[k] < nums[j]) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
bool bruteForce(std::vector<int> nums) {
  int n = nums.size();

  int num_i = nums[0];      // * keep 'i' value as pointer
  for (int j = 1; j < n; ++j) {
    num_i = std::min(num_i, nums[j]);
    for (int k = j + 1; k < n; ++k) {
      if (num_i < nums[k] && nums[k] < nums[j])
        return true;
    }
  }

  return false;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using Monotonic Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool find132pattern(std::vector<int> nums) {
  int n = nums.size();
  int num3 = INT_MIN;
  std::stack<int> st;

  // * consider nums[j] as the largest element (i.e., n2)
  for (int j = n - 1; j > 0; --j) {

    // * found nums[i] element
    if (nums[j] < num3) {
      return true;
    }

    // * found new nums[k]
    while (!st.empty() && st.top() < nums[j]) {
      num3 = st.top();
      st.pop();
    }

    st.push(nums[j]);
  }

  return false;
}

int main() {
  // * testcase 1
  // std::vector<int> nums = {1, 2, 3, 4};

  // * testcase 2
  // std::vector<int> nums = {3, 1, 4, 2};
  
  // * testcase 3
  std::vector<int> nums = {-1, 3, 2, 0};
  
  printArr(nums);

  // bool ans = bruteForce(nums);

  bool ans = find132pattern(nums);
  std::cout << "132 Pattern: " << ans << std::endl;
  return 0;  
}

// * run the code
// * g++ --std=c++17 13-132-pattern.cpp -o output && ./output