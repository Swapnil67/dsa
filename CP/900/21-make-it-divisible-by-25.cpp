/*
 * NAME         : Make it Divisible by 25
 * 
 * Description  : You are given a positive integer n. In one move, you can remove 
 *                any single digit from the number. Leading zeros resulting from 
 *                removals are automatically ignored. Your task is to find the 
 *                minimum number of moves required to make the remaining number 
 *                divisible by 25 and strictly positive. It is guaranteed that 
 *                a valid answer always exists for the given input.
 * 
 * Constraints  : 
 *                - 1 <= t <= 10^4 (Number of test cases)
 *                - 25 <= n <= 10^18 (The given integer does not contain leading zeros)
 * 
 * Example 1    :
 * Input        : n = 100
 * Output       : 0
 * Explanation  : The number 100 is already divisible by 25, so 0 moves are needed.
 * 
 * Example 2    :
 * Input        : n = 71345
 * Output       : 3
 * Explanation  : We can remove the digits 1, 3, and 4 to obtain the number 75, 
 *                which is divisible by 25.
 *
 * https://codeforces.com/problemset/problem/1593/B
 * https://leetcode.com/problems/minimum-operations-to-make-a-special-number/description/
*/

// ! Observation 
/*
* Check from end of n for '00', '25', '50', '75'; count non-matching digits as operations.

* Loop from the back and keep checking occurence of last 2 digits divisible by 25 which are mentioned above
* all the other number count as a delete operations. Do this for all 4 possible values.
* Return the minimum from all 4 operations.

* s = "71345"
* Here we have 75 as last two digits but for that we first need to remove "134" hence our ops become 3.
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

int check_ops(string s, string p) {
  int n = s.length();
  
  int ops = 0;
  int checker_idx = p.length() - 1;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == p[checker_idx]) {
      checker_idx--;
      if (checker_idx < 0)
        break;
    }
    else {
      ops++;
    }
  }
  
  if (checker_idx >= 0)
    return 1e10;
 
  return ops;
}

// * TC = O(n) (num string length)
// * SC = O(1)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    
    vector<string> possible_values = {"00", "25", "50", "75"};
    int min_ops = s.length() + 1;
    for (auto &p: possible_values) {
      min_ops = min(min_ops, check_ops(s, p));
    }

    cout << min_ops << "\n";
  }
  return 0;
}


// * Run the code
// * g++ --std=c++20 21-make-it-divisible-by-25.cpp -o output && ./output

// * testcases
/*
5
100
71345
3259
50555
2050047

*/

// * Output
/*
0
3
1
3
2
*/

// * Explanation
/*
* In the first test case, it is already given a number divisible by 25.
* 
* In the second test case, we can remove the digits 1, 3, and 4 to get the number 75.
* 
* In the third test case, it's enough to remove the last digit to get the number 325.
* 
* In the fourth test case, we can remove the three last digits to get the number 50.
* 
* In the fifth test case, it's enough to remove the digits 4 and 7.
*/