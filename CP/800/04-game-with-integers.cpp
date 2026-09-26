/*
 * Game with Integers (Codeforces 1899A)
 * 
 * Description
 * Vanya and Vova are playing a game with an integer n. On each turn, a player 
 * can either add 1 to the current integer or subtract 1 from it. The players take 
 * turns, with Vanya going first. If after Vanya's move the integer is divisible 
 * by 3, Vanya immediately wins. If 10 moves pass and Vanya has not won, Vova wins. 
 * Assuming both players play optimally, determine who wins the game.
 * 
 * Example 1    :
 * Input        : n = 1
 * Output       : "First"
 * Explanation  : Vanya can subtract 1 on the first move to make n = 0, which 
 *                is divisible by 3, winning the game immediately.
 * 
 * Example 2    :
 * Input        : n = 3
 * Output       : "Second"
 * Explanation  : Since n is already divisible by 3, any move Vanya makes (to 2 or 4) 
 *                will not be divisible by 3. Vova can then always adjust it back to a 
 *                multiple of 3 on his turn, preventing Vanya from winning within 10 moves.
 * 
 * Example 3    :
 * Input        : n = 5
 * Output       : "First"
 * Explanation  : Vanya can add 1 on the first move to reach 6, which is 
 *                divisible by 3, winning the game immediately.
 * 
 * Example 4    :
 * Input        : n = 100
 * Output       : "First"
 * Explanation  : 100 leaves a remainder of 1 when divided by 3, so Vanya can 
 *                subtract 1 to make it 99, winning on the first move.
 * 
 * Example 5    :
 * Input        : n = 999
 * Output       : "Second"
 * Explanation  : 999 is divisible by 3, so Vova can counter every move Vanya makes 
 *                to keep Vanya from ever landing on a multiple of 3.
 * 
 * Example 6    :
 * Input        : n = 1000
 * Output       : "First"
 * Explanation  : 1000 leaves a remainder of 1 when divided by 3, so Vanya can 
 *                subtract 1 to reach 999 and win on turn 1.
 * 
 * https://codeforces.com/problemset/problem/1899/A
 */

#include <vector>
#include <iostream>

using namespace std;

// ! Observation

// * n % 3 = 0  => [3, 6, 9, 12, 15]  (If vanya do +1/-1 to any of these no. vova will make counter move)
// * n % 3 = 1  => [4, 7, 10, 13, 16] (If vanya -1 from any of these no. he wins)
// * n % 3 = 2  => [3, 6, 9, 12, 15]  (If vanya +1 from any of these no. he wins)

int main() {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 3 == 0) // * not possible
      cout << "Second" << endl;
    else // * always possible
      cout << "First" << endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-cover-in-water.cpp -o output && ./output

// * Testcases
/*
6
1
3
5
100
999
1000
*/
