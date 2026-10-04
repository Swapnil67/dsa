/*
 * Leetcode - 2844
 * Minimum Operations to Make a Special Number
 * 
 * Find the minimum operations (digit deletions) to make a number divisible by 25.
 * A number is divisible by 25 if its last two digits form "00", "50", "25", or "75".
 * 
 * Examples     : 
 *                - "2245047" -> Output: 2 (delete '4', '7' to get "22450")
 *                - "2908305" -> Output: 3 (delete '8', '3', '5' to get "2900")
 *                - "10"      -> Output: 1 (delete '1' to get "0")

 *
 * https://leetcode.com/problems/minimum-operations-to-make-a-special-number/
*/

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
  cout << " ]" << "\n";
}


int check_ops(string num, string p) {
  int n = num.length();
  int checker_idx = p.length() - 1;

  int ops = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (num[i] == p[checker_idx]) {
      checker_idx--;
      if (checker_idx < 0)
        break;
    }
    else {
      ops++;
    }
  }

  if (checker_idx >= 0)
    return INT_MAX;

  return ops;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int minimumOperations(string num) {
  int n = num.length();
  if (n == 1 && num[0] != '0')
    return 1;

  vector<string> possible_values = {"00", "25", "50", "75"};
  int min_ops = INT_MAX;
  for (auto &p : possible_values)
    min_ops = min(min_ops, check_ops(num, p));

  if (min_ops == INT_MAX) {
    // * If any '0' in number the remove all the other digits
    for (int i = 0; i < n; ++i) {
      if (num[i] == '0')
        return n - 1;
    }
    return n;
  }

  return min_ops;
}
int main(void) {
  vector<string> testcase = {"0", "2245047", "2908305", "10", "100", "1"};
  for (auto &t: testcase) {
    int ans = minimumOperations(t);
    cout << "num: " << t << "\n";
    cout << "Minimum Operations: " << ans << "\n";
    cout << "--------------------------------------\n";
  }

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-min-ops-to-make-a-special-num.cpp -o output && ./output
