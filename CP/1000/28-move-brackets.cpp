/*
 * C. Move Brackets
 *
 * https://codeforces.com/problemset/problem/1374/C 
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;


// * Time Complexity (TC): O(n)
// * Space Complexity (SC): O(n)
int main()
{
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		string s;
		cin >> n >> s; 

		ll sum = 0; // * Initialize sum to track balance of brackets
		ll ops = 0; // * Initialize ops to count the number of operations needed

		// * Iterate over each character in the string
		for (int i = 0; i < n; i++) {
			if (s[i] == ')')
				sum--; // * Decrement sum for a closing bracket
			else
				sum++; // * Increment sum for an opening bracket

			// * If sum is negative, it means there are more closing brackets than opening
			if (sum < 0) {
				ops++; // * Increment operations needed
				sum = 0; // * Reset sum to zero to start fresh
			}
		}

		cout << ops << endl; 
	}
	return 0;
}

// * Run the code
// * g++ --std=c++20 28-move-brackets.cpp -o output && ./output
