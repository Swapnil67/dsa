/*
 * Leetcode - 1718
 * Construct the Lexicographically Largest Valid Sequence
 * 
 * Given an integer n, find a sequence with elements in the range [1, n] that satisfies all of the following:
 * - The integer 1 occurs once in the sequence.
 * - Each integer between [2...n] occurs twice in the sequence.
 * - For every integer 'i' between 2 & n, the distance between the two occurrences of 'i' is exactly 'i'.

 * The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

 * Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

 * A subsequence is an array that can be derived from another array by deleting some or no elements without
 * changing the order of the remaining elements.

 * Example 1
 * input            : n = 3
 * output           : [3,1,2,3,2]
 * Explanation      : [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.

 * Example 1
 * input       : n = 5
 * output      : [5,3,1,4,3,5,2,4,2]

 * https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/
*/

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

vector<bool> used;
bool solve(int& n, vector<int>& ans, int i) {
  if (i >= ans.size())
      return true;

  // * We have already filled a value here
  if (ans[i] != -1)
      return solve(n, ans, i + 1);

  for (int num = n; num >= 1; --num) {
    if (used[num]) // * check if already taken
      continue;

    // * DO
    ans[i] = num;
    used[num] = true;

    // * TRY
    if (num == 1) {
      if (solve(n, ans, i + 1))
        return true;
    }
    else {
      // * Each integer between 2 and n occurs twice in the sequence.
      int j = i + num;
      if (j < ans.size() && ans[j] == -1) {
        ans[j] = num;

        if (solve(n, ans, i + 1))
          return true;

        ans[j] = -1;
      }
    }

    // * UNDO
    ans[i] = -1;
    used[num] = false;
  }

  return false;
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * TIME COMPLEXITY O(n!)
// * SPACE COMPLEXITY O(n + n) (Recursion Stack + used array)
vector<int> constructDistancedSequence(int n) {
  used.assign(n + 1, false);
  vector<int> ans((2 * n - 1), -1);
  solve(n, ans, 0);
  return ans;
}

int main(void) {
  // * testcase 1
  // int n = 3;

  // * testcase 1
  int n = 5;

  cout << "n: " << n << endl;

  vector<int> ans = constructDistancedSequence(n);
  cout << "Lexicographically Largest Valid Sequence" << endl;
  printArr(ans);

  return 0;
}


// * Run the code
// * g++ --std=c++20 23-construct-the-lexicographically-largest-valid-sequence.cpp -o output && ./output 