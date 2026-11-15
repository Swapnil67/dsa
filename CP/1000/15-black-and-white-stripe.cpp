/*
 * D. Black and White Stripe
 * 
 * You are given a stripe of checkered paper of length n. Each cell is colored 
 * either white ('W') or black ('B'). 
 * 
 * Your task is to determine the minimum number of white cells that must be 
 * recolored to black in order to obtain a contiguous segment of at least k 
 * consecutive black cells on the stripe. If a segment of k consecutive black 
 * cells already exists, output 0.
 * 
 * Constraints:
 * - 1 <= t <= 10^4 (Number of test cases)
 * - 1 <= k <= n <= 2 * 10^5 (Length of stripe and required block length)
 * - The sum of n over all test cases does not exceed 2 * 10^5.
 * - The input string consists only of characters 'W' and 'B'.
 * 
 * Example 1    :
 * Input        : n = 5, k = 3, s = "BBWWBB"
 * Output       : 1
 * Explanation  : You can change the 3rd cell from 'W' to 'B' to get "BBBwBB", 
 *                which creates a contiguous segment of 3 black cells.
 * 
 * Example 2    :
 * Input        : n = 5, k = 1, s = "BBWWBB"
 * Output       : 0
 * Explanation  : A contiguous black segment of length 1 already exists 
 *                (multiple times), so no changes are necessary.
 *
 * https://codeforces.com/problemset/problem/1690/D
*/

#include<vector>
#include<iostream>

using namespace std;
typedef long long ll;


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

// * Time Complexity (TC): O(n) = O(2*10^5)
// * Space Complexity (SC): O(n) = O(2*10^5)
ll bruteForce(void) {
  ll n, k;
  cin >> n >> k;
  
  string s;
  cin >> s;

  // * Initialize a prefix sum array to count the number of 'W's up to each position
  vector<ll> prefix_w(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    prefix_w[i + 1] = prefix_w[i] + (s[i] == 'W'); // * Increment prefix_w sum if current cell is 'W'
  }
  printArr(prefix_w);

  ll minimum_cells = n;
  // * Iterate over each possible segment of length k
  for (int i = 0; i <= n - k; ++i) {
    // * Calculate the number of 'W's in the current segment of length k
    long long diff = prefix_w[i + k] - prefix_w[i];
    // * Update the minimum cells to recolor if the current segment has fewer 'W's
    minimum_cells = min(minimum_cells, diff);
  }
  return minimum_cells;
}

// * Time Complexity (TC): O(n) = O(2*10^5)
// * Space Complexity (SC): O(1)
ll solve(void) {
  ll n, k;
  cin >> n >> k;
  
  string s;
  cin >> s;
  
  ll recolor = 0, minimum_cells = n;
  ll i = 0, j = 0;
  while (j < n) {
    if (s[j] == 'W') // * recolor it to Black and increment recolor.
      recolor++;
    
    if ((j - i + 1) > k) { // * Shrink Window
      if (s[i] == 'W') {
        recolor--; 
      }
      i++;
    }
    
    if ((j - i + 1) == k) { // * Found k-length segment
      //  * Update the minimum cells to recolor if the current segment has fewer 'W's
      minimum_cells = min(minimum_cells, recolor);
    }

    j++;
  }
  
  return minimum_cells;
}

int main(void) {
  ll t;
  cin >> t;
  
  while (t--) {
    ll minimum_cells = bruteForce();
    // ll minimum_cells = solve();
    cout << minimum_cells << "\n";
  }
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 15-black-and-white-stripe.cpp -o output && ./output

// * testcases
/*
4
5 3
BBWBW
5 5
BBWBW
5 1
BBWBW
1 1
W

*/

// * Output
/*
1
2
0
1
*/