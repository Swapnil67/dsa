/*
 * Sum of Medians
 * 
 * Description:
 * A median of an array of integers of length n is defined as the element standing on the 
 * ceil(n / 2) position (1-indexed) in the non-decreasing ordering of its elements. 
 * You are given two integers n and k and a non-decreasing array of n * k integers. 
 * Divide all numbers into k arrays of size n, such that each number belongs to exactly one array. 
 * Find the maximum possible sum of the medians of all k arrays.
 * 
 * Constraints:
 * 1 <= t <= 100 (number of test cases)
 * 1 <= n, k <= 1000
 * 0 <= a_i <= 10^9
 * The sum of n * k over all test cases does not exceed 2 * 10^5.
 * 
 * Example 1    :
 * Input        : n = 2, k = 4, a = [0, 2, 4, 6, 8, 10, 12, 14]
 * Output       : 24
 * Explanation  : [0,2], [4,6], [8,10], [12,14] => 24   (Here median index is 1)
 *                 ^      ^      ^       ^ 
 * 
 * Example 2    :
 * Input        : n = 4, k = 3, a = [2 4 16 18 21 27 36 53 82 91 92 95]
 * Output       : 145
 * Explanation  : [2,91,92,95], [4,36,53,82], [16,18,21,27] => 145 (Here median index is 2)
 *                   ^             ^              ^       
 *
 * https://codeforces.com/problemset/problem/1440/B
*/

// ! Observation + Greedy + Two pointer

// ! Observation
/*
* Sort the array. Form k groups of size m from the right so that each group’s median is as large as possible. 
* Start at the position of the first median on the right, add that element, 
* then move left by “half the group size (rounded down) plus one” positions to land on the next median; 
* repeat this k times and sum those k medians.
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;


// * Greedy median selection
// * Time Complexity (TC): O(n*k) = O(2*10^5)
// * Space Complexity (SC): O(n*k) = O(2*10^5)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n*k);
    for (int i = 0; i < n*k; ++i)
      cin >> a[i];
      
    ll pointer = n * k; // * Initialize pointer to the end of the vector
		ll sum = 0; // * Initialize sum to store the sum of medians
		while (k--) // * Loop k times to calculate the sum of medians
		{
			pointer -= (n / 2 + 1); // * Move the pointer to the median position of the current subarray
			sum += a[pointer]; // * Add the median value to the sum
		}
      
    cout << sum << "\n";
  }
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 28-sum-of-medians.cpp -o output && ./output

// * testcases
/*
6
2 4
0 24 34 58 62 64 69 78
2 2
27 61 81 91
4 3
2 4 16 18 21 27 36 53 82 91 92 95
3 4
3 11 12 22 33 35 38 67 69 71 94 99
2 1
11 41
3 3
1 1 1 1 1 1 1 1 1

*/

// * Output
/*
165
108
145
234
11
3
*/
