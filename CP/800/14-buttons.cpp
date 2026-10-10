/*
 * Buttons
 * 
 * Although Anna and Katie are still friends, they have a lot of disagreements. 
 * Today, they found a device with $a + b + c$ buttons.
 * 
 * The buttons are configured as follows:
 * - $a$ buttons can only be pressed by Anna.
 * - $b$ buttons can only be pressed by Katie.
 * - $c$ buttons can be pressed by either of them.
 * 
 * Anna and Katie decide to play a game. They take turns pressing buttons, with Anna going first:
 * - On each turn, a player must choose and press an unpressed button that they are allowed to press.
 * - Each button can be pressed at most once during the game.
 * - The player who cannot make a move on their turn loses the game.
 * 
 * Assuming both Anna and Katie play optimally, determine who will win the game.
 * Return "First" if Anna wins, or "Second" if Katie wins.
 * 
 * Constraints:
 * 1 <= t <= 10^4 (number of test cases)
 * 1 <= a, b, c <= 10^9
 * 
 * Example 1    :
 * Input        : a = 1, b = 1, c = 1
 * Output       : "First"
 * Explanation  : On the first turn, Anna presses the shared button ($c$). Now no shared buttons remain, and each player has 1 button remaining that only they can press. Katie must press her exclusive button, then Anna presses hers. Katie cannot make a turn and loses, so Anna ("First") wins.
 * 
 * Example 2    :
 * Input        : a = 1, b = 2, c = 1
 * Output       : "Second"
 * Explanation  : After both players play optimally, Anna runs out of valid moves first, so Katie ("Second") wins.
 *
 * https://codeforces.com/problemset/problem/1858/A
*/

#include <iostream>
using namespace std;

// * Time Complexity (TC): O(1)
// * Space Complexity (SC): O(1)
int main()
{
  int t; // * Number of test cases
  cin >> t;
  while (t--)
  {
    long long a, b, c; // * a: buttons only Anna can press, b: buttons only Katie can press, c: buttons either can press
    cin >> a >> b >> c;

    // * Check if the number of buttons that can be pressed by either is odd
    if (c % 2 == 1) // * odd
    {
      // * If c is odd, the player with more exclusive buttons will win
      if (b > a)                  // * Katie has more exclusive buttons
        cout << "Second" << endl; // * Katie wins
      else
        cout << "First" << endl; // * Anna wins
    }
    else // * even
    {
      // * If c is even, the player with more exclusive buttons will win
      if (a > b)                 // * Anna has more exclusive buttons
        cout << "First" << endl; // * Anna wins
      else
        cout << "Second" << endl; // * Katie wins
    }
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 14-buttons.cpp -o output && ./output

// * testcase

/*
5
1 1 1
9 3 3
1 2 3
6 6 9
2 2 8

*/

// * output
/*
First
First
Second
First
Second
*/

