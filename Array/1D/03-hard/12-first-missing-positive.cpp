/*
 * First Missing Positive
 * Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
 * 
 * Example 1:
 * Input: nums = [1,2,0]
 * Output: 3
 * Explanation: The numbers in the range [1,2] are all in the array.
 * 
 * Example 2:
 * Input: nums = [3,4,-1,1]
 * Output: 2
 * Explanation: 1 is in the array but 2 is missing.
 * 
 * Example 3:
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 * Explanation: The smallest positive integer 1 is missing.
 * 
 * https://leetcode.com/problems/first-missing-positive/description/
 * https://www.naukri.com/code360/problems/first-missing-positive_699946
*/

#include <set>
#include <vector>
#include <iostream>

using namespace std;

// * ------------------------- UTILITY FUNCTIONS -------------------------`

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

template <typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

bool isElementPresent(vector<int> arr, int n, int ele) {
  for (int i = 0; i < n; ++i) {
    if(arr[i] == ele)
      return true;
  }
  return false;
}

// * ------------------------- APPROACH 1: Brute Approach -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> arr) {
  int n = arr.size();
  for (int i = 1; i <= n + 1; ++i) {
    if (!isElementPresent(arr, n, i))
      return i;
  }
  return -1;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * HashSet
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int betterApproach(vector<int> arr) {
  int n = arr.size();

  // * put all elements into hashSet
  set<int> hashSet;
  for (int i = 0; i < n; ++i)
    hashSet.insert(arr[i]);

  // * Search missing numbers from [1...n+1]
  for (int i = 1; i <= n + 1; ++i) {
    if(!hashSet.count(i))
      return i;
  }
  return -1;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * Put the element at its right position (swap)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int firstMissingPositive(vector<int> arr) {
  int n = arr.size();
  // * Put the elements to their particular positions
  for (int i = 0; i < n; ++i) {
    int ele = arr[i]; // * 4

    // * check if ele is +ve number
    if(ele >= 1 && ele <= n) {
      int chair = ele - 1; // * 3

      // * check if ele is at its correct position
      if (arr[chair] != ele) {
        // * swap
        swap(arr[chair], arr[i]);
        --i;
      }
    } 
  }

  // printArr(arr);
  for (int i = 1; i <= n; ++i) {
    if (i != arr[i - 1])
      return i;
  }
  return n + 1;
}

int main() {
  // * testcase 1
  // vector<int> arr = {1, 2, 0};
  // * testcase 2
  vector<int> arr = {3, 4, -1, 1};
  // * testcase 3
  // vector<int> arr = {7, 8, 9, 11, 12};

  cout << "Input Array" << endl;
  printArr(arr);
  // int ans = bruteForce(arr);
  // int ans = betterApproach(arr);
  int ans = firstMissingPositive(arr);
  cout << "Missing positive integer " << ans << endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 12-first-missing-positive.cpp -o output && ./output