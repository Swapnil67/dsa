/*
 * Make It Increasing
 * 
 * Description:
 * Given an array of n positive integers a = [a_1, a_2, ..., a_n]. You can perform the following 
 * operation on the array any number of times: 
 * Choose any index i (1 <= i <= n) and replace a_i with floor(a_i / 2) (divide a_i by 2 and round down).
 * Find the minimum number of operations required to make the array strictly increasing 
 * (a_1 < a_2 < ... < a_n). If it is impossible to make the array strictly increasing, return -1.
 * 
 * Constraints:
 * 1 <= n <= 30
 * 0 <= a_i <= 2 * 10^9
 * 
 * Example 1    :
 * Input        : nums = [3, 6, 5, 10]
 * Output       : 2
 * Explanation  : You can divide a_2 = 6 by 2 once to get 3. The array becomes. 
 *                Then divide a_1 = 3 by 2 once to get 1. The array becomes, 
 *                which is strictly increasing. The total number of operations is 2.
 * 
 * Example 2    :
 * Input        : nums = [5, 4, 3, 2, 1]
 * Output       : -1
 * Explanation  : It is impossible to make this array strictly increasing using the allowed operations.
 *
 * https://codeforces.com/problemset/problem/1675/B
*/

// ! Observation
/*
 * Let's see first the naive approach from going left to right
 * 
 * If we go from Left -> right we'll then if we make a[2] < a[3] then it is possible that 
 * a[2] became less than a[1] also then we need to check again from start.

 * We'll move from right to left making sure that a[i] < a[i + 1]
 * this how if we make a[3] < a[4], then we don't need to check a[3] with a[5] since its already less
 * than a[4] it will be automatically less than a[5].
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * Greedy from right to left
// * TC = O(n^2)
// * SC = O(n) (Input array)
int main(void)
{
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

    int min_ops = 0;
    // * Greedy from right to left
    for (int i = n - 2; i >= 0; --i) {
      // * Make a[i] smaller than a[i+1]
      while (a[i] >= a[i + 1]) { 
        a[i] = a[i] / 2;
        min_ops += 1; // * increase the operations
        if (a[i] == 0) { // * cannot decrease more
          break;
        }
      }

      // * Cannot make array increasing
      if (a[i] == 0 && a[i + 1] == 0) {
        min_ops = -1;
        break;
      }
    }

    cout << min_ops << endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 15-make-it-increasing.cpp -o output && ./output

// * testcases
/*
7
3
3 6 5
4
5 3 2 1
5
1 2 3 4 5
1
1000000000
4
2 8 7 5
5
8 26 5 21 10
2
5 14

*/

// * Output
/*
2
-1
0
0
4
11
0
*/