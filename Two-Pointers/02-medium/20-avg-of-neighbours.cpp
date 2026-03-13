/*
 * Leetcode - 1968
 * Array With Elements Not Equal to Average of Neighbors 
 * 
 * You are given a 0-indexed array nums of distinct integers. You want to rearrange the elements in the array such that
 * every element in the rearranged array is not equal to the average of its neighbors.
 * 
 * More formally, the rearranged array should have the property such that for every i 
 * in the range 1 <= i < nums.length - 1, (nums[i-1] + nums[i+1]) / 2 is not equal to nums[i].
 * 
 * Return any rearrangement of nums that meets the requirements.
 * 
 * Example: 1
 * Input: nums = [1,2,3,4,5]
 * Output: [1,2,4,5,3]
 * 
 * Example: 2
 * Input: nums = [6,2,0,9,7]
 * Output: [9,7,6,2,0]
 * 
 * https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/description/
*/

#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>

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

// * ------------------------- APPROACH: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
// * Shuffling the array using two pointers
vector<int> rearrangeArray(vector<int> &nums) {
  // * sort the nums
  sort(nums.begin(), nums.end());

  // * Shuffle the numbers
  vector<int> ans;
  int n = nums.size();
  int l = 0, r = n - 1;
  while (ans.size() != n) {
    ans.push_back(nums[l]);
    l++;

    if (l <= r) {
      ans.push_back(nums[r]);
      r--;
    }
  }

  return ans;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
// * Shuffling the array using deque
vector<int> rearrangeArray2(vector<int> &nums) {
  // * sort the nums
  sort(nums.begin(), nums.end());

  // * create a deque with nums
  deque q(nums.begin(), nums.end());

  vector<int> ans;
  while (q.size() > 0) {
    // * push from back first
    ans.push_back(q.back());
    q.pop_back();
    
    // * push from front
    if(q.size() > 0) {
      ans.push_back(q.front());
      q.pop_front();
    }
  }

  return ans;
}

int main(void) {
  vector<int> nums = {1, 2, 3, 4, 5};

  std::cout << "Input Nums: ";
  printArr(nums);
  
  // vector<int> ans = rearrangeArray(nums);
  vector<int> ans = rearrangeArray2(nums);
  
  std::cout << "Output Nums: ";
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 20-avg-of-neighbours.cpp -o output && ./output

