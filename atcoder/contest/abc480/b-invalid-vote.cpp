/*
 * Invalid Vote
 * Description  : N candidates with unique names S_i and M ballots with strings T_j are given. 
 *                Votes are awarded if T_j matches a candidate's name exactly, or if changing 
 *                exactly 1 character of T_j yields exactly one candidate's name. Otherwise, 
 *                the vote is invalid. Find the vote count for each candidate.
 * Constraints  : 1 <= N, M <= 100, 1 <= |S_i|, |T_j| <= 10.
 * 
 * https://atcoder.jp/contests/abc480/tasks/abc480_b
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
void solve() {
  ll n, m;
  cin >> n >> m;

  vector<string> s(n);
  for (int i = 0; i < n; ++i) 
    cin >> s[i];

  vector<int> ans(n);
  for (int rep = 0; rep < m; ++rep) {
    string t;
    cin >> t;

    bool done = false;
    vector<int> almost;
    for (int i = 0; i < n; ++i) {
      if (s[i] == t) { // * We found exact match
        done = true;
        ans[i]++;
        break;
      }

      if (s[i].length() != t.length())
        continue;
      
      // * count the differences
      int cnt = 0;
      for (int j = 0; j < (int)t.length(); ++j) {
        if (s[i][j] != t[j])
          cnt++;
      }
      if (cnt == 1) almost.push_back(i);
    }

    if (done) continue;
    if (almost.size() == 1) // * exactly one string with 1 difference
      ans[almost[0]]++;
  }

  for (auto x: ans)
    cout << x << '\n';
}

int main(void) {
  // Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  solve();
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 b-invalid-vote.cpp -o output && ./output
