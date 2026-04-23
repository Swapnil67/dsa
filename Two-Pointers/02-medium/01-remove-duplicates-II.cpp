/*
 * Leetcode - 80
 * Remove Duplicates from Sorted Array II
 * 
 * Here each unique element must appear atmost twice. 
 * The relative order of the elements should be kept the same.
 * 
 * Example 1
 * Input  : nums = [1,1,1,2,2,3]
 * Output : 5, nums = [1,1,2,2,3,_]
 * 
 * Example 2
 * Input  : nums = [0,0,1,1,1,1,2,3,3]
 * Output : 7, nums = [0,0,1,1,2,3,3,_,_]

 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Map Data Structure
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int bruteForce(vector<int> &arr) {
  int n = arr.size(), i = 0;
  unordered_map<int, int> countMap;
  
  for (int j = 0; j < n; ++j) {
    int val = arr[j];
    if (countMap.count(val) && countMap[val] >= 2) {
      // * ignore element
      continue;
    }
    else {
      arr[i] = val;
      i++;
      countMap[val]++;
    }
  }

  return i;
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * count the duplicates & loop over duplicates
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int removeDuplicates(vector<int> &arr) {
  int n = arr.size();
  int i = 0, j = 0;

  while (j < n) {
    int c = 1;
    // * count the duplicates
    while ((j + 1) < n && arr[j] == arr[j + 1]) {
        c++;
        j++;
    }

    // * loop over duplicates
    for (int k = 0; k < min(2, c); ++k) {
        arr[i] = arr[j];
        i++;
    }
    j++;
  }
  return i;
}

int main(void) {
  // * testcase 1
  vector<int> nums = {1, 1, 1, 2, 2, 3};

  // * testcase 2
  // vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};

  // * testcase 3
  // vector<int> nums = {1, 1};
  
  // * testcase 4
  // vector<int> nums = {1, 2, 2};
  
  cout << "Input nums: ";
  printArr(nums);

  // int ans = bruteForce(nums);
  int ans = removeDuplicates(nums);

  cout << ans << endl;
  printArr(nums);
  return 0;
}

// * Run the code
// * g++ --std=c++20 01-remove-duplicates-II.cpp -o output && ./output