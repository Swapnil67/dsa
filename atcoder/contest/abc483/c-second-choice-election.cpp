/*
 * C - Second Choice Election 
 * 
 * https://atcoder.jp/contests/abc483/tasks/abc483_c 
*/

#include <set>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define PRINT_VEC_PAIRS(p) for (auto &it: p) cout << it.first << ' ' << it.second << '\n'

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

// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> freq(n + 1);
  vector<vi> instead(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    freq[a]++;
    instead[a].push_back(b);
  }

  // * For debug
  // printArr(freq);
  // for (auto i: instead) {
  //   printArr(i);
  // }

  // * Add the ranking of candidates
  set<pair<int, int>> ranking; // * {votes, candidate}
  for (int i = 1; i <= n; ++i) {
    ranking.insert({freq[i], -i});
  }
  // PRINT_VEC_PAIRS(ranking); // * For debug

  for (int a = 1; a <= n; ++a) {
    // * Remove candidate 'a' and add 'b'
    for (int b : instead[a]) {
      ranking.erase({freq[a], -a});
      ranking.erase({freq[b], -b});
      freq[a]--;
      freq[b]++;
      ranking.insert({freq[a], -a});
      ranking.insert({freq[b], -b});
    }

    cout << -ranking.rbegin()->second << '\n';

    // * Go back to the original
    for (int b : instead[a]) {
      ranking.erase({freq[a], -a});
      ranking.erase({freq[b], -b});
      freq[a]++;
      freq[b]--;
      ranking.insert({freq[a], -a});
      ranking.insert({freq[b], -b});
    }
  }
}

// ! More optimal
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
void optimal() {
  int n, m;
  cin >> n >> m;
  vector<int> freq(n + 1);
  vector<vi> instead(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    freq[a]++;
    instead[a].push_back(b);
  }

  // * For debug
  // printArr(freq);
  // for (auto i: instead) {
  //   printArr(i);
  // }

  // * 1st and 2nd winners
  pair<int, int> first = {-1, -1}; // * first winner
  pair<int, int> second = {-1, -1}; // * second winner
  for (int a = 1; a <= n; ++a) {
    pair<int, int> p = {freq[a], -a}; // * current candidate
    if (p > first) {
      second = first;
      first = p;
    }
    else if (p > second) {
      second = p;
    }
  }
  // cout << first.first << ' ' << first.second << '\n';
  // cout << second.first << ' ' << second.second << '\n';

  // * check withdraws from 1...n
  for (int a = 1; a <= n; ++a) {
    pair<int, int> best = {-1, -1};
    for (int b : instead[a]) {
      freq[b]++;
      best = max(best, make_pair(freq[b], -b));
    }
    if (-first.second != a) { // * If 1st candidate does not withdraws.
      best = max(best, first);
    } else { // * Go for 2nd candidate.
      best = max(best, second);
    }
    cout << -best.second << '\n';

    // * Go back to the original
    for (int b : instead[a]) {
      freq[b]--;
    }
  }
}

int main(void) {
  // solve();
  optimal();
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 c-second-choice-election.cpp -o output && ./output
