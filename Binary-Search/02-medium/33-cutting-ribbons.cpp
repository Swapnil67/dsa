/*
 * Leetcode - ?
 * Cutting Ribbons
 *
 * Example 1    :
 * Input        : ribbons = [9,7,5], k = 3
 * Output       : 5
 * Explanation  :
 *
 * Example 2    :
 * Input        : ribbons = [7,5,9], k = 4
 * Output       : 4
 * Explanation  :
 *
 * Example 3    :
 * Input        : ribbons = [5,7,9], k = 22
 * Output       : 0
 * Explanation  :
 *
 * Example 4    :
 * Input        : ribbons = [4, 4, 4, 4], k = 8
 * Output       : 2
 * Explanation  :
 *
 * https://neetcode.io/problems/cutting-ribbons/
 */

// ! Meta, Google

#include <vector>
#include <iostream>
#include <algorithm>

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

bool is_valid(vector<int> &ribbons, int &max_ribbons, int &max_len) {
  int cur_ribbons = 0;
  for (auto &r : ribbons) {
    cur_ribbons += (r / max_len);
    if (cur_ribbons >= max_ribbons)
      return true;
  }
  return false;
}

// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
int maxLength(vector<int> &ribbons, int k) {
  int n = ribbons.size();
  int l = 1, r = *max_element(begin(ribbons), end(ribbons));
  int ans = 0;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (is_valid(ribbons, k, m)) {
      ans = m;
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // int k = 22;
  // vector<int> ribbons = {5, 7, 9};

  // * testcase 2
  int k = 4;
  vector<int> ribbons = {7, 5, 9};

  // * testcase 3
  // int k = 8;
  // vector<int> ribbons = {4, 4, 4, 4};

  cout << "k: " << k << endl;
  cout << "Ribbons: ";
  printArr(ribbons);

  int ans = maxLength(ribbons, k);
  cout << "Max Length: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 33-cutting-ribbons.cpp -o output && ./output
