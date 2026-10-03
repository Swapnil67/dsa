/*
 * Forked!
 * 
 * Description
 * On an infinite chessboard, a custom knight has an attack movement defined by two 
 * integers a and b (where a != b or a == b). This means a knight can move from its 
 * position by jumping a units in one direction and b units in a perpendicular direction. 
 * Thus, from any position, there are up to 8 possible relative attack positions: 
 * (±a, ±b) and (±b, ±a).
 * 
 * Given the coordinates of the King (xk, yk) and the Queen (xq, yq), find the number of 
 * distinct positions on the board from which the knight can simultaneously attack 
 * both the King and the Queen.
 * 
 * Constraints:
 * 1 <= a, b <= 10^8
 * 1 <= xk, yk, xq, yq <= 10^8
 * The King and the Queen occupy different cells.
 * 
 * Example 1    :
 * Input        : a = 2, b = 1, xk = 1, yk = 1, xq = 4, yq = 4
 * Output       : 2
 * Explanation  : The knight can be placed at (2, 3) or (3, 2). From either position, 
 *                it can attack the King at (1, 1) and the Queen at (4, 4) simultaneously.
 * 
 * Example 2    :
 * Input        : a = 1, b = 1, xk = 1, yk = 1, xq = 2, yq = 2
 * Output       : 2
 * Explanation  : Since a = b, there are fewer distinct attack offsets. The knight can be 
 *                placed at (1, 2) or (2, 1) to attack both pieces.
 * 
 * Example 3    :
 * Input        : a = 2, b = 1, xk = 1, yk = 1, xq = 1, yq = 8
 * Output       : 0
 * Explanation  : The King and Queen are too far apart. There is no position where a single 
 *                knight can reach both in one move.
 * 
 * https://codeforces.com/problemset/problem/1904/A
*/


#include <set>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation

// * Since our inputs are very big we cannot do O(n^2) or O(n^3) solutions
// * We need to do either O(logn) or O(1) soln.

// * So we start thinking from the king and queen perspective 
// * We find all the possible positions from where king & queen can be attacked, 
// * And then find the points which are intersecting in both list.

int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;

    ll kr, kc;
    cin >> kr >> kc;
    
    ll qr, qc;
    cin >> qr >> qc;
    
    set<pair<ll, ll>> king_hits;
    set<pair<ll, ll>> queen_hits;

    // * All 8 directions from a cell.
    vector<vector<ll>> dirs = {{a, b}, {b, a}, {-a, -b}, {-b, -a}, {a, -b}, {b, -a}, {-a, b}, {-b, a}};
    for (auto &dir: dirs) {
        king_hits.insert({dir[0]+kr, dir[1]+kc});
        queen_hits.insert({dir[0]+qr, dir[1]+qc});
    }
    
    // * For debug
    // for (auto &it: king_hits) {
    //     cout << it.first << "," << it.second << "\n";
    // }
    
    ll ans = 0;
    for (auto &pos: king_hits) {
      if (queen_hits.count(pos))
        ans++;
    }
    
    cout << ans << "\n";
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-forked.cpp -o output && ./output

// * testcase

/*
4
2 1
0 0
3 3
1 1
3 1
1 3
4 4
0 0
8 0
4 2
1 4
3 4

*/


// * output
/*
2
1
2
0
*/

