/*
 * A. Red Versus Blue
 * 
 * Description:
 * Team Red and Team Blue played a series of n matches. In the end, Team Red won r times 
 * and Team Blue won b times. It is guaranteed that Team Blue was less skilled than 
 * Team Red, so b is strictly less than r (b < r), and r + b = n.
 * 
 * You want to reconstruct a string of length n representing the match history, where 
 * 'R' denotes a win by Team Red and 'B' denotes a win by Team Blue. The match history 
 * must be generated such that the maximum number of consecutive wins by any team 
 * (the longest contiguous sequence of the same character) is as small as possible.
 * 
 * If there are multiple valid strings that achieve this minimum possible value, 
 * output any of them.
 * 
 * Constraints:
 * - 1 <= t <= 1000 (Number of test cases)
 * - 3 <= n <= 100 (Total number of matches)
 * - 1 <= b < r <= n (Number of wins for Team Blue and Team Red)
 * - r + b = n
 * 
 * Example 1    :
 * Input        : n = 7, r = 4, b = 3
 * Output       : RBRBRBR
 * Explanation  : Each 'B' strictly separates the 'R' characters, keeping the maximum 
 *                consecutive streak of any team down to exactly 1.
 * 
 * Example 2    :
 * Input        : n = 6, r = 5, b = 1
 * Output       : RRBRRR
 * Explanation  : The single 'B' divides the 5 'R's into groups of 2 and 3. The maximum 
 *                consecutive streak of identical outcomes is 3. No distribution can 
 *                yield a smaller maximum streak.
 *
 * https://codeforces.com/problemset/problem/1659/A
 * https://leetcode.com/problems/distant-barcodes/description/
*/

#include<iostream>

using namespace std;
typedef long long ll;

string solve(void) {
  int n, r, b;
  cin >> n >> r >> b;
  
  // * Calculate the number of 'R's to be placed between each 'B'
  int length_of_red = r / (b + 1);
	// * Calculate the extra 'R's that need to be distributed
  int extra_red = r % (b + 1);
  
  string s = "";
  // * Loop to construct the string with minimum consecutive wins
  for (int times = 1; times <= b + 1; ++times) {
    // * Add the calculated number of 'R's
    s.append(length_of_red, 'R');

    // * Distribute the extra 'R's
    if (extra_red > 0) {
      s += 'R';
      extra_red--;
    }

    // * Add 'B' except for the last segment
    if (times != b + 1)
      s += 'B';
  }
  
  return s;
}

// * Pigeon hole principle
// * Time Complexity (TC): O(100)
// * Space Complexity (SC): O(100)
int main(void) {
  ll t;
  cin >> t;
  
  while (t--) {
    string ans = solve();
    cout << ans << "\n";
  }
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 16-red-versus-blue.cpp -o output && ./output

// * testcases
/*
3
7 4 3
6 5 1
19 13 6

*/

// * Output
/*
RBRBRBR
RRRBRR
RRBRRBRRBRRBRRBRRBR
*/