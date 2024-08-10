/*
 * Rearrange Array Elements by Sign
 * You are given a 0-indexed integer array nums of even length consisting of an variable number of positive
 * and negative integers.
 * 
 * Example 1:
 * Input: nums = [3,1,-2,-5,2,-4,7,8]
 * Output: [3,-2,1,-5,2,-4,7,8]
 * Explanation: The positive integers in nums are [3,1,2,7,8]. The negative integers are [-2,-5,-4].

 * https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
 * https://www.naukri.com/code360/problems/alternatives_893342
*/

// ! Here number of -ve & +ve integers are not equal

#include<iostream>


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
  std::vector<int> positiveNums;
  std::vector<int> negativeNums;
  int n = arr.size();

  // * Step 1:
  // * Put the +ve & -ve nums in respective arrays
  for (int i = 0; i < n; i++) {
    if (arr[i] >= 0)
      positiveNums.push_back(arr[i]);
    else
      negativeNums.push_back(arr[i]);
  }

  // * Step 2
  // * Check which numbers are greater in length +ve or -ve
  int posLength = positiveNums.size(), negLength = negativeNums.size();
  if(posLength > negLength) {
    // * More +ve than -ve numbers
    // * Step 3
    // * Rearrage numbers till negLength
    for (int i = 0; i < negLength; i++) {
      arr[2 * i] = positiveNums[i];
      arr[2 * i + 1] = negativeNums[i];
    }

    // * Step 4
    // * Put the remaining positive to end of array
    int idx = negLength * 2;
    for (int i = negLength; i < posLength; i++) {
      arr[idx] = positiveNums[i];
      idx++;
    }
  }
  else {
    // * More -ve than +ve numbers
    // * Step 3
    // * Rearrage numbers till posLength
    for (int i = 0; i < posLength; i++) {
      arr[2 * i] = positiveNums[i];
      arr[2 * i + 1] = negativeNums[i];
    }

    // * Step 4
    // * Put the remaining negative to end of array
    int idx = posLength * 2;
    for (int i = posLength; i < negLength; i++) {
      arr[idx] = negativeNums[i];
      idx++;
    }
  }
}

void rearrangeBySignB(std::vector<int> &arr) {
  int n = arr.size();

  // * Step 1:
  // * Put the +ve & -ve nums in respective arrays
  std::vector<int> posArr, negArr;
  for (int i = 0; i < n; i++) {
    if(arr[i] >= 0) 
      posArr.push_back(arr[i]);
    else 
      negArr.push_back(arr[i]);
  }

  // * Step 2
  // * Two pointer loop
  int n1 = posArr.size(), n2 = negArr.size();
  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    arr[2 * i] = posArr[i];
    i++;
    arr[2 * j + 1] = negArr[j];
    j++;
  }

  int idx = i + j;
  if (i != n1 - 1) {
    while(i < n1)
      arr[idx++] = posArr[i++];
  }
  else {
    while(j < n2)
      arr[idx++] = negArr[j++];
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
// * g++ --std=c++17 06-rearrange-array-elements-by-sign-b.cpp -o 06-rearrange-array-elements-by-sign-b && ./06-rearrange-array-elements-by-sign-b