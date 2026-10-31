/*
 * Concatenation of Prefixes
 * 
 * Description:
 * Given an array A of length N, a sequence B is formed by sequentially appending 
 * the prefixes of A (i.e., (A_1), (A_1, A_2), ..., (A_1, ..., A_N)). Answer Q queries 
 * where each query asks for the sum of elements in B from index L to R (1-indexed).
 * 
 * Constraints:
 * - 1 <= N, Q <= 10^5
 * - -10^8 <= A_i <= 10^8
 * - 1 <= L <= R <= N * (N + 1) / 2
 * 
 * Example 1    :
 * Input        : N = 4, Q = 3, A = [1, 10, 100, 1000]
 *                Query 1: L = 3, R = 6
 *                Query 2: L = 1, R = 10
 *                Query 3: L = 8, R = 8
 * Output       : 121
 *                1234
 *                10
 * Explanation  : B is.
 *                - Query 1: B[3] + ... + B[6] = 10 + 1 + 10 + 100 = 121.
 *                - Query 2: Sum of all elements = 1234.
 *                - Query 3: B[8] = 10.
 * 
 * Example 2    :
 * Input        : N = 7, Q = 1, A = [10^8, 10^8, 10^8, 10^8, 10^8, 10^8, 10^8], Query: L = 1, R = 28
 * Output       : 2800000000
 *
 * https://atcoder.jp/contests/abc480/tasks/abc480_d
*/

/*
 * TECHNIQUE: Coordinate Mapping via Binary Search & Second-Order Prefix Sums
 * 
 * 1. COORDINATE MAPPING (INDEX DECONSTRUCTION):
 * The virtual array B is built out of cascading blocks of prefix sums:
 *   Block 1 (len 1): [A_1]
 *   Block 2 (len 2): [A_1, A_2]
 *   Block 3 (len 3): [A_1, A_2, A_3]
 *   ...
 *   Block k (len k): [A_1, A_2, ..., A_k]
 * 
 * The total number of elements completely contained within the first 'k' blocks 
 * follows the triangular number formula: Total = k * (k + 1) / 2.
 * 
 * Because this formula increases monotonically (always goes up), we use BINARY SEARCH 
 * to find the largest number of full blocks 'k' that fit entirely within a flat, 
 * 1-dimensional query index 'm'. 
 * Once 'k' is found, the leftover items spilling into the next block are calculated 
 * as: extra = m - (k * (k + 1) / 2). Since every block restarts at index 1, these 
 * extra items are simply the first 'extra' elements of the original array A.
 * 
 * 2. SECOND-ORDER PREFIX SUMS (PREFIX SUM OF PREFIX SUMS):
 * Your original loop ran through 'k' blocks to sum up their values one by one. 
 * Since 'k' can be as large as N, an O(N) loop inside Q queries leads to O(Q * N), 
 * resulting in a Time Limit Exceeded (TLE) error.
 * 
 * To optimize this to O(1) per query, we precompute a "Prefix Sum of Prefix Sums" 
 * array (let's call it pre_pre). 
 * If 'pre[i]' stores the sum of the first 'i' elements of A, then 'pre_pre[k]' 
 * stores the sum of: pre[1] + pre[2] + ... + pre[k]. 
 * This instantly gives us the total sum of all full blocks up to 'k' without looping!
 * 
 * Final O(1) Helper Evaluation:
 * Total Prefix Sum up to index 'm' = pre_pre[k] + pre[extra]
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

void solve() {
  int n, q;
  cin >> n >> q;
  
  vector<int> a(n);
  vector<ll> pre(n + 1);
  vector<ll> pre_pre(n + 1);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    pre[i + 1] = pre[i] + a[i]; // * 1-based
    pre_pre[i + 1] = pre_pre[i] + pre[i + 1]; // * Accumulate the block sums
  }
  // printArr(a);
  // printArr(pre);
  // printArr(pre_pre);

  // ! Binary Search
  const auto helper = [&](ll m) {
    int low = 0, high = n;
    while (low < high) {
      int k = (low + high + 1) / 2;
      ll tmp = (ll)k * (k + 1) / 2;
      if (tmp <= m) {
        low = k;
      } else {
        high = k - 1;
      }
    }

    // cout << low << ' ' << high << '\n';
    int k = low;
    ll tmp = (ll)k * (k + 1) / 2;
    int extra = m - tmp;
    ll ans = pre[extra] + pre_pre[k];
    // for (int i = 1; i <= k; ++i) {
    //   ans += pre[i];
    // }
    return ans;
  };

  while (q--) {
    ll L, R;
    cin >> L >> R;
    cout << helper(R) - helper(L - 1) << '\n';
  }
}

int main(void) {
  // Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  solve();

  return 0;
}
 

// * Run the code
// * g++ --std=c++20 d-concatenation-of-prefixes.cpp -o output && ./output

// * testcase
/*
4 3
1 10 100 1000
3 6
1 10
8 8

7 1
100000000 100000000 100000000 100000000 100000000 100000000 100000000
1 28


*/

/*
121
1234
10

2800000000

*/
