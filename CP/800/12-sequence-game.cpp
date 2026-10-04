/*
 * Sequence Game
 * 
 * Description:
 * You are given a sequence of integers b of length n. This sequence was generated 
 * from a secret original sequence a of length m (where n <= m <= 2n) using a specific rule: 
 * the first element is always kept (b[1] = a[1]), and for any subsequent element a[i], 
 * it is added to sequence b if and only if it is greater than or equal to the previous 
 * element in a (i.e., a[i-1] <= a[i]). Reconstruct any valid original sequence a that 
 * could produce the given sequence b.
 * 
 * Constraints:
 * - 1 <= t <= 10^4 (number of test cases).
 * - 1 <= n <= 2 * 10^5 (length of sequence b).
 * - 1 <= b[i] <= 10^9 (elements of sequence b).
 * - The sum of n over all test cases does not exceed 2 * 10^5.
 * 
 * Example 1    :
 * Input        : b = [4, 6, 3]
 * Output       : [4, 6, 1, 3]
 * Explanation  : The original sequence [4, 6, 1, 3] yields [4, 6, 3] because 
 *                4 is kept initially, 6 >= 4 (kept), 1 < 6 (skipped), and 3 >= 1 (kept). 
 *                This matches b perfectly.
 * 
 * Example 2    :
 * Input        : b = [1, 2, 3]
 * Output       : [1, 2, 3]
 * Explanation  : The sequence b is already non-decreasing. The original sequence can 
 *                be identical to b since 1 is kept, 2 >= 1 (kept), and 3 >= 2 (kept).
 *
 * https://codeforces.com/problemset/problem/1862/B
*/
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation

// * Every b[i] jotted down from 'a' must be greater than or equal to the previous numbers in 'a'
// * b = [4, 6, 3]
// * a = [4, 6, 3, 3]

// * Constructive Duplicate on decrease
// * TC = O(n)
// * SC = O(n)
int main(void)
{
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
  {
    ll n;
    cin >> n;
    vector<int> b(n, 0);
    for (int i = 0; i < n; ++i)
      cin >> b[i];

    vector<ll> a;
    a.push_back(b[0]);
    for (int i = 1; i < n; ++i) {
      if (b[i] < b[i - 1]) // * the prev no. must be >= the current no.
        a.push_back(b[i]);
      a.push_back(b[i]);
    }

    // * print output
    int m = a.size();
    cout << m << endl;
    for (auto &x : a)
      cout << x << " ";
    cout << endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 12-sequence-game.cpp -o output && ./output

// * testcase

/*
6
3
4 6 3
3
1 2 3
5
1 7 9 5 7
1
144
2
1 1
5
1 2 2 1 1

*/

// * output
/*
6
4 3 2 6 3 3
3
1 2 3
6
1 7 9 3 5 7
1
144
2
1 1
6
1 2 2 1 1 1
*/

