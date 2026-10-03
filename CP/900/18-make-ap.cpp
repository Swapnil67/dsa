/*
 * NAME         : Make AP
 * 
 * Description  : Given three positive integers a, b, and c. You can multiply one 
 *                (and only one) of these integers by a positive integer m (m >= 1) 
 *                exactly once. Determine if it is possible to make the sequence 
 *                a, b, c an arithmetic progression in that exact order (i.e., b - a = c - b).
 * 
 * Constraints  : 
 *                - 1 <= t <= 10^4 (Number of test cases)
 *                - 1 <= a, b, c <= 10^8
 * 
 * Example 1    :
 * Input        : a = 10, b = 5, c = 30
 * Output       : YES
 * Explanation  : We can choose m = 7 and multiply b by 7. The sequence becomes 
 *                10, 35, 30, which forms an arithmetic progression because 35 - 10 = 30 - 35 = -5.
 * 
 * Example 2    :
 * Input        : a = 30, b = 5, c = 10
 * Output       : YES
 * Explanation  : We can choose m = 7 and multiply b by 7. The sequence becomes 
 *                30, 35, 10, which forms an arithmetic progression because 35 - 30 = 10 - 35 = -25.
 * 
 * Example 3    :
 * Input        : a = 1, b = 2, c = 3
 * Output       : YES
 * Explanation  : The sequence 1, 2, 3 is already an arithmetic progression, so we 
 *                can choose m = 1 and multiply any element by 1.
 * 
 * Example 4    :
 * Input        : a = 1, b = 2, c = 4
 * Output       : NO
 * Explanation  : There is no positive integer m that can multiply one of the elements 
 *                to make the sequence an arithmetic progression.
 *
 * Link         : https://codeforces.com/problemset/problem/1624/B
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation

/*
* a b c => AP 
* b - a = d
* c - b = d'
* 
* d == d'                 -------- eq1
*
* We can multiply any one by some number let's say 'm' 
* So we need to find possible m for all three
*
* CASE 1: Multiply some number by a
*
* a.m b c
* d  = c - b
* d' = b - a.m
*
* From eq1 we can say
* 
* c - b = b - a.m
* a.m = 2.b - c
* m = (2.b - c) / a
* Therefore m > 0 && (2.b - c) % a == 0
*
* CASE 2: Multiply some number by b
* a   b.m   c
* d  = c - b.m   |   d' = b.m - a
* 
* So for above eq its difficult to solve since we've 'm' unknown in both equations
* Let's see a different way
* We know the this    d == d'

*      d           d'
* -----------------------
* a          b          c
* -----------------------
*           d''
* we can say d'' = (c - a)
* 
* so d = d' = (d'' / 2) 
*             (c - a) / 2
* 
* now from d' = b.m - a
* (c - a)/2 = b.m - a
* b.m = (c - a)/2 + a
* m = ((a + c) / 2) / b

* CASE 3: Multiply some number by c
* 
* Same as CASE 1.
* 
*/

string solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  
  if ((b - a) == (c - b)) 
    return "YES";
    
  // * Case 1: (Multiply some number with 'a')
  ll new_a = 2 * b - c;
  if (new_a / a > 0 && new_a % a == 0) 
    return "YES";
    
  // * Case 2: (Multiply some number with 'b')
  ll new_b = (a + c) / 2;
  if (new_b / b > 0 && new_b % b == 0 && (c - a) % 2 == 0)
    return "YES";
  
  // * Case 3: (Multiply some number with 'c')
  ll new_c = 2 * b - a;
  if (new_c / c > 0 && new_c % c == 0) 
    return "YES";
  
  return "NO";
}

// * TC = O(n)
// * SC = O(n) (Input array)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    string ans = solve();
    cout << ans << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 18-make-ap.cpp -o output && ./output

// * testcases
/*
11
10 5 30
30 5 10
1 2 3
1 6 3
2 6 3
1 1 1
1 1 2
1 1 3
1 100000000 1
2 1 1
1 2 2

*/

// * Output
/*
YES
YES
YES
YES
NO
YES
NO
YES
YES
NO
YES
*/