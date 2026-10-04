/*
 * Three Indices
 * 
 * Description:
 * Given a permutation p of length n, find any three indices i, j, and k such that:
 * 1 <= i < j < k <= n, and p_i < p_j and p_j > p_k.
 * If such a peak element (p_j) with smaller elements to its left and right exists, 
 * output "YES" followed by the 1-based indices i, j, and k. Otherwise, output "NO".
 * 
 * Constraints:
 * 1 <= t <= 200 (number of test cases)
 * 3 <= n <= 1000 (length of the permutation)
 * The array p contains a permutation of integers from 1 to n.
 * 
 * Example 1    :
 * Input        : n = 4, p = [2, 1, 4, 3]
 * Output       : YES
 *                2 3 4
 * Explanation  : For indices 2, 3, and 4 (1-indexed):
 *                p_2 = 1, p_3 = 4, p_4 = 3. 
 *                This satisfies 1 < 4 and 4 > 3, making it a valid peak.
 * 
 * Example 2    :
 * Input        : n = 4, p = [4, 3, 2, 1]
 * Output       : NO
 * Explanation  : The array is strictly decreasing, so it is impossible to find a peak structure.
 *
 * https://codeforces.com/problemset/problem/1380/A
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

vector<int> solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
    
  for (int i = 1; i < n - 1; ++i) {
    if (a[i] > a[i-1] && a[i] > a[i+1]) {
      return {i, i+1, i+2};
    }
  }
  
  return {};
}

// * Find the mountain
// * Time Complexity (TC): O(n) = O(10^3)
// * Space Complexity (SC): O(1)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    vector<int> indices = solve();
    if (!indices.size()) {
      cout << "NO" << "\n";
    } else {
      cout << "YES" << "\n";
      cout << indices[0] << " " << indices[1] << " " << indices[2] << "\n";
    }
  }
  
  return 0;
}


// * Run the code
// * g++ --std=c++20 29-three-indices.cpp -o output && ./output

// * testcases
/*
6
2 4
0 24 34 58 62 64 69 78
2 2
27 61 81 91
4 3
2 4 16 18 21 27 36 53 82 91 92 95
3 4
3 11 12 22 33 35 38 67 69 71 94 99
2 1
11 41
3 3
1 1 1 1 1 1 1 1 1

*/

// * Output
/*
165
108
145
234
11
3
*/
