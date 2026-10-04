/*
 * Number Spiral
 * 
 * https://cses.fi/problemset/task/1071
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation
/*
* Here we have 2 cases
*
* Case 1: y >= x (Horizontal)
*      A: y is even => y^2 + (x-1)
*      B: y is odd => (y-1)^2 + x
*
* Case 2: x > y (Vertical)
*      A: x is even => (x-1)^2 + y
*      B: x is odd => x^2 + (y-1)
*/

// * TIME COMPLEXITY O(1)
// * SPACE COMPLEXITY O(1)
int main(void) {
  ll t;
  cin >> t;
  while (t--) {
    ll y, x;
    cin >> y >> x;
    if (y >= x) {
      if (y & 1) {
        // * (y-1)^2 + x
        cout << ((y - 1) * (y - 1)) + x << endl;
      } else {
        // * y^2 + (x-1)
        cout << (y * y) - (x - 1) << endl;
      }
    } else {
      if (x & 1) {
        // * x^2 + (y-1)
        cout << (x * x) - (y - 1) << endl;
      } else {
        // * (x-1)^2 + y
        cout << ((x - 1) * (x - 1)) + y << endl;
      }
    }
  }
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 06-number-spiral.cpp -o output && ./output

/*
Input:
3
2 3
1 1
4 2

Output:
2 4 1 3 
2 4 1 3 5 
*/