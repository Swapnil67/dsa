/*
 * B. JoJo's Incredible Adventures
 *
 * https://codeforces.com/problemset/problem/1820/B
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

// * Time Complexity (TC): O(n)
// * Space Complexity (SC): O(1)
void solve() {
  // * take input
  string s;
  cin >> s;
  
  ll n = s.size();
  ll maxi = 0, cnt = 0;
  
  // Iterate over the string to find the longest sequence of '1's
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1')
      cnt++;
    else
      cnt = 0;
    
    maxi = max(maxi, cnt);
  }
  
  
  // If the entire string is '1's, the area is n*n
  if (maxi == n) {
    cout << n * n << '\n';
    return;
  }
  
  // Check if the string starts and ends with '1'
  if (s[0] == '1' && s[n-1] == '1') {
    cnt = 0;
    int i = 0;
    while (i < n && s[i] == '1') { // Count '1's from the start
      i++;
      cnt++;
    }
    
    int j = n - 1;
    while (j > i && s[j] == '1') { // Count '1's from the end
      j--;
      cnt++;
    }
    
    maxi = max(maxi, cnt); // Update the maximum length
  }
  
  maxi++; // Increment the maximum length by 
  ll temp = (maxi + 1) / 2; // Calculate half of the incremented length
  cout << (temp) * (maxi / 2) << endl; // Calculate and print the maximum area
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}