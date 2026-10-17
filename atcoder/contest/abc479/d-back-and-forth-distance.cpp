/*
 * D - Back and Forth Distance
 * 
 * https://atcoder.jp/contests/abc479/tasks/abc479_d
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

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

/*
 * LOGIC AND INTUITION BEHIND THIS SOLUTION:
 * 
 * * 1. Problem Setup:
 *    We have 'n' nodes arranged linearly. 
 *    - Moving from left to right: The direct edge from i to i+1 costs R[i].
 *    - Moving from right to left: The direct edge from i to i-1 costs L[i].
 * 
 * * 2. Prefix and Suffix Minimums:
 *    The problem allows us to bounce "back-and-forth" to find optimal routes.
 *    - When moving forward (s < t), we don't just look at R[s]. We could potentially
 *      step BACKWARDS to a cheaper rightward path found earlier in the sequence. 
 *      'pre_min_R[i]' stores the absolute cheapest rightward edge cost available 
 *      from index 1 up to i.
 *    - When moving backward (s > t), we might step FORWARDS to a cheaper leftward
 *      path found later in the sequence. 'suf_min_L[i]' stores the cheapest leftward 
 *      edge cost available from index i up to n.
 * 
 * * 3. Query Transitions:
 *    - For s < t (Moving Right): The cost is the minimum of taking the direct right 
 *      edge R[s], OR stepping left (L[s]) and utilizing the best historical rightward 
 *      edge available before us (pre_min_R[s - 1]).
 *    - For s > t (Moving Left): The cost is the minimum of taking the direct left 
 *      edge L[s], OR stepping right (R[s]) and utilizing the best upcoming leftward 
 *      edge available ahead of us (suf_min_L[s + 1]).
 */

int main(void) {
  // * Optimize standard I/O operations for performance
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll n, q;
  if (!(cin >> n >> q)) return 0;

  // * L[i] stores the cost to move left from node i to i-1 (valid from index 2 to n)
  // * R[i] stores the cost to move right from node i to i+1 (valid from index 1 to n-1)
  vector<ll> L(n + 2, 0), R(n + 2, 0);
  for (size_t i = 2; i <= n; ++i) {
    cin >> L[i];
  }
  for (size_t i = 1; i <= n - 1; ++i) {
    cin >> R[i];
  }

  const ll INF = 1e18 + 5; // * Used large INF to prevent overflow with long long

  // * pre_min_R[i] = lowest cost to go right anywhere from node 1 to node i
  vector<ll> pre_min_R(n + 2, INF);
  if (n > 1) {
    pre_min_R[1] = R[1]; // * Correctly initialized with the first rightward edge cost
    for (size_t i = 2; i <= n - 1; ++i) {
      pre_min_R[i] = min(pre_min_R[i - 1], R[i]);
    }
  }

  // * suf_min_L[i] = lowest cost to go left anywhere from node i to node n
  vector<ll> suf_min_L(n + 2, INF);
  if (n > 1) {
    suf_min_L[n] = L[n]; // * Initialized with the last leftward edge cost
    for (size_t i = n - 1; i >= 2; --i) {
      suf_min_L[i] = min(suf_min_L[i + 1], L[i]);
    }
  }

  // * Processing the distance queries
  while (q--) {
    ll s, t;
    cin >> s >> t;
    ll ans = 0;
    
    if (s < t) {
      // * If going right, compare going directly right vs. stepping left once 
      // * and taking the best previous rightward shortcut.
      ans = min(R[s], L[s] + pre_min_R[s - 1]);
    } else {
      // * If going left, compare going directly left vs. stepping right once 
      // * and taking the best upcoming leftward shortcut.
      ans = min(L[s], R[s] + suf_min_L[s + 1]);
    }
    cout << ans << '\n';
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 d-back-and-forth-distance.cpp -o output && ./output

// * testcase
/*
5 7
5 6 2 9
3 1 3 8
1 2
2 1
2 4
3 2
3 5
4 3
5 2


*/