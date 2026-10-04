/*
 * Leetcode - 2251 (Variant: Number of Flowers in Full Bloom)
 * Number of Lamps Illuminating Control Points
 * 
 * Description
 * Imagine that there are several lamps placed on a number line, each of which 
 * illuminates some segment of the line. Specifically, the lamps are represented 
 * in a two-dimensional array lamps, where the i-th lamp covers the segment from 
 * lamps[i][0] to lamps[i][1], inclusive.
 * 
 * Additionally, you are given a list of control points on this number line, 
 * represented by an array points. Your task is to find the number of lamps that 
 * illuminate each control point. Specifically, for each control point points[j] 
 * in the array, your task is to find the number of lamps lamps[i] which include 
 * this point within its covered segment - when points[j] lies inside the segment 
 * [lamps[i][0], lamps[i][1]].
 * 
 * As a result, return an array of integers, where the i-th integer corresponds 
 * to the answer for the i-th control point.
 * 
 * Example 1    :
 * Input        : lamps = [[1, 7], [5, 11], [7, 9]], points = [7, 1, 5, 10, 9, 15]
 * Output       : [3, 1, 2, 1, 2, 0]
 * Explanation  : 
 * - point[0] = 7 is illuminated by all three lamps: 7 lies in all three segments [1, 7], [5, 11], and [7, 9].
 * - point[1] = 1 is illuminated by lamp[0]: 1 lies inside [1, 7].
 * - point[2] = 5 is illuminated by lamp[0] and lamp[1]: 5 lies inside both [1, 7] and [5, 11].
 * - point[3] = 10 is illuminated by lamp[1]: 10 lies inside [5, 11].
 * - point[4] = 9 is illuminated by lamp[1] and lamp[2]: 9 lies inside both [5, 11] and [7, 9].
 * - point[5] = 15 is not illuminated by any lamps.
 *
 * https://www.desiqna.in/16114/visa-oa-sde-intern-ctc-30-lac-27th-oct
 * https://docs.google.com/document/d/1aVeYtS91K9O6INZk6RjMA25vvN4FQ70AxCa1py937Kk/edit?tab=t.0 
 * https://leetcode.com/problems/number-of-flowers-in-full-bloom/
*/

// ! OA
// ! Visa

#include <vector>
#include <iostream>
#include <unordered_map>

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

// ! Only works under following constraint
// ! 0 <= l, r <= 1e5 (100000) 
// * TIME COMPLEXITY O(N + Q)
// * SPACE COMPLEXITY O(N)
vector<ll> bruteForce(vector<vector<ll>> lamps, vector<ll> points) {
  int N = 20;
  vector<ll> line(N, 0);
  for (auto &lamp: lamps) { // * O(N)
    ll l = lamp[0], r = lamp[1];
    line[l] += 1;
    if (r + 1 < N)
      line[r + 1] += -1;
  }
  printArr(line);

  // * Prefix sum
  for (int i = 1; i < N; ++i) {
    line[i] = line[i - 1] + line[i];
  }
  printArr(line);

  // * Get intersecting lamps
  vector<ll> ans;
  for (auto &p: points) { // * O(Q)
    ans.push_back(line[p]);
  }
  return ans;
}

// * Sweep-Line Algorithm
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
vector<ll> findPoints(vector<vector<ll>> lamps, vector<ll> points) {
  vector<pair<ll, ll>> pos;

  // * First push the intervals
  for (auto &lamp: lamps) {
    int start = lamp[0], end = lamp[1];
    pos.push_back({start, 0});
    pos.push_back({end, 2});
  }
  
  // * Push the points for which we need to find intersection
  for (auto &p: points) {
    pos.push_back({p, 1});
  }
  sort(all(pos));

  // * For debug
  for (auto &p : pos) cout << p.first << " " << p.second << endl;

  // * {point: intersections}
  unordered_map<ll, ll> mp;
  ll c = 0;
  for (auto &p: pos) {
    if (p.second == 0) { 
      c = c + 1; // * range is starting
    } else if (p.second == 1) { 
      mp[p.first] = c; // * Store the intersection of this point
    } else { 
      c = c - 1;  // * range is ending
    }
  }

  // * Get the no of intersections for each point
  vector<ll> ans;
  for (auto &p: points) {
    ans.push_back(mp[p]);
  }
  return ans;
}

int main(void) {
  // * testcase 1
  vector<vector<ll>> lamps = {{1, 7}, {5, 11}, {7, 9}};
  vector<ll> points = {7, 1, 5, 10, 9, 15};

  // * testcase 2

  cout << "lamps: " << endl;
  for (auto &l : lamps)
    printArr(l);

  cout << "points: ";
  printArr(points);
  
  // vector<ll> ans = bruteForce(lamps, points);
  vector<ll> ans = findPoints(lamps, points);
  
  cout << "Answer: ";
  printArr(ans);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 07-no-of-lamps-illuminating-control-points-visa-oa.cpp -o output && ./output

