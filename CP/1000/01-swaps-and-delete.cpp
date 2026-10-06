/*
 * NAME: 1913B - Swap and Delete
 * 
 * Description:
 * You are given a binary string s (consisting only of '0' and/or '1'). You can perform two operations:
 * 1. Remove a character from s (costs 1 coin).
 * 2. Swap any pair of characters in s (costs 0 coins).
 * 
 * You can perform these operations in any order and any number of times to get a new string t.
 * The string t is "good" if for every index i, t[i] != s[i] (compared with the initial s).
 * Find the minimum total cost (deletions) to make a modified string t good.
 * 
 * Constraints:
 * 1 <= t <= 10^4 (number of test cases)
 * 1 <= |s| <= 2 * 10^5 (length of binary string s)
 * The sum of |s| over all test cases does not exceed 2 * 10^5.
 * 
 * Example 1    :
 * Input        : s = "0"
 * Output       : 1
 * Explanation  : You have to delete the character from s to get an empty string t, which costs 1 coin.
 * 
 * Example 2    :
 * Input        : s = "011"
 * Output       : 1
 * Explanation  : Delete the second character to get "01", then swap them to get t = "10". 
 *                Since t[0] != s[0] and t[1] != s[1], t is good. Total cost is 1 coin.
 *
 * https://codeforces.com/problemset/problem/1913/B
*/

#include <vector>
#include <iostream>
using namespace std;

// ! Observation
/*
* s = 111100
* 
* We'll count number of 0s and 1s and try to greedily maximize our ops 2 (swap)
* c1 = 4 & c0 = 2
*
* s = 111100
* t = 001100
*/

int solve() {
  string s;
  cin >> s;                             // * Read the binary string for the current test case
  int n = s.size();                     // * Get the length of the string
  int count_of_0s = 0, count_of_1s = 0; // * Initialize counters for '0's and '1's

  // * Count the number of '0's and '1's in the string
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      count_of_0s++;
    else
      count_of_1s++;
  }

  int length_of_t = 0; // * Initialize the length of the resulting good string

  // * Determine the maximum length of a good string that can be formed
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' && count_of_1s > 0) {
      count_of_1s--; // * Use a '1' to make a pair with '0'
      length_of_t++; // * Increase the length of the good string
    }
    else if (s[i] == '1' && count_of_0s > 0) {
      count_of_0s--; // * Use a '0' to make a pair with '1'
      length_of_t++; // * Increase the length of the good string
    }
    else {
      break; // No more pairs can be formed
    }
  }
  return n - length_of_t;
}

// ! Greedy Prefix Matching
// * Time Complexity (TC): O(n) = O(2*10^5)
// * Space Complexity (SC): O(n) = O(2*10^5)
int main() {
  // Optimize standard I/O operations for competitive programming
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

	int t;
	cin >> t; // Read the number of test cases
	while (t--) {
		// Output the minimum cost to make the string good
    ll min_cost = solve();
		cout << min_cost << endl;
	}
	return 0;
}

// * Run the code
// * g++ --std=c++20 01-swaps-and-delete.cpp -o output && ./output

// * testcases
/*
4
0
011
0101110001
111100

*/

// * Output
/*
1
1
0
4
*/