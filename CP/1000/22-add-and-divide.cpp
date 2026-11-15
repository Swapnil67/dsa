/*
 * Add and Divide
 * 
 * Description:
 * You are given two positive integers a and b. You can perform two kinds of operations 
 * any number of times in any order:
 * 1. a = floor(a / b) (replace a with the integer part of the division between a and b)
 * 2. b = b + 1 (increase b by 1)
 * 
 * Your goal is to find the minimum number of total operations required to make a = 0.
 * 
 * Constraints:
 * 1 <= a, b <= 10^9
 * The number of independent test cases t does not exceed 100.
 * 
 * Example 1    :
 * Input        : a = 9, b = 2
 * Output       : 4
 * Explanation  : One of the optimal paths to reduce a to 0 is:
 *                1. Divide a by b: a = floor(9/2) = 4, b = 2 (Op count = 1)
 *                2. Divide a by b: a = floor(4/2) = 2, b = 2 (Op count = 2)
 *                3. Increase b   : a = 2, b = 2 + 1 = 3    (Op count = 3)
 *                4. Divide a by b: a = floor(2/3) = 0, b = 3 (Op count = 4)
 *                Total operations = 4.
 * 
 * Example 2    :
 * Input        : a = 1337, b = 1
 * Output       : 9
 * Explanation  : Since dividing by 1 infinitely results in 1337 without decreasing a,
 *                we must first increase b before applying any division operations.
 *                The total minimum combination of increments and divisions gives 9.
 *
 * https://codeforces.com/problemset/problem/1485/A
*/

// ! Observation
/*
* It's always optimal to perform all b = b + 1 increments first, before starting any divisions.
* 
* Brute force a small number of initial increments for b. 
* For each choice (e.g., incrementing b from 0 to 35 times),
* calculate the total operations needed: (number of increments) + (number of divisions).
* The answer is the minimum total you find.

* a = 1000000000, b = 1
* a = a / b, b = b + 1
* new_b: 2, operations: 31
* new_b: 3, operations: 21
* new_b: 4, operations: 18
* new_b: 5, operations: 17
* new_b: 6, operations: 17
* new_b: 7, operations: 17
* new_b: 8, operations: 17
* new_b: 9, operations: 18
* new_b: 10, operations: 19
* new_b: 11, operations: 19
* new_b: 12, operations: 20
* new_b: 13, operations: 21
* new_b: 14, operations: 21
* new_b: 15, operations: 22
* new_b: 16, operations: 23
* new_b: 17, operations: 24
* new_b: 18, operations: 25
* new_b: 19, operations: 26
* new_b: 20, operations: 26
* new_b: 21, operations: 27
* new_b: 22, operations: 28
* new_b: 23, operations: 29
* new_b: 24, operations: 30
* new_b: 25, operations: 31
* new_b: 26, operations: 32
* new_b: 27, operations: 33
* new_b: 28, operations: 34
* new_b: 29, operations: 35
* new_b: 30, operations: 36
* new_b: 31, operations: 37
* new_b: 32, operations: 37

* You can see there as we keep on adding '1' to 'b' our total number of operations also increases
* So we need to find some threshold after that we would do the division operation.
*/


#include <iostream>

using namespace std;
typedef long long ll;

ll solve() {
  ll a, b;
  cin >> a >> b;

  ll ans = INT_MAX;
  for (int addition = 0; addition < 32; ++addition) { // * Iterate over possible increments of b (log2(a))
    ll operations = addition; // * Start with the current increment as operations
    ll new_b = b + addition; // * Calculate the new value of b
    // * If new_b is 1, skip this iteration as division by 1 is not useful
    if (new_b == 1)
      continue;

    ll copy_a = a;
    while (copy_a > 0) { // * log2(a)
      copy_a /= new_b; // * Divide a by the current b
      operations++;
    }

    cout << "new_b: " << new_b << ", operations: " << operations << endl;
    ans = min(ans, operations);
  } 

  return ans;
}

// * Greedy Minimising
// * Time Complexity (TC): O(log2(a)^2)
// * Space Complexity (SC): O(1)
int main(void) {
  ll t;
  cin >> t;
  while (t--) {
    ll ans = solve();
    cout << ans << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 22-add-and-divide.cpp -o output && ./output

// * testcases
/*
6
9 2
1337 1
1 1
50000000 4
991026972 997
1234 5678

*/

// * Output
/*
4
9
2
12
3
1
*/
