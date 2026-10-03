/*
 * 1878C - Vasilije in Cacak
 * 
 * Description:
 * Given three positive integers n, k, and x, determine if it is possible to choose k distinct 
 * integers between 1 and n inclusive such that their sum is exactly equal to x.
 * 
 * Constraints:
 * 1 <= t <= 10^4 (Number of test cases)
 * 1 <= n <= 2 * 10^5
 * 1 <= k <= n
 * 1 <= x <= 4 * 10^10
 * 
 * Example 1    :
 * Input        : n = 5, k = 3, x = 10
 * Output       : YES
 * Explanation  : We need to pick 3 distinct integers from the range that sum up to 10. We can choose {2, 3, 5} because 2 + 3 + 5 = 10.
 * 
 * Example 2    :
 * Input        : n = 5, k = 3, x = 5
 * Output       : NO
 * Explanation  : The minimum possible sum of picking 3 distinct integers from is 1 + 2 + 3 = 6. Since x = 5 is strictly less than 6, it is impossible.
 * 
*/

// ! Observation
// * If we want to create x as a sum, this x sum should be 
// * x >= min_sum && x <= max_sum

// * min_sum = sum of first k integers
// * max_sum = sum of last k integers


#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    ll n, k, x;
    cin >> n >> k >> x;

    // * Total sum [1...n]
    ll total_sum = n * (n + 1) / 2;

    // * Sum from [1...k]
    ll k_first_sum = k * (k + 1) / 2;

    // * Sum from [1...n-k]
    ll k_sum2 = (n - k) * ((n - k) + 1) / 2;

    ll k_last_sum = total_sum - k_sum2;

    if (x >= k_first_sum && x <= k_last_sum)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-chemistry.cpp -o output && ./output

// * testcases
/*
12
5 3 10
5 3 3
10 10 55
6 5 20
2 1 26
187856 87856 2609202300
200000 190000 19000000000
28 5 2004
2 2 2006
9 6 40
47202 32455 613407217
185977 145541 15770805980

*/


// * Output
/*
YES
NO
YES
YES
NO
NO
YES
NO
NO
NO
YES
YES
*/