/*
 * Range Update Trick
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
  cout << " ]" << endl;
}

// * Using Nested loop
// * TIME COMPLEXITY O(N*Q)
// * SPACE COMPLEXITY O(N) (If we use diff answer array)
void bruteForce(vector<int> &nums, vector<vector<int>> &queries) {
  int n = nums.size();
  for (auto &q: queries) {
    int l = q[0], r = q[1];
    for (int i = 0; i < n; ++i) {
      if (i >= l && i <= r) {
        nums[i] += 1;
      }
    }
  }
}

// * Using Prefix Sum
// * TIME COMPLEXITY O(N + Q)
// * SPACE COMPLEXITY O(N)
void rangeUpdate(vector<int> &nums, vector<vector<int>> &queries) {
  int n = nums.size();
  for (auto &q: queries) {
    int l = q[0], r = q[1];
    nums[l] += 1;
    if (r + 1 < n) nums[r + 1] = -1;
  }
  for (int i = 1; i < n; ++i) {
    nums[i] += nums[i - 1];
  }
}

int main(void) {
  vector<int> nums = {0, 0, 0, 0, 0};
  vector<vector<int>> queries = {{1, 2}, {2, 3}, {1, 4}};

  cout << "queries: " << endl;
  for (auto q : queries)
    printArr(q);

  cout << "nums: ";
  printArr(nums);

  // bruteForce(nums, queries);
  rangeUpdate(nums, queries);

  cout << "ans: ";
  printArr(nums);
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 range-query-update-trick.cpp -o output && ./output
