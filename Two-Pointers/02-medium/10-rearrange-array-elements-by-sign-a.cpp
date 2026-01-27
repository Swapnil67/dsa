/*
 * Leetcode - 2149
 * Rearrange Array Elements by Sign
 * You are given a 0-indexed integer array nums of even length consisting of an equal number of
 * positive and negative integers.
 * 
 * Example 1:
 * Input: nums = [3,1,-2,-5,2,-4]
 * Output: [3,-2,1,-5,2,-4]
 * Explanation: The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].

 * Example 2:
 * Input: nums = [-1,1]
 * Output: [1,-1]
 * Explanation: 1 is the only positive integer and -1 the only negative integer in nums.
 * 
 * https://www.naukri.com/code360/problems/alternate-numbers_6783445
 * https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
*/

// ! Here number of -ve & +ve integers are equal

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Create different arrays for +ve & -ve elements
// * TIME COMPLEXITY O(N) + O(N/2)
// * SPACE COMPLEXITY O(N)
std::vector<int> bruteForce(std::vector<int> &arr) {
  std::vector<int> n_pos;
  std::vector<int> n_neg;
  int n = arr.size();

  // * O(N)
  for (int i = 0; i < n; i++) {
    if (arr[i] >= 0) 
      n_pos.push_back(arr[i]);
    else
      n_neg.push_back(arr[i]);
  }

  // * O(N/2)
  for (int i = 0; i < n / 2; i++) {
    arr[2 * i] = n_pos[i];
    arr[2 * i + 1] = n_neg[i];
  }
  return arr;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Take +ve and -ve indexes in variable 
// * TIME COMPLEXITY O(N) 
// * SPACE COMPLEXITY O(N)
std::vector<int> rearrangeArray(std::vector<int> arr) {
  int n = arr.size();

  // * initialize the ans array
  std::vector<int> ans(n);

  // * Intialize the positive & negative indexes
  int p_index = 0; // * even index
  int n_index = 1; // * odd index
  for (int i = 0; i < n; i++) {
    if(arr[i] < 0) {
      ans[n_index] = arr[i];
      n_index += 2; // * next negative index
    } else {
      ans[p_index] = arr[i];
      p_index += 2; // * next positive index
    }
  }
  return ans;
}

int main() {
  std::vector<int> arr = {1, 2, -4, -5};
  std::cout << "Before Rearranging" << std::endl;
  printArr(arr);

  // std::vector<int> ans = bruteForce(arr);
  std::vector<int> ans = rearrangeArray(arr);
  
  std::cout << "After Rearranging" << std::endl;
  printArr(ans);
  
  return 0;
}

// * Run the code
// * g++ --std=c++17 10-rearrange-array-elements-by-sign-a.cpp -o output && ./output