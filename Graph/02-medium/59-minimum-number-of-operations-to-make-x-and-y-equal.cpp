/*
 * Leetcode - 2998
 * Minimum Number of Operations to Make X and Y Equal
 *
 * You are given two positive integers x and y.
 *
 * In one operation, you can do one of the four following operations:
 * 1. Divide x by 11 if x is a multiple of 11.
 * 2. Divide x by 5 if x is a multiple of 5.
 * 3. Decrement x by 1.
 * 4. Increment x by 1.
 *
 * Return the minimum number of operations required to make x and y equal.
 *
 * Example 1    :
 * Input        : x = 26, y = 1
 * Output       : 3
 *
 * Example 2    :
 * Input        : x = 54, y = 2
 * Output       : 4
 *
 * Example 3    :
 * Input        : x = 25, y = 30
 * Output       : 5
 *
 * https://leetcode.com/problems/minimum-number-of-operations-to-make-x-and-y-equal/
 */

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

int minimumOperationsToMakeEqual(int x, int y) {
  if (x == y)
    return 0;

  unordered_set<int> seen;
  seen.insert(x);

  queue<int> q;
  q.push(x);

  int ops = 0;
  while (!q.empty()) {
    int N = q.size();

    while (N--) {
      int num = q.front();
      q.pop();

      if (num == y)
        return ops;

      if (num % 11 == 0 && !seen.count(num / 11)) {
        q.push(num / 11);
        seen.insert(num / 11);
      }

      if (num % 5 == 0 && !seen.count(num / 5)) {
        q.push(num / 5);
        seen.insert(num / 5);
      }

      if (!seen.count(num - 1) && num - 1 >= 0) {
        q.push(num - 1);
        seen.insert(num - 1);
      }

      if (!seen.count(num + 1)) {
        q.push(num + 1);
        seen.insert(num + 1);
      }
    }

    ops += 1;
  }

  return -1;
}

int main(void) {
  // * testcase 1
  // int x = 26, y = 1;

  // * testcase 2
  // int x = 54, y = 2;

  // * testcase 3
  int x = 25, y = 30;

  int ans = minimumOperationsToMakeEqual(x, y);
  std::cout << "Min no. of operations: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 59-minimum-number-of-operations-to-make-x-and-y-equal.cpp -o output && ./output
