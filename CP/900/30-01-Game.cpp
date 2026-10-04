/*
 * 01 Game
 * 
 * Description:
 * Alice and Bob are playing a game with a binary string `s` consisting only of '0' and '1'. 
 * They make alternating moves, with Alice going first. During each move, the current player 
 * must choose two different adjacent characters of the string (i.e., "01" or "10") and delete them. 
 * The player who cannot make a move loses the game. Determine who wins if both players play optimally.
 * 
 * Constraints:
 * 1 <= t <= 1000 (number of test cases)
 * 1 <= |s| <= 100 (length of the string)
 * The string `s` consists only of characters '0' and '1'.
 * 
 * Example 1    :
 * Input        : s = "01"
 * Output       : DA
 * Explanation  : Alice deletes "01", leaving an empty string. Bob has no moves left and loses. 
 *                "DA" means Alice wins.
 * 
 * Example 2    :
 * Input        : s = "1111"
 * Output       : NET
 * Explanation  : There are no different adjacent characters, so Alice cannot make a single move. 
 *                She loses immediately. "NET" means Bob wins.
 *
 * https://codeforces.com/problemset/problem/1373/B
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation
// * Count zeros and ones; determine minimum for moves.

bool solve() {
  string s;
  cin >> s;
  
  int count_of_zeros = 0, count_of_ones = 0;
  for (auto &c: s) {
    if (c == '0') {
      count_of_zeros++;
    } else {
      count_of_ones++;
    }
  }
  
  // * Calculate the number of operations possible
  int min_moves = min(count_of_zeros, count_of_ones);
  
  // * If odd moves then alice wins, else bob wins
  return (min_moves&1);
}


// * Time Complexity (TC): O(n) = O(100)
// * Space Complexity (SC): O(n) = O(100)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    bool alice_win = solve();
    if (alice_win) {
      cout << "DA" << "\n"; 
    } else {
      cout << "NET" << "\n";
    }
  }
  
  return 0;
}


// * Run the code
// * g++ --std=c++20 30-01-Game.cpp -o output && ./output

// * testcases
/*
3
01
1111
0011

*/

// * Output
/*
DA
NET
NET
*/
