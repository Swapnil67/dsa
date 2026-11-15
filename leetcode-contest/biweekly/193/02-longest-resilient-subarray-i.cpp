/*
 * NAME         : Longest Resilient Subarray I
 * 
 * Description  : Find the length of the longest resilient subarray where removing any 
 *                single element leaves the remaining sum divisible by `k`.
 * 
 * Examples Summary:
 * - Example 1: nums = [2,4,6,3], k = 2 -> Output: 3 ([2, 4, 6])
 * - Example 2: nums = [1,4,7,1], k = 3 -> Output: 4 ([1, 4, 7, 1])
 * - Example 3: nums = [5,5,4,8], k = 4 -> Output: 2 ([4, 8])
 *                (For full details and explanations, refer to the source link below).
 *
 * https://leetcode.com/problems/longest-resilient-subarray-i/
 * https://docs.google.com/document/d/1UKMjrVaZO8ZfD9jZ8H1mTgx8B2K0eemTSiBelu4OQTc/edit?tab=t.0
 */


// * x % k == y % k
// * x ≡ y [mod k]

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

// Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))

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

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int resilientSubarray(vector<int>& v, int k) {
  int n = v.size();
  int ans = 0;
  for (size_t i = 0; i < n; ++i) {
    ll sum = 0;
    ll cur = v[i] % k;
    for (size_t j = i; j < n; ++j) {
      sum += v[j];
      if (v[j] % k != cur)
        break;

      if ((sum - v[i]) % k == 0) {
        ans = max(ans, (int)(j - i + 1));
      }
    }
  }
  return ans;
}

int main(void) {
  // * testcase 1
  int k = 2;
  vi nums = {2, 4, 6, 3};

  // * testcase 2
  // int k = 3;
  // vi nums = {1, 4, 7, 1};

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
