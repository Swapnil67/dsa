/*
 * Maximum Product Subarray
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

 * https://www.naukri.com/code360/problems/subarray-with-maximum-product_6890008
 * https://leetcode.com/problems/maximum-product-subarray/description/
*/

#include<iostream>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}


int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  int maxProduct = INT_MIN;
  for (int i = 0; i < n; i++) {
    int curProd = 1;
    for (int j = i; j < n; j++) {
      curProd *= arr[j];
      maxProduct = std::max(maxProduct, curProd);
    }
  }
  return maxProduct;
}

int findMaxProduct(std::vector<int> arr) {
  int n = arr.size(), maxProduct = INT_MIN;
  int curProduct = 1;
  for (int i = 0; i < n; i++) {
    if(arr[i] * curProduct < 0) {
      curProduct = 1;
    }
    else {
      curProduct *= arr[i];
      maxProduct = std::max(maxProduct, curProduct);
    }
  }
  return maxProduct;
}

int main() {
  // * testcase 1
  std::vector<int> arr = {2, 3, -2, 4};
  // * testcase 2
  // std::vector<int> arr = {-2, 0, -1};
  printArr(arr);
  // int maxProduct = bruteForce(arr);
  int maxProduct = findMaxProduct(arr);
  std::cout << "Maximum product subarray is " << maxProduct << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 14-maximum-product-subarray.cpp -o 14-maximum-product-subarray && ./14-maximum-product-subarray