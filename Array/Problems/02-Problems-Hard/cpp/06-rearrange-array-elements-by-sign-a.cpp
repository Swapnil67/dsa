/*
 * Rearrange Array Elements by Sign
 * You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
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

#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N) + O(N) = O(2N)
// * SPACE COMPLEXITY O(N)
std::vector<int> bruteForce(std::vector<int> &arr) {
  std::vector<int> n_pos;
  std::vector<int> n_neg;
  int n = arr.size();

  // * O(N)
  for(int i=0; i<n; i++) {
    if(arr[i] >= 0) {
      n_pos.push_back(arr[i]);
    }
    else {
      n_neg.push_back(arr[i]);
    }
  }

  // * O(N)
  for(int i=0; i<n/2; i++) {
    arr[2*i] = n_pos[i];
    arr[2*i+1] = n_neg[i];
  }
  // * OR
  // for(int i=0; i<n/2; i++) {
  //   arr.push_back(p_arr[i]);
  //   arr.push_back(n_arr[i]);
  // }

  return arr;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Only works when +ve and -ve elements same in count
// * TIME COMPLEXITY O(N) 
// * SPACE COMPLEXITY O(N)
std::vector<int> optimalApproach(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> ans(n);
  // * Intialize the positive & negative indexes
  int p_index = 0, n_index = 1;
  for(int i=0; i<n; i++) {
    if(arr[i] < 0) {
      ans[n_index] = arr[i];
      n_index += 2; // * next negative index
    }
    else {
      ans[p_index] = arr[i];
      p_index += 2; // * next positive index
    }
  }
  return ans;
}

int main() {
  std::vector<int> arr = {1, 2, -4, -5};
  std::cout<<"Before Rearranging"<<std::endl;
  printArr(arr);

  std::cout<<"After Rearranging"<<std::endl;
  // std::vector<int> ans = bruteForce(arr);
  std::vector<int> ans = optimalApproach(arr);
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++17 06-rearrange-array-elements-by-sign-a.cpp -o 06-rearrange-array-elements-by-sign-a && ./06-rearrange-array-elements-by-sign-a