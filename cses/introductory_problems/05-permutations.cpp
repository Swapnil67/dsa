/*
 * Permutations
 * 
 * https://cses.fi/problemset/task/1070
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Odd & Even

void solve() {
  ll n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  else if (n <= 3) {
    cout << "NO SOLUTION" << endl;
    return;
  }
  
  // * soln
  vector<ll> even, odd;
  for (int i = 1; i <= n; ++i) {
    if (i & 1) {
      odd.push_back(i);
    } else {
      even.push_back(i);
    }
  }

  vector<ll> p = even;
  p.insert(p.end(), begin(odd), end(odd));

  for (int i = 0; i < n; ++i) {
    cout << p[i] << " ";
  }
  cout << endl;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) (Input string)
int main(void) {
  solve();
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 05-permutations.cpp -o output && ./output

/*
Input:
4
5

Output:
2 4 1 3 
2 4 1 3 5 
*/