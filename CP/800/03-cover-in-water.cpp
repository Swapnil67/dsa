/*
 * Cover in Water (Codeforces 1900A)
 * 
 * Description
 * Filip has a row of cells, some of which are empty ('.') and some are blocked ('#'). 
 * He wants to fill all empty cells with water using two available actions:
 * 1. Place water in an empty cell.
 * 2. Remove water from a cell and place it in any other empty cell.
 * 
 * Additionally, if an empty cell has water in both its left and right adjacent cells, 
 * it automatically fills up with water. Find the minimum number of times he needs 
 * to perform action 1 to fill all empty cells.
 * 
 * Example 1    :
 * Input        : n = 3, s = "..."
 * Output       : 2
 * Explanation  : You can place water in the 1st and 3rd cells using action 1. 
 *                The 2nd cell will automatically fill because its neighbors have water.
 * 
 * Example 2    :
 * Input        : n = 7, s = "##....#"
 * Output       : 2
 * Explanation  : There are 4 consecutive empty cells "....". You can place water in the 
 *                3rd and 5th cells. The 4th cell automatically fills. Then you can use 
 *                action 2 to move water from the 4th cell to the 6th cell, prompting 
 *                the 4th cell to automatically refill itself.
 * 
 * Example 3    :
 * Input        : n = 7, s = ".#.#.#."
 * Output       : 4
 * Explanation  : There are no 3 consecutive empty cells, so no cell can be filled 
 *                automatically. You must place water manually in all 4 empty cells.
 * 
 * Example 4    :
 * Input        : n = 4, s = "####"
 * Output       : 0
 * Explanation  : There are no empty cells to fill.
 * 
 * Example 5    :
 * Input        : n = 3, s = "#.#"
 * Output       : 1
 * Explanation  : There is only one empty cell, so you only need to place water there once.
 * 
 */

#include <vector>
#include <iostream>

using namespace std;

// ! Observation
// * If I can have 3 consecutive empty cells then I can fill all the remaining empty cells.

void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;

  bool continuous_three_empty_cells = false;
  long long empty_cells_count = 0;
  for (int i = 0; i < n; ++i) {
    if (i - 2 >= 0 && s[i] == '.') {
      if (s[i - 1] == '.' && s[i - 2] == '.') {
        continuous_three_empty_cells = true;
        break;
      }
    }
    if (s[i] == '.')
      empty_cells_count += 1;
  }

  if (continuous_three_empty_cells)
    cout << 2 << endl;
  else
    cout << empty_cells_count << endl;
}

int main() {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}

 
// * Run the code
// * g++ --std=c++20 03-cover-in-water.cpp -o output && ./output

// * Testcases
/*
6
3
...
7
##....#
7
..#.#..
4
####
10
#...#..#.#
5
.#...
*/
