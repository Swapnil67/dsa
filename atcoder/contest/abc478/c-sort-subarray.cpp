/*
 * C - Sort Subarray
 * 
 * https://atcoder.jp/contests/abc478/tasks/abc478_c
*/

#include <vector>
#include <iostream>
#include <algorithm>

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

// * Count sorted prefix & suffix then check if remaning subarr b/w i & j can be sorted since we have 'k' bound.
/*
* n = 9, k = 6

* i =  0 1 2 3 4 5 6 7 8
* a = [1 4 1 4 2 1 3 5 6]
* b = [1 1 1 2 3 4 4 5 6]      (sorted vector)
*        i         j

* prefix_match(i) = 1
* suffix_match(j) = 6
* 
* k >= (j - i + 1) ==> (6 >= 6) ==> "Yes"
*/

// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  // * copy of a & sort it.
  vector<int> b = a; 
  sort(all(b));
  printArr(b);

  // * Find the longest matching prefix
  int i = 0;
  while (i < n && a[i] == b[i])
    i++;
  
  // * Find the longest matching suffix
  int j = n - 1;
  while (j >= 0 && a[j] == b[j]) 
    j--;

  cout << i << " " << j << endl;

  cout << (k >= j - i + 1 ? "Yes" : "No") << "\n";

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 c-sort-subarray.cpp -o output && ./output

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