#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  vector<ll> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  
  for (int i = 0; i < n; ++i) {
    int ans;
    if (i == 0 || i == n - 1) {
      ans = x[n - 1] - x[0];
    }
    else {
      // * Case1: 'i' go to the leftmost(0) and left neighbour goes to last person(n-1)
      // * 0              i             n-1
      // * ---------------------------------
      // * p           p  z  p            p
      // * zombie will go to left and infest the first left neighbor and the neighbor will go to right till n-1.
      int one = max(x[i] - x[0], x[n - 1] - x[i - 1]);
      
      // * Case2: 'i + 1' go to the leftmost(0) and 'i' goes to last person(n-1)
      // * 0             i                n-1
      // * ---------------------------------
      // * p          p  z  p              p
      // * zombie will go to right and infest the first right neighbor and the neighbor will go to left till 0.
      int two = max(x[i + 1] - x[0], x[n - 1] - x[i]);
      // * Take min of two path
      ans = min(one, two);
    }
    cout << ans / 2 << '\n'; // * since both are moving towards each other.
  }
  
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 d-wannabe-zombie.cpp -o output && ./output

// * testcase
/*
5
2 4 10 14 18

*/

/*
8
7
6
6
8
*/
