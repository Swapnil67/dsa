/*
* Very Easy Task
*
* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

bool canMakeCopies(ll total_copies_required, ll m1_time, ll m2_time, ll total_sec) {
  // * create one copy by machince which takes min time
  total_copies_required -= 1; // * Decrease required no. of copies by 1
  
  // * Remaining time after first copy
  total_sec -= min(m1_time, m2_time);
  if (total_sec < 0)
    return false; // * Not enough time for even the first copy
  
  // * No. of copies machine A can create in given total_sec.
  ll copies_from_machine_A = total_sec / m1_time;
  // * No. of copies machine B can create in given total_sec.
  ll copies_from_machine_B = total_sec / m2_time;
  
  // * If they both can create requried no. of copies then return true.
  return (copies_from_machine_A + copies_from_machine_B) >= total_copies_required;
}

// * Binary Search on Answers
// * Time Complexity:  O(max_time)
// * Space Complexity: O(1)
void solve() {
  // * Take input
  ll n, x, y;
  cin >> n >> x >> y;
  
  ll l = 0, r = 1e10;
  ll ans = -1;
  while (l <= r) {
    ll m = l + (r - l) / 2;
    if (canMakeCopies(n, x, y, m)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  
  cout << ans << '\n';
}

int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  solve();
  
  return 0;
}



// * Run the code
// * g++ --std=c++20 very-easy-task.cpp -o output && ./output

// * testcase

/*
4 1 1

5 1 2


*/


// * output
/*
3

4
*/

