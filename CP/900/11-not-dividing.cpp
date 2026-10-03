/*
 * Not Dividing
 * 
 * You are given an array of positive integers nums of length n. You can perform 
 * the following operation at most 2n times: choose any index i and increment 
 * nums[i] by 1. 
 * Transform the array such that for every adjacent pair of elements, the 
 * element on the right is not divisible by the element on the left. In other 
 * words, nums[i + 1] % nums[i] != 0 for all 0 <= i < n - 1. You do not need to 
 * minimize the total number of operations used, as long as it does not exceed 2n.
 * 
 * Constraints:
 * 1 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^9
 * The sum of nums.length over all test cases does not exceed 5 * 10^4
 * 
 * Example 1    :
 * Input        : nums = [2, 4, 3, 6, 3]
 * Output       : [2, 5, 3, 7, 3]
 * Explanation  : 5 is not divisible by 2, 3 is not divisible by 5, 7 is not divisible by 3, and 3 is not divisible by 7. The final sequence satisfies the condition.
 * 
 * Example 2    :
 * Input        : nums = [1, 2, 4, 2]
 * Output       : [2, 3, 4, 3]
 * Explanation  : The transformed sequence [2, 3, 4, 3] satisfies the condition because 3%2 != 0, 4%3 != 0, and 3%4 != 0.
 *
 * https://codeforces.com/problemset/problem/1794/B
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation

// * If we have '1' in array then its a problem since 1 can always divide any integer.
// * So first we change all '1' occurences to '2' (at worst O(N))
// * Now we check if a[i] % a[i - 1] == 0 then we simply increment a[i], since consecutive numbers are not
// * divisible dy each other except 1 (Which we already handled).

// * TC = O(n)
// * SC = O(n)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    for (int i = 0; i < n; ++i) {
      if (a[i] == 1)
        a[i] += 1;
    }

    for (int i = 1; i < n; ++i) {
      if (a[i] % a[i - 1] == 0) {
        a[i] += 1;
      }
    }

    for (int i = 0; i < n; ++i)
      cout << a[i] << " ";
    cout << "\n";
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 11-not-dividing.cpp -o output && ./output

// * testcases
/*
3
4
2 4 3 6
3
1 2 3
2
4 2

*/

// * Output
/*
4 5 6 7
3 2 3
4 2
*/