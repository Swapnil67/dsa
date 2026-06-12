/*
 * Leetcode - 2233
 * Maximum Product After K Increments
 * 
 * You are given an array of non-negative integers nums and an integer k. 
 * In one operation, you may choose any element from nums and increment it by 1.
 * 
 * Return the maximum product of nums after at most k operations. Since the answer may be very large, 
 * return it modulo 109 + 7. Note that you should maximize the product before taking the modulo. 
 * 
 * Example 1
 * input  : nums = [0,4], k = 5
 * output : 20

 * Example 2
 * input  : nums = [6,3,3,2], k = 2
 * output : 216
 * 
 * https://leetcode.com/problems/maximum-product-after-k-increments
*/

#include <queue>
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

// * ------------------------- Optimal Approach -------------------------`
// * TIME COMPLEXITY O(nlogm)
// * SPACE COMPLEXITY O(n)
int maximumProduct(vector<int> &nums, int k) {
  // * Populate min heap
  priority_queue<int, vector<int>, greater<int>> pq(nums.begin(),
                                                    nums.end());

  while (k--) {
    auto num = pq.top();
    pq.pop();
    pq.push(num + 1);
  }

  int M = 1e9 + 7;
  long long ans = 1;
  while (!pq.empty()) {
    ans = ((ans % M) * (pq.top() % M)) % M;
    pq.pop();
  }
  return (int)ans;
}

int main(void) {
  // * testcase 1
  int k = 5;
  vector<int> nums = {0, 4};

  // * testcase 2
  // int k = 2;
  // vector<int> nums = {6, 3, 3, 2};

  // * testcase 2
  // int k = 54;
  // vector<int> nums = {24, 5, 64, 53, 26, 38};

  cout << "k: " << k << endl; 
  cout << "Nums: ";
  printArr(nums);

  int ans = maximumProduct(nums, k);
  cout << "Maximum Product After K Increments: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 22-maximum-product-after-k-increments.cpp -o output && ./output