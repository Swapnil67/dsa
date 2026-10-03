/*
 * Luntik and Subsequences (Codeforces 1582B)
 * 
 * Description  : You are given an array a of length n. The total sum of all elements 
 *                in the array is s. A subsequence of a is called "nearly full" if the 
 *                sum of its elements is exactly equal to s - 1. Find the total number 
 *                of nearly full subsequences of the array a.
 * 
 * Constraints  : 
 *                - 1 <= t <= 1000 (Number of test cases)
 *                - 1 <= n <= 60 (Length of the array)
 *                - 0 <= a[i] <= 10^9 (Elements of the array)
 * 
 * Example 1    :
 * Input        : n = 5, a = [1, 2, 3, 4, 5]
 * Output       : 1
 * Explanation  : The total sum is s = 15. We want subsequences with a sum of 14. 
 *                Removing the element '1' yields the subsequence [2, 3, 4, 5], 
 *                which sums to 14.
 * 
 * Example 2    :
 * Input        : n = 5, a = [2, 1, 0, 3, 0]
 * Output       : 4
 * Explanation  : The total sum is s = 6. We want subsequences with a sum of 5. 
 *                We must remove the element '1' and we can choose to either include 
 *                or exclude each of the two '0' elements. This gives 1 * 2^2 = 4 
 *                valid subsequences.
 *
 * https://codeforces.com/problemset/problem/1582/B
*/

// ! Combinatrics

// ! Observation
/*
* Let total array sum be s.

* To find subseq with sum as s - 1, there should be a atleast one 1 present in the array, then only its possible 
* to remove that 1 and make subseq with sum s-1.

* Formula:
* Count zeros and ones; zeros double subsequence possibilities.
* Calculate  2^count_of_zeros × count_of_ones

* Eg: a = [3 0 2 0 1 1]  sum = 7, we need to find subseq with sum = 6
* count_of_zeros = 2, count_of_ones = 2
* no of subsequences = 2^count_of_zeros * count_of_ones
* no of subsequences = 2^2 * 2
* no of subsequences = 8
* 
*/

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

ll solve() {
  int n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  ll count_of_ones = 0, count_of_zeros = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      count_of_zeros += 1;
    }
    else if (a[i] == 1) {
      count_of_ones += 1;
    }
  }
  
  // * ans = 2^count_of_zeros * count_of_ones
  return pow(2, count_of_zeros) * count_of_ones;
}

// * TC = O(n)
// * SC = O(n) (Input Array)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 22-luntik-and-subsequences.cpp -o output && ./output

// * testcases
/*
5
5
1 2 3 4 5
2
1000 1000
2
1 0
5
3 0 2 1 1
5
2 1 0 3 0

*/

// * Output
/*
1
0
2
4
4
*/
