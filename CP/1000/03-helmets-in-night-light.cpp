/*
 * Helmets in Night Light
 * 
 * Pak Chanek needs to notify all n residents in a village about an announcement.
 * Initially, he can share the announcement directly with any resident at a cost of p per person.
 * Once a resident i receives the announcement, they can share it with up to a_i other residents,
 * with each share costing b_i. 
 * Find the minimum total cost required to notify all n residents.
 * 
 * Constraints:
 * 1 <= t <= 10^4 (Number of test cases)
 * 1 <= n <= 10^5 (Sum of n over all test cases does not exceed 10^5)
 * 1 <= p <= 10^5
 * 1 <= a_i <= 10^5
 * 1 <= b_i <= 10^5
 * 
 * Example 1    :
 * Input        : n = 6, p = 3, a = [2, 3, 2, 1, 1, 3], b = [4, 3, 2, 4, 3, 3]
 * Output       : 16
 * Explanation  : Pak Chanek pays 3 to inform resident 3 (b_3 = 2). Resident 3 then shares it with 2 others 
 *               (e.g., residents 2 and 5) at a cost of 2 * 2 = 4. Resident 2 (b_2 = 3) then shares it with the 
 *               remaining 3 residents at a cost of 3 * 3 = 9. Total cost = 3 + 4 + 9 = 16.
 * 
 * Example 2    :
 * Input        : n = 1, p = 5, a = [5], b = [3]
 * Output       : 5
 * Explanation  : There is only 1 resident, so Pak Chanek must inform them directly for a cost of 5.
 *
 * https://codeforces.com/problemset/problem/1876/A
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

ll solve() {
  ll n, p;
  cin >> n >> p;

  // * Read the maximum number of residents each resident can share the announcement to
  VEC(a, n, ll); READ_VEC(a);
  // * Read the cost for each resident to share the announcement
  VEC(b, n, ll); READ_VEC(b);
  
  VEC(V, n, pair<ll, ll>); // * Vector to store pairs of (sharing cost, max shares)
  for (int i=0; i<n; ++i) {
    V[i] = {b[i], a[i]};
  }
  sort(all(V));

  ll min_cost = p;       // * Start with the cost of sharing to one resident directly
  ll already_shared = 1; // * Start with one resident already informed
  for (auto &it: V) {
    ll can_be_shared = it.second; // * Max number of residents this resident can share with
    ll sharing_cost = it.first;   // * Cost for this resident to share

    // * If the sharing cost is greater than or equal to direct sharing cost, break
    if (sharing_cost >= p)
      break;
      
    if (already_shared + can_be_shared >= n) {
      min_cost += (n - already_shared) * sharing_cost;
      already_shared = n; // * All residents are informed
      break;
    } else {
      min_cost += can_be_shared * sharing_cost; // * Add cost for sharing
      already_shared += can_be_shared;          // * Update the count of informed residents
    }
  }

  // * Add the cost for the remaining residents to be informed directly
  min_cost += (n - already_shared) * p; // * chief sharing
	
	return min_cost;
}


// * Time Complexity (TC): O(nlogn) = O(10^5(log2(10^5))) = O(10^5 * 17) = O(1.7 * 10^6)
// * Space Complexity (SC): O(n) = O(10^5)
int main() {
	ll t;
	cin >> t; // * Read the number of test cases
	while (t--) {
    int min_ops = solve();
		cout << min_ops << endl;
	}
	return 0;
}

// * Run the code
// * g++ --std=c++20 03-helmets-in-night-light.cpp -o output && ./output

// * testcases
/*
3
6 3
2 3 2 1 1 3
4 3 2 6 3 6
1 100000
100000
1
4 94
1 4 2 3
103 96 86 57

*/

// * Output
/*
16
100000
265
*/