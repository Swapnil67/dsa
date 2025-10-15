/*
 * Leetcode - 1718
 * Construct the Lexicographically Largest Valid Sequence
 * 
 * Given an integer n, find a sequence with elements in the range [1, n] that satisfies all of the following:
 * - The integer 1 occurs once in the sequence.
 * - Each integer between 2 and n occurs twice in the sequence.
 * - For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.

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

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

std::vector<bool> used;
bool solve(int& n, std::vector<int>& ans, int i) {
  if (i >= ans.size())
      return true;

  // * We have already filled a value here
  if (ans[i] != -1)
      return solve(n, ans, i + 1);

  for (int num = n; num >= 1; --num) {
    if (used[num]) // * check if already taken
      continue;

    // * DO
    used[num] = true;
    ans[i] = num;

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
    used[num] = false;
    ans[i] = -1;
  }

  return false;
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n!)
// * SPACE COMPLEXITY O(n + n) (Recursion Stack + used array)
std::vector<int> constructDistancedSequence(int n) {
  used.assign(n + 1, false);
  std::vector<int> ans(2 * n - 1, -1);
  solve(n, ans, 0);
  return ans;
}

int main(void) {
  // int n = 3;
  int n = 5;

  std::cout << "n: " << n << std::endl;

  std::vector<int> ans = constructDistancedSequence(n);
  std::cout << "Answer" << std::endl;
  printArr(ans);

  return 0;
}


// * Run the code
// * g++ --std=c++20 23-construct-the-lexicographically-largest-valid-sequence.cpp -o output && ./output 