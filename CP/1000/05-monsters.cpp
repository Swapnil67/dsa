/*
 * NAME
 * Monsters
 * 
 * Description:
 * There are n monsters standing in a row, numbered 1 to n. The i-th monster has a_i health points. 
 * Monocarp deals k damage to the monster with the highest health. If multiple monsters have the 
 * highest health, he attacks the one with the smallest index. A monster dies when its health 
 * drops to 0 or less. Output the order in which the monsters die.
 * 
 * Constraints:
 * 1 <= t <= 10^4 (number of test cases)
 * 1 <= n <= 3 * 10^5 (number of monsters)
 * 1 <= k <= 10^9 (damage per attack)
 * 1 <= a_i <= 10^9 (health points)
 * The sum of n over all test cases does not exceed 3 * 10^5.
 * 
 * Example 1    :
 * Input        : n = 3, k = 2, a = [1, 2, 3]
 * Output       : [2, 1, 3]
 * Explanation  : 
 * - The health points are initially [1, 2, 3]. Highest health is monster 3 (hp=3). Damage dealt: [1, 2, 1].
 * - Highest health is monster 2 (hp=2). Damage dealt: [1, 0, 1]. Monster 2 dies first.
 * - Remaining are [1, 0, 1]. Monsters 1 and 3 tie at hp=1. Monster 1 has smaller index, so it is attacked: [0, 0, 1]. Monster 1 dies second.
 * - Remaining is [0, 0, 1]. Monster 3 is attacked: [0, 0, -1]. Monster 3 dies third.
 * 
 * Example 2    :
 * Input        : n = 4, k = 3, a = [9, 8, 2, 4]
 * Output       : [1, 4, 2, 3]
 * Explanation  : The monsters die in the exact sequence of 1, 4, 2, and lastly 3.
 *
 * Link 
 * https://codeforces.com/problemset/problem/1849/B
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))

// * Time Complexity (TC): O(nlogn) = O(3*10^5log(3*10^5)) = O(10^6)
// * Space Complexity (SC): O(n)
int main() {
	int t;
	cin >> t; // Read the number of test cases
	while (t--) {
		long long n, k;
		cin >> n >> k; // Read the number of monsters and the damage value

		// Vector to store pairs of health points and their respective indices
		vector<pair<long long, long long>> health_points(n);
    
		for (long long i = 0; i < n; i++) { // * Loop through each monster
			long long x;
			cin >> x; // * Read the initial health points of each monster
			// * Store the health points and index (1-based) as a pair
			health_points[i] = {x, i + 1};
		}

		// * Adjust the health points to determine the effective health after damage
		for (long long i = 0; i < n; i++) {
			// * Calculate the remainder of health points when divided by k
			health_points[i].first = health_points[i].first % k;
			// * If the remainder is 0, set it to k to handle full damage cases
			if (health_points[i].first == 0)
				health_points[i].first = k;
		}

		// * Sort the monsters based on effective health and index
		// * Sort in descending order of effective health, and ascending order of index if health is the same
		sort(health_points.begin(), health_points.end(), [&](pair<long long, long long> a, pair<long long, long long> b) {
			if (a.first != b.first)
				return a.first > b.first;
			return a.second < b.second;
		});

		// Output the indices of monsters in the order they die
		for (auto it : health_points)
			cout << it.second << " ";
		cout << endl;
	}
	return 0;
}

// * Run the code
// * g++ --std=c++20 05-monsters.cpp -o output && ./output

// * testcases
/*
3
3 2
1 2 3
2 3
1 1
4 3
2 8 3 5

*/

// * Output
/*
2 1 3 
1 2 
3 1 2 4 
*/