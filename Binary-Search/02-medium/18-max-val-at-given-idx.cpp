/**
 * * Leetcode - 1802
 * * Maximum Value at a Given Index in a Bounded Array

 * * You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) 
 * * that satisfies the following conditions:
 * 
 * * - nums.length == n
 * * - nums[i] is a positive integer where 0 <= i < n.
 * * - abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
 * * - The sum of all the elements of nums does not exceed maxSum.
 * * - nums[index] is maximized.
 * 
 * * Return nums[index] of the constructed array.
 * 
 * * Example 1:
 * * Input       : n = 4, index = 2,  maxSum = 6
 * * Output      : 2
 * * Explanation : nums = [1,2,2,1] is one array that satisfies all the conditions.
 
 * * https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/
*/

#include <vector>
#include <iostream>

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Check for every maxSum till 0;
// * totalSum = __ leftSum __ + i + __ rightSum __
// * totalSum <= maxSum 

// * TIME COMPLEXITY O(N * maxSum)
// * SPACE COMPLEXITY O(1)
int bruteForce(int n, int index, int maxSum) {
  for (int i = maxSum; i > 0; --i) {
    int curMaxSum = i;
    
    // * Find the left sum
    int idx = index;
    int leftSum = 0;
    while (idx > 0) {
      // * This will make sure that adjacent ele to left have diff <= 1
      leftSum += curMaxSum - 1;
      curMaxSum -= 1;
      idx--;
    }
    
    // * Find the right sum
    curMaxSum = i;
    idx = index;
    int rightSum = 0;
    while (idx < n - 1) {
      // * This will make sure that adjacent ele to right have diff <= 1
      rightSum += curMaxSum - 1;
      curMaxSum -= 1;
      idx++;
    }

    // * Check if total array sum exceeds maxSum
    int totalSum = leftSum + i + rightSum;
    std::cout << leftSum << " + " << i << " + " << rightSum << " = " << totalSum << std::endl;
    if (totalSum <= maxSum)
      return i;
  }
  return 0;
}

// * [(x - 4) + (x - 3) + (x - 2) + (x - 1) + x]
// * (count * x) - (4 + 3 + 2 + 1)
// * (count * x) - sum of first count natural numbers
long long getSumByFormula(long long count, long long x) {
  return (count * x) - (count * (count + 1)) / 2;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int maxValue(int n, int index, int maxSum) {
  long long l = 1;
  long long r = maxSum;

  int result = 0;
  while (l <= r) {
    long long m = l + (r - l) / 2;

    // * Find the left sum
    long long expectedLeftCnt = (long long)index;
    long long leftCount = std::min(expectedLeftCnt, (m - 1));
    long long leftSum = getSumByFormula(leftCount, m);
    leftSum += std::max(0ll, expectedLeftCnt - (m - 1));   // * extra ones if any

    // * Find the right sum
    long long expectedRightCnt = (n - index - 1);
    long long rightCount = std::min(expectedRightCnt, m - 1);
    long long rightSum = getSumByFormula(rightCount, m);
    rightSum += std::max(0ll, expectedRightCnt - (m - 1));   // * extra ones if any

    long long totalSum = leftSum + m + rightSum;
    if (totalSum <= maxSum) {
      result = std::max(m,  (long long)result);
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }

  return result;
}


int main() {
  // int n = 4, index = 2, maxSum = 6;
  int n = 6, index = 1,  maxSum = 10;
  
  std::cout << "n: " << n << std::endl;
  std::cout << "index: " << index << std::endl;
  std::cout << "maxSum: " << maxSum << std::endl;

  // int ans = bruteForce(n, index, maxSum);
  int ans = maxValue(n, index, maxSum);
  std::cout << "Ans: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 18-max-val-at-given-idx.cpp -o output && ./output


// * [_  _  6  _]
// * [4  5  6  7]