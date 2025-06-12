/*
 * Leetcode - 167
 * Two Sum II - Input Array Is Sorted
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
 * find two numbers such that they add up to a specific target number.
 * Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
 * 
 * Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
 * 
 * Example 1
 * Input  : numbers = [2,7,11,15], target = 9
 * Output : [1, 2]
 * 
 * Example 2
 * Input  : numbers = [2,3,4], target = 6
 * Output : [1, 3]
 * 
 * Example 3
 * Input  : numbers = [-1,0], target = -1
 * Output : [1, 2]
 * 
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*/

#include <iostream>
#include <vector>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::vector<int> findTwoSumSorted(std::vector<int> &arr, int target) {    
  int n = arr.size();
  std::vector<int> ans;
  int i = 0, j = n - 1;
  while(i < j) {
    int cur_sum = arr[i] + arr[j];
    if(cur_sum == target) {
      ans.push_back(i + 1);
      ans.push_back(j + 1);
      return ans;
    }
    else if(cur_sum > target) {
      j--;
    }
    else {
      i++;
    }
  }
  return ans;
}

// * ------------------------- Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool findTwoSum(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while (l < r) {
    int sum = arr[l] + arr[r];
    if (sum == target) {
      return true;
    }
    if (sum > target)
      r -= 1;
    else
      l += 1;
  }
  return false;
}

int main() {
  int target = 9;
  std::vector<int> arr = {2, 7, 11, 15};
  printArr(arr);

  // * Note that this does not returns the index
  bool ans = findTwoSum(arr, target);
  std::cout << "Sum found " << ans << std::endl;
  
  // * Note that this returns the index
  // std::vector<int> ans = findTwoSumSorted(arr, target);
  // printArr(ans);
  return 0;
}

// * run the code
// * g++ --std=c++17 02-two-sum-sorted-arr.cpp -o output && ./output