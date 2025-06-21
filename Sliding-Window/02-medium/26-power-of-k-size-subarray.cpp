
/**
 * * Leetcode - 3254
 * * Find the Power of K-Size Subarrays I
 * * You are given an array of integers nums of length n and a positive integer k.
 * * The power of an array is defined as:
 *    * Its maximum element if all of its elements are consecutive and sorted in ascending order.
 *    * -1 otherwise.
 * 
 *  * You need to find the power of all subarrays of nums of size k.

 * * Example 1
 * * Input  : nums = [1,2,3,4,3,2,5], k = 3
 * * Output : [3,4,-1,-1,-1]

 * * Example 2
 * * Input  : nums = [2,2,2,2,2], k = 4
 * * Output : [-1,-1]

 * * Example 3
 * * Input  : nums = [3,2,3,2,3,2], k = 2
 * * Output : [-1,3,-1,3,-1]
 * 
 * * https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Check all possible k sized subarrays
// * TIME COMPLEXITY O(N * K)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<int> arr, int k) {
  int n = arr.size();
  std::vector<int> ans;

  for (int i = 0; i <= n - k; ++i) {
    int cur_power = -1;
    for (int j = i; j < i + k; ++j) {
      if (j > i) {
        if(arr[j] == arr[j - 1] + 1) {
          cur_power = arr[j];
        }
        else {
          cur_power = -1;
          break;
        }
      }
    }
    ans.push_back(cur_power);
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Classic Sliding Window
// * Keep the consecutive_count variable
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
std::vector<int> resultsArray(std::vector<int> arr, int k) {
  int n = arr.size();
  std::vector<int> ans((n - k + 1), -1);
  int consecutive_cnt = 0; // * count of consecutive elements

  // * Find the answer in first k subarray
  for (int i = 0; i < k; ++i) {
    if (i > 0 && arr[i - 1] + 1 == arr[i]) {
      consecutive_cnt++;
    } else {
      consecutive_cnt = 1;
    }
  }
  if(consecutive_cnt == k) {
    ans[0] = arr[k - 1];
  }

  // * Find the remaining ans through sliding window
  int i = 1;  // * here 'i' acts a current index for ans vector
  int j = k;
  while (j < n) {
    if (arr[j - 1] + 1 == arr[j]) {
      consecutive_cnt++;
    } else {
      consecutive_cnt = 1;
    }

    // * If window is greater than k
    if (consecutive_cnt >= k) {
      ans[i] = arr[j];
    }

    i++;
    j++;
  }

  return ans;
}

int main() {
  // * testcase 1
  int k = 3;
  std::vector<int> arr = {1, 2, 3, 4, 3, 2, 5};
  
  // * testcase 2
  // int k = 4;
  // std::vector<int> arr = {2, 2, 2, 2, 2};
  
  // * testcase 3
  // int k = 2;
  // std::vector<int> arr = {3, 2, 3, 2, 3, 2};

  printArr(arr);

  // std::vector<int> ans = bruteForce(arr, k);
  std::vector<int> ans = resultsArray(arr, k);
  std::cout << "Find the Power of K-Size Subarrays: " << std::endl;
  printArr(ans);
  return 0;

}


// * Run the code
// * g++ --std=c++20 26-power-of-k-size-subarray.cpp -o output && ./output
