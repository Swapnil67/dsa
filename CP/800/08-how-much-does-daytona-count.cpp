/*
 * How Much Does Daytona Cost?
 * 
 * Description
 * Given an array nums of n integers and an integer k, determine if there exists a subarray 
 * in nums where k is the most frequent element (the majority element). The majority element 
 * of a subarray is the element that appears strictly more times than any other element 
 * in that specific subarray.
 * 
 * Return true if such a subarray exists, and false otherwise.
 * 
 * Constraints:
 * 1 <= n <= 100
 * 1 <= k <= 100
 * 1 <= nums[i] <= 100
 * 
 * Example 1    :
 * Input        : nums = [1 4 3 4 1], k = 4
 * Output       : true
 * Explanation  : We can choose the subarray [4] or. In both cases, 4 is the most 
 *                frequent element.
 * 
 * Example 2    :
 * Input        : nums = [43 5 60 4 2], k = 6
 * Output       : false
 * Explanation  : The element 6 is not even present in the array, so it can never be the most 
 *                frequent element in any subarray.
 * 
 * Example 3    :
 * Input        : nums = [3], k = 3
 * Output       : true
 * Explanation  : The element 3 appears in the array. We can just pick the single-element 
 *                subarray, where 3 is trivially the most frequent.
 * 
 * https://codeforces.com/problemset/problem/1878/A
*/

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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    
    bool found = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == k)
            found = true;
    }
    
    cout << (found ? "YES" : "NO") << endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 08-how-much-does-daytona-count.cpp -o output && ./output

// * testcase

/*
7
5 4
1 4 3 4 1
4 1
2 3 4 4
5 6
43 5 60 4 2
2 5
1 5
4 1
5 3 3 1
1 3
3
5 3
3 4 1 5 5

*/


// * output
/*
YES
NO
NO
YES
YES
YES
YES
*/

