/*
 * Two Sets
 * 
 * https://cses.fi/problemset/task/1092
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation
/*
* total_sum = even -> maybe we can split
* total_sum = odd -> split not possible
*
* Keep pushing the next element to array which has smaller total sum
* n = 8
* A = {8 5 3 2}
* B = {7 6 4 1}
*/

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int main(void) {
  ll n;
  cin >> n;

  ll total_sum = n * (n + 1) / 2;
  // * If odd split not possible
  if (total_sum & 1) { 
    cout << "NO" << "\n";
    return 0;
  }

  // * Do split
  vector<ll> a, b;
  ll A = 0, B = 0;
  for (int i = n; i >= 1; --i) {
    if (A > B) {
      b.push_back(i);
      B += i;
    } else {
      a.push_back(i);
      A += i;
    }
  }

  cout << "YES" << "\n";
  cout << a.size() << "\n";
  for (auto &x : a)
    cout << x << " ";
  cout << "\n";
  cout << b.size() << "\n";
  for (auto &x : b)
    cout << x << " ";
  cout << "\n";

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 08-two-sets.cpp -o output && ./output

/*
Input:
7

6

Output:
YES
4
1 2 4 7
3
3 5 6

NO
*/