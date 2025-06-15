/**
 * * Leetcode - 1838
 * * Frequency of the Most Frequent Element
 * * The frequency of an element is the number of times it occurs in an array.
 * * You are given an integer array nums and an integer k. In one operation, 
 * * you can choose an index of nums and increment the element at that index by 1.
 * * Return the maximum possible frequency of an element after performing at most k operations.

 * * Example 1
 * * Input  : nums = [1, 2, 4], k = 5
 * * Output : 3
 * * Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
 * *              4 has a frequency of 3.

 * * Example 2
 * * Input  : nums = [1,4,8,13], k = 5
 * * Output : 2
 * * Explanation : Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
 * 
 * * Example 2
 * * Input  : nums = [3,9,6], k = 2
 * * Output : 1

 * * https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/
*/

// ! [HINT] => Mostly frequent element will be one of the array elements

#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Using Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int myBruteForce(std::vector<int> arr, int k) {
  int n = arr.size();
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    int ele = arr[i], cur_ops = k;
    int j = 0;
    for (; j < n; ++j) {
      if(arr[j] < ele) {
        int required_ops = ele - arr[j];
        if (cur_ops > 0 && required_ops <= cur_ops) {
          cur_ops -= required_ops;
        }
        else {
          break;
        }
      }
      else {
        break;
      }
    }
    ans = std::max(ans, j + 1);
  }
  return ans;
}


// * -------------------------- Binary Search Approach

int bSearch(int target_idx, int k,  std::vector<int> arr, std::vector<int> prefix_arr) {
  int l = 0, r = target_idx;
  int best_idx = target_idx;

  while(l <= r) {
    int m = (l + r) / 2;

    // * Count number of elements b/w target_idx & mid index
    long long count = (target_idx - m + 1);

    // * Make all numbers equal to target_idx value and calculate sum
    long long window_sum = count * arr[target_idx];

    // * Sum from mid to target_idx in array using prefix sum method
    long long original_sum =
        prefix_arr[target_idx] - prefix_arr[m] + arr[m];

    // * Calculate how many operations we need
    if(window_sum - original_sum > k) {
      // * Decrease the gap b/w m -> target_idx
      l = m + 1;
    }
    else {
      // * Increase the gap b/w m -> target_idx
      best_idx = m;   // * cur best window from m => target_idx
      r = m - 1;
    }
  }
  return target_idx - best_idx + 1;
}

// * Sort the array & calculate prefix_sum for array
// * After sort it will be easy to determine which number we want to increment
// * Eg [1,4,8,13] => for '8' we only focus on '1' & '4' similarly for '13' we focus on '1', '4', '8'
// * TIME COMPLEXITY O(N * nlogn)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int k) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());

  // * Create prefix sum array
  std::vector<int> prefix_arr(n);
  prefix_arr[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefix_arr[i] += prefix_arr[i - 1] + arr[i];
  }
  
  int ans = INT_MIN;
  for (int target_idx = 0; target_idx < n; ++target_idx) {
    int freq = bSearch(target_idx, k, arr, prefix_arr);
    ans = std::max(ans, freq);
  }
  return ans;
}

// * ------------------------- APPROACH 3A: Optimal Approach -------------------------`
// * Classic Sliding Window
// * Keep cur_sum & window_sum
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int betterApproach(std::vector<int> arr, int k) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());

  int i = 0, j = 0;
  long long cur_sum = 0;
  int ans = 0;

  while(j < n) {
    cur_sum += arr[j];

    // * Count number of elements b/w i => j [window count]
    int count = j - i + 1;

    // * Make all numbers equal to arr[j] value and calculate sum
    long long window_sum = (long long)count * (long long)arr[j];
    // std::cout << count << " " << window_sum << " " << cur_sum << " " << ans << std::endl;

    // * Calculate how many operations we need
    int ops = window_sum - cur_sum;
    while (ops > k) {
      cur_sum -= arr[i];
      i++;
      long long new_window_sum = (long long)(j - i + 1) * (long long)arr[j];
      ops = new_window_sum - cur_sum;
    }
    ans = std::max(ans, (j - i + 1));
    j++;
  }
  return ans;
}

// * ------------------------- APPROACH 3B: Optimal Approach -------------------------`
// * Classic Sliding Window
// * Keep cur_sum & window_sum
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxFrequency(std::vector<int> arr, int k) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());

  int i = 0, j = 0;
  long cur_sum = 0;
  int ans = 0;

  while (j < n) {
    cur_sum += arr[j];

    // * Make all numbers equal to arr[j] value and calculate sum
    long long window_sum = (long)(j - i + 1) * arr[j];
    // std::cout << count << " " << window_sum << " " << cur_sum << " " << ans << std::endl;

    if(window_sum - cur_sum > k) {
      cur_sum -= arr[i];
      i++;
    } else {
      ans = std::max(ans, (j - i + 1));
    }
    j++;
  }
  return ans;
}

int main() {

  // * testcase 1
  // int k = 5;
  // std::vector<int> arr = {1, 2, 4};

  // * testcase 2
  // int k = 5;
  // std::vector<int> arr = {1,4,8,13};

  // * testcase 3
  int k = 2;
  std::vector<int> arr = {3, 9, 6};
  
  printArr(arr);
  
  // int ans = bruteForce(arr, k);
  // int ans = betterApproach(arr, k);
  int ans = maxFrequency(arr, k);
  std::cout << "Frequency of the Most Frequent Element: " << ans << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 06-freq-of-most-freq-ele.cpp -o output && ./output