/*
 * First and Last Position of an Element In Sorted Array
 * You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
 * Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.
 * 
 * Note :
 * 1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
 * 2. 'arr' may contain duplicate elements.
 * 
 * Example 1:
 * Input: arr = [ 0, 1, 1, 5 ],  k = 1
 * Output: [1,2]
 * 
 * Example 2:
 * Input: arr = [ 1, 3, 3, 5 ], k = 9
 * Output: [-1, -1]
 * 
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 * https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549
*/

#include <vector>
#include <iostream>

// * Using Lower & Upper Bound concept

using namespace std;

template <typename T>
void printArr(vector<T> &nums) {
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * Lower bound -> arr[i] >= k
int findLowerBound(vector<int> arr, int k) {
  int n = arr.size();
  int l = 0, r = n - 1;
  int idx = n;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] >= k) {
      idx = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  
  return idx;
}

// * Upper bound -> arr[i] > k
int findUpperBound(vector<int> arr, int k) {
  int n = arr.size();
  int l = 0, r = n - 1;
  int idx = n;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] > k) {
      idx = m - 1;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }

  return idx;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
pair<int, int> bruteForce(vector<int> arr, int k) {
  pair<int, int> ans(-1, -1);
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    if(arr[i] == k) {
      if (ans.first == -1) {
        ans.first = i;
        ans.second = i;
      } else if(ans.first != -1) {
        ans.second = i;
      }
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(2logN)
// * SPACE COMPLEXITY O(1)
pair<int, int> firstAndLastOccurence(vector<int> arr, int k) {
  int n = arr.size();
  int firstOccurence = findLowerBound(arr, k);
  
  // * If k not found
  if (firstOccurence == n || arr[firstOccurence] != k) {
    return {-1, -1};
  }

  int lastOccurence = findUpperBound(arr, k);
  pair<int, int> ans(firstOccurence, lastOccurence);
  return ans;
}

int main() {
  // * testcase 1
  int k = 1;
  vector<int> arr = {0, 1, 1, 5};

  // * testcase 2
  // vector<int> arr = {1, 3, 9, 15};
  // int k = 9;

  // * testcase 3
  // vector<int> arr = {1, 3, 3, 5};
  // int k = 9;
  
  printArr(arr);
  // pair<int, int> ans = bruteForce(arr, k);
  pair<int, int> ans = firstAndLastOccurence(arr, k);
  cout << "First Occurence of '" << k << "' is at index " << ans.first << endl;
  cout << "Last Occurence of '" << k << "' is at index " << ans.second << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 06-first-and-last-occurence-a.cpp -o output && ./output
