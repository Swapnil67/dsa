/**
 * * Contains Duplicate
 * * Given an integer array nums, return true if any value appears at least twice in the array, and return false if
 * * every element is distinct.

 * * Example 1
 * * Input  : nums = [1,2,3,1]
 * * Output : true

 * * Example 2
 * * Input  : nums = [1,2,3,4]
 * * Output : false

 * * https://leetcode.com/problems/contains-duplicate/description/
*/

#include <set>
#include <iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

bool containsDuplicate(std::vector<int> &nums) {
  std::set<int> st;
  for (int i = 0; i < nums.size(); i++) {
    if (st.find(nums[i]) != st.end()) {
      return true;
    }
    st.insert(nums[i]);
  }
  return false;
}

int main() {
  // std::vector<int> arr = {1, 2, 3, 4};
  std::vector<int> arr = {1, 2, 3, 1};
  std::cout<<"Input Array "<<std::endl;
  printArr(arr);
  bool isDuplicate = containsDuplicate(arr);
  std::cout<<"Does array contains duplicate "<<isDuplicate<<std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 14-contains-duplicate.cpp -o 14-contains-duplicate && ./14-contains-duplicate