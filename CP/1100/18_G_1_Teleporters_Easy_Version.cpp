/*
 * G1. Teleporters (Easy Version)
 *
 * https://codeforces.com/problemset/problem/1791/G1
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define PRINT_VEC(p)   \
  for (auto &it : p)   \
    cout << it << ' '; \
  cout << '\n'

// * Time Complexity (TC): O(nlogn)
// * Space Complexity (SC): O(n)
void solve() {
	ll n; 
	cin >> n;
	ll c;
	cin >> c;
	vector<ll> cost;

	// * Read the cost of each teleporter and calculate the effective cost
	for (int i = 1; i <= n; i++) { // * Loop through each teleporter
		ll x;
		cin >> x; // * Cost to use teleporter at position i
		cost.push_back(i + x); // * Effective cost includes moving to position i
	}

	// * Sort the costs in ascending order to use the cheapest teleporters first
	sort(cost.begin(), cost.end());

	int i = 0; // * Index to iterate through the sorted costs
	int ans = 0; // * Counter for the number of teleporters used

	// * Use teleporters while there are enough coins
	while (i < n && cost[i] <= c) {
		c -= cost[i]; // * Deduct the cost from the available coins
		ans++; // * Increment the count of teleporters used
		i++; // * Move to the next teleporter
	}

	cout << ans << endl; 
}

int main() {
	ll t;
	cin >> t; // Read the number of test cases
	while (t--) 
		solve();
}

// * Run the code
// * g++ --std=c++20 18_G_1_Teleporters_Easy_Version.cpp -o output && ./output
