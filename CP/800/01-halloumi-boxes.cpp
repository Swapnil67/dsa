/*
 * Halloumi Boxes (Codeforces 1903A)
 * 
 * Description
 * Theofanis has n boxes, each with an integer a_i written on it. He wants to sort 
 * the boxes in non-decreasing order. However, he can only reverse any subarray of 
 * boxes of length at most k. You need to determine if it is possible to sort the 
 * boxes using any number of such reverse operations.
 * 
 * Example 1    :
 * Input        : n = 3, k = 2, boxes = [1, 2, 3]
 * Output       : YES
 * Explanation  : The boxes are already sorted in non-decreasing order.
 * 
 * Example 2    :
 * Input        : n = 3, k = 1, boxes = [3, 2, 1]
 * Output       : NO
 * Explanation  : Since k = 1, you can only reverse subarrays of length 1, which 
 *                does not change the array. The array is not sorted, so it's impossible.
 * 
 * https://codeforces.com/problemset/problem/1903/A
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
  cout << " ]" << endl;
}

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)

#include <vector>
#include <iostream>
using namespace std;

void solve()
{
  // * Take inputs
  int n, k;
  cin >> n;
  cin >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  // * if we can do atmost two reverse then we can sort the array
  if (k >= 2) {
    cout << "YES" << endl;
    return;
  }

  // * Check sorted
  bool isSorted = true;
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) {
      isSorted = false;
      break;
    }
  }

  if (isSorted)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-halloumi-boxes.cpp -o output && ./output

// * Testcases
/*
5
3 2
1 2 3
3 1
9 9 9
4 4
6 4 2 1
4 3
10 3 830 14
2 1
3 1
*/