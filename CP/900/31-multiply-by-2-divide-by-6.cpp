/*
 * Multiply by 2, divide by 6
 * 
 * Description:
 * Given a positive integer n, you can perform two types of operations:
 * 1. Multiply n by 2.
 * 2. Divide n by 6 (this operation is allowed only if n is divisible by 6 without a remainder).
 * Your task is to find the minimum number of moves needed to obtain 1 from n, 
 * or determine if it is impossible to do so.
 * 
 * Constraints:
 * 1 <= t <= 2 * 10^4 (number of test cases)
 * 1 <= n <= 10^9
 * 
 * Example 1    :
 * Input        : n = 6
 * Output       : 1
 * Explanation  : The number 6 is divisible by 6. Divide 6 by 6 to get 1 in exactly 1 move.
 * 
 * Example 2    :
 * Input        : n = 9
 * Output       : 2
 * Explanation  : Multiply 9 by 2 to get 18 (1st move). Divide 18 by 6 to get 3 (2nd move). 
 *                Divide 3 by 6 is impossible, so we are stuck. Wait, let's look at the optimal path:
 *                9 * 2 = 18 (move 1)
 *                18 * 2 = 36 (move 2)
 *                36 / 6 = 6 (move 3)
 *                6 / 6 = 1 (move 4)
 *                Total moves = 4.
 *
 * Example 3    :
 * Input        : n = 5
 * Output       : -1
 * Explanation  : 5 is not divisible by 3, so multiplying by 2 or dividing by 6 will never yield a factor of 3 
 *                needed to eventually reduce the number down to 1 using division by 6.
 * 
 * https://codeforces.com/problemset/problem/1374/B
*/

// ! Observation
/*
* When we are told to divide by 6 it actually means that we need to remove all 2 and 3 factors
* since 2*3 = 6.
* So if our number has any factor other than 2 and 3 we'll return -1.
* Eg: 15 = 3^1 + 5^1 (this cannot be made 1 by dividing 6)
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

int solve() {
  ll n;
  cin >> n;
  
  int count_of_2 = 0, count_of_3 = 0;
  
  // * Count how many times n can be divided by 3
  while (n > 0 && n % 3 == 0) {
    count_of_3++;
    n /= 3;
  }
  
  // * Count how many times n can be divided by 2
  while (n > 0 && n % 2 == 0) {
    count_of_2++;
    n /= 2;
  }
  
  // * If n is not reduced to 1 or if there are more divisions by 2 than by 3, 
  // * it's impossible (Eg: 24 = 2^3 + 3^1)
  if (n > 1 || count_of_2 > count_of_3) {
    return -1;
  }
  
  // * Count how many extra factors of 2 is needed (for operation 1) and then divide by 6 (operation 2)
  // * operation 1 = (count_of_3 - count_of_2)
  // * operation 2 = count_of_3
  // * Eg: 36 = 2^1 + 3^2
  return (count_of_3 - count_of_2) + count_of_3;
}

// * Counting Factors
// * Time Complexity (TC): O(log2(n)) = O(30)
// * Space Complexity (SC): O(1)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    int moves = solve();
    cout << moves << "\n"; 
  }
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 31-multiply-by-2-divide-by-6.cpp -o output && ./output

// * testcases
/*
7
1
2
3
12
12345
15116544
387420489

*/

// * Output
/*
0
-1
2
-1
-1
12
36
*/
