/*
 * Leetcode - 962
 * Maximum Width Ramp
 * 
 * Example 1
 * Input       : nums = [6,0,8,2,1,5]
 * Output      : 4
 * Explanation : The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
 * 
 * Example 2
 * Input       : nums = [9,8,1,0,1,9,4,0,4,1]
 * Output      : 7
 * Explanation : The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
 * 
 * Example 3
 * Input       : nums = [2,2,1]
 * Output      : 1
 * Explanation : The maximum width ramp is achieved at (i, j) = (0, 1): nums[0] = 2 and nums[1] = 2.
 * 
 * https://leetcode.com/problems/maximum-width-ramp/description/
*/

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


void printStack(stack<int> st) {
  cout << "-------- stack --------\n";
  while (!st.empty()) {
    printf("%d ", st.top());
    st.pop();
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: Brute Approach -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> &nums) {
  int n = nums.size();
  int ans = INT_MIN;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (nums[i] <= nums[j]) {
        ans = max(ans, j - i);
      }
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int betterApproach(vector<int> &nums) {
  int n = nums.size();
  int ans = INT_MIN;
  
  for (int i = 0; i < n; ++i) {
    // * start from the back for every 'i'
    int j = n - 1;
    while (nums[i] > nums[j]) {
      j--;
    }
    ans = max(ans, j - i);
  }

  return ans < 0 ? 0 : ans;
}


// * ------------------------- APPROACH 3A: Optimal Approach -------------------------`
// * Find Max to right for input nums + Two Pointers
// * TIME COMPLEXITY O(2N) ~ O(N)
// * SPACE COMPLEXITY O(N)
int maxWidthRampA(vector<int> &nums) {
  int n = nums.size();
  int ans = INT_MIN;

  // * Create a vector where for each element next greater element
  vector<int> max_to_right(n);
  int curMax = INT_MIN;
  for (int i = n - 1; i >= 0; --i) {
    curMax = max(curMax, nums[i]);
    max_to_right[i] = curMax;
  }
  printArr(max_to_right);

  int i = 0, j = 0;
  while (j < n) {
    if (nums[i] <= max_to_right[j]) {
      ans = max(ans, j - i);
    } else {
      i++;
    }
    j++;
  }

  return ans < 0 ? 0 : ans;
}

// * ------------------------- APPROACH 3B: Optimal Approach -------------------------`
// * Monotonic Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int maxWidthRampB(vector<int> &nums) {
  int n = nums.size();

  // * Decreasing stack
  stack<int> st;
  st.push(0);
  for (int i = 1; i < n; ++i) {
    if (nums[st.top()] > nums[i]) { // * Prev ele should be greater for decreasing order
      st.push(i);
    }
  }
  printStack(st); // * For debugging

  if (st.empty())
    return 0;
    
  int ans = 0;
  int j = n - 1;
  while(!st.empty()) {
    while(!st.empty() && nums[st.top()] <= nums[j]) {
      ans = max(ans, j - st.top());
      st.pop();
    }
    j--;
  }

  return ans;
}



int main() {
  // * testcase 1
  vector<int> nums = {6, 0, 8, 2, 1, 5};

  // * testcase 2
  // vector<int> nums = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
  
  // * testcase 3
  // vector<int> nums = {2, 2, 1};

  cout << "Input nums: ";
  printArr(nums);

  // int ans = bruteForce(nums);
  // int ans = betterApproach(nums);
  // int ans = maxWidthRampA(nums);
  int ans = maxWidthRampB(nums);
  
  cout << "Maximum Width Ramp: " << ans << endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 17-max-width-ramp.cpp -o output && ./output
