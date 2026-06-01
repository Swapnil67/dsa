/*
 * Leetcode - 97
 * Interleaving String
 * 
 * Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
 * 
 * An interleaving of two strings s and t is a configuration where s and t are divided 
 * into n and m substrings respectively, such that:
 * 
 * - s = s1 + s2 + ... + sn
 * - t = t1 + t2 + ... + tm
 * - |n - m| <= 1
 * - The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
 * 
 * Note: a + b is the concatenation of strings a and b.
 * 
 * 
 * Example 1
 * input            : s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * output           : true
 * 
 * Example 2
 * input            : s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * output           : false
 * 
 * https://leetcode.com/problems/interleaving-string
 * https://neetcode.io/problems/interleaving-string
*/

#include <vector>
#include <cstring>
#include <iostream>

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

int m, n, N;
bool dfs(int i, int j, int k, string &s1, string &s2, string &s3) {
  if (i == m && j == n && k == N)
    return true;

  if (k >= N) // * either s1 or s2 is finished completely
    return false;

  bool res = false;
  if (s1[i] == s3[k])
    res = dfs(i + 1, j, k + 1, s1, s2, s3);

  if (res == true)
    return res;

  if (s2[j] == s3[k])
    res = dfs(i, j + 1, k + 1, s1, s2, s3);
  return res;
}

bool dfs(int i, int j, int k, string &s1, string &s2, string &s3,
         int (&t)[][101][201]) {
  if (i == m && j == n && k == N)
    return true;

  if (t[i][j][k] != -1)
    return t[i][j][k];

  if (k >= N) // * either s1 or s2 is finished completely
    return false;

  bool res = false;
  if (s1[i] == s3[k])
    res = dfs(i + 1, j, k + 1, s1, s2, s3, t);

  if (res == true)
    return res;

  if (s2[j] == s3[k])
    res = dfs(i, j + 1, k + 1, s1, s2, s3, t);

  return t[i][j][k] = res;
}


bool dfs(int i, int j, string &s1, string &s2, string &s3,
         int (&t)[][101]) {
  if (i == m && j == n)
    return true;

  if (i + j >= N) // * either s1 or s2 is finished completely
    return false;

  if (t[i][j] != -1)
    return t[i][j];


  bool res = false;
  if (s1[i] == s3[i + j])
    res = dfs(i + 1, j, s1, s2, s3, t);

  if (res == true)
    return res;

  if (s2[j] == s3[i + j])
    res = dfs(i, j + 1, s1, s2, s3, t);

  return t[i][j] = res;
}


// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^(m + n))
// * SPACE COMPLEXITY O(m + n)
int bruteForce(string s1, string s2, string s3) {
  m = s1.length(), n = s2.length(), N = s3.length();
  if (N != m + n)
    return false;

  return dfs(0, 0, 0, s1, s2, s3);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Use only 'i' and 'j' and let 'k' with t[][][]
// * Top Down + Memoization
// * TIME COMPLEXITY O(m * n * N)
// * SPACE COMPLEXITY O(m * n * N)
int isInterleave(string s1, string s2, string s3) {
  m = s1.length(), n = s2.length(), N = s3.length();
  if (N != m + n)
    return false;

  int t[101][101][201];
  memset(t, -1, sizeof(t));
  return dfs(0, 0, 0, s1, s2, s3, t);
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * Use only 'i' and 'j' and let 'k' = 'i + j'
// * Top Down + Memoization
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n)
int isInterleave(string s1, string s2, string s3) {
  m = s1.length(), n = s2.length(), N = s3.length();
  if (N != m + n)
    return false;

  int t[101][101];
  memset(t, -1, sizeof(t));
  return dfs(0, 0, s1, s2, s3, t);
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++17 19-interleaving-string.cpp -o output && ./output
