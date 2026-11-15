/*
 * Array Coloring
 * 
 * You are given an array consisting of $n$ integers. Your task is to determine whether it is 
 * possible to color all its elements in two colors (such as blue and red) in such a way that 
 * the sums of the elements of both colors have the same parity (both sums are even or both sums 
 * are odd). Each color must have at least one element assigned to it.
 * 
 * Return "YES" if such a coloring is possible, or "NO" otherwise.
 * 
 * Constraints:
 * 1 <= t <= 1000 (number of test cases)
 * 2 <= n <= 50 (length of the array)
 * 1 <= a[i] <= 50 (elements of the array)
 * 
 * Example 1    :
 * Input        : arr = [1, 2, 4, 3, 2, 3, 5, 4]
 * Output       : "YES"
 * Explanation  : We can color the elements [1, 2, 3] blue (sum = 6, which is even) and the elements [4, 2, 3, 5, 4] red (sum = 18, which is even). Both sums have the same parity.
 * 
 * Example 2    :
 * Input        : arr = [3, 3, 2]
 * Output       : "YES"
 * Explanation  : We can color [3, 3] blue (sum = 6, even) and [2] red (sum = 2, even). Both sums have the same parity.
 * 
 * Example 3    :
 * Input        : arr = [1, 2, 2]
 * Output       : "NO"
 * Explanation  : No matter how we partition the array into two non-empty color groups, one group will have an odd sum and the other will have an even sum, resulting in different parities.
 *
 * https://codeforces.com/problemset/problem/1857/A
*/

// ! Observation

// * If total sum is even we can divide that, but if we've odd sum then it cannot be divide.

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  
  ll total_sum = 0;
  vector<ll> a(n);
  for (auto &x: a) {
    cin >> x;
    total_sum += x;
  }
  
  if (total_sum % 2 == 0) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}

// * Time Complexity (TC): O(N)
// * Space Complexity (SC): O(N)
int main(void) {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 14-buttons.cpp -o output && ./output

// * testcase

/*
7
8
1 2 4 3 2 3 5 4
2
4 7
3
3 9 8
2
1 7
5
5 4 3 2 1
4
4 3 4 5
2
50 48

*/

// * output
/*
YES
NO
YES
YES
NO
YES
YES
*/

