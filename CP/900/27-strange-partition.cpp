/*
 * Strange Partition
 * 
 * Description:
 * Given an array `a` of `n` integers and an integer `x`. You can repeatedly replace any two 
 * adjacent elements by their sum. The beauty of an array is defined as the sum of ceil(b_i / x) 
 * for all elements b_i in the array. Find the minimum and maximum possible beauty of the array 
 * after performing any number of operations.
 * 
 * Constraints:
 * 1 <= t <= 1000 (number of test cases)
 * 1 <= n <= 10^5 (length of the array)
 * 1 <= x <= 10^9
 * 1 <= a_i <= 10^9
 * The sum of n over all test cases does not exceed 10^5.
 * 
 * Example 1    :
 * Input        : n = 3, x = 3, a = [3, 6, 9]
 * Output       : 6 6
 * Explanation  : 
 *                - To get minimum beauty: Combine all elements into one [18]. ceil(18/3) = 6.
 *                - To get maximum beauty: Keep all elements separate [3, 6, 9]. 
 *                  ceil(3/3) + ceil(6/3) + ceil(9/3) = 1 + 2 + 3 = 6.
 * 
 * Example 2    :
 * Input        : n = 3, x = 4, a = [6, 4, 3]
 * Output       : 4 5
 * Explanation  : 
 *                - To get minimum beauty: Combine all elements [13]. ceil(13/4) = 4.
 *                - To get maximum beauty: Keep all elements separate [6, 4, 3].
 *                  ceil(6/4) + ceil(4/4) + ceil(3/4) = 2 + 1 + 1 = 5.
 *
 * https://codeforces.com/problemset/problem/1471/A
*/


#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation
/*
* _        _        _  _     _   _         
* |  y + z  |       | y |    | z |     
* | ------  |   <=  _____  + _____      
* |    x    |         x        x

* So using above analogy we can say that.
* max beauty = we need to perform 0 operations (right side), we'll take sum of all beauty of individual elements.
* min beauty = we need to perform n-1 operation (left side), we'll take total sum and then find the beauty.
*/

// * Greedy grouping with ceiling
// * Time Complexity (TC): O(n) = O(10^5)
// * Space Complexity (SC): O(n) = O(10^5)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
      
    // * For maximum beauty, perform zero operations: 
    // * sum of ceil(a[i]/x) for each original element.
    ll max_beauty = 0, total_sum = 0;
    for (int i = 0; i < n; ++i) {
      total_sum += a[i];
      int beauty = (a[i] + x - 1) / x;
      max_beauty += beauty;
    }
    
    // * For minimum beauty, perform n−1 operations to get a single element
    // * ceil(total_sum / x)
    ll min_beauty = (total_sum + x - 1) / x;
    
    cout << min_beauty << " " <<  max_beauty << "\n";
  }
  
  return 0;
}
