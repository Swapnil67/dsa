/*
 * Leetcode - 4057
 * Number of Intersecting Interval Pairs II
 * 
 * Description:
 * Given a 2D integer array `intervals` of `n` elements representing closed intervals `[start_i, end_i]`, 
 * return the number of pairs of indices `(i, j)` with `0 <= i < j < n` where the intervals intersect. 
 * Two intervals intersect if they share at least one point, including endpoints.
 * 
 * 
 * Example 1    :
 * Input        : intervals = [[1,2],[2,3],[3,4]]
 * Output       : 2
 * Explanation  : There are 2 pairs of indices that satisfy the conditions in the statement:
 *                - Intervals [1, 2] and [2, 3] intersect at the point 2.
 *                - Intervals [2, 3] and [3, 4] intersect at the point 3.
 * 
 * Example 2    :
 * Input        : intervals = [[1,5],[2,4],[3,6]]
 * Output       : 3
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 *                - The intersection of [1, 5] and [2, 4] is [2, 4].
 *                - The intersection of [1, 5] and [3, 6] is [3, 5].
 *                - The intersection of [2, 4] and [3, 6] is [3, 4].
 * 
 * https://leetcode.com/problems/number-of-intersecting-interval-pairs-i/
*/

// ! Leetcode Contest

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

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

// * INTUITION FOR COUNTING INTERSECTING INTERVALS:

// * STRATEGY USED:
// *
// * 1. Sweep-Line Algorithm (or Event-Driven Simulation): 
// *    Flattening 2D spatial objects (intervals) into discrete 1D events (Start/End) 
// *    and processing them sequentially along a sorted timeline.
// *
// * 2. Complementary Counting (Inclusion-Exclusion Principle): 
// *    Solving the problem backward by calculating the total possible combinations 
// *   and subtracting the invalid cases (non-intersecting pairs) to find the target answer.

// *
// * 1. The Problem: Checking every interval against every other interval takes O(N^2) time, which is too slow.
// *
// * 2. The Trick (Complementary Counting): Instead of counting pairs that DO overlap, count pairs that DO NOT overlap, 
// *    and subtract them from the total possible pairs.
// *    * Total Pairs = N * (N - 1) / 2
// *    * Intersecting Pairs = Total Pairs - Non-Intersecting Pairs
// *
// * 3. The Sweep-Line Strategy: Flatten 2D intervals into a 1D timeline of Start (0) and End (1) events, 
// *    then sort them from left to right.
// *
// * 4. Walking the Timeline: Keep a counter (done) of how many intervals have completely finished. 
// *    * Every time a new interval starts, any interval already finished (done) cannot possibly touch it. 
// *    * Subtract the 'done' count from your total pairs to remove these non-intersecting combinations.
// *
// * 5. Edge Cases: Marking Start = 0 and End = 1 ensures that if a start and end happen at the exact same coordinate, 
// *    Start is processed first. This automatically counts touching intervals (like [1, 5] and) as intersecting.
// *
// * 6. Complexity: Time: O(N log N) (due to sorting) | Space: O(N) (to store events).


// * TIME COMPLEXITY O(N*logN)
// * SPACE COMPLEXITY O(N)
long long countIntersectingIntervals(vector<vector<int>> &intervals) {
  // * Sweep-Line Algorithm
  vector<pair<int, int>> pos;
  pos.reserve(intervals.size() * 2); // Optimization: Pre-allocate memory
  for (auto &A : intervals) {
    pos.push_back({A[0], 0}); // 0 represents Start
    pos.push_back({A[1], 1}); // 1 represents End
  }
  sort(pos.begin(), pos.end());

  long long n = intervals.size();
  long long res = n * (n - 1) / 2; // Total possible pairs
  long long done = 0;

  // * Remove the pairs which ended before starting new interval
  for (auto &p : pos) {
    res -= (p.second == 0) ? done : 0;
    done += p.second; // Increments only on End events (1)
  }

  return res;
}

int main(void) {
  return 0;
}


// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

