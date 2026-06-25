/*
 * Leetcode - 1871
 * Jump Game VII
 * 
 * You are given a 0-indexed binary string s and two integers minJump and maxJump. 
 * In the beginning, you are standing at index 0, which is equal to '0'. 
 * You can move from index i to index j if the following conditions are fulfilled:  
 * -> i + minJump <= j <= min(i + maxJump, s.length - 1), and
 * -> s[j] == '0'.
 * 
 * Return true if you can reach index s.length - 1 in s, or false otherwise.
 * 
 * Example 1
 * input            : s = "011010", minJump = 2, maxJump = 3
 * output           : true
 * Explanation      : In the first step, move from index 0 to index 3. 
 *                    In the second step, move from index 3 to index 5.

 * Example 2
 * input            : s = "01101110", minJump = 2, maxJump = 3
 * output           : false
 *
 * https://neetcode.io/problems/jump-game-vii/question
 * https://leetcode.com/problems/jump-game-vii/description/ 
*/

// ! Amazon, Google

#include <vector>
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

// * Without Memoization
bool dfs(int i, string &s, int &minJump, int &maxJump) {
  int n = s.length();
  if (i == n - 1)
    return true;

  int end = min(i + maxJump, n - 1);
  for (int jump = minJump; jump <= maxJump; ++jump) {
    int j = i + jump; 

    if (j >= n)
      break;

    if (s[j] == '0' && dfs(j, s, minJump, maxJump))
      return true;
  }

  return false;
}

// * With Memoization
bool dfs(int i, string &s, int &minJump, int &maxJump, vector<int> &dp) {
  int n = s.length();
  if (i == n - 1)
    return true;

  if (dp[i] != -1)
    return dp[i];

  for (int jump = minJump; jump <= maxJump; ++jump) {
    int j = i + jump; // * next jump index

    if (j >= n)
      break;

    if (s[j] == '0' && dfs(j, s, minJump, maxJump, dp))
      return dp[i] = true;
  }

  return dp[i] = false;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// !TLE
// * Top Down (Exponential)
// * TIME COMPLEXITY O(n^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(string &s, int &minJump, int &maxJump) {
  return dfs(0, s, minJump, maxJump);
}

// * ------------------------- Approach: Better Approach -------------------------
// !TLE
// * Top Down + Memoization
// * TIME COMPLEXITY O(n * (maxJump - minJump))
// * SPACE COMPLEXITY O(n)
int betterApproach(string &s, int &minJump, int &maxJump) {
  vector<int> dp(s.length(), -1);
  return dfs(0, s, minJump, maxJump, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// !TLE
// * Bottom Up 
// * TIME COMPLEXITY O(n * (maxJump - minJump))
// * SPACE COMPLEXITY O(1)
int canReach(string &s, int &minJump, int &maxJump) {
  int n = s.length();
  vector<int> t(n, -1);
  t[n - 1] = true;

  for (int i = n - 2; i >= 0; --i) {
    for (int jump = minJump; jump <= maxJump; ++jump) {
      int j = i + jump;

      if (j >= n)
        break;

      if (s[j] == '0' && t[j] == true) {
        t[i] = true;
        break;
      }
    }
  }

  return t[0];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Dynamic Programming (Sliding Window) 

// * Intuition
// * At position 'i', you can jump to 'i' from any previous position 'j' where:
// * j + minJump <= i <= j + maxJump
// * s[j] == '0' and t[j] == true (j is reachable)

// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int canReach2(string &s, int &minJump, int &maxJump) {
  int n = s.length();
  if (s[n - 1] == '1')
    return false;

  vector<bool> t(n, false);
  t[0] = true;
  int cnt = 0;

  for (int i = 1; i < n; ++i) {

    if (i >= minJump && t[i - minJump])
      cnt++;

    if (i > maxJump && t[i - maxJump - 1])
      cnt--;

    if (cnt > 0 && s[i] == '0')
      t[i] = true;
  }

  printArr(t);

  return t[n - 1];
}

int main(void) {
  // * testcase 1
  string s = "011010";
  int minJump = 2, maxJump = 3;

  // * testcase 2
  // string s = "01101110";
  // int minJump = 2, maxJump = 3;

  cout << "Input: " << s << endl;
  cout << "minJump: " << minJump << ", maxJump: " << maxJump << endl;

  // int ans = canReach(s, minJump, maxJump);
  int ans = canReach2(s, minJump, maxJump);
  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 05-jump-game-vii.cpp -o output && ./output
