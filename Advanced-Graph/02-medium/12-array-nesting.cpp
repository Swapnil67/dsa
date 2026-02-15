/*
 * Leetcode - 565
 * Array Nesting
 * 
 * You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].
 * You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:
 * - The first element in s[k] starts with the selection of the element nums[k] of index = k.
 * - The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
 * - We stop adding right before a duplicate element occurs in s[k].
 * 
 * Return the longest length of a set s[k].
 * 
 * Example 1    :
 * Input        : nums = [5,4,0,3,1,6,2]
 * Output       : 4
 * Explanation  :  One of the longest sets s[k]: {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}

 * Example 2    :
 * Input        : nums = [0,1,2]
 * Output       : 1
 * 
 * https://leetcode.com/problems/array-nesting/description/
*/

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * ------------------------- APPROACH 1: Brute Force Approach -------------------------
// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<int> &nums) {
  int n = nums.size(), ans = 0;
  vector<bool> visited(n, false);
  for (int x : nums) {
    int cnt = 0;
    while (!visited[x]) {
      cnt += 1;
      visited[x] = true;
      x = nums[x];
    }
    ans = max(ans, cnt);
  }
  return ans;
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(1)
int arrayNesting(vector<int> &nums) {
  int n = nums.size(), ans = 0;
  for (int x : nums) {
    if (x == -1)
      continue;

    int cnt = 0;
    while (nums[x] != -1) {
      cnt += 1;
      int prev = x;
      x = nums[x];
      nums[prev] = -1;
    }
    ans = max(ans, cnt);
  }
  return ans;
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 12-array-nesting.cpp -o output && ./output
