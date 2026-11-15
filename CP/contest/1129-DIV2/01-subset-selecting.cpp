/*
 *  A. Subset Selecting
 *
 * https://codeforces.com/contest/2277/problem/A
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

// * Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]
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

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

// * Testcase
/*
6
3 1
0 2 1
4 2
1 2 3 4
5 2
0 1 0 1 0
5 4
0 0 1 0 0
5 1
4 0 0 0 2
6 2
0 0 2 1 0 0

*/

// * Output
/*
3
0
2
1
1
3

*/