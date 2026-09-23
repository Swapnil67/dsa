/*
 * AtCoder 
 * Frog A
 * 
 * There is a frog who is initially on Stone 1. 
 * He will repeat the following action some number of times to reach Stone N:
 * - If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. 
 * Here, a cost of ∣hi − hj∣ is incurred, where j is the stone to land on.
 * 
 * Find the minimum possible total cost incurred before the frog reaches Stone N
 * 
 * Example 1    :
 * Input        : a = [10 30 40 20]
 * Output       : 30
 * Explanation  : If we follow the path 1 → 2 → 4, the total cost incurred would be  ∣10−30∣+∣30−20∣=30.
 * 
 * Example 2    :
 * Input        : a = [10 10]
 * Output       : 0
 * Explanation  : If we follow the path 1 → 2, the total cost incurred would be  ∣10−10∣=0.
 * 
 * Example 3    :
 * Input        : a = [30 10 60 10 60 50]
 * Output       : 40
 * Explanation  : If we follow the path 1 → 3 → 5 → 6, the total cost incurred would be ∣30−60∣+∣60−60∣+∣60−50∣=40.
 * 
 * https://atcoder.jp/contests/dp/tasks/dp_a
 * https://drive.google.com/file/d/1KKEwaoTZxjRbHNqBMSiK1NsYdN_4ZZ7e/view
 * https://docs.google.com/document/d/1k5Nbylqu-yXSlNpeVStlbTrfil75Wnq3VwaVVRoQMy0/edit?tab=t.0
 * 
*/

#include<vector>
#include<iostream>

using namespace std;
typedef long long ll;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n + 1, 0); 
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  
  vector<ll> dp(n + 1, 0); 
  dp[1] = 0;
  dp[2] = abs(a[1] - a[2]);
  ll i = 3;
  while (i <= n) {
    ll val1 = abs(a[i] - a[i - 2]) + dp[i - 2];
    ll val2 = abs(a[i] - a[i - 1]) + dp[i - 1];
    dp[i] = min(val1, val2);
    i++;
  }

  // printArr(dp); // * for debug
  cout << dp[n] << " " << endl;
}

int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  solve();
  return 0;
}

// * Run the code
// * g++ --std=c++20 01-frog-A.cpp -o output && ./output

/*
* testcase 1
4
10 30 40 20

* testcase 2
2
10 10

* testcase 3
6
30 10 60 10 60 50
*/