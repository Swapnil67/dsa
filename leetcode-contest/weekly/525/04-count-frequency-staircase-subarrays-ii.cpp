
/*
 * Leetcode - 4095
 * Count Frequency Staircase Subarrays II
 * 
 * https://leetcode.com/problems/count-frequency-staircase-subarrays-ii/
 * https://leetcode.com/problems/count-frequency-staircase-subarrays-ii/submissions/2181382874/
 */

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
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

// * Length -> Distinct Elements
// * 1 -> 1
// * 3 -> 2
// * 6 -> 3
// * 10 -> 4

// * Condition for valid staircase  
// * Len of subarray == (rank * (rank + 1) / 2)
// * where rank is number of unique elements in current subarray

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int countStaircase(vector<int> &nums) {
  typedef long long ll;
  ll n = nums.size();

  ll ans = 0;
  vector<ll> freq_vec(1e5 + 2, 0);
  vector<ll> rank_vec(1e5 + 2, 0);
  vector<ll> seen;

  for (ll i = 0; i < n; ++i) {
    ll rank = 0;
    for (ll j = i; j < n; ++j) {
      int v = nums[j];
      seen.push_back(v);
      freq_vec[v]++;
      if (rank_vec[v] == 0) {
        rank++;
        rank_vec[v] = rank;
      }

      if (freq_vec[v] > rank_vec[v]) // * Invalid Staircase
        break;

      // * If valid staircase
      if ((j - i + 1) == rank * (rank + 1) / 2) {
        ans += 1;
      }

      // * Pruning
      if (i + (rank * 1LL * (rank + 1) / 2) > n)
        break;
    }

    // * Reset the vectors
    for (auto s : seen) {
      freq_vec[s] = 0;
      rank_vec[s] = 0;
    }
    seen.clear();
  }

  return ans;
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  return 0;
}
