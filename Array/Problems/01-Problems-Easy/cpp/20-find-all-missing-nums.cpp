/**
 * * Find All Numbers Disappeared in an Array
 * * Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all 
 * * the integers in the range [1, n] that do not appear in nums.

 * * Example 1
 * * Input  : nums = [4,3,2,7,8,2,3,1]
 * * Output : [5,6]

 * * Example 2
 * * Input  : nums = [1,1]
 * * Output : [2]
 * 
 * * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

bool linearSearch(std::vector<int> arr, int target) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    if(arr[i] == target) return true;
  }
  return false;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N1) [For answer only]
std::vector<int> bruteForce(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if(!linearSearch(arr, i)) {
      ans.push_back(i);
    }
  }
  return ans;
}

std::vector<int> betterApproach(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> hashArr(n, 0);
  for (int i = 0; i < n; i++) {
    hashArr[arr[i]] = 1;
  }

  std::vector<int> ans;
  for (int i = 1; i <= hashArr.size(); i++) {
    if(hashArr[i] == 0) {
      ans.push_back(i);
    }
  }

  return ans;
}

int main() {
  std::cout << "Input Array" << std::endl;
  // * testcase 1
  // std::vector<int> arr = {1, 1};
  // * testcase 2
  std::vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
  printArr(arr);

  // std::vector<int> ans = bruteForce(arr);
  std::vector<int> ans = betterApproach(arr);
  std::cout << "Missing Numbers" << std::endl;
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++17 20-find-all-missing-nums.cpp -o 20-find-all-missing-nums && ./20-find-all-missing-nums
