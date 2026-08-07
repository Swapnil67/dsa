/*
 * Leetcode - 153
 * Maximum Product Subarray
 * 
 * Given an integer array nums, find a subarray that has the largest product, and return the product.
 * 
 * Example 1:
 * Input: nums = [2, 3, -2, 4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * Example 2:
 * Input: nums = [-2, 0, -1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 * https://leetcode.com/problems/maximum-product-subarray/description/
 * https://www.naukri.com/code360/problems/subarray-with-maximum-product_6890008
*/

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

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Nested Loop [Find all subarray product]
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> arr) {
  int n = arr.size();
  int maxProduct = INT_MIN;
  for (int i = 0; i < n; i++) {
    int curProd = 1;
    for (int j = i; j < n; j++) {
      curProd *= arr[j];
      maxProduct = max(maxProduct, curProd);
    }
  }
  return maxProduct;
}

// * ------------------------- APPROACH 2: Optimal Approach A -------------------------`
// * Prefix & Suffix product
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int findMaxProduct(vector<int> arr) {
  int n = arr.size(), maxProduct = INT_MIN;
  int prefix = 1, suffix = 1;
  for (int i = 0; i < n; i++) {
    if(prefix == 0) prefix = 1;
    if(suffix == 0) suffix = 1;
    prefix = prefix * arr[i];
    suffix = suffix * arr[n-i-1];
    maxProduct = max(maxProduct, max(prefix, suffix));
  }
  return maxProduct;
}

// * ------------------------- APPROACH 3: Optimal Approach B -------------------------`
// * Kadanes algorithm
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int kadanesAlgo(vector<int> arr) {
  int n = arr.size();
  int curMax = arr[0], curMin = arr[0], res = arr[0];
  for (int i = 1; i < n; i++) {
    int temp = curMax * arr[i];
    curMax = max(max(temp, curMin * arr[i]), arr[i]);
    curMin = min(min(temp, curMin * arr[i]), arr[i]);
    res = max(curMax, res);
  }
  return res;
}


int main() {
  // * testcase 1
  // vector<int> arr = {2, 3, -2, 4};
  
  // * testcase 2
  // vector<int> arr = {-2, 0, -1};

  // * testcase 3
  vector<int> arr = {-5, 2, 3, 4, -1};

  printArr(arr);
  
  // int maxProduct = bruteForce(arr);
  int maxProduct = findMaxProduct(arr);
  // int maxProduct = kadanesAlgo(arr);

  cout << "Maximum product subarray is " << maxProduct << endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 03-maximum-product-subarray.cpp -o output && ./output