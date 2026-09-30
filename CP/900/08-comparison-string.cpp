/*
 * Comparison String
 * 
 * Description:
 * You are given a string s of length n, where each character is either '<' or '>'.
 * 
 * An array a consisting of n + 1 elements is compatible with the string s if, 
 * for every i from 0 to n - 1, the character s[i] represents the result of 
 * comparing a[i] and a[i + 1]:
 *   - s[i] is '<' if and only if a[i] < a[i + 1]
 *   - s[i] is '>' if and only if a[i] > a[i + 1]
 * 
 * The cost of the array is defined as the number of distinct elements in it.
 * Calculate the minimum possible cost among all arrays that are compatible with s.
 * 
 * Constraints:
 * 1 <= s.length <= 100
 * s consists only of characters '<' and '>'.
 * 
 * Example 1    :
 * Input        : s = ">>"
 * Output       : 3
 * Explanation  : A compatible array is [3, 2, 1], which has 3 distinct elements. No compatible array can have fewer than 3 distinct elements.
 * 
 * Example 2    :
 * Input        : s = ">><<"
 * Output       : 3
 * Explanation  : A compatible array is [3, 2, 1, 2, 3], which contains the distinct values {1, 2, 3}, giving a cost of 3.
 * 
 * https://codeforces.com/problemset/problem/1837/B
*/

// ! Greedy

// ! Observation
// * The answer is (Length of longest substring made of same characters + 1)

/*
* set of elements = [a < b < c < d]
*  s = < < < > < > > >
* Longest chain of same char = "<<<" 
* Ans = 3 + 1 = 4
*
* Proof: 4 char are enough to satisfy above equation  
* a < b < c < d > c < d > c > b > a
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

// * Count and Reset pattern
// * Greedy on longest streak
// * TC = O(n)
// * SC = O(1)
int main(void)
{
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    // * Length of longest substring made of same characters
    ll cur_substr_len = 1LL, longest_substr_len = 1LL;
    for (int i = 1; i < n; ++i) {
      if (s[i] == s[i - 1]) {
        cur_substr_len++;
      }
      else {
        longest_substr_len = max(longest_substr_len, cur_substr_len);
        cur_substr_len = 1;
      }
    }
    longest_substr_len = max(longest_substr_len, cur_substr_len);

    cout << longest_substr_len + 1 << endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 08-comparison-string.cpp -o output && ./output

// * testcases
/*
4
4
<<>>
4
>><<
5
>>>>>
7
<><><><

*/

// * Output
/*
3
3
6
2
*/