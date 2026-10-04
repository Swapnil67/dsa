/*
 * Goals of Victory
 * 
 * Description
 * There are n teams in a football tournament where each pair of teams plays against 
 * each other exactly once. For any match, both teams score a certain number of goals.
 * The efficiency of a team is defined as the total number of goals scored by that team 
 * across all its matches minus the total number of goals scored by its opponents 
 * in those same matches.
 * 
 * You are given an array efficiencies of length n - 1, representing the efficiencies of 
 * n - 1 teams. One team's efficiency is missing. Find and return the efficiency of 
 * the missing team. It can be mathematically proven that this missing value is unique.
 * 
 * Constraints:
 * 2 <= n <= 100
 * -100 <= efficiencies[i] <= 100
 * The total number of goals scored in the entire tournament does not exceed 250,000.
 * 
 * Example 1    :
 * Input        : efficiencies = [3, -4, 5], n = 4
 * Output       : -4
 * Explanation  : The sum of the given efficiencies is 3 + (-4) + 5 = 4. 
 *                Since the net sum of all team efficiencies in a tournament must always 
 *                equal 0 (every goal scored by one team is a goal conceded by an opponent), 
 *                the missing efficiency must be 0 - 4 = -4.
 * 
 * Example 2    :
 * Input        : efficiencies = [-30, 12, -15, 25], n = 5
 * Output       : 8
 * Explanation  : The sum of the given efficiencies is (-30) + 12 + (-15) + 25 = -8. 
 *                To bring the overall tournament sum back to 0, the final missing 
 *                team's efficiency must be 8.
 * 
 * https://codeforces.com/problemset/problem/1877/A
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation
// * Assume we have [a1, a2, a3] and we need to find a4 efficiency
// * sum = a1 + a2 + a3 + a4
// * a4 = sum - (a1 + a2 + a3);

// * We can say that sum or all the efficiency is equal to 0
// * a4 = -(a1 + a2 + a3)

int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    
    int missing_freq = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
        missing_freq += a[i];
    }
    
    cout << -missing_freq << endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-goals-of-victory.cpp -o output && ./output

// * testcase

/*
2
4
3 -4 5
11
-30 12 -57 7 0 -81 -68 41 -89 0

*/


// * output
/*
-4
265

*/

