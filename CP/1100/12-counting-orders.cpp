/*
 * Counting Orders
 * 
 * Description  : You are given two arrays `a` and `b` each consisting of `n` integers. 
 *                All elements of array `a` are pairwise distinct. Find the number of 
 *                ways to reorder `a` such that `a[i] > b[i]` for all 1 <= i <= n. 
 *                Since the answer can be large, return it modulo 10^9 + 7.
 *                
 *                Two ways of reordering are considered different if the resulting 
 *                arrays are different.
 * 
 * Constraints  : 
 *                1 <= n <= 2 * 10^5
 *                1 <= a[i], b[i] <= 10^9
 *                All elements in `a` are distinct.
 * 
 * Example 1    :
 * Input        : n = 6, a = [9, 6, 4, 2, 8, 5], b = [2, 2, 5, 9, 1, 4]
 * Output       : 4
 * Explanation  : There are 4 distinct valid reorderings of `a` that satisfy the condition:
 *                1. [5, 6, 8, 2, 9, 4]
 *                2. [5, 6, 9, 2, 8, 4]
 *                3. [6, 5, 8, 2, 9, 4]
 *                4. [6, 5, 9, 2, 8, 4]
 * 
 * Example 2    :
 * Input        : n = 2, a = [1, 2], b = [2, 1]
 * Output       : 0
 * Explanation  : No matter how we reorder `a`, we can never satisfy `a[i] > b[i]` for all indices.
 *
 * https://codeforces.com/problemset/problem/1827/A
 */

// ! Combinatorics

/*
 * INTUITION & LOGIC:
 * 
 * 1. The Bottleneck Constraint (Greedy Choice):
 *    The elements in 'b' represent limits that elements in 'a' must beat. 
 *    The largest element in 'b' (b[0] after descending sort) is the hardest constraint to satisfy. 
 *    If we process 'b' from largest to smallest, we first find choices for the hardest constraints.
 * 
 * 2. Matching Choices:
 *    For each element b[i], we find how many elements in 'a' are strictly greater than b[i].
 *    Since 'a' is sorted in ascending order, we use upper_bound to find the first element 
 *    not greater than b[i]. The count of valid elements is: count = n - idx.
 * 
 * 3. Account for Element Consumption (The Combinatorics):
 *    Since we process 'b' in descending order, any element in 'a' that satisfies a large b[i] 
 *    will *also* automatically satisfy all subsequent, smaller elements in 'b'.
 *    Therefore, the 'i' elements we have already paired up with larger 'b' values are guaranteed 
 *    to be part of the current 'count' pool.
 *    
 *    To avoid using the same element of 'a' twice, we subtract 'i' (the number of elements 
 *    already consumed) from our total valid options: (ele_greater_than_bi - i).
 * 
 * 4. Counting Principles (Product Rule):
 *    By the fundamental counting principle, the total number of valid reorderings is 
 *    the product of available choices at each step, computed modulo 10^9 + 7.
 *    If at any point choices drop to <= 0, max(..., 0LL) ensures the product correctly becomes 0.
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

// Time Complexity (TC): O(n log n) due to sorting and binary search
// Space Complexity (SC): O(n) to store vectors a and b
void solve() {
  ll n;
  cin >> n;

  VEC(a, n, ll); READ_VEC(a);
  sort(all(a));  // * ascending order
  
  VEC(b, n, ll); READ_VEC(b);
  sort(rall(b)); // * descending order
  
  ll MOD = 1e9 + 7;
  ll answer = 1;
  for (size_t i = 0; i < n; ++i) {
    // * Find the first element in 'a' that is strictly greater than b[i]
    ll idx = upper_bound(all(a), b[i]) - a.begin();
    ll ele_greater_than_bi = n - idx;
    
    // * Available choices = (Total qualified elements in 'a') - (Elements already assigned to larger b[j])
    ll available_choices = ele_greater_than_bi - i;
    
    // * Accumulate the combinations using modular multiplication
    answer = answer * max(available_choices, 0LL) % MOD;
  }
  
  cout << answer << '\n';
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
// * g++ --std=c++20 11-maximum-sum.cpp -o output && ./output

// * testcases
/*
5
6
9 6 8 4 5 2
4 1 5 6 3 1
3
4 3 2
3 4 9
1
2
1
3
2 3 4
1 3 3
12
2 3 7 10 23 28 29 50 69 135 420 1000
1 1 2 3 5 8 13 21 34 55 89 144

*/

// * Output
/*
32
0
1
0
13824

*/