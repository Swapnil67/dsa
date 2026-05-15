/*
* Leetcode - 2976
* Minimum Cost to Convert String I
*
* You are given two 0-indexed strings source and target, both of length n and consisting of lowercase
* English letters. You are also given two 0-indexed character arrays original and changed, 
* and an integer array cost, where cost[i] represents the cost of changing the character original[i]
* to the character changed[i].

* You start with the string source. In one operation, you can pick a character x from the string and change 
* it to the character y at a cost of z if there exists any index j such that 
* cost[j] == z, original[j] == x, and changed[j] == y.

* Return the minimum cost to convert the string source to the string target using any number of operations. 
* If it is impossible to convert source to target, return -1.

* Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

* Example 1:
* Input         : source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], 
*                 changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
* Output        : 3
* Explanation   : To convert the string "abcd" to string "acbe":
*                 - Change value at index 1 from 'b' to 'c' at a cost of 5.
*                 - Change value at index 2 from 'c' to 'e' at a cost of 1.
*                 - Change value at index 2 from 'e' to 'b' at a cost of 2.
*                 - Change value at index 3 from 'd' to 'e' at a cost of 20.
*                 The total cost incurred is 5 + 1 + 2 + 20 = 28.
* 
* Example 2:
* Input         : source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
* Output        : 0

*
* https://leetcode.com/problems/minimum-cost-to-convert-string-i/
*/

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

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

// * ------------------------- Approach 1: Optimal -------------------------
// * Floyd Warshall
// * TIME COMPLEXITY O(26)
// * SPACE COMPLEXITY O(26)
long long minimumCost(
    string source,
    string target,
    vector<char> &original,
    vector<char> &changed,
    vector<int> &cost)
{
  // * Create an Adjacency Matrix
  long long N = 26;
  vector<vector<long long>> dist(N, vector<long long>(N, INT_MAX));
  int n = original.size();
  for (int i = 0; i < n; ++i) {
    char s = original[i] - 'a', t = changed[i] - 'a';
    dist[s][t] = min(dist[s][t], (long long)cost[i]);
  }
  // cout << "dist: " << endl;
  // for (auto &vec : dist)
  //   printArr(vec);

  // * Count the min dist from every 'V' to every other 'V'
  // * Distance to itself will be 0
  for (int i = 0; i < N; ++i)
    dist[i][i] = 0;

  // * Apply Floyd Warshall
  for (int via = 0; via < N; ++via) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
          continue;

        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
      }
    }
  }
  // cout << "dist: " << endl;
  // for (auto &vec : dist)
  //   printArr(vec);

  // * Find the distance from source -> target string using Adj Matrix we created
  long long ans = 0;
  for (int i = 0; i < source.size(); ++i) {
    if (source[i] == target[i])
      continue;

    long long min_cost = dist[source[i] - 'a'][target[i] - 'a'];
    if (min_cost == INT_MAX) { // * we never reached on this dest
      // cout << source[i] << " " << target[i] << endl;
      return -1;
    }
    
    ans += min_cost;
  }

  return ans;
}

int main(void) {
  // * testcase 1
  string source = "abcd", target = "acbe";
  vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'},
                    changed = {'b', 'c', 'b', 'e', 'b', 'e'};
  vector<int> cost = {2, 5, 5, 1, 2, 20};

  // * testcase 2
  // string source = "aaaa", target = "bbbb";
  // vector<char> original = {'a', 'c'},
  //                   changed = {'c', 'b'};
  // vector<int> cost = {1, 2};

  cout << "original: ";
  printArr(original);

  cout << "changed: ";
  printArr(changed);

  cout << "cost: ";
  printArr(cost);
  
  // * testcase 2
  // string source = "aaaa", target = "bbbb";
  // vector<int> cost = {1, 2};
  // vector<char> original = {'a', 'c'}, changed = {'c', 'b'};

  long long ans = minimumCost(source, target, original, changed, cost);
  cout << "Ans: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-min-cost-to-convert-string-i.cpp -o output && ./output

