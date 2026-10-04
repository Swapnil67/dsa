/*
 * Count Subarrays with Sum Equal to Length
 *
 * Given an integer array 'nums', find the total number of continuous 
 * subarrays where the sum of its elements is exactly equal to the 
 * length of that subarray.
 * 
 * Formally, find the number of pairs (i, j) such that:
 * 0 <= i <= j < nums.size() AND sum(nums[i...j]) == (j - i + 1)
 *
 * Examples:
 * Input: nums = [1, 1, 1, 1]
 * Output: 10
 * Explanation: All 10 possible subarrays have a sum equal to their length.
 *
 * Input: nums = [2, 3, 1]
 * Output: 1
 * Explanation: Only the subarray [1] (at index 2) has a sum equal 
 *              to its length of 1.
 *
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^9 <= nums[i] <= 10^9
 *
 * Time Complexity Goal: O(N)
 * Space Complexity Goal: O(N) or O(1)
 * 
 * https://codeforces.com/problemset/problem/1398/C
 * https://docs.google.com/document/d/1KvjLTpkL1NtQ4ZdkFpWQr1yfWoeW1J3jb1WH4oFTWTc/edit?tab=t.0
 */

// ! codeforces

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

/*
! ================================================================================
! MATHEMATICAL INTUITION: Count Subarrays with Sum Equal to Length
! ================================================================================
* Goal: Find the number of continuous subarrays from index 'i' to 'j' such that:
*       sum[i...j] == j - i + 1  (Sum equals Length)
* 
* 1. Let 'p' be the Prefix Sum array, where p[x] is the sum of elements from 0 to x.
*    The sum of any subarray from i to j can be calculated in O(1) time as:
*    sum[i...j] = p[j] - p[i - 1]
* 
* 2. Substitute this into our goal equation:
*    p[j] - p[i - 1] = j - i + 1
* 
* 3. Break the right-hand side apart to isolate 'j' and 'i':
*    p[j] - p[i - 1] = j + 1 - i
* 
* 4. Group all terms related to the current index 'j' on the left side, 
*    and all terms related to the past boundary index 'i' on the right side:
*    p[j] - (j + 1) = p[i - 1] - i
* 
* 5. Observe the beautiful symmetry of the template on both sides.
*    To make both sides look identical, we shift our focus from the start 
*    index 'i' to the past boundary index 'k' just before it (k = i - 1).
*    Since k = i - 1, it naturally follows that i = k + 1.
*    Substituting 'k' into the right side: p[i - 1] - i  ->  p[k] - (k + 1).
*    The full equation now simplifies perfectly to:
*    Current Index State: p[j] - (j + 1)
*    Past Boundary State: p[k] - (k + 1)
* 
* 6. Conclusion:
*    Both sides share the exact same template: p[x] - (x + 1).
*    As we loop through the array at index 'j', we compute 'check = p[j] - (j + 1)'.
*    We use a Hash Map to look up how many times this exact value appeared in the past.
* 
* 7. Base Case (i = 0):
*    If a valid subarray starts exactly at the beginning (index 0), the past 
*    boundary index is k = i - 1 = -1.
*    Evaluating the template for the base case:
*    p[-1] - (-1 + 1) -> 0 - 0 = 0.
*    Therefore, we pre-populate our hash map with mp[0] = 1.
* ================================================================================
*/

int solve(vector<int> &nums) {
  int n = nums.size();
  if (n == 0)
      return 0;

  // * 1. Build the Prefix Sum array
  // * p[i] will store the cumulative sum from nums[0] to nums[i]
  vector<int> p(n, 0);
  p[0] = nums[0];
  for (int i = 1; i < n; ++i) {
    p[i] = p[i - 1] + nums[i];
  }
  printArr(p);

  int ans = 0;
  unordered_map<int, int> mp;
  // * 2. Base Case Initialization
  mp[0] = 1; // * testcase 3

  // * 3. Iterate through the array to find matching subarrays
  for (int j = 0; j < n; ++j) {
    // * Calculate the target value for the current index 'j'
    int check = p[j] - (j + 1);

    // * If 'check' exists in our map, it means we found past indices 'i-1'
    // * that satisfy: p[j] - j == p[i-1] - (i-1)
    if (mp.count(check))
      ans += mp[check];
    
    // * Record the current state into the map so future indices 
    // * can look back and form pairs with it.
    mp[check]++;
  }

  return ans;
}

// ! Without prefix array
int solve2(vector<int> &nums) {
  int n = nums.size();
  if (n == 0)
    return 0;

  // * 2. Base Case Initialization
  unordered_map<int, int> mp;
  mp[0] = 1; // * testcase 3

  int sum = 0, ans = 0;
  // * 3. Iterate through the array to find matching subarrays
  for (int j = 0; j < n; ++j) {
    sum += nums[j]; // * current prefix sum

    // * Calculate the target value for the current index 'j'
    int check = sum - (j + 1);

    // * If 'check' exists in our map, it means we found past indices 'i-1'
    // * that satisfy: p[j] - j == p[i-1] - (i-1)
    if (mp.count(check))
      ans += mp[check];
    
    // * Record the current state into the map so future indices 
    // * can look back and form pairs with it.
    mp[check]++;
  }

  return ans;
}


int main(void) {
	// * testcase 1  // * Ans = 10
    // vector<int> nums = {1, 1, 1, 1};

    // * testcase 2  // * Ans = 6
    // vector<int> nums = {1, 1, 0, 1, 1};
 
    // * testcase 3  // * Ans = 1
    // vector<int> nums = {1};

    // * testcase 4  // * Ans = 3
    vector<int> nums = {1, 2, 0};

    // * testcase  5 // * Ans = 1
    // vector<int> nums = {6, 0, 0, 0, 0, 5};

    cout << "Array: ";
    printArr(nums);

    // int ans = solve(nums);
    int ans = solve2(nums);

    cout << "Number of good subarrays: " << ans << endl;

    return 0;
}

// * Run the code
// * g++ --std=c++20 01-cnt-subarrays-with-sum-eq-to-len.cpp -o output && ./output
