/*
 * Leetcode - 983
 * Minimum Cost For Tickets
 * 
 * 
 * Example 1    :
 * Input        : days = [1,4,6,7,8,20], costs = [2,7,15]
 * Output       : 11
 * Explanation  : On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
 *                On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
 *                On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
 *                In total, you spent $11 and covered all the days of your travel.
 * 
 * Example 2    :
 * Input        : days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
 * Output       : 17
 * Explanation  : On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
 *                On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
 *
 * https://leetcode.com/problems/minimum-cost-for-tickets/description/
 * https://neetcode.io/problems/minimum-cost-for-tickets/question
*/

// ! Google, Meta, Amazon, Microsoft, Uber, TikTok

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * without memoization
int dfs(int i, vector<int> &days, vector<int> &costs) {
	int n = days.size();
	if (i >= n)
		return 0;

	int costDay = costs[0] + dfs(i + 1, days, costs);

	// * skip till ith day is curr_day+7 as we are buying week pass
	int j = i;
	while (j < n && days[i] + 7 > days[j])
		j++;
	int costWeek = costs[1] + dfs(j, days, costs);

	// * skip till ith day is curr_day+30 as we are buying month pass
	j = i;
	while (j < n && days[i] + 30 > days[j])
		j++;
	int costMonth = costs[2] + dfs(j, days, costs);

	return min({costDay, costWeek, costMonth});
}

// * with memoization
int dfs(int i, vector<int> &days, vector<int> &costs, vector<int> &dp) {
	int n = days.size();
	if (i >= n)
		return 0;

	if (dp[i] != -1)
		return dp[i];

	int costDay = costs[0] + dfs(i + 1, days, costs, dp);

	// * skip till ith day is curr_day+7 as we are buying week pass
	int j = i;
	while (j < n && days[i] + 7 > days[j])
		j++;
	int costWeek = costs[1] + dfs(j, days, costs, dp);

	// * skip till ith day is curr_day+30 as we are buying month pass
	j = i;
	while (j < n && days[i] + 30 > days[j])
		j++;
	int costMonth = costs[2] + dfs(j, days, costs, dp);

	return dp[i] = min({costDay, costWeek, costMonth});
}


// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * Recursion
// * TIME COMPLEXITY O(3^n)
// * SPACE COMPLEXITY O(n) 
int bruteForce(vector<int> &days, vector<int> &costs) {
	return dfs(0, days, costs);
}

// * ------------------------- Approach 2: Better Approach -------------------------
// * Recursion + Memoization (Top Down)
// * TIME COMPLEXITY O(max_days)
// * SPACE COMPLEXITY O(n)
int betterApproach(vector<int> &days, vector<int> &costs) {
	vector<int> dp(days.size() + 1, -1);
	return dfs(0, days, costs, dp);
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(max_days)
// * SPACE COMPLEXITY O(n)
int mincostTickets(vector<int> &days, vector<int> &costs) {
	int n = days.size();
	unordered_set<int> st(begin(days), end(days));
	
	int last_day = days.back();
	// * t[i] = min cost to travel to date 'i'
	vector<int> t(last_day + 1, 0);
	t[0] = 0;
	for (int i = 1; i <= last_day; ++i) {
		if (!st.count(i)) { // * not travelling this day
			t[i] = t[i - 1]; // * skip
 			continue;
		}

		t[i] = INT_MAX; // * lets assume that current day cost is INT_MAX

		int day_1_pass = t[max(0, i - 1)] + costs[0];
		int day_7_pass = t[max(0, i - 7)] + costs[1];
		int day_30_pass = t[max(0, i - 30)] + costs[2];

		t[i] = min({day_1_pass, day_7_pass, day_30_pass});
	}

	return t[last_day];
}


int main(void) {
	// * testcase 1
	vector<int> days = {1, 4, 6, 7, 8, 20}, costs = {2, 7, 15};

	// * testcase 2
	// vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}, costs = {2, 7, 15};

	cout << "Days: ";
	printArr(days);
	cout << "Costs: ";
	printArr(costs);

	// int ans = bruteForce(days, costs);
	// int ans = betterApproach(days, costs);
	int ans = mincostTickets(days, costs);
	cout << "Minimum cost: " << ans << endl;

	return 0;
}
 
// * Run the code
// * g++ --std=c++20 16-minimum-cost-for-tickets.cpp -o output && ./output
