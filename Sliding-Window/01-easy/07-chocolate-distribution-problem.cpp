/*
 * Chocolate Distribution Problem
 * 
 * Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. 
 * Each packet can have a variable number of chocolates. There are m students, 
 * the task is to distribute chocolate packets among m students such that -
 * 
 * - i. Each student gets exactly one packet.
 * - ii. The difference between maximum number of chocolates given to a student and minimum number of 
 *       chocolates given to a student is minimum and return that minimum possible difference.

 * Example 1:
 * Input: arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
 * Output: 6
 * Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 
 *              by choosing following m packets :[3, 4, 9, 7, 9].

 * Example 2:
 * Input       : arr = [7, 3, 2, 4, 9, 12, 56], m = 3
 * Output      : 2
 * Explanation : The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 
 *               by choosing following m packets :[3, 2, 4].

 * Example 3:
 * Input       : arr = [3, 4, 1, 9, 56], m = 5
 * Output      : 55
 * Explanation : With 5 packets for 5 students, each student will receive one packet, 
 *               so the difference is 56 - 1 = 55.

 * https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
*/

#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

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

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------`
// * Sliding window Approach
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
int findMinDiff(std::vector<int> &a, int m) {
  int n = a.size();
  sort(begin(a), end(a)); // * O(nlogn)

  int cur_min = INT_MAX;
  int i = 0, j = 0;
  while (j < n) {
    if ((j - i + 1) > m) {
      i++;
    }

    if ((j - i + 1) == m) {
      cur_min = std::min(cur_min, a[j] - a[i]);
    }
    j++;
  }

  return cur_min;
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------`
// * Sliding window Approach
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
int findMinDiff(std::vector<int> &a, int m) {
  int n = a.size();
  sort(begin(a), end(a));

  int i = 0, j = m - 1;
  int ans = INT_MAX;
  while (j < n) {
    ans = std::min(ans, a[j] - a[i]);
    i++, j++;
  }
  return ans;
}

int main(void) {
  int m = 5;
  std::vector<int> arr = {3, 4, 1, 9, 56, 7, 9, 12};
  std::cout << "Input Array" << std::endl;
  printArr(arr);

  int ans = findMinDiff(arr, m);
  std::cout << ans << std::endl;
}

// * Run the code
// * g++ --std=c++17 07-chocolate-distribution-problem.cpp -o output && ./output

// * 3, 4, 1, 9, 56, 7, 9, 11

// * Sort the given array 

// * 1, 3, 4, 7, 9, 9, 11, 56
// * i
// *             j

// * 1, 3, 4, 7, 9, 9, 11, 56
// *    i
// *                j
