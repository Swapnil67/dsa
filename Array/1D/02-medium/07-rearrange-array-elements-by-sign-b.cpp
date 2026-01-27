/*
 * Leetcode - 2149
 * Rearrange Array Elements by Sign
 * 
 * You are given a 0-indexed integer array nums of even length consisting of an variable number of positive
 * and negative integers.
 * 
 * Example 1:
 * Input: nums = [3,1,-2,-5,2,-4,7,8]
 * Output: [3,-2,1,-5,2,-4,7,8]
 * Explanation: The positive integers in nums are [3,1,2,7,8]. The negative integers are [-2,-5,-4].

 * https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
 * https://www.naukri.com/code360/problems/alternate-positive-and-negative_893342
 * https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
*/

// ! Amazon, Google, Meta, Microsoft, Apple

// ! Here number of -ve & +ve integers are not equal

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N) + O(N) = O(2N)
// * SPACE COMPLEXITY O(N)
void rearrangeBySign(std::vector<int> &arr) {
  std::vector<int> positive_nums;
  std::vector<int> negative_nums;
  int n = arr.size();

  // * Step 1:
  // * Put the +ve & -ve nums in respective arrays
  for (int i = 0; i < n; i++) {
    if (arr[i] >= 0)
      positive_nums.push_back(arr[i]);
    else
      negative_nums.push_back(arr[i]);
  }
  
  // * Step 2
  // * Check which numbers are greater in length +ve or -ve
  int posLength = positive_nums.size(), negLength = negative_nums.size();
  if (posLength > negLength) {
    // * More +ve than -ve numbers
    // * Step 3
    // * Rearrage numbers till negLength
    for (int i = 0; i < negLength; i++) {
      arr[2 * i] = positive_nums[i];
      arr[2 * i + 1] = negative_nums[i];
    }

    // * Step 4
    // * Put the remaining positive to end of array
    int idx = negLength * 2;
    for (int i = negLength; i < posLength; i++) {
      arr[idx] = positive_nums[i];
      idx++;
    }
  }
  else {
    // * More -ve than +ve numbers
    // * Step 3
    // * Rearrage numbers till posLength
    for (int i = 0; i < posLength; i++) {
      arr[2 * i] = positive_nums[i];
      arr[2 * i + 1] = negative_nums[i];
    }

    // * Step 4
    // * Put the remaining negative to end of array
    int idx = posLength * 2;
    for (int i = posLength; i < negLength; i++) {
      arr[idx] = negative_nums[i];
      idx++;
    }
  }
}

// * ------------------------- Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
void rearrangeBySignB(std::vector<int> &arr) {
  int n = arr.size();

  // * Step 1:
  // * Put the +ve & -ve nums in respective arrays
  std::vector<int> positive_nums, negative_nums;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= 0)
      positive_nums.push_back(arr[i]);
    else
      negative_nums.push_back(arr[i]);
  }

  // * Step 2
  // * Two pointer loop
  int n1 = positive_nums.size(), n2 = negative_nums.size();
  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    arr[2 * i] = positive_nums[i];
    i++;
    arr[2 * j + 1] = negative_nums[j];
    j++;
  }

  int idx = i + j;
  if (i != n1 - 1) {
    while(i < n1)
      arr[idx++] = positive_nums[i++];
  }
  else {
    while(j < n2)
      arr[idx++] = negative_nums[j++];
  }
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {3, 1, -2, -5, 2, -4, 7, 8};
  
  // * testcase 2
  std::vector<int> arr = {3, 1, -2, -5, 2, -4, -7, -8, 3, -9};

  std::cout<<" ----- Before Rearranging ----- "<<std::endl;
  printArr(arr);
  std::cout<<" ----- After Rearranging ----- "<<std::endl;
  rearrangeBySign(arr);

  printArr(arr);
}

// * Run the code
// * g++ --std=c++20 07-rearrange-array-elements-by-sign-b.cpp -o output && ./output

