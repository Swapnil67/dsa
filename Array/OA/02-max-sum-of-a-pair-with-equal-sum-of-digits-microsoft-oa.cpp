/*
 * Leetcode - 2342
 * Max Sum of a Pair With Equal Sum of Digits
 * 
 * You are given a 0-indexed array nums consisting of positive integers. 
 * You can choose two indices i and j, such that i != j, and the sum of 
 * digits of the number nums[i] is equal to that of nums[j].
 * 
 * Return the maximum value of nums[i] + nums[j] that you can obtain 
 * over all possible indices i and j that satisfy the conditions. 
 * If no such pair of indices exists, return -1.
 * 
 * Example 1    :
 * Input        : nums = [18,43,36,13,7]
 * Output       : 54
 * Explanation  : The pairs (i, j) that satisfy the conditions are:
 *                - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
 *                - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
 *                So the maximum sum that we can obtain is 54.
 * 
 * Example 2    :
 * Input        : nums = [51, 71, 17, 42]
 * Output       : 93
 * Explanation  : There are two pairs of numbers whose digits add up to an equal sum: (51, 42) and (17, 71), 
 *                The first pair sums up to 93
 * 
 * 
 * Example 3    :
 * Input        : nums = [10,12,19,14]
 * Output       : -1
 * Explanation  : There are no two numbers that satisfy the conditions, so we return -1.
 * 
 * https://www.desiqna.in/13267/microsoft-coding-oa-sde-1-may-3-2023
 * https://drive.google.com/file/d/1GaqUkd9oh0nrhCozGoWHP7OoDjmI_t4f/view
 * https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/
*/

// ! OA
// ! Microsoft

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

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

// * Return a digit sum of a num (eg, 123 => 6)
ll getSum(int n) {  // * O(logn) eg: log10(1000) = 3.
  ll sum = 0;
  while(n) {
    sum += (n % 10);
    n /= 10;
  }
  return sum;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Check all possible pairs
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
ll bruteForce(vector<int> nums) {
  int n = nums.size();
  ll maxSum = -1;
  for (int i = 0; i < n; ++i) {
    ll digitSum1 = getSum(nums[i]); 
    for (int j = i + 1; j < n; ++j) {
      ll digitSum2 = getSum(nums[j]);
      if (digitSum1 == digitSum2) {
        maxSum = max(maxSum, (ll)(nums[i] + nums[j]));
      }
    }
  }
  return maxSum;
}


// * ------------------------- APPROACH 2: Better APPROACH -------------------------
// * Hashmap
// * m = is the maximum value an element can take & n = no. of elements in nums
// * TIME COMPLEXITY O(nlogm) 
// * SPACE COMPLEXITY O(n)
int maximumSum(vector<int> &nums) {
  int n = nums.size();

  // * {digitSum, num}
  unordered_map<int, int> mp;

  ll maxSum = -1; // * Tracks the maximum sum of two elements with the same digit sum

  for (int i = 0; i < n; ++i) {
    int num = nums[i];
    ll digitSum = getSum(num); // * Calculate the digit sum of the current number

    // * Check if we have already seen another number with the exact same digit sum
    if (mp.count(digitSum) > 0) {
      // * Calculate the pair sum of the current number and the largest previous number,
      // * then update maxSum if this new pair sum is larger.
      maxSum = max(maxSum, (ll)(num + mp[digitSum]));

      // * Keep only the largest number for this specific digit sum in the map
      if (num > mp[digitSum]) {
        mp[digitSum] = num;
      }
    }
    else {
      // * If this digit sum is seen for the first time, store the current number
      mp[digitSum] = num;
    }
  }

  return maxSum;
}

int main(void) {
  // * testcase 1
  vector<int> nums = {18, 43, 36, 13, 7};

  // * testcase 2
  // vector<int> nums = {51, 71, 17, 42};

  // * testcase 3
  // vector<int> nums = {10, 12, 19, 14};

  cout << "nums: ";
  printArr(nums);

  // ll ans = bruteForce(nums);
  ll ans = maximumSum(nums);
  cout << "Max sum: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 02-max-sum-of-a-pair-with-equal-sum-of-digits-microsoft-oa.cpp -o output && ./output
