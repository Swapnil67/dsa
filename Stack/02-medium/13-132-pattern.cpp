/*
 * 132 Pattern
 * Leetcode - 456
 * 
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
// ! Meta, Amazon, Google

#include <stack>
#include <vector>
#include <climits>
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

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^3)
// * SPACE COMPLEXITY O(1)
bool bruteForce(vector<int> nums) {
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
bool betterApproach(vector<int> nums) {
  int n = nums.size();

  int num_i = nums[0];      // * keep 'i' value as pointer
  for (int j = 1; j < n; ++j) {
    num_i = min(num_i, nums[j]);
    for (int k = j + 1; k < n; ++k) {
      if (num_i < nums[k] && nums[k] < nums[j])
        return true;
    }
  }

  return false;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------
// * num1 < num3 < num2 
// * num2 will be largest & num3 will be second largest
// * Using Monotonic Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool find132pattern(vector<int> nums) {
  int n = nums.size();
  int num3 = INT_MIN; 
  stack<int> st;

  // * consider st.top() as the largest element (i.e., num2)
  // * consider nums[j] as num1

  for (int j = n - 1; j >= 0; --j) {

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
  // vector<int> nums = {1, 2, 3, 4};

  // * testcase 2
  // vector<int> nums = {3, 1, 4, 2};
  
  // * testcase 3
  vector<int> nums = {-1, 3, 2, 0};

  cout << "Input nums: " << endl;
  printArr(nums);

  // bool ans = bruteForce(nums);
  // bool ans = betterApproach(nums);
  bool ans = find132pattern(nums);
  
  cout << "132 Pattern: " << ans << endl;

  return 0;  
}

// * run the code
// * g++ --std=c++17 13-132-pattern.cpp -o output && ./output