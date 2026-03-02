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
 * https://www.naukri.com/code360/problems/two-sum_4244495
 * https://www.geeksforgeeks.org/problems/two-sum-in-sorted-array/1
*/

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}
// * ------------------------- Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
vector<int> findTwoSumSorted(vector<int> &arr, int target) {    
  int n = arr.size();
  int i = 0, j = n - 1;
  while(i < j) {
    int cur_sum = arr[i] + arr[j];
    if (cur_sum == target) {
      return {i + 1, j + 1};
    } else if(cur_sum > target) {
      j--;
    } else {
      i++;
    }
  }
  return {-1, -1};
}

// * ------------------------- Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool findTwoSum(vector<int> arr, int target) {
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
  // * testcase 1
  int target = 9;
  vector<int> arr = {2, 7, 11, 15};

  std::cout << "Input nums: ";
  printArr(arr);
  std::cout << "target: " << target << std::endl;

  // * Note that this does not returns the index
  // bool ans = findTwoSum(arr, target);
  // cout << "Sum found " << ans << endl;
  
  // * Note that this returns the index
  vector<int> ans = findTwoSumSorted(arr, target);
  printArr(ans);
  
  return 0;
}

// * run the code
// * g++ --std=c++17 02-two-sum-sorted-arr.cpp -o output && ./output