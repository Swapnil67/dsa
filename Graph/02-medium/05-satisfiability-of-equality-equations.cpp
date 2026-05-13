/*
 * Leetcode - 990
 * Satisfiability of Equality Equations
 *
 * You are given an array of strings equations that represent relationships between variables where each
 * string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".
 * Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

 * Return true if it is possible to assign integers to variable names so as to satisfy all the given equations
 * or false otherwise.

 * Example 1  :
 * Input      : equations = ["a==b","b!=a"]
 * Output     : false
 * 
 * Example 2  :
 * Input      : equations = ["b==a","a==b"]
 * Output     : true
 * 
 * https://leetcode.com/problems/satisfiability-of-equality-equations/description/
 * 
 */

// ! DSU

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
    if (i != n - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

int find(int x, vector<int> &parent) {
  if (x == parent[x])
    return x;
  return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank) {
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);

  // * Already in same set
  if (x_parent == y_parent)
    return;

  if (rank[x_parent] > rank[y_parent]) {
    parent[y_parent] = x_parent; 
  }
  else if (rank[x_parent] < rank[y_parent]) {
    parent[x_parent] = y_parent; 
  }
  else {
    parent[x_parent] = y_parent; 
    rank[y_parent]++;
  }
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool equationsPossible(vector<string>& equations) {
  int N = 26;

  // * Initialize rank and parent vectors
  vector<int> rank(N, 0), parent(N);
  for (int i = 0; i < N; ++i) {
    parent[i] = i;
  }

  // * Group all the '==' equation first
  for (auto &s : equations) {
    if (s[1] == '=') {
      int a = s[0] - 'a', b = s[3] - 'a';
      // cout << a << " " << b << endl;
      Union(a, b, parent, rank);
    }
  }
  
  // * Check if parent of '!=' equations are same
  for (auto &s : equations) {
    if (s[1] == '!') {
      int a = s[0] - 'a', b = s[3] - 'a';
      int a_parent = find(a, parent);
      int b_parent = find(b, parent);
      // cout << a_parent << " " << b_parent << endl;

      if (a_parent == b_parent)
        return false;
    }
  }

  return true;
}

int main(void) {
  // * testcase 1
  // vector<string> equations = {"a==b", "b!=a"};

  // * testcase 2
  // vector<string> equations = {"a==b", "b==a"};

  // * testcase 3
  // vector<string> equations = {"a==b", "b!=c", "c==a"};

  // * testcase 4
  vector<string> equations = {"c==c", "b==d", "x!=z"};

  cout << "Equations: " << endl;
  printArr(equations);

  bool ans = equationsPossible(equations);
  cout << "Ans: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-satisfiability-of-equality-equations.cpp -o output && ./output