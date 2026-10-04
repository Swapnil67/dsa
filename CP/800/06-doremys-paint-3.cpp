/*
 * Doremy's Paint 3
 * 
 * An array of positive integers is considered good if all the sums of two adjacent 
 * elements are equal to the same value. More formally, an array b of length n is good 
 * if there exists an integer k such that b[0] + b[1] = b[1] + b[2] = ... = b[n-2] + b[n-1] = k.
 * 
 * Given an array nums, determine if you can permute its elements (rearrange their order) 
 * in any way such that the resulting array becomes good. Return true if it is possible, 
 * and false otherwise.
 * 
 * Example 1    :
 * Input        : nums = [8, 9]
 * Output       : true
 * Explanation  : The array is already good because it only has two elements, so the sum of 
 *                adjacent elements is trivially 8 + 9 = 17.
 * 
 * Example 2    :
 * Input        : nums = [1, 1, 2]
 * Output       : true
 * Explanation  : We can permute the array to [1, 2, 1]. The adjacent sums are 1 + 2 = 3 
 *                and 2 + 1 = 3, which are equal.
 * 
 * Example 3    :
 * Input        : nums = [2, 4, 6, 8]
 * Output       : false
 * Explanation  : It is impossible to rearrange the elements to make the adjacent sums equal.
 * 
 * https://codeforces.com/problemset/problem/1890/A
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation

// * a0 + a1 + a2 + a3 + a4 + ......... + an

// * For any index 2 <= i <= n - 1 following should be true

// * a[i-1] + a[i] == a[i] + a[a+1]
// * a[i-1] == a[i+1]  --- (From above eq we can remove a[i])

// * so we can say that for any 'i' its prev and next elements should be same.
// * Also we can claim that all the elements on even indices are same.
// * Also we can claim that all the elements on odd indices are same.

// * There are only two possibilities 
// * A. All elements are same  (Eg, [1,1,1,1,1])
// * B. Array must have only two distinct elements (Eg [1,2,1,2,1,2])
// *    - Here freq of elements at odd/even indices should be same or abs(f1 - f2) == 1

bool solve() {
  long long n;
  cin >> n;

  vector<ll> a(n, 0);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int a1 = -1, a2 = -1;
  int f1 = 0, f2 = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == a1) {
      f1 = f1 + 1;
    } else if (a[i] == a2) {
      f2 = f2 + 1;
    } else if (a1 == -1) {
      a1 = a[i];
      f1 = 1;
    } else if (a2 == -1) {
      a2 = a[i];
      f2 = 1;
    } else {
      return false;
    }
  }

  // * All elements in array are same
  if (a2 == -1) return true;

  // * Half elements are a1 and other half are a2 (Even length array)
  if (f1 == f2)
    return true;

  // * For odd length we need to check if diff in freq is 1
  return (abs(f2 - f1) == 1);
}

int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    bool res = solve();
    cout << ((res == true) ? "YES" : "NO") << endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-doremys-paint-3.cpp -o output && ./output

// * testcase
/*
5
2
8 9
3
1 1 2
4
1 1 4 5
5
2 3 3 3 3
4
100000 100000 100000 100000

*/

// * output
/*
Yes
Yes
No
No
Yes
*/