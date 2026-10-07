/*
 * Distinct Split
 * 
 * Description  : Given a string s, split it into two non-empty substrings a and b 
 *                such that a + b = s. Maximize the sum of the number of distinct 
 *                characters in a and b.
 * 
 * Constraints  : 2 <= n <= 2 * 10^5, s consists of lowercase English letters.
 * 
 * Example 1    :
 * Input        : n = 2, s = "aa"
 * Output       : 2
 * Explanation  : The only split is a = "a", b = "a". f(a) = 1, f(b) = 1. Sum = 2.
 * 
 * Example 2    :
 * Input        : n = 7, s = "abcabcd"
 * Output       : 7
 * Explanation  : Split into a = "abc", b = "abcd". f(a) = 3, f(b) = 4. Sum = 7.
 *
 * https://codeforces.com/problemset/problem/1791/D
*/

#include<vector>
#include<iostream>
#include<unordered_set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
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

// * count unique char in range l...r
ll count_unique(int l, int r, string s) {
  unordered_set<char> st;
  while (l <= r) {
    st.insert(s[l++]);
  }
  return st.size();
}

// ! TLE
// * Count unique character count for left & right substrings on each split
// * Time Complexity (TC): O(n^2) ~ O((2*10^5)^2)
// * Space Complexity (SC): O(n) ~ O(2*10^5)
ll bruteForce() {
  int n;
  cin >> n;
	string s;
	cin >> s;
  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    ll left = count_unique(0, i, s);          // * unique characters in left substring
    ll right = count_unique(i + 1, n - 1, s); // * unique characters in right substring
    // cout << left << " " << right << endl;
    ans = max(ans, (left + right));
  }
  return ans;
}

// ! Greedy Prefix - Suffix
// * Time Complexity (TC): O(n) ~ O(2*10^5)
// * Space Complexity (SC): O(n) ~ O(2*10^5)
ll distinctPairs() {
  int n;
  cin >> n;
	string s;
	cin >> s;
  VEC(prefix_unique_count, n + 1, ll); // * Vector to store the count of unique characters in prefix
  VEC(suffix_unique_count, n + 1, ll); // * Vector to store the count of unique characters in suffix
  unordered_set<char> st; // * Set to store distinct characters

  // * Calculate the number of distinct characters in the prefix for each position
  for (int i = 0; i < n; ++i) {
    st.insert(s[i]);
    prefix_unique_count[i] = st.size();
  }
  // printArr(prefix_unique_count);

  st.clear(); // * Clear the set for reuse

  // * Calculate the number of distinct characters in the suffix for each position
  for (int i = n - 1; i >= 0; --i) {
    st.insert(s[i]);
    suffix_unique_count[i] = st.size();
  }
  // printArr(suffix_unique_count);

  ll ans = 0; // * Variable to store the maximum possible value of f(a) + f(b)
  // * Find the maximum value of f(a) + f(b) by iterating over possible split points
  for (int i = 0; i < n; ++i) {
    ans = max(ans, prefix_unique_count[i] + suffix_unique_count[i+1]);
  }
  
  return ans;
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    // ll ans = bruteForce();
    ll ans = distinctPairs();
    cout << ans << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 08-distinct-split.cpp -o output && ./output

// * testcases
/*
5
2
aa
7
abcabcd
5
aaaaa
10
paiumoment
4
aazz

*/

// * Output
/*
2
7
2
10
3
*/