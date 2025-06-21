
/**
 * * Leetcode - 2779
 * * Maximum Beauty of an Array After Applying Operation
 * * You are given a 0-indexed array nums and a non-negative integer k.
 * * In one operation, you can do the following:
 *    * Choose an index i that hasn't been chosen before from the range [0, nums.length - 1].
 *    * Replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k].
 * 
 * * The beauty of the array is the length of the longest subsequence consisting of equal elements.
 * * Return the maximum possible beauty of the array nums after applying the operation any number of times.
 * 
 * * Note that you can apply the operation to each index only once.

 * * Example 1
 * * Input  : nums = [4, 6, 1, 2], k = 2
 * * Output : 3

 * * Example 2
 * * Input  : nums = [1, 1, 1, 1], k = 10
 * * Output : 4

 * * https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/
*/

#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(N)

// * Check the overlapping intervals
// * (-1, 3) & (0 , 4) are overlapping intervals

// * -1 0 1 2 3 4 5 6 7 8 9       intervals
// *  <------->                   (-1, 3)
// *     <------>                 (0, 4)
// *        <------>              (2, 6)
// *            <------>          (4, 8)

int bruteForce(std::vector<int> arr, int k) {
  int n = arr.size();
  std::vector<std::pair<int, int>> intervals;

  // * Create pair of intervals
  for (int i = 0; i < n; ++i) {
    intervals.push_back({arr[i] - k, arr[i] + k});
  }
  std::sort(intervals.begin(), intervals.end()); // * o(nlogn)

  // * For debugging
  // for(auto a: intervals) {
  //   std::cout << "(" << a.first << ", " << a.second << ")" << std::endl;
  // }

  int max_beauty = 0;
  std::deque<int> dq;
  for (std::pair<int, int> &interval : intervals) { // * o(n)
    // * Here we are checking are the intervals overlapping, if not the pop the front interval
    while (!dq.empty() && dq.front() < interval.first) {
      dq.pop_front();
    }
    dq.push_back(interval.second);
    max_beauty = std::max(max_beauty, (int)dq.size());
  }

  return max_beauty;
}

// * ------------------------- APPROACH 2A: Optimal Approach -------------------------`
// * Binary Search
// * TIME COMPLEXITY 2 * O(nlogn)
// * SPACE COMPLEXITY O(1)

int binarySearch(std::vector<int> &nums, int target) {
  int n = nums.size();
  int l = 0, r = n - 1, ans = 0;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if (target >= nums[m]) { // * y <= (x + 2k) 
      ans = m;
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return ans;
}

// *  x                  y
// * [(x - k), (x + k)], [(y - k), (y + k)]
// * For overlapping we know (x + k) >= (y - k)
// * x + 2k >= y   (adding 'k' on both sides)
// * y <= (x + 2k)
int maximumBeauty(std::vector<int> arr, int k) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());

  int max_beauty = 0;
  for (int i = 0; i < n; ++i) {
    int x = arr[i];
    int y = x + 2 * k;

    // * Find the max index of element who is >= 'y'
    int j = binarySearch(arr, y);
    max_beauty = std::max(max_beauty, j - i + 1);
  }

  return max_beauty;
}

// * ------------------------- APPROACH 2B: Optimal Approach -------------------------`
// * Sliding Window
// * y <= (x + 2k)
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
int maximumBeauty2(std::vector<int> arr, int k) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());

  int max_beauty = 0;
  int i = 0, j = 0;
  while (i < n) {
    // * incr 'j' till arr[j] <= (arr[i] + 2k) 
    while (j < n && (arr[i] + 2 * k) >= arr[j]) {
      j++;
    }
    max_beauty = std::max(max_beauty, j - i);
    i++;
  }

  return max_beauty;
}


int main() {
  // * testcase 1
  int k = 2;
  std::vector<int> arr = {4, 6, 1, 2};

  // * testcase 2
  // int k = 10;
  // std::vector<int> arr = {1, 1, 1, 1};

  // * testcase 3
  // int k = 2;
  // std::vector<int> arr = {3, 2, 3, 2, 3, 2};

  printArr(arr);

  int ans = bruteForce(arr, k);
  // int ans = maximumBeauty(arr, k);
  // int ans = maximumBeauty2(arr, k);
  std::cout << "Maximum Beauty of an Array After Applying Operation: " << ans << std::endl;
  return 0;

}


// * Run the code
// * g++ --std=c++20 27-max-beauty-of-arr.cpp -o output && ./output

