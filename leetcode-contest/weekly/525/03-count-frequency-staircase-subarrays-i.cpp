
/*
 * Leetcode - 4094
 * Count Frequency Staircase Subarrays II
 * 
 * https://leetcode.com/problems/count-frequency-staircase-subarrays-i/
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

// * Subarray Length -> Valid Staircase
// * 1 -> true
// * 3 -> true
// * 6 -> true
// * 10 -> true

// * Subarr Length -> Distinct Elements
// * 1 -> 1
// * 3 -> 2
// * 6 -> 3
// * 10 -> 4


// ! Without Pruning
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int bruteForce(vector<int> &nums) {
  ll n = nums.size();

  unordered_map<ll, bool> valid_staircase_len_mp; // * {valid_len, boolean}
  unordered_map<ll, ll> staircase_unique_ele_mp;  // * {valid_len, unique_elements}
  ll sum = 0, i = 1;
  while (sum <= n) {
    sum += i;
    valid_staircase_len_mp[sum] = true;
    staircase_unique_ele_mp[sum] = i;
    i++;
  }
  // PRINT_VEC_PAIRS(valid_staircase_mp);
  // PRINT_VEC_PAIRS(staircase_unique_ele_mp);

  ll ans = 0;
  unordered_map<ll, ll> freq_mp, rank_mp;
  for (ll i = 0; i < n; ++i) {
    freq_mp.clear();
    rank_mp.clear();
    ll rank = 0;
    for (ll j = i; j < n; ++j) {
      int v = nums[j];
      freq_mp[v]++;
      if (!rank_mp.count(v)) {
        rank++;
        rank_mp[v] = rank;
      }

      // * Ele cannot appear more than its rank. (freq = 3, but rank = 2)
      if (freq_mp[v] > rank_mp[v]) // * Invalid Staircase
        break;

      // * check if this is valid len
      ll len = j - i + 1;
      if (valid_staircase_len_mp.count(len)) {
        if (staircase_unique_ele_mp[len] == (ll)freq_mp.size()) {
          ans += 1;
        }
      }
    }
  }
  return ans;
}

// ! With Pruning
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int countStaircase(vector<int> &nums) {
  ll n = nums.size();

  // * g -> {len_of_subarr, 1}
  // * g2 -> {len_of_subarr, distinct_elements}
  unordered_map<ll, ll> g, g2;
  g.clear();
  g2.clear();
  unordered_map<ll, bool> valid_staircase_len_mp; // * {valid_len, boolean}
  unordered_map<ll, ll> staircase_unique_ele_mp;  // * {valid_len, unique_elements}
  ll sum = 0, i = 1;
  while (sum <= n) {
    sum += i;
    valid_staircase_len_mp[sum] = true;
    staircase_unique_ele_mp[sum] = i;
    i++;
  }
  // PRINT_VEC_PAIRS(g); PRINT_VEC_PAIRS(g2);

  unordered_map<ll, ll> freq, rank_mp;
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    freq.clear();rank_mp.clear();
    ll rank = 0;
    for (ll j = i; j < n; ++j) {
      ll val = nums[j];
      freq[val]++;
      if (!rank_mp.count(val)) {
        rank++;
        rank_mp[val] = rank;
      }

      // * Ele cannot appear more than its rank. (freq = 3, but rank = 2)
      if (freq[val] > rank_mp[val])
        break;

      // * check if this is valid len
      int len = j - i + 1;
      if (valid_staircase_len_mp[len] == 1) {
        // * how many distinct elements should this subarray have.
        if (rank == staircase_unique_ele_mp[len])
          ans = ans + 1;
      }

      // * Minimum subarray len required to satisfy 'u' distinct
      // * elements is 1 + 2 + ... + u = u * (u + 1) / 2. (sum of 1...u)
      // * If not enough elements remain in nums, break early.
      if (i + (1LL * rank * (rank + 1) / 2) > n) {
        j = n + 5;
      }
    }
  }

  return ans;
}


int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  return 0;
}
