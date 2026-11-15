/*
 * Sort the Subarray
 * 
 * Description  : Monocarp had an array `a` consisting of `n` integers. He chose two 
 *                indices `l` and `r` (1 <= l <= r <= n) and sorted the elements in the 
 *                subarray a[l...r] in non-descending order. The rest of the array remained 
 *                unchanged. This resulted in a new array `a'`. 
 *                
 *                You are given both arrays `a` and `a'`. Find the indices `l` and `r` that 
 *                Monocarp could have chosen. If there are multiple valid pairs of (l, r), 
 *                choose the one that maximizes the length of the sorted subarray (i.e., 
 *                maximizes r - l + 1).
 * 
 * Constraints  : 
 *                1 <= t <= 10^4 (Number of test cases)
 *                2 <= n <= 2 * 10^5
 *                1 <= a[i], a'[i] <= n
 *                It is guaranteed that a' can be obtained from a by sorting a single subarray.
 *                The sum of n over all test cases does not exceed 2 * 10^5.
 * 
 * Example 1    :
 * Input        : n = 7, a = [6, 7, 3, 4, 4, 6, 5], a' = [6, 3, 4, 4, 7, 6, 5]
 * Output       : 2 5
 * Explanation  : Sorting the subarray from index 2 to 5 in `a` gives [3, 4, 4, 7], 
 *                resulting in `a'`. This is the longest valid subarray length.
 * 
 * Example 2    :
 * Input        : n = 3, a = [1, 2, 1], a' = [1, 1, 2]
 * Output       : 2 3
 * Explanation  : Sorting from index 2 to 3 gives the required result.
 * 
 * Example 3    :
 * Input        : n = 5, a = [2, 2, 1, 1, 2], a' = [2, 1, 1, 2, 2]
 * Output       : 2 5
 * Explanation  : Sorting the subarray from index 2 to 5 converts [2, 1, 1, 2] into [1, 1, 2, 2].
 *
 * https://codeforces.com/problemset/problem/1821/B
 */

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;
typedef long long ll;

#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

void solve() {
  ll n;
  cin >> n;

  VEC(a, n, ll); READ_VEC(a);
  VEC(b, n, ll); READ_VEC(b);

  // * Find the first and last positions where the arrays differ
  int change1 = -1, change2 = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      if (change1 == -1) {
        change1 = i; // * First differing position
      } else {
        change2 = i; // * Last differing position
        break;
      }
    }
  }

  // * Extend the left boundary of the subarray if possible
  int i = change1 - 1;
  while (i >= 0) {
    if (b[i + 1] >= b[i]) // * left ele should be smaller
      i--;
    else
      break;
  }
  change1 = i + 1;

  // * If no second change was found, assume the end of the array
  if (change2 == -1) {
    change2 = n - 1;
  }

  // * Extend the right boundary of the subarray if possible
  int j = change2 + 1;
  while (j < n - 1) {
    if (b[j] >= b[j - 1]) // * right ele should be bigger
      j++;
    else 
      break;
  }
  change2 = j - 1;

  cout << change1 + 1 << " " << change2 + 1 << endl;
}

int main() {
  // Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
	return 0;
} 

// * Run the code
// * g++ --std=c++20 14-sort-the-subarray.cpp -o output && ./output


// * testcases
/*
3
7
6 7 3 4 4 6 5
6 3 4 4 7 6 5
3
1 2 1
1 1 2
3
2 2 1
2 1 2

*/

// * Output
/*
2 5
1 3
2 3
*/