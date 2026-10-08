/*
 * D - Range Set Insertion Query
 * 
 * https://atcoder.jp/contests/abc478/tasks/abc478_d
*/

#include <map>
#include <set>
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

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()

void bruteForce(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int n, q;
  cin >> n >> q;
  
  vector<unordered_set<int>> buckets(n);
  
  for (int i = 0; i < q; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    for (int j = l - 1; j <= r - 1; ++j) {
      buckets[j].insert(x);
    }
  }
  
  for (int i = 0; i < n; ++i) {
    cout << buckets[i].size() << " ";
  }
  cout << "\n";
}

// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
void betterApproach() {
  int n, q;
  cin >> n >> q;

  vector<vector<int>> events(n + 2);
  for (int i = 0; i < q; ++i) {
    int L, R, x;
    cin >> L >> R >> x;
    events[L].push_back(x);
    events[R + 1].push_back(-x);
  }

  for (auto &vec : events)
    printArr(vec);

  map<int, int> freq;
  for (int i = 1; i <= n; ++i) {
    for (auto &x: events[i]) {
      if (x > 0) {
        freq[x]++;
      } else {
        x *= -1;
        if (--freq[x] == 0) {
          freq.erase(x);
        }
      }
    }
    cout << freq.size() << " ";
  }
  cout << "\n";
}
 

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  bruteForce();
  return 0;
}

// * Run the code
// * g++ --std=c++20 d-range-set-insertion-query.cpp -o output && ./output

// * testcases
/*
9 6
1 4 1 4 2 1 3 5 6

3 1
3 2 1

30 25
1 2 2 22 14 10 14 10 18 5 15 8 17 22 10 17 11 25 13 16 9 19 26 7 11 12 23 3 30 30
*/

// * output
/*
Yes
No
Yes
*/