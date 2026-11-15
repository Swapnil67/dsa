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
const ll MAXN = 1e18;

// * Macros
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

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
  ll n, k;
  cin >> n >> k;
  VEC(h, n, ll); READ_VEC(h);
  
  // * dp[i] = min cost to reach index 'i'
  VEC(dp, n, ll);
  dp[0] = 0;
  for (int j = 1; j < n; ++j) {
    ll min_cost = MAXN;
    int i = 1;
    while (i <= k && j - i >= 0) { // * check prev 'k' steps
      min_cost = min(min_cost, abs(h[j] - h[j - i]) + dp[j - i]);
      i++;
    } 
    dp[j] = min_cost;
  }

  cout << dp[n - 1] << " " << endl;
}

void solvePath() {
  ll n, k;
  cin >> n >> k;
  VEC(h, n, ll); READ_VEC(h);
  
  // * dp[i] = min cost to reach index 'i'
  vector<ll> path(n); 
  VEC(dp, n, ll);
  dp[0] = 0;
  for (int j = 1; j < n; ++j) {
    ll min_cost = MAXN;
    int i = 1;
    while (i <= k && j - i >= 0) { // * check prev 'k' steps
      ll cur_cost = abs(h[j] - h[j - i]) + dp[j - i];
      if (min_cost > cur_cost) {
        path[j] = (j - i);
        min_cost = cur_cost;
      }
      i++;
    } 
    dp[j] = min_cost;
  }

  printArr(path);
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  solve();
  // * To see the optimal path run the following function and enter input again
  // solvePath(); 
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

