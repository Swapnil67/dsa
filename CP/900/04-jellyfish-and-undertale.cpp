/*
 * NAME: 1875A - Jellyfish and Undertale
 * 
 * Description:
 * Jellyfish has a bomb with a timer that decreases by 1 every second. If the timer reaches 0, 
 * the bomb explodes. The timer can never exceed a maximum capacity of 'a' seconds. 
 * She has 'n' tools. The i-th tool can increase the timer by x[i] seconds instantly when used, 
 * but the timer will still be capped at 'a'. If she starts with an initial time of 'b', 
 * find the maximum number of seconds the bomb can run before exploding if she uses the tools optimally.
 * 
 * Constraints:
 * 1 <= t <= 2 * 10^4 (Number of test cases)
 * 1 <= b < a <= 10^9
 * 1 <= n <= 100
 * 1 <= x[i] <= 10^9
 * 
 * Example 1    :
 * Input        : a = 5, b = 3, n = 3, x = [1, 1, 7]
 * Output       : 9
 * Explanation  : Start at 3s. Let it tick down to 1s (elapsed: 2s). Use tool 3 (7s), timer caps at 5s. 
 *                Let it tick down to 1s (elapsed: +4s). Use tool 1 (1s), timer becomes 2s. 
 *                Let it tick down to 1s (elapsed: +1s). Use tool 2 (1s), timer becomes 2s. 
 *                Let it run down to 0s (elapsed: +2s). Total = 2 + 4 + 1 + 1 + 2 = 9 seconds.
 * 
 * Example 2    :
 * Input        : a = 10, b = 2, n = 2, x = [2, 1]
 * Output       : 5
 * Explanation  : Start at 2s. Let it tick to 1s. Use tool 1 (+2) -> 3s. Let it tick to 1s. 
 *                Use tool 2 (+1) -> 2s. Let it run to 0s. Total = 1 + 2 + 2 = 5 seconds.
 * 
 * 
 * https://codeforces.com/problemset/problem/1875/A
*/


#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    ll a, b, n;
    cin >> a >> b >> n;
    vector<ll> tools(n);
    for (int i = 0; i < n; ++i)
      cin >> tools[i];

    for (int i = 0; i < n; ++i)
      b = b + min(tools[i], a - 1);

    cout << b << "\n";
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-jellyfish-and-undertale.cpp -o output && ./output

// * testcases
/*
2
5 3 3
1 1 7
7 1 5
1 2 5 6 8

*/


// * Output
/*
9
21
*/