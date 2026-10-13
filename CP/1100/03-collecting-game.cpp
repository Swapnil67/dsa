/*
 * Collecting Game
 * 
 * You are given an array `nums` of `n` positive integers. You start a game with an initial 
 * score. If your current score is greater than or equal to any element in the array that 
 * has not been removed yet, you can choose to remove that element and add its value to 
 * your score. 
 * 
 * For each index `i` (0-indexed), calculate the maximum number of *other* elements you can 
 * remove if your initial score is equal to `nums[i]`. Note that the initial element at 
 * index `i` is automatically removed and added to your score at the start.
 * 
 * Constraints:
 * - 1 <= t <= 5000 (Number of test cases)
 * - 1 <= n <= 10^5 (Length of the array)
 * - 1 <= nums[i] <= 10^9
 * - The sum of `n` over all test cases does not exceed 10^5.
 * 
 * Example 1    :
 * Input        : nums = [20, 5, 1, 4, 2]
 * Output       : [4, 3, 0, 2, 1]
 * Explanation  : 
 * - For i = 0 (nums[0] = 20): Initial score becomes 20. You can remove all other 4 elements.
 * - For i = 1 (nums[1] = 5): Initial score becomes 5. You can remove 1, 2, 4 (score becomes 5+1+2+4 = 12). 12 is less than 20, so you stop. Total removed: 3 elements.
 * - For i = 2 (nums[2] = 1): Initial score is 1. You cannot remove any other element. Total removed: 0 elements.
 * - For i = 3 (nums[3] = 4): Remove 1 and 2 (score becomes 4+1+2 = 7). Then remove 5 (score becomes 7+5 = 12). Stops before 20. Total removed: 2 elements.
 * - For i = 4 (nums[4] = 2): Remove 1 (score becomes 2+1 = 3). Stops before 4. Total removed: 1 element.
 * 
 * Example 2    :
 * Input        : nums = [1, 1, 1]
 * Output       : [2, 2, 2]
 * Explanation  : For any element chosen, the score becomes 1, which allows removing the other two 1s sequentially.
 *
 * Link to similar problems on LeetCode:
 * - [LeetCode 2141: Maximum Running Time of N Computers](https://leetcode.com "LeetCode 2141") (Prefix sums + Greedy/Binary Search)
 * - [LeetCode 2261: K Divisible Elements Subarrays](https://leetcode.com "LeetCode 2261")
 * - [LeetCode 2594: Minimum Time to Repair Cars](https://leetcode.com "LeetCode 2594")
 * 
 * https://codeforces.com/problemset/problem/1904/B
*/


#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

// Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// ! Observation
/*
* a = [20, 5, 1, 4, 2]
*
* We'll create vector of pairs {a[i], i} & sort it
* v = [(1, 2) (2, 4) (4, 3) (5, 1) (20, 0)]
*
* We'll also have a prefix sum vector
* pre = [1, 3, 7, 12, 32]
*
* Now for every i from 0 - (n - 1), we'll check how many elements we can remove.
* found += idx - j

* Eg:
* ------------------------------
* j: 2, found = 2;
* (8, -2147483648) => lower bound idx: 4
* idx = 4 - 1 = 3
* found += 3 - 2 = 3
* There we can remove 1 more element from the right part.

* now j = idx
* j: 3, found = 3
* (13, -2147483648) => lower bound idx: 4
* idx = 4 - 1 = 3
* Here we can see that our idx == j so here we'll break since we cannot find more larger elements than 'j' on right.
* ------------------------------

* For j = 3 we can remove 3 elements from array
*/

// ! TLE
// ! This will not works sinces a[i] > 1e9
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
void bruteForce() {
  ll n;
  cin >> n;
  VEC(a, n, ll); READ_VEC(a);

  // * Sort in non-decreasing order
  VEC(nums, n, pair<ll, ll>);
  for (int i = 0; i < n; ++i) {
    nums[i] = {a[i], i};
  }
  sort(all(nums));

  VEC(ans, n, ll);
  // * For every idx 'i' find which elements it can remove and gain points.
  for (int i = 0; i < n; ++i) {
    int score = nums[i].first;
    // cout << "score: " << score << ", idx: " << nums[i].second << "\n";
    int points = 0;
    for (int j = 0; j < n; ++j) {
      if (i != j && score > nums[j].first) {
        score += nums[j].first;
        points++;
      }
    }
    ans[nums[i].second] = points;
  }  
  
  for (auto &p: ans) 
    cout << p << " ";
  cout << "\n";
}

void optimalApproach() {
  ll n;
  cin >> n;
  ll a;
  VEC(v, n, pair<ll, ll>);
  for (size_t i= 0; i < n; ++i) {
    cin >> a;
    v[i] = {a, i};
  }
  sort(all(v));
  
  // * Calculate prefix sums
  VEC(pre, n, ll);
  pre[0] = v[0].first;
  for (size_t i= 1; i < n; ++i) {
    pre[i] = pre[i - 1] + v[i].first;
  }

  VEC(ans, n, ll);
	// * Calculate the maximum number of additional elements that can be removed
  for (size_t i = 0; i < n; ++i) { // * O(nlogn)
    ll j = i;  
    ll found = i; // * since we can already remove elements smaller than 'i'
    while (j < n) { // * We need the check for all the prefix sums from 'j'
      pair<ll, ll> temp = {pre[j] + 1, INT_MIN};
      ll idx = lower_bound(begin(v), end(v), temp) - begin(v);
      idx--;
      if (idx == j)
        break;
      found += (idx - j);
      j = idx;
    }
    ans[v[i].second] = found;
  }

  // * Output the results for the current test case
  for (size_t i = 0; i < n; ++i) { // * O(n)
    cout << ans[i] << " ";
  } 
  cout << "\n";
} 

// * Greedy With Binary Search
// * Time Complexity (TC): O(nlogn)
// * Space Complexity (SC): O(n)
int main() {
  // Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  while (t--) {
    // bruteForce();
    optimalApproach();
  }
	return 0;
}

// * Run the code
// * g++ --std=c++20 03-collecting-game.cpp -o output && ./output

// * testcases
/*
4
5
20 5 1 4 2
3
1434 7 1442
1
1
5
999999999 999999999 999999999 1000000000 1000000000

*/

// * Output
/*
4 3 0 3 1 
1 0 2 
0 
4 4 4 4 4 
*/