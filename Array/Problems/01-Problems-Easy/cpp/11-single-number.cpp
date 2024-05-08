/**
 * * Single Number
 * * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

 * * Example 1
 * * Input  : 'arr' = [2,2,1]
 * * Output : 1

 * * Example 2
 * * Input  : 'arr' = [4,1,2,1,2]
 * * Output : 4
 * 
 * * Example 3
 * * Input  : 'arr' = [1]
 * * Output : 1

 * * https://leetcode.com/problems/single-number/description/
 * * https://www.naukri.com/code360/problems/find-the-single-element_6680465
*/

#include<iostream>

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) {
    int numCount = 0, num = arr[i];
    for(int j = 0; j<n; j++) {
      if(arr[j] == num) {
        numCount++;
      }
    }
    if(numCount == 1) {
      return num;
    }
  }
  return 0;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
int betterApproach(std::vector<int> arr) {
  
}


int main() {
  // std::vector<int> arr = { 1, 1, 2, 3, 3, 4, 4 };
  std::vector<int> arr = { 8, 8, 9, 9, 10 };
  int singleNumber = bruteForce(arr);
  std::cout<<"Single Number "<<singleNumber<<std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 11-single-number.cpp -o 11-single-number && ./11-single-number