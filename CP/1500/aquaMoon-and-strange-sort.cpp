/*
* A. AquaMoon and Strange Sort 
*
* https://codeforces.com/problemset/problem/1545/A
*/

#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  
  // * cnt[value][0] -> count of this value at even indices
  // * cnt[value][1] -> count of this value at odd indices
  map<int, vector<int>> cnt;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    
    // * If value not yet in map, initialize counts
    if (!cnt.count(a[i]))
      cnt[a[i]] = {0, 0};

    // * Increase count based on index parity
    cnt[a[i]][i % 2]++;
  }

  // * Create a sorted copy of the array
  vector<int> b = a;
  sort(begin(b), end(b));
  
  // * Subtract counts based on where elements appear
  // * in the sorted array
  for (int i = 0; i < n; ++i) {
    cnt[b[i]][i % 2]--;
  }
  
  // * Check if all counts return to zero
  // * If not, arrangement is impossible
  bool ok = true;
  for (auto &p: cnt) {
    if (p.second[0] != 0 || p.second[1] != 0) {
      ok = false;
      break;
    }
  }
  
  if (ok)
    cout << "YES" << '\n';
  else 
    cout << "NO" << '\n';
}

int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll t;
  cin >> t;
  while (t--)
    solve();
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 aquaMoon-and-strange-sort.cpp -o output && ./output

// * Testcase
/*
3 3 3
1 2 3
1 2 1
1 3 2
2 3 4
1 2
1 3
2 3

*/

// * Output
/*
9 18 17
*/