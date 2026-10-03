/*
 * Odd Grasshopper
 * 
 * Description  : A grasshopper starts at an initial coordinate x0 on a 1D numeric axis. 
 *                In the i-th minute (for i = 1, 2, ..., n), the grasshopper makes a 
 *                jump of distance exactly i. The direction depends on the parity of its 
 *                current coordinate before the jump:
 *                - If the current coordinate is EVEN, it jumps to the LEFT (subtracts i).
 *                - If the current coordinate is ODD, it jumps to the RIGHT (adds i).
 *                Determine the grasshopper's final coordinate after exactly n jumps.
 * 
 * Constraints  : 
 *                - 1 <= t <= 10^4 (Number of test cases)
 *                - -10^14 <= x0 <= 10^14
 *                - 0 <= n <= 10^14
 * 
 * Example 1    :
 * Input        : x0 = 0, n = 1
 * Output       : -1
 * Explanation  : At minute 1, the grasshopper is at 0 (even). It jumps left by 1. 
 *                Final position: 0 - 1 = -1.
 * 
 * Example 2    :
 * Input        : x0 = 0, n = 2
 * Output       : 1
 * Explanation  : At minute 1, it is at 0 (even) -> jumps left by 1 to -1. 
 *                At minute 2, it is at -1 (odd) -> jumps right by 2. 
 *                Final position: -1 + 2 = 1.
 * 
 * Example 3    :
 * Input        : x0 = 10, n = 10
 * Output       : 11
 * Explanation  : After tracking the alternating odd/even jumps up to 10 minutes, 
 *                the coordinate lands at 11.
 * 
 * Example 4    :
 * Input        : x0 = 10, n = 0
 * Output       : 10
 * Explanation  : With 0 jumps, the grasshopper stays at its initial position.
 *
 * https://codeforces.com/problemset/problem/1607/B
*/

// ! Observation
/*
* jumps -  0 1  2 3 4  5  6 7 8  9 10 11 12 13 14 15 16 17 18 19 20
* pos   -  0 -1 1 4 0 -5  1 8 0 -9 1  12 0 -13 1  16 0 -17 1  20 0

* We can make following observations
* j % 4 == 0, pos = 0
* j % 4 == 1, pos = -n
* j % 4 == 2, pos = 1
* j % 4 == 3, pos = n + 1

* The above assumptions will only work if frog starts from postion 0.
* but in problem we are given a x0 postion at which frog starts.

* So if x0 is even we can say that our above assumptions are still valid its just that 
* our final position is shifted by x0.
* final answer = x0 + answer

* Now if x0 is odd
* 
* final answer = x0 - answer
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * Parity & Modulo
// * TC = O(t)
// * SC = O(1)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    ll start, jumps;
    cin >> start >> jumps;
    
    ll final_pos;
    if (jumps % 4 == 0) {
      final_pos = 0;
    } else if (jumps % 4 == 1) {
      final_pos = -jumps;
    } else if (jumps % 4 == 2) {
      final_pos = 1;
    } else if (jumps % 4 == 3) {
      final_pos = jumps + 1;
    }
    
    if (start & 1) { // * odd
      final_pos = start - final_pos;
    } else {
      final_pos = start + final_pos;
    }
    
    cout << final_pos << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 19-odd-grasshopper.cpp -o output && ./output

// * testcases
/*
9
0 1
0 2
10 10
10 99
177 13
10000000000 987654321
-433494437 87178291199
1 0
-1 1

*/

// * Output
/*
-1
1
11
110
190
9012345679
-87611785637
1
0
*/