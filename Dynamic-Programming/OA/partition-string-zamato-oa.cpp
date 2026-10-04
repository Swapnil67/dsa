/*
 * New Network Protocol
 * 
 * Description:
 * A string must be transferred using a custom network protocol.
 * The protocol processes the string as follows:
 * - Each pair of identical characters in a given substring is processed together.
 * - If any pair contains matching characters (e.g., "aa"), it requires an additional sameTime seconds.
 * - The string can be split into multiple contiguous substrings before transmission, with each split adding partitionTime seconds.
 * 
 * Calculate the minimum possible total extra time required, which is the sum of:
 * - Time for processing pairs with matching characters within each partition.
 * - Time for creating partitions.
 * 
 * Constraints:
 * - 1 <= s.length <= 2500
 * - 1 <= sameTime, partitionTime <= 10^5
 * - s consists only of lowercase English letters.
 * 
 * Example 1    :
 * Input        : s = "abcabcc", sameTime = 1, partitionTime = 4
 * Output       : 5
 * Explanation  : Two optimal approaches exist:
 *                1. Split into ["abc", "abcc"]:
 *                   - "abc" has no matching pairs: 0 seconds
 *                   - "abcc" has one "cc" pair: 1 * sameTime = 1 second
 *                   - 1 split made: 1 * partitionTime = 4 seconds
 *                   - Total: 0 + 1 + 4 = 5 seconds
 *                2. Keep as ["abcabcc"]:
 *                   - 5 matching pairs ("aa", "bb", "cc", "cc", "cc"): 5 * sameTime = 5 seconds
 *                   - 0 splits made: 0 seconds
 *                   - Total: 5 seconds
 * 
 * Example 2    :
 * Input        : s = "abbaa", sameTime = 5, partitionTime = 1
 * Output       : 2
 * Explanation  : Split into ["ab", "ba", "a"]:
 *                - None of these substrings contain matching pairs of characters: 0 seconds
 *                - 2 splits made: 2 * partitionTime = 2 seconds
 *                - Total: 0 + 2 = 2 seconds
 * 
 * https://www.desiqna.in/19307/zomato-oa-sde-coding-questions-and-solutions-2026-set-3
 * https://docs.google.com/document/d/1Vg8xu1_dHF7Pz3_m5Ye6L4u1TQCfKNMje8k49Etils0/edit?tab=t.0
*/

// ! OA
// ! Zamato

// ! Partition DP

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

// * sameTime => x
// * partitionTime => y

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

/*
* -> dp[i]   => y + dp[i-1] + 0*(x) => y + dp[i-1] 
*    OR 
*            => y + dp[i-2] + g1*(x) => where g1 is the count of repetitions pairs in the range [i-1..i] 
*    OR
*            => y + dp[i-3] + g2*(x) => where g2 is the count of repetitions pairs in the range [i-2..i] 
*/

// * TIME COMPLEXITY O(N*N*26)
// * SPACE COMPLEXITY O(N)

int bruteForce(string s, int x, int y) {
  int n = s.length();
  s = '1' + s; // * convert to 1 based indexing

  // * dp[i] = minimum cost to divide string optimally from index 1 to index 'i'.
  vector<ll> dp(n + 1, 1e18);
  dp[0] = -y; // * For case when adding partition at '0' pos

  for (int i = 1; i <= n; ++i) {
    ll cost = 1e18;
    unordered_map<ll, ll> freq_mp;
    for (int j = i; j >= 1; --j) { // * All psbl partition from [j....i]
      freq_mp[s[j]]++;
      ll g = 0LL;
      for (char c = 'a'; c <= 'z'; ++c) {
        int f = freq_mp[c]; // * Frequency of char c
        // * "aabaa" => 6 pairs of char 'a'
        g = g + (f*(f-1))/2; // * Add no. of pairs psbl from 'ith' char
      }
      ll p = g * x; // * cost of matching characters in partition [j....i]
      cost = min(cost, y + dp[j - 1] + p);
    }
    dp[i] = cost;
  }

  // printArr(dp); // * For Debug
  return dp[n];
}

int main(void) {
  // * testcase 1
  // int x = 1, y = 4;
  // string s = "abcabcc";
  
  // * testcase 2
  int x = 5, y = 1;
  string s = "abbaa";

  int ans = bruteForce(s, x, y);
  cout << "Minimum cost: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 partition-string-zamato-oa.cpp -o output && ./output
