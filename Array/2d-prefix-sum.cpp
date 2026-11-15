#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

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

// * TIME COMPLEXITY O(n * m)
// * SPACE COMPLEXITY O(n * m)
int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);

  vector<vi> grid = {
      {1, 2, 3, 5, 6, 1},
      {2, 1, 3, 0, 1, 7},
      {0, 1, 2, 4, 5, 6},
      {1, 2, 3, 4, 0, 7},
      {2, 1, 0, 1, 2, 3},
  };

  int m = grid.size(), n = grid[0].size();
  vector<vi> p(m + 1, vi(n + 1, 0));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      p[i][j] = grid[i - 1][j - 1];
      p[i][j] += p[i - 1][j];
      p[i][j] += p[i][j - 1];
      p[i][j] -= p[i - 1][j - 1];
    }
  }

  for (auto vec : p)
    printArr(vec);

  int q;
  cin >> q;
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int sum = p[x2][y2] -
              p[x1 - 1][y2] -
              p[x2][y1 - 1] +
              p[x1 - 1][y1 - 1];
    cout << sum << '\n';
  }

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 2d-prefix-sum.cpp -o output && ./output
