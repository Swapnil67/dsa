
/*
 * NAME: Self-Stopping Shower
 * 
 * Description:
 * Find the minimum manual button presses needed to keep hot water running continuously from 0 to T, 
 * given N people press the button at times A_i, and each press extends hot water duration by K seconds.
 * 
 * Constraints:
 * - 1 <= N <= 2 * 10^5, 1 <= K, T <= 10^9, 0 <= A_i <= 10^9
 * 
 * Example 1    :
 * Input        : N = 3, K = 4, T = 20, A = [6, 7, 12]
 * Output       : 4
 * Explanation  : Presses at 0, 2, 10, and 16 cover the timeline continuously.
 * 
 * Example 2    :
 * Input        : N = 9, K = 37, T = 480, A = [12, 123, 132, 213, 231, 312, 321, 500, 1000]
 * Output       : 11
 *
 * https://atcoder.jp/contests/abc480/tasks/abc480_c
*/

/*
 * INTUITION:
 * The goal is to cover the time interval [0, T] continuously. 
 * Each button press extends the hot water flow for exactly K seconds.
 * 
 * Instead of tracking active intervals chronologically, we can look at the 
 * gaps between consecutive points where hot water is guaranteed to start. 
 * If a person presses the button at A_i, they automatically guarantee coverage 
 * for the interval [A_i, A_i + K].
 * 
 * By sorting all arrival times, the maximum continuous coverage from a single 
 * press at A_i to the next person at A_{i+1} is capped at K seconds. If the 
 * physical distance (diff = A_{i+1} - A_i) is strictly greater than K, it leaves 
 * an uncovered "dead zone" of length: 
 *     x = diff - K
 * 
 * To fill this dead zone optimally using our own button presses, we apply a 
 * greedy choice: each manual press gives us up to K seconds of coverage. 
 * Thus, we need ceil(x / K) additional manual presses to close the gap.
 * 
 * Boundary Conditions:
 * 1. To ensure we are covered starting exactly at time 0, we insert an artificial 
 *    press at '-K'. After sorting, this guarantees that time 0 is naturally 
 *    evaluated against the first person's arrival time.
 * 2. To ensure coverage extends all the way up to time T, we insert an artificial 
 *    press milestone at 'T'.
 */

 
#include <vector>
#include <iostream>
#include <algorithm>

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
  cout << " ]" << "\n";
}

// ! Greedy on differences
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
void solve() {
  int n, k, t;
  cin >> n >> k >> t;

  vector<int> a;
  int val;
  for (int i = 0; i < n; ++i)  {
    cin >> val;
    // * Ignore events that happen after the target timestamp T
    if (val <= t) { 
      a.push_back(val);
    }
  }

  // * Boundary injection: -k covers up to time 0, and t acts as our rightmost deadline
  a.push_back(-k);
  a.push_back(t);

  // * Sort the timeline chronologically to easily calculate consecutive gaps
  sort(begin(a), end(a));
  // printArr(a); // * For debug
  
  int ans = 0;
  for (int i = 0; i < (int)a.size() - 1; ++i) {
    int diff = a[i + 1] - a[i];
    // cout << diff << '\n';
    // * If the gap between events is larger than what a single press (K) can bridge
    if (diff > k) {
      long long x = diff - k; // * The length of the remaining dead zone
      ans += (x + k - 1) / k; // * Greedy addition: integer ceiling of (x / k)
    }
  }

  cout << ans << '\n';
}

int main(void) {
  // Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  solve();
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 c-self-stopping-shower.cpp -o output && ./output
