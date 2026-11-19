/*
 * B. Li Hua and Pattern
 *
 * https://codeforces.com/problemset/problem/1797/B
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
  
// * Time Complexity (TC): O(n^2)
// * Space Complexity (SC): O(n^2)
int main() {
	ll t;
	cin >> t; // Read the number of test cases
	while (t--) {
		ll n, k;
		cin >> n >> k; 
		ll arr[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		ll mismatches = 0; // Initialize a counter for mismatched cells

		// * Count the number of mismatched cells compared to the 180-degree rotated pattern
		for (int i = 0; i < n; i++) { // * Loop over rows
			for (int j = 0; j < n; j++) { // * Loop over columns
				// * Compare the cell with its 180-degree rotated counterpart
				if (arr[i][j] != arr[n - i - 1][n - j - 1]) {
					mismatches++; // * Increment the counter if they are different
				}
			}
		}
		mismatches /= 2; // * Each mismatch is counted twice, so divide by 2

		// * Check if the number of mismatches can be corrected with k operations
		if (mismatches > k) {
			cout << "NO" << endl; // * Not enough operations to correct mismatches
		} else {
			ll temp = k - mismatches; // * Calculate remaining operations after correcting mismatches
			// * Check if the remaining operations can be used to make the pattern symmetric
			if (temp % 2 == 0) {
				cout << "YES" << endl; // * Even number of operations left, pattern can be symmetric
			} else {
				if (n % 2 == 0) {
					cout << "NO" << endl; // * Odd operations left and even n, cannot be symmetric
				} else {
					cout << "YES" << endl; // * Odd operations left and odd n, can be symmetric
				}
			}
		}
	}

}

// * Run the code
// * g++ --std=c++20 17_B_Li_Hua_and_Pattern.cpp -o output && ./output