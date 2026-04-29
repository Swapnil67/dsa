/*
 * Leetcode - 907
 * Sum of Subarray Minimums
 * 
 * Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
 * Since the answer may be large, return the answer modulo 109 + 7.
 * 
 * Example 1
 * Input  : arr = [3, 1, 2, 4]
 * Output : 17
 * Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
 *              Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum is 17.
 * 
 * Example 2
 * Input  : arr = [1, 1]
 * Output : 3
 * 
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/
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
  for (int i = 0; i < n; ++i) {
    long long cur_min = nums[i];
    for (int j = i; j < n; ++j) {
      cur_min = min(cur_min, (long long)nums[j]);
      sum += cur_min;
    }
    // cout << sum << endl;
  }
  return sum;
}

// * Previous Smaller or Equal Element
// * TC = O(N)
vector<int> get_pse(vector<int> &nums) {
  int n = nums.size();
  stack<int> st;
  vector<int> pse(n, -1);      

  for (int i = 0; i < n; ++i) {
    while (!st.empty() && nums[st.top()] >= nums[i]) {
      st.pop();
    }

    // * top will be smaller than current element
    // * since stack is in increasing order
    if (st.size())
      pse[i] = st.top();

    st.push(i);
  }
  return pse;
}

// * Next Smaller element
// * TC = O(N)
vector<int> get_nse(vector<int> &nums) {
  int n = nums.size();
  stack<int> st;
  vector<int> nse(n, n);

  for (int i = 0; i < n; ++i) {
    while (!st.empty() && nums[st.top()] >= nums[i]) {
      nse[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  return nse;
}

// * Get nse & pse both from single function
void helper(vector<int> &arr, vector<int> &pse, vector<int> &nse) {
  int n = arr.size();
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && arr[st.top()] >= arr[i]) {
      nse[st.top()] = i;
      st.pop();
    }
    if (!st.empty()) {
      pse[i] = st.top();
    }
    st.push(i);
  }
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * TC = O(N)
// * SC = O(N)
int sumSubarrayMins(vector<int> nums) {
  int n = nums.size();

  vector<int> pse = get_pse(nums);
  cout << "Previous Smaller Elements: ";
  printArr(pse);
  
  vector<int> nse = get_nse(nums);
  cout << "Next Smaller Elements: ";
  printArr(nse);

  long long sum = 0;
  const int M = 1e9 + 7;

  for (int i = 0; i < n; ++i) {
    int ps = i - pse[i]; // * Left mai kitne elements honge
    int ns = nse[i] - i; // * Right mai kitne elements honge
    long long total_subarrays = ps * ns;
    // cout << total_subarrays << endl;
    // * itne total_subarrays subarrays honge jinka minimum is arr[i]
    long long total_sum = total_subarrays * nums[i];
    // cout << total_sum << endl;
    sum = (sum + total_sum) % M;
  }
  
  cout << "Smallest Sum: " << sum << endl;
  return sum;
}

int main() {
  // * testcase 1
  // vector<int> nums = {1, 1};      // * Edge case
  
  // * testcase 2
  vector<int> nums = {3, 1, 2, 4};
  
  // * testcase 3
  // vector<int> nums = {11, 81, 94, 43, 3};
  
  cout << "Input Array" << endl;
  printArr(nums);
  
  // long long ans = bruteForce(nums);
  long long ans = sumSubarrayMins(nums);
  
  cout << "Sum of Subarray Minimums: " << ans << endl;

  return 0;
}

// * run the code
// * g++ --std=c++20 14A-sum-of-subarray-minimums.cpp -o output && ./output
