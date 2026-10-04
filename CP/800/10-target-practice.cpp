/*
 * Target Practice
 * 
 * Description:
 * A 10x10 target consists of five concentric square rings. The outermost ring 
 * awards 1 point, the next ring inward awards 2 points, the third awards 3 points, 
 * the fourth awards 4 points, and the innermost 2x2 square awards 5 points. 
 * Given a 10x10 grid representing where arrows landed ('X' represents an arrow hit, 
 * and '.' represents an empty cell), calculate the total points scored.
 * 
 * Constraints:
 * - The grid size is fixed at 10 rows and 10 columns.
 * - Each cell contains either 'X' or '.'.
 * - 1 <= t <= 1000 (number of test cases).
 * 
 * Example 1    :
 * Input        : grid = [
 *                  "X.........",
 *                  "..........",
 *                  ".......X..",
 *                  ".....X....",
 *                  "......X...",
 *                  "..........",
 *                  ".........X",
 *                  "..X.......",
 *                  "..........",
 *                  ".........X"
 *                ]
 * Output       : 17
 * Explanation  : The arrow at (0, 0) is worth 1 point.
 *                The arrow at (2, 7) is worth 3 points.
 *                The arrow at (3, 5) is worth 4 points.
 *                The arrow at (4, 6) is worth 4 points.
 *                The arrow at (6, 9) is worth 1 point.
 *                The arrow at (7, 2) is worth 3 points.
 *                The arrow at (9, 9) is worth 1 point.
 *                Total points = 1 + 3 + 4 + 4 + 1 + 3 + 1 = 17.
 * 
 * Example 2    :
 * Input        : grid = [
 *                  "..........",
 *                  "..........",
 *                  "..........",
 *                  "..........",
 *                  "....X.....",
 *                  ".....X....",
 *                  "..........",
 *                  "..........",
 *                  "..........",
 *                  ".........."
 *                ]
 * Output       : 10
 * Explanation  : The arrows at (4, 4) and (5, 5) both fall into the innermost 5th ring, 
 *                yielding 5 + 5 = 10 points.
 *
 * Link         : https://codeforces.com/problemset/problem/1873/C
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

int score[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,2,2,2,2,2,1},
    {1,2,3,3,3,3,3,3,2,1},
    {1,2,3,4,4,4,4,3,2,1},
    {1,2,3,4,5,5,4,3,2,1},
    {1,2,3,4,5,5,4,3,2,1},
    {1,2,3,4,4,4,4,3,2,1},
    {1,2,3,3,3,3,3,3,2,1},
    {1,2,2,2,2,2,2,2,2,1},
    {1,1,1,1,1,1,1,1,1,1},
};

// * TC = O(t)
// * SC = O(100)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    char a[10][10];
    for (int i = 0; i < 10; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < 10; ++j) {
        a[i][j] = s[j];
      }
    }

    int total_score = 0;
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (a[i][j] == 'X')
          total_score += score[i][j];
      }
    }

    cout << total_score << endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-target-practice.cpp -o output && ./output

// * testcase

/*
4
X.........
..........
.......X..
.....X....
......X...
..........
.........X
..X.......
..........
.........X
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
....X.....
..........
..........
..........
..........
..........
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX

*/


// * output
/*
17
0
5
220
*/

