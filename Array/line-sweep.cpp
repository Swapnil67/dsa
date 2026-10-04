/*
 * Leetcode -  
 * NAME
 * 
 * Description
 * 
 * Example 1    :
 * Input        : nums = [-1,1,2,3,1], target = 2
 * Output       : 3
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 * 
 * Example 2    :
 * Input        : nums = [-6,2,5,-2,-7,-1,3], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 * 
*/

#include <map>
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

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
void findPoints(vector<vector<ll>> intervals) {
  vector<pair<ll, ll>> pos;
  for (auto &it: intervals) {
    ll s = it[0], e = it[1];
    pos.push_back({s, 0});
    pos.push_back({e, 1});
  }
  sort(all(pos));

  // * For debug
  // for (auto &p : pos) cout << p.first << " " << p.second << endl;

  // * {point: intersections}
  map<ll, ll> mp;
  ll c = 0;
  for (auto &p: pos) {
    if (p.second == 0) {
      c += 1; // * A range is starting
      mp[p.first] = c;
    } else {
      if (!mp.count(p.first))
        mp[p.first] = c;
      c -= 1; // * A range is ending
    }
  }

  // * Check what are the intersections of each points
  cout << "Intersection Points" << endl;
  for (auto &it : mp)
    cout << it.first << ": " << it.second << endl;
}

int main(void) {
  // * testcase 1
  vector<vector<ll>> intervals = {{1, 7}, {5, 11}, {7, 9}};

  // * testcase 2

  cout << "intervals: " << endl;
  for (auto &l : intervals)
    printArr(l);

  findPoints(intervals);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 line-sweep.cpp -o output && ./output
