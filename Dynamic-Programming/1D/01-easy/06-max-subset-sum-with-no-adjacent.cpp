/*
 * Max subset sum with no adjacent element
 * 
 * 
 * Example 1    :
 * Input        : nums = [ 2, -3, 5, -8, 7 ]
 * Output       : 14 => (2 + 5 + 7)
 * 
 * Example 2    :
 * Input        : nums =  2, 4, 6, 7, 8 ]
 * Output       : 16 => (2 + 6 + 8)
 * 
 * https://www.desiqna.in/dp2
 * https://drive.google.com/file/d/1aVaVeGDUlkinRW7Z1BTVY59t_exe70iA/view
 * https://www.naukri.com/code360/problems/max-non-adjacent-sum_4830857
 * https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1
*/

// ! Walmart

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

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

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
void solve(vl nums) {
  int n = nums.size();

  // * dp[i] = max sum at index 'i'
  // * dp[i] = max({nums[i] + dp[i - 2], dp[i - 1], nums[i]})
  vl dp(n);
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);
  for (int i = 2; i < n; ++i) {
    dp[i] = max({nums[i] + dp[i - 2], dp[i - 1], nums[i]});
  }
  cout << dp[n - 1] << '\n';
}

int main(void) {
  // * testcase 1
  // vl nums = {2, -3, 5, -8, 7};

  // * testcase 2
  vl nums = {2, 4, 6, 7, 8};

  cout << "nums: ";
  printArr(nums);

  solve(nums);
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 06-max-subset-sum-with-no-adjacent.cpp -o output && ./output
