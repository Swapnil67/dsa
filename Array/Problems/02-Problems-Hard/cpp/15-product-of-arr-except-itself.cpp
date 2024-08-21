/*
 * Product of Array Except Self
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all 
 * * the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * 
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * 
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]

 * https://www.naukri.com/code360/library/product-of-array-except-self
 * https://leetcode.com/problems/product-of-array-except-self/description/
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void reverse(std::vector<int> &arr) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while (l < r) {
    swap(arr[l++], arr[r--]);
  }
}

// * ------------------------- APPROACH 1 -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> ans;
  for (int i = 0; i < n; ++i) {
    int sum = 1;
    for (int j = 0; j < n; ++j) {
      if(i != j) {
        sum *= arr[j];
      }
    }
    ans.push_back(sum);
  }
  return ans;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Use Prefix & Postfix Arrays
// * TIME COMPLEXITY O(3N)
// * SPACE COMPLEXITY O(2N)
std::vector<int> betterApproach(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> prefixArr;
  std::vector<int> postFixArr;

  int pre = 1;
  for (int i = 0; i < n; ++i) {
    pre *= arr[i];
    prefixArr.push_back(pre);
  }
  // printArr(prefixArr);

  int post = 1;
  for (int i = n - 1; i >= 0; --i) {
    post *= arr[i];
    postFixArr.push_back(post);
  }
  reverse(postFixArr);

  // printArr(postFixArr);

  std::vector<int> ans;
  for (int i = 0; i < n; ++i) {
    pre = 1, post = 1;
    if(i > 0) {
      pre = prefixArr[i - 1];
    }
    if (i < n - 1) {
      post = postFixArr[i + 1];
    }
    // std::cout << "i: " << i << " = " << pre << " => " << post << std::endl;
    ans.push_back(pre * post);
  }

  return ans;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * Use answer as a prefix array
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
std::vector<int> productExceptSelf(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> ans(n);

  int pre = 1;
  for (int i = 0; i < n; ++i) {
    ans[i] = pre;
    pre *= arr[i];
  }
  // printArr(ans);

  int post = 1;
  for (int i = n - 1; i >= 0; --i) {
    ans[i] = ans[i] * post;
    post *= arr[i];
  }
  // printArr(ans);

  return ans;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {1, 2, 3, 4};
  // * testcase 2
  std::vector<int> arr = {1, 2, 4, 6};

  printArr(arr);
  // std::vector<int> ans = bruteForce(arr);
  // std::vector<int> ans = betterApproach(arr);
  std::vector<int> ans = productExceptSelf(arr);
  printArr(ans);
  return 0;
}

// * g++ --std=c++17 15-product-of-arr-except-itself.cpp -o output && ./output