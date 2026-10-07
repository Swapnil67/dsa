/*
 * Basketball Together
 * 
 * You have an array of n players, each with a given power level. 
 * You want to form teams to defeat an enemy team with a total 
 * power of D. The power of a team is defined as the number of 
 * players in it multiplied by the maximum power level among 
 * them. Each player can belong to at most one team. Find the 
 * maximum number of teams you can form that strictly defeat the 
 * enemy team (team power > D).
 * 
 * Constraints  : 1 <= n <= 10^5
 *                1 <= D <= 10^9
 *                1 <= P_i <= 10^9 (power of each player)
 * 
 * Example 1    :
 * Input        : n = 6, D = 180, P = [90, 80, 70, 60, 50, 48]
 * Output       : 2
 * Explanation  : We can form 2 teams. 
 *                Team 1: [90, 48] -> Max power 90 * 2 players = 180 (not > 180). 
 *                Instead, pair [90, 48, 50] -> 90 * 3 = 270 > 180 (Valid).
 *                Team 2: [80, 70, 60] -> 80 * 3 = 240 > 180 (Valid).
 * 
 * Example 2    :
 * Input        : n = 1, D = 10, P = [5]
 * Output       : 0
 * Explanation  : The only player has power 5. To exceed 10, we need 5 * players > 10, 
 *                which requires 3 players, but we only have 1.
 *
 * https://codeforces.com/problemset/problem/1725/B
*/

// ! Observation
/*
* Sort powers, use two pointers to form strongest teams.
* Sort the players by power. 
* Use two pointers, left and right, and at each step try to form a team captained by right. 
* Compute how many players are needed; if [left..right] has enough, form the team, add one win, 
* and advance both pointers to consume those players; otherwise, no more teams can be formed.
*/

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

// ! Sorting & Greedy Two pointers
// * Time Complexity (TC): O(nlogn) = O(10^5*log2(10^5)) = O(10^6)
// * Space Complexity (SC): O(n)
int main() {
  ll n, P;
  cin >> n >> P;
  VEC(power, n, ll); READ_VEC(power);
  
  // * Sort the player powers in non-decreasing order
  sort(all(power)); // * O(nlogn)
  
  ll l = -1, r = n - 1;
  ll team_size = 1, wins = 0;
  while (l < r) {
    // * We need bigger team
    if ((power[r] * team_size <= P) && l < r) {
      // * If not, increase the team size by including more players from the left
      team_size++;
      l++;
    }
    else {
	    // * If the team can defeat the enemy, count this team as a win
			wins++;
			// * Move the right pointer to form a new team
			r--;
			// * Reset the team size for the new team
			team_size = 1;
    }
  }
  
  cout << wins << "\n";
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 11-basketball-together.cpp -o output && ./output

// * testcases
/*
6 180
90 80 70 60 50 100
*/

// * Output
/*
2
*/