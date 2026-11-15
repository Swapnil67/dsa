/*
 * Valerii Against Everyone
 * 
 * You are given an array 'b' of length 'n'. An array 'a' is defined such that 
 * a_i = 2^(b_i) for each element. Determine if there exist two non-intersecting 
 * subarrays of 'a' that have the exact same sum of elements.
 * 
 * Constraints  :
 *                1 <= t <= 100 (number of test cases)
 *                2 <= n <= 1000
 *                0 <= b_i <= 10^9
 * 
 * Example 1    :
 * Input        : n = 6, b = [4, 3, 0, 1, 2, 0]
 * Output       : YES
 * Explanation  : The array 'a' becomes [16, 8, 1, 2, 4, 1]. We can choose the first subarray 
 *                from index 3 to 3 (element 1) and the second subarray from index 6 to 6 
 *                (element 1). Their sums are both 1, and they do not intersect.
 * 
 * Example 2    :
 * Input        : n = 3, b = [2, 5, 4]
 * Output       : NO
 * Explanation  : The array 'a' becomes [4, 32, 16]. Every unique combination of powers of 2 
 *                yields a distinct binary bit representation, meaning no two non-intersecting 
 *                subarrays can ever achieve an identical sum.
 *
 * https://codeforces.com/problemset/problem/1438/B
*/

// ! Observation

// * If the array 'b' is all distinct, answer is surely "NO" else "YES".

#include <vector>
#include <iostream>
#include <unordered_set>
 
using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
	vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  unordered_set<ll> st; // * Create a set to store unique elements
  for (auto &x: a) 
    st.insert(x);

  // * If the size of the set is less than n, it means there are duplicates
  if (st.size() < n) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

// * Powers of two uniqueness
// * Time Complexity (TC): O(n) = O(1000)
// * Space Complexity (SC): O(n) = O(1000)
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
// * g++ --std=c++20 practice.cpp -o output && ./output

// * testcases
/*
2
6
4 3 0 1 2 0
2
2 5

*/

// * Output
/*
YES
NO
*/