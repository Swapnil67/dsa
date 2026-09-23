/*
 * AtCoder 
 * Frog B
 * 
 * There is a frog who is initially on Stone 1. 
 * He will repeat the following action some number of times to reach Stone N:
 * - If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K.
 * Here, a cost of ∣hi − hj∣ is incurred, where j is the stone to land on.
 * 
 * Find the minimum possible total cost incurred before the frog reaches Stone N
 * 
 * Example 1    :
 * Input        : a = [10 30 40 50 20], k = 3
 * Output       : 30
 * Explanation  : If we follow the path 1 → 2 → 5, the total cost incurred would be ∣10−30∣+∣30−20∣=30
 * 
 * Example 2    :
 * Input        : a = [10 20 10], k = 1
 * Output       : 20
 * Explanation  : If we follow the path 1 → 2 → 3, the total cost incurred would be ∣10−20∣+∣20−10∣=20.
 * 
 * Example 3    :
 * Input        : a = [10 10], k = 100
 * Output       : 0
 * Explanation  : If we follow the path 1 → 2, the total cost incurred would be ∣10−10∣=0.
 * 
 * Example 3    :
 * Input        : a = [40 10 20 70 80 10 20 70 80 60], k = 4
 * Output       : 40
 * Explanation  : If we follow the path 1 → 4 → 8 → 10, the total cost incurred would be ∣40−70∣+∣70−70∣+∣70−60∣=40.
 * 
 * https://atcoder.jp/contests/dp/tasks/dp_b
 * https://drive.google.com/file/d/1KKEwaoTZxjRbHNqBMSiK1NsYdN_4ZZ7e/view
 * https://docs.google.com/document/d/1k5Nbylqu-yXSlNpeVStlbTrfil75Wnq3VwaVVRoQMy0/edit?tab=t.0
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

#include<vector>
#include<iostream>

using namespace std;
typedef long long ll;
const ll MAXN = 1e18;

void solve() {
  ll n, k;
  cin >> n;
  cin >> k;
  vector<ll> a(n + 1, 0); 
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  
  vector<ll> dp(n + 1, 0); 

  dp[1] = 0;
  dp[2] = abs(a[1] - a[2]);
  ll i = 3;
  while (i <= n) {
    ll minCost = MAXN;
    ll j = 1;
    while (j <= k && i - j >= 1) {
      minCost = min(minCost, abs(a[i] - a[i - j]) + dp[i - j]);
      j++;
    }
    dp[i] = minCost;
    i++;
  }

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
// * g++ --std=c++20 02-frog-B.cpp -o output && ./output

/*
* testcase 1
5 3
10 30 40 50 20

* testcase 2
3 1
10 20 10

* testcase 3
2 100
10 10

* testcase 4
10 4
40 10 20 70 80 10 20 70 80 60
*/