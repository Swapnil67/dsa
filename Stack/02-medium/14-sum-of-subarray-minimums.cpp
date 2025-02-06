/*
 * Sum of Subarray Minimums
 * Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
 * Since the answer may be large, return the answer modulo 109 + 7.

 * * Example 1
 * * Input  : arr = [3,1,2,4]
 * * Output : 17
 * 
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/
*/

#include <iostream>
#include <vector>
#include <stack>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int bruteForce(std::vector<int> nums) {
  int n = nums.size();
  long long sum = 0;
  for(int i = 0; i < n; ++i) {
    long long cur_min = nums[i];
    long long cur_sum = 0;
    for(int j = i; j < n; ++j) {
      if(cur_min > nums[j]) {
        cur_min = nums[j];
      }
      cur_sum += cur_min;
    }
    // std::cout << cur_sum << std::endl;
    sum += cur_sum;
  }
  return sum;
}

// * Next Smallest To Left
// * TC = O(N)
std::vector<int> nsl_vec(std::vector<int> &nums) {
  int n = nums.size();
  std::stack<int> st;
  std::vector<int> nsl(n, -1);      

  for (int i = 0; i < n; ++i) {
    while (!st.empty() && nums[st.top()] >= nums[i]) {
      st.pop();
    }
    nsl[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  return nsl;
}

// * Next Smallest To Right
// * TC = O(N)
std::vector<int> nsr_vec(std::vector<int> &nums) {
  int n = nums.size();
  std::stack<int> st;
  std::vector<int> nsr(n, n);

  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && nums[st.top()] > nums[i]) {
      st.pop();
    }
    nsr[i] = st.empty() ? n : st.top();
    st.push(i);
  }
  return nsr;
}

// * TC = O(N)
// * SC = O(N)
int sumSubarrayMins(std::vector<int> nums) {
  int n = nums.size();

  std::vector<int> nsl = nsl_vec(nums);
  std::vector<int> nsr = nsr_vec(nums);
  // printArr(nsl);
  // printArr(nsr);

  long long sum = 0;
  const int M = 1e9 + 7;

  for (int i = 0; i < n; ++i) {
    int ls = i - nsl[i];  // * Left mai kitne elements honge
    int rs = nsr[i] - i;  // * Right mai kitne elements honge
    long long total_subarrays = ls * rs;
    // * itne total_subarrays subarrays honge jinka minimum is arr[i]
    long long total_sum = total_subarrays * nums[i];
    sum = (sum + total_sum) % M;
  }
  
  return sum;
}

int main() {
  std::vector<int> nums = {3, 1, 2, 4};
  // std::vector<int> nums = {11, 81, 94, 43, 3};

  printArr(nums);
  // long long ans = bruteForce(nums);
  long long ans = sumSubarrayMins(nums);
  std::cout << "Sum of Subarray Minimums: " << ans << std::endl;
  return 0;
}

// * run the code
// * $CXX --std=c++17 14-sum-of-subarray-minimums.cpp -o output && ./output
