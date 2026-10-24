/*
 * Divan and a New Project
 * 
 * You are given an integer n and an array a of length n, where a[i] represents
 * the number of times building (i + 1) needs to be visited over the next ten years.
 *
 * There are n + 1 buildings in total, numbered from 0 to n. Building 0 is the 
 * main headquarters. You need to assign an integer coordinate x[i] to each building 
 * i (for 0 <= i <= n) on a 1-dimensional coordinate line such that:
 * 1. All assigned coordinates are distinct: x[i] != x[j] for all i != j.
 * 2. The total time spent walking between the headquarters and all buildings is minimized.
 *
 * Walking between building 0 (at x[0]) and building i (at x[i]) takes |x[0] - x[i]| minutes 
 * each way. Since each visit requires a round trip, visiting building i a[i] times takes 
 * 2 * |x[0] - x[i]| * a[i] minutes.
 * 
 * Return the minimum total walking time along with an array x representing valid 
 * distinct coordinates for buildings 0 through n.
 * 
 * Constraints:
 * 1 <= n <= 2 * 10^5
 * 0 <= a[i] <= 10^6
 * The sum of n over all test cases does not exceed 2 * 10^5.
 * 
 * Example 1    :
 * Input        : n = 3, a = [2, 4, 3]
 * Output       : min_time = 18, x = [0, -2, 1, -1]
 * Explanation  : Place building 0 at coordinate 0:
 *                - Building 2 (a[1] = 4) is placed at 1 -> cost: 2 * |0 - 1| * 4 = 8
 *                - Building 3 (a[2] = 3) is placed at -1 -> cost: 2 * |0 - (-1)| * 3 = 6
 *                - Building 1 (a[0] = 2) is placed at -2 -> cost: 2 * |0 - (-2)| * 2 = 8
 *                Total walking time is 8 + 6 + 4 = 18 minutes (if placed at 1, -1, 2).
 *                Any placement achieving the minimum total cost of 18 is valid.
 * 
 * Example 2    :
 * Input        : n = 5, a = [2, 1, 10, 2, 5]
 * Output       : min_time = 44, x = [0, 2, -3, 1, -2, -1]
 * Explanation  : Place building 0 at coordinate 0.
 *                Sorting frequencies in descending order gives [10, 5, 2, 2, 1].
 *                Assign closest distances {1, -1, 2, -2, 3}:
 *                - Building 3: dist = 1, cost = 2 * 1 * 10 = 20
 *                - Building 5: dist = 1, cost = 2 * 1 * 5 = 10
 *                - Building 1: dist = 2, cost = 2 * 2 * 2 = 8
 *                - Building 4: dist = 2, cost = 2 * 2 * 2 = 8
 *                - Building 2: dist = 3, cost = 2 * 3 * 1 = 6
 *                Minimum total cost = 20 + 10 + 8 + 8 + 6 = 44 (or 42 depending on duplicate ties).
 * 
 * https://codeforces.com/problemset/problem/1614/B
*/

// ! Observation
/*
* Sort buildings by visits, alternate coordinates symmetrically.
*/

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

void solve(void) {
  ll n;
  cin >> n;

  // * Read the number of visits for each building
  VEC(visits, n, ll); READ_VEC(visits);

	// * Create a vector of pairs to map visits to their original indices
  VEC(building_map, n, pair<ll,ll>);
  for (int i = 0; i < n; ++i) {
    building_map[i] = {visits[i], i};
  }
  
  // * Sort the buildings by the number of visits in descending order
  sort(rbegin(building_map), rend(building_map));
  // for (auto &it: building_mp) cout << it.first << ' ' << it.second << '\n'; // * For debug
  
  // * Initialize the answer vector with size n+1 (including headquarters)
  VEC(ans, n + 1, ll);
  
  // * Headquarters is at coordinate 0
  ans[0] = 0;
  
  ll minutes = 0;
  ll coordinate = 1;
  for (int i = 0; i < n; ++i) {
    // * Assign coordinates to buildings based on sorted visits
		ans[building_map[i].second + 1] = coordinate; // * Add 1 since building starts from 1

		// * Calculate the time spent walking to this building
		minutes += (2 * abs(coordinate) * building_map[i].first);
		
		// * Alternate the coordinate placement between positive and negative
		if (coordinate < 0) {
		  coordinate = abs(coordinate) + 1;
		} else {
		  coordinate = -coordinate;
		}
  }
  
  // * Output the total minutes spent walking
	cout << minutes << '\n';
	// * Output the coordinates of the buildings
	for (auto it : ans)
		cout << it << " ";
	cout << '\n';
	
} 

// ! Greedy With sorting
// * Time Complexity (TC): O(nlogn) = O(2*10^5 * log(2*10^5)) = O(10^6)
// * Space Complexity (SC): O(n) = O(2*10^5) = O(10^6)
int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll t;
  cin >> t;

  while (t--) {
    solve();
  }
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 19-divan-and-a-new-project.cpp -o output && ./output

// * testcases
/*
4
3
1 2 3
5
3 8 10 6 1
5
1 1 1 1 1
1
0

*/

// * Output
/*
14
2 4 1 3
78
1 -1 0 2 3 4
18
3 6 1 5 2 4
0
1 2
*/
