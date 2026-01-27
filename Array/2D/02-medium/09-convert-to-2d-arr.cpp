/*
 * Convert an Array Into a 2D Array With Conditions
 *
 * You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
 * 
 * The 2D array should contain only the elements of the array nums.
 * Each row in the 2D array contains distinct integers.
 * The number of rows in the 2D array should be minimal.
 * 
 * Input: nums = [1,3,4,1,2,3,1]
 * Output: [[1,3,4,2],[1,3],[1]]
 * Explanation: We can create a 2D array that contains the following rows:
 * - 1,3,4,2
 * - 1,3
 * - 1
 * 
 * Input: nums = [1,2,3,4]
 * Output: [[1,2,3,4]]
 * Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.

 * https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/
*/

#include<set>
#include<map>
#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void printMatrix(std::vector<std::vector<int>> matrix) {
  int r = matrix.size();
  for (int i = 0; i < r; ++i) {
    int c = matrix[i].size();
    for (int j = 0; j < c; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(N ^ 2)
// * SPACE COMPLEXITY O(N)
std::vector<std::vector<int>> bruteForce(std::vector<int> arr) {
  int n = arr.size();
  std::vector<std::vector<int>> ans;

  std::map<int, int> countMap;
  for (int i = 0; i < n; ++i) {
    countMap[arr[i]]++;
  }

  for (int i = 0; i < n; ++i) {
    std::vector<int> t;
    std::set<int> st;
    for (int j = 0; j < n; ++j) {
      int val = arr[j];
      if(!st.count(val) && countMap.count(val) && countMap[val] > 0) {
        t.push_back(val);
        countMap[val]--;
        st.insert(val);
      }
    }
    if (t.size())
      ans.push_back(t);
    // printArr(t);
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
std::vector<std::vector<int>> findMatrix(std::vector<int> arr) {
  int n = arr.size();
  
  std::vector<std::vector<int>> ans;
  std::map<int, int> countMap;

  for (int i = 0; i < n; ++i) {
    int row = countMap[arr[i]];
    if(ans.size() == row)
      ans.push_back({});

    ans[row].push_back(arr[i]);
    countMap[arr[i]] += 1;
  }
  return ans;
}

int main() {
  std::vector<int> nums = {1, 3, 4, 1, 2, 3, 1};
  // std::vector<int> nums = {1, 2, 3, 4};
  printArr(nums);
  // std::vector<std::vector<int>> ans = bruteForce(nums);
  std::vector<std::vector<int>> ans = findMatrix(nums);
  printMatrix(ans);
  return 0;
}

// * run the code 
// * g++ --std=c++17 09-convert0=-to-2d-arr.cpp -o output && ./output
