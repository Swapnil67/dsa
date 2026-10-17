/*
 * C - Bento Packing
 * 
 * https://atcoder.jp/contests/abc479/tasks/abc479_c
*/

// ! 0/1 Knapsack

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

ll  n, W, ans;
vector<ll> A(21), B(21);

void rec(int i, ll sum_a, ll sum_b) { // * O(2^N)
  if (i >= n) {
    ans = max(ans, sum_a);
    return;
  }

  rec(i + 1, sum_a, sum_b); // * Skip
  if (sum_b + B[i] <= W)
    rec(i + 1, sum_a + A[i], sum_b + B[i]); // * Take
} 

// * TIME COMPLEXITY O(2^N)
// * SPACE COMPLEXITY O(N)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin >> n >> W;
  for (int i = 0; i < n; ++i) {
    cin >> A[i] >> B[i];
  }

  // * rec(idx, sum_a, sum_b)
  rec(0, 0, 0);

  cout << ans << '\n';
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 c-bento-packing.cpp -o output && ./output
