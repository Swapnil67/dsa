/*
* C. Superultra's Favorite Permutation
*
* https://codeforces.com/contest/2037/problem/C
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

// ! Observation
/*
* 1. Parity Property: The sum of any two distinct odd numbers is an even number >= 4, which is always composite. 
*    Similarly, the sum of any two distinct even numbers is an even number >= 6, which is also always composite.
*
* 2. Grouping: If we group all odd numbers together and all even numbers together, every adjacent pair within
*    each group automatically has a composite sum. We only need to ensure the single boundary where the odd group 
*    meets the even group sums to a composite number.
*
* 3. Smallest Composite Boundary: The smallest odd composite number is 9. Using 5 (from the odd group) and 4 (from the even group) 
*    at the junction gives 5 + 4 = 9, which is composite.
*
* 4. Edge Cases (n <= 4): Since we need both 4 and 5 to form this valid boundary, any n < 5 cannot use this construction. 
*    By checking all permutations for n = 2, 3, and 4, no valid arrangement exists because at least one odd-even 
*    adjacent pair will sum to a prime (2, 3, 5, or 7).
*/

// ! Approach: Parity Grouping with a 5-4 Bridge
// * Time Complexity: O(n)
// * Space Complexity: O(n)
void solve() {
  // * take input
  ll n; 
  cin >> n;

  if (n <= 4) {
    cout << -1 << '\n';
    return;
  }

  for (int i = 1; i <= n; i += 2) {
    if (i == 5) continue;
    cout << i << ' '; 
  }
  cout << "5 4 ";
  for (int i = 2; i <= n; i += 2) {
    if (i == 4) continue;
    cout << i << ' '; 
  }
  
  cout << '\n';
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}

// * Run the code
// * g++ --std=c++20 C_Superultra_s_Favorite_Permutation.cpp -o output && ./output
