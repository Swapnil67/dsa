/*
 * Increasing Array
 * 
 * https://cses.fi/problemset/task/1094
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) (Input string)
int main(void) {
  // * testcases

  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  // * soln
  ll moves = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) {
      int ops = (a[i - 1] - a[i]);
      a[i] += ops;
      moves += ops;
    }
  }

  cout << moves << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 04-increasing-array.cpp -o output && ./output

/*
Input:
5
3 2 5 1 7

10
6 10 4 10 2 8 9 2 7 7


Output:
5
*/

// * 6 + 8 + 2 + 1 + 8 + 3 + 3 = 