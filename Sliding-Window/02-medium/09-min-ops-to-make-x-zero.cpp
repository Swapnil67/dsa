
/**
 * * Leetcode - 1658
 * * Minimum Operations to Reduce X to Zero
 * * You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or
 * * the rightmost element from the array nums and subtract its value from x. 
 * * Note that this modifies the array for future operations.
 * 
 * * Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 * * Example 1
 * * Input  :  nums = [1,1,4,2,3], x = 5
 * * Output : 2
 * * Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
 * 
 * * Example 2
 * * Input  : nums = [5,6,7,8,9], x = 4
 * * Output : -1
 * 
 * * https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero
*/

#include <map>
#include <numeric>
#include <climits>
#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Using prefix sum map
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(X)
int minOperations2(std::vector<int> &arr, int x) {
  int n = arr.size();

  // * Make prefix sum map
  std::map<int, int> prefix_sum;
  prefix_sum[0] = -1;
  long long sum = 0;
  for(int i = 0; i < n; ++i) {
    sum += arr[i];
    prefix_sum[sum] = i;   // * storing sum in map
  }

  // * If total sum is less than x
  if(sum < x) {
    return -1;
  }

  long long target_sum = sum - x;
  // std::cout << "Total Sum: " << sum << " & Target Sum: " << target_sum << std::endl;

  long long cur_sum = 0;
  int j = 0, ans = -1;
  while (j < n) {
    cur_sum += arr[j];
    long long check_sum = cur_sum - target_sum; 
    // * check if we found 'check_sum' previously
    if (prefix_sum.find(check_sum) != prefix_sum.end()) {
      ans = std::max(ans, j - prefix_sum[check_sum]);
    }
    j++;
  }

  if (ans < 0)
    return -1;

  return n - ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Classic Sliding Window + Basic Algebra
// * left_sum + right_sum == x
// * _______________ sum ________________
// * [left_sum][__ sum - x __][right_sum]
// * target_sum = sum - x
// * Problem converted to simple sliding window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int minOperations(std::vector<int> &arr, int x) {
  int n = arr.size();
  int i = 0, j = 0, ans = INT_MIN;
  long long total_sum = accumulate(arr.begin(), arr.end(), 0);
  long long target_sum = total_sum - x;
  // printf("total_sum: %d, target_sum: %d\n", total_sum, target_sum);
  int cur_sum = 0;
  while(j < n) {
    cur_sum += arr[j];
    
    // * Shrink the window
    while(i <= j && cur_sum > target_sum) {
      cur_sum -= arr[i];
      i++;
    }

    if(cur_sum == target_sum) {
      ans = std::max(ans, (j - i + 1));
    }
    j++; 
  }

  if (ans < 0)
    return -1;
  return n - ans;
}

int main() {
  // * testcase 1
  // int x = 3;
  // std::vector<int> arr = {1, 1};
  // * testcase 2
  // int x = 5;
  // std::vector<int> arr = {1, 1, 4, 2, 3};
  // * testcase 3
  // int x = 4;
  // std::vector<int> arr = {5, 6, 7, 8, 9};
  // * testcase 4
  int x = 10;
  std::vector<int> arr = {3, 2, 20, 1, 1, 3};

  printf("Input Array\n");
  printArr(arr);

  // int ans = minOperations(arr, x);
  int ans = minOperations2(arr, x);
  printf("Minimum Operations to Reduce X to Zero is %d\n", ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-min-ops-to-make-x-zero.cpp -o output && ./output