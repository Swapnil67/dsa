/*
 * Leetcode - 1079
 * Letter Tile Possibilities
 * 
 * You have n  tiles, where each tile has one letter tiles[i] printed on it.
 * 
 * Return the number of possible non-empty sequences of letters you can make using the letters 
 * printed on those tiles.

 * Example 1
 * input       : tiles = "AAB"
 * output      : 8
 * Explanation : The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

 * Example 2
 * input       : tiles = "AAABBC"
 * output      : 188

 * Example 3
 * input       : tiles = "S"
 * output      : 1
 * 
 * https://leetcode.com/problems/letter-tile-possibilities/description/
*/

// ! Amazon, Google

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

void solveBrute(
    string &s,
    string cur,
    vector<bool> &used,
    unordered_set<string> &ans)
{
  ans.insert(cur); // * Add to set
  // cout << cur << endl;

  for (int i = 0; i < s.size(); ++i) {
    if (used[i]) // * prevent using repetative index
      continue;

    used[i] = true;
    cur.push_back(s[i]);

    solveBrute(s, cur, used, ans);

    used[i] = false;
    cur.pop_back();
  }
}

void solve(int &total, vector<int> &freq_vec) {
  total++;
  for (int i = 0; i < 26; ++i) {
    if (freq_vec[i] == 0)
      continue;

    freq_vec[i]--;
    solve(total, freq_vec);
    freq_vec[i]++;
  }
}

// * ------------------------- Approach 1 : Brute Force Approach -------------------------
// * Subsets + Permutation
// * TIME COMPLEXITY O(n!)
// * SPACE COMPLEXITY O(n! * n)
int bruteForce(string tiles) {
  int n = tiles.length();
  vector<bool> used(n, false);
  unordered_set<string> ans;
  solveBrute(tiles, "", used, ans);
  return ans.size() - 1; // * exclude the empty sequence
}

// * ------------------------- Approach 2 : Optimal Approach -------------------------
// * TIME COMPLEXITY O(n!)
// * SPACE COMPLEXITY O(1)
int numTilePossibilities(string tiles) {
  // * Count freq of each char
  vector<int> freq_vec(26, 0);
  for (char &c : tiles) {
    freq_vec[c - 'A']++;
  }

  int total = 0;
  solve(total, freq_vec);
  return total - 1;
}

int main(void) {
  string s = "AAB";
  cout << "Input string: " << s << endl;

  // int ans = bruteForce(s);
  int ans = numTilePossibilities(s);
  cout << "Letter Tile Possibilities " << ans << endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 10-letter-tile-possibilities.cpp -o output && ./output