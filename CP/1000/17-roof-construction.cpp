/*
 * B. Roof Construction
 * 
 * You are given an integer n. You need to find a permutation p of length n 
 * (containing every integer from 0 to n - 1 exactly once) such that the maximum 
 * bitwise XOR value of adjacent elements is minimized.
 * 
 * More formally, you want to minimize the value:
 * max( p[i] XOR p[i + 1] ) for all 0 <= i < n - 1.
 * 
 * If there are multiple permutations that achieve the minimum possible maximum 
 * XOR value, output any of them.
 * 
 * Constraints:
 * - 1 <= t <= 10^4 (Number of test cases)
 * - 2 <= n <= 2 * 10^5 (Length of the permutation)
 * - The sum of n over all test cases does not exceed 2 * 10^5.
 * 
 * Example 1    :
 * Input        : n = 4
 * Output       : 2 3 1 0
 * Explanation  : The adjacent XOR values are:
 *                - 2 XOR 3 = 1
 *                - 3 XOR 1 = 2
 *                - 1 XOR 0 = 1
 *                The maximum value among these is 2. It can be proven that a 
 *                maximum value less than 2 is impossible for n = 4.
 * 
 * Example 2    :
 * Input        : n = 3
 * Output       : 2 0 1
 * Explanation  : The adjacent XOR values are:
 *                - 2 XOR 0 = 2
 *                - 0 XOR 1 = 1
 *                The maximum value is 2.
 *
 * https://codeforces.com/problemset/problem/1632/B
*/

// ! Observation
/*
* Achieve the minimum possible cost of 2^k (where 2^k is the largest power of two less than n).
* A valid construction that achieves this is to arrange numbers [2^k−1, 2^k−2,…,0] followed by [2^k, 2^(k+1),...,2^(n−1)]
*/

#include<vector>
#include<cmath>
#include<iostream>

using namespace std;
typedef long long ll;

/*
* We'll greedily take the remove money at day which has max amount in bank.
* Rest we'll add 2 for the remaining days we remove.
*/
// * ans = 2^(n-k+1) + 2*(k-1)

vector<ll> solve(void) {
  ll n;
  cin >> n;
  n--; // Decrement n to work with zero-based index
  
  ll msb = log2(n); // * Find the most significant bit position of n
  vector<ll> ans; 
  ll num = pow(2, msb) - 1; // * Calculate the largest number with all bits set below msb
  while (num >= 0)  { // * Fill the vector with numbers from num to 0
    ans.push_back(num);
    num--;
  }
  
  num = pow(2, msb); // * Start from the next power of 2
  while (num <= n) { // * Fill the vector with numbers from num to n
    ans.push_back(num);
    num++;
  }
  
  return ans;
}

// * Greedy + Bit manipulation
// * Time Complexity (TC): O(n) = O(2*10^5)
// * Space Complexity (SC): O(n) = O(2*10^5)
int main(void) {
  ll t;
  cin >> t;

  while (t--) {
    auto ans = solve();
    for (auto &num: ans)
      cout << num << " ";
    cout << "\n";
  }
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 17-roof-construction.cpp -o output && ./output

// * testcases
/*
3
7 4 3
6 5 1
19 13 6

*/

// * Output
/*
RBRBRBR
RRRBRR
RRBRRBRRBRRBRRBRRBR
*/