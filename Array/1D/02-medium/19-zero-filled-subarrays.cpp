/*
 * Number of Zero-Filled Subarrays
 * Given an integer array nums, return the number of subarrays filled with 0.

 * Example 1:
 * Input: nums = [1, 3, 0, 0, 2, 0, 0, 4]
 * Output: 6
 * 
 * Example 2:
 * Input: nums = [0, 0, 0, 2, 0, 0]
 * Output: 9
 * 
 * Example 3:
 * Input: nums = [2, 10 ,2019]
 * Output: 0

 * https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
 * https://www.naukri.com/code360/problems/count-subarrays-consisting-of-only-0-s-and-only-1-s-in-a-binary-array_1262154
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

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


void printArr(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Nested Loop [Find all subarray]
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
long long zeroFilledSubarrayBrute(vector<int>& nums) {
  int n = nums.size();
  long long zero_subarray_cnt = 0;
  for (int i = 0; i < n; ++i) {
    int c = 0;
    for (int j = i; j < n; ++j) {
      if(nums[j] == 0) {
        c++;
      } else {
        break;
      }
    }
    cout << c << endl;
    zero_subarray_cnt += c;
  }

  return zero_subarray_cnt;  
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Non-Empty Consecutive Subsets = (N * (N + 1)) / 2
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
long long zeroFilledSubarray(vector<int>& nums) {
  long long n = nums.size();
  long long ans = 0, count = 0;
  for (int i = 0; i < n; ++i) {
    if (nums[i] == 0) {
      count++;
    } else {
      // * Consecutive Subsets count
      ans += count * (count + 1LL) / 2LL;
      count = 0;
    }
  }
  ans += count * (count + 1LL) / 2LL;
  return ans;
}

// * Coding Ninja version 
// * count both 0s, 1s subarrays
long long numberofSubarrays(vector<int>& nums) {
  int n = nums.size();
   int one_c = 0, zero_c = 0, res_zero = 0, res_one = 0;
   for (int i = 0; i < n; ++i) {
     if (nums[i] == 0) {
       zero_c += 1;
       res_zero += zero_c;
       one_c = 0;
     }
     else if (nums[i] == 1) {
       zero_c = 0;
       one_c += 1;
       res_one += one_c;
     }
     else {
       one_c = 0;
       zero_c = 0;
     }
   }
  return res_zero + res_one;
}

int main() {
  // * testcase 1
  vi arr = {1, 3, 0, 0, 2, 0, 0, 4};

  // * testcase 2
  // vi arr = {2, 10, 2019};

  cout << "Input Array: ";
  printArr(arr);

  // long long ans = zeroFilledSubarrayBrute(arr);
  long long ans = zeroFilledSubarray(arr);
  cout << "Zero filled subarrays: " << ans << endl;

  vi arr1 = {1, 0, 0, 0, 1, 0, 1};
  long long ans1 = numberofSubarrays(arr1);
  cout << "Zero & one filled subarrays: " << ans1 << endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 19-zero-filled-subarrays.cpp -o output && ./output

/*
* Pattern
* 0             -> 1
* 0 0           -> 3
* 0 0 0         -> 6
* 0 0 0 0       -> 10
* 0 0 0 0 0     -> 15
* 0 0 0 0 0 0   -> 21

*/