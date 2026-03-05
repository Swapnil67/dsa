/*
 * Sum of Subarray Maximum
 *
 * Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
 * Since the answer may be large, return the answer modulo 109 + 7.
 * 
 * Example 1
 * Input  : arr = [3, 1, 2, 4]
 * Output : 30
 * 
 * Example 2
 * Input  : arr = [1, 1]
 * Output : 3
 * 
 * https://www.geeksforgeeks.org/problems/sum-of-max-of-subarrays/1
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

// * ------------------------- APPROACH 1: Brute Approach -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> nums) {
  int n = nums.size();
  long long sum = 0;
  for(int i = 0; i < n; ++i) {
    long long curMax = nums[i];
    long long cur_sum = 0;
    for(int j = i; j < n; ++j) {
      curMax = max(curMax, (long long)nums[j]);
      cur_sum += curMax;
    }
    // cout << cur_sum << endl;
    sum += cur_sum;
  }
  return sum;
}

// * Next Greater Element
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
vector<int> nextGreater(vector<int> &nums) {
  int n = nums.size();

  vector<int> nge(n, n);
  stack<int> st;

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
vector<int> prevGreater(vector<int> &nums) {
  int n = nums.size();

  vector<int> pge(n, -1);
  stack<int> st;

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
int sumSubarrayMaxs(vector<int> nums) {
  int n = nums.size();

  vector<int> nge = nextGreater(nums);
  printArr(nge);
  vector<int> pge = prevGreater(nums);
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
  cout << "Input Array" << endl;
  // * testcase 1
  vector<int> nums = {1, 1};      // * Edge case

  // * testcase 2
  // vector<int> nums = {3, 1, 2, 4};

  // * testcase 3
  // vector<int> nums = {11, 81, 94, 43, 3};

  printArr(nums);
  
  // long long ans = bruteForce(nums);
  long long ans = sumSubarrayMaxs(nums);
  cout << "Sum of Subarray Minimums: " << ans << endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 14B-sum-of-subarray-maximums.cpp -o output && ./output
