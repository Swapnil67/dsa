/*
 * Bad Boy (Codeforces 1537B)
 * 
 * Description:
 * Anton is trapped in a grid room of size n x m. He is currently at cell (i, j). 
 * There are two hidden yo-yos in the grid room. Anton wants to visit both yo-yos 
 * (in any order) and then return to his initial cell (i, j). 
 * You need to find the coordinates of the two yo-yos, (x1, y1) and (x2, y2), 
 * such that the total Manhattan distance Anton has to travel is maximized. 
 * If there are multiple answers, you can output any of them.
 * 
 * Constraints:
 * 1 <= t <= 10^4 (number of test cases)
 * 1 <= n, m <= 10^9
 * 1 <= i <= n
 * 1 <= j <= m
 * 
 * Example 1 :
 * Input : n = 2, m = 3, i = 1, j = 1
 * Output : 1 1 2 3
 * Explanation : Placing the yo-yos at opposite extreme corners (1, 1) and (2, 3) maximizes the total Manhattan distance Anton travels.
 * 
 * Example 2 :
 * Input : n = 1, m = 1, i = 1, j = 1
 * Output : 1 1 1 1
 * Explanation : The grid only has one cell, so both yo-yos must be placed at (1, 1).
 * 
 * https://codeforces.com/problemset/problem/1537/B
 */

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * TC = O(1)
// * SC = O(1)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    // * Grid size
    ll n, m;
    cin >> n >> m;
    
    // * Anton pos
    ll x, y;
    cin >> x >> y;
    
    // * Positions of two yo-yos
    cout << 1 << " " << 1 << " " << n << " " << m << "\n";
  }
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 25-bad-boy.cpp -o output && ./output

// * testcases
/*
7
2 3 1 1
4 4 1 2
3 5 2 2
5 1 2 1
3 1 3 1
1 1 1 1
1000000000 1000000000 1000000000 50

*/

// * Output
/*
1 2 2 3
4 1 4 4
3 1 1 5
5 1 1 1
1 1 2 1
1 1 1 1
50 1 1 1000000000
*/
