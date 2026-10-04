
/*
 * Leetcode - 3974
 * Maximum Total Sum of K Selected Elements
 * 
 * 
 * Example 1    :
 * Input        : nums = [-1,1,2,3,1], target = 2
 * Output       : 3
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 * 
 * Example 2    :
 * Input        : nums = [-6,2,5,-2,-7,-1,3], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 *
 * https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/description/
*/

#include <vector>
#include <iostream>

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

long long maxSum(vector<int> &nums, int k, int mul) {
    // * 1. Sort in descending order to bring the largest elements to the
    // * front
    sort(nums.begin(), nums.end(), greater<int>());

    long long ans = 0;

    // * 2. Simply greedily pick the top k largest elements
    for (int i = 0; i < k; ++i) {
        // * If mul > 0, use it; otherwise, the multiplier defaults to 1
        long long current_multiplier = max(1, mul);

        ans += 1LL * nums[i] * current_multiplier;

        // * Decrement the multiplier for the next element
        mul--;
    }

    return ans;
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

