/*
 * Leetcode - 525
 * Contiguous Array
 * 
 * Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
 * 
 * Example 1    :
 * Input        : nums = [0,1,0]
 * Output       : 2
 * Explanation  : [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 * 
 * Example 2    :
 * Input        : nums = [0,1,1,1,1,1,0,0,0]
 * Output       : 6
 * Explanation  : [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
 *
 * https://leetcode.com/problems/contiguous-array/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

// * Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]
#define PRINT_VEC_PAIRS(p) for (auto &it: p) cout << it.first << ' ' << it.second << '\n'

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

// * Using Preix Sum + Hashmap
// * count_of_1s = count_of_0s
// * count_of_1s - count_of_0s = 0
// * TIME COMPLEXITY O(3N)
// * SPACE COMPLEXITY O(N)
int findMaxLength(vector<int> &a) {
  int n = a.size();
  // * Step 1: Convert 0 => -1, and 1 => 1
  // * [0, 1, 1, 0] => [-1, 1, 1, -1]
  vector<int> v(n, 1);
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0)
      v[i] = -1;
  }
  // printArr(v);

  // * Step 2: Calcuate the prefix sum for v
  vector<int> p(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + v[i - 1];
  }
  // printArr(p);

  // Step 3: Find largest valid subarray
  int ans = 0;
  unordered_map<int, int> mp;
  for (int i = 0; i <= n; ++i) {
    int val = p[i];

    if (mp.count(val)) // * valid subarray
      ans = max(ans, (i - mp[val]));

    if (!mp.count(val)) // * since we need largest subarray
      mp[val] = i;
  }

  return ans;
}

// * Using Hashmap
int findMaxLength(vector<int>& a) {
  int n = a.size();
  int count = 0, ans = 0;
  unordered_map<int, int> count_mp;
  count_mp[0] = -1;
  for (int i = 0; i < n; ++i) {
    count += (a[i] == 0) ? -1 : 1;
    if (count_mp.count(count)) {
      ans = max(ans, i - count_mp[count]);
    }
    else {
      count_mp[count] = i;
    }
  }
  return ans;
}

int main(void) {
  // * testcase 1
  // vector<int> nums = {0,1};

  // * testcase 2
  // vector<int> nums = {0, 1, 0};

  // * testcase 3
  vector<int> nums = {0, 1, 1, 1, 1, 1, 0, 0, 0};

  cout << "nums: ";
  printArr(nums);  

  int ans = findMaxLength(nums);
  cout << "Contiguous Array: " << ans << '\n';

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 29-contiguous-array.cpp -o output && ./output
