/*
 * Sum of Subarray Maximum
 * Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
 * Since the answer may be large, return the answer modulo 109 + 7.

 * * Example 1
 * * Input  : arr = [3, 1, 2, 4]
 * * Output : 17

 * * Example 2
 * * Input  : arr = [1, 1]
 * * Output : 3
 * 
*/

#include <stack>
#include <vector>
#include <iostream>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: Brute Approach -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> nums) {
  int n = nums.size();
  long long sum = 0;
  for(int i = 0; i < n; ++i) {
    long long curMax = nums[i];
    long long cur_sum = 0;
    for(int j = i; j < n; ++j) {
      curMax = std::max(curMax, (long long)nums[j]);
      cur_sum += curMax;
    }
    // std::cout << cur_sum << std::endl;
    sum += cur_sum;
  }
  return sum;
}

// * Next Greater Element
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
std::vector<int> nextGreater(std::vector<int> &nums) {
  int n = nums.size();

  std::vector<int> nge(n, n);
  std::stack<int> st;

  for (int i = 0; i < n; ++i) {
    while (!st.empty() && nums[st.top()] <= nums[i]) {
      nge[st.top()] = i;
      st.pop();
    }

    st.push(i);
  }

  return nge;
}

// * Previous Greater Element
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
std::vector<int> prevGreater(std::vector<int> &nums) {
  int n = nums.size();

  std::vector<int> pge(n, -1);
  std::stack<int> st;

  for (int i = 0; i < n; ++i) {
    while (!st.empty() && nums[st.top()] <= nums[i]) {
      st.pop();
    }

    if (st.size()) {
      pge[i] = st.top();
    } 

    st.push(i);
  }

  return pge;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * TC = O(N)
// * SC = O(N)
int sumSubarrayMaxs(std::vector<int> nums) {
  int n = nums.size();

  std::vector<int> nge = nextGreater(nums);
  printArr(nge);
  std::vector<int> pge = prevGreater(nums);
  printArr(pge);

  int M = 1e9 - 7;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    int ng = nge[i] - i;      // * Next Greater 
    int pg = i - pge[i];      // * Prev Greater

    long long total_subarrays = ng * pg;
    sum = (sum + (total_subarrays * nums[i])) % M;
  }

  return sum;
}


int main() {
  std::cout << "Input Array" << std::endl;
  // * testcase 1
  // std::vector<int> nums = {1, 1};      // * Edge case

  // * testcase 2
  std::vector<int> nums = {3, 1, 2, 4};

  // * testcase 3
  // std::vector<int> nums = {11, 81, 94, 43, 3};

  printArr(nums);
  
  // long long ans = bruteForce(nums);
  long long ans = sumSubarrayMaxs(nums);
  std::cout << "Sum of Subarray Minimums: " << ans << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 14B-sum-of-subarray-maximums.cpp -o output && ./output
