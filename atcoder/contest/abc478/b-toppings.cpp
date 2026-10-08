/*
 * B - Toppings
 * 
 * https://atcoder.jp/contests/abc478/tasks/abc478_b
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// * TIME COMPLEXITY O(N^3)
// * SPACE COMPLEXITY O(1)
void solution() {
  ll n, v;
  cin >> n >> v;

  vector<ll> w(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  ll max_happiness = 0;
  for (int i = 1; i <= n - 2; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      for (int k = j + 1; k <= n; ++k) {
        if (i + j + k <= v) {
          max_happiness = max(max_happiness, w[i - 1] + w[j - 1] + w[k - 1]);
        }
      }
    }
  }
  
  cout << max_happiness << "\n";
}

int main(void) {
  solution();
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 b-toppings.cpp -o output && ./output

// * testcases
/*
5 9
31 41 59 26 53

10 16
102228 448944 131224 326172 500169 670309 976672 579051 974511 773940
*/

// * output
/*
143

2095925
*/