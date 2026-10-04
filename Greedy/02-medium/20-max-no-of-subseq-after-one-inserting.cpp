/*
 * Leetcode - 3628
 * Maximum Number of Subsequences After One Inserting
 * 
 * You are given a string s consisting of uppercase English letters.
 * 
 * You are allowed to insert at most one uppercase English letter at any position 
 * (including the beginning or end) of the string.
 * 
 * Return the maximum number of "LCT" subsequences that can be formed in the resulting string 
 * after at most one insertion.
 * 
 * Example 1    :
 * Input        : s = "LMCT"
 * Output       : 2
 * Explanation  : We can insert a "L" at the beginning of the string s to make "LLMCT", which has 2 
 *                subsequences, at indices [0, 3, 4] and [1, 3, 4].
 * 
 * Example 2    :
 * Input        : s = "LCCT"
 * Output       : 4
 * Explanation  : We can insert a "L" at the beginning of the string s to make "LLCCT", 
 * which has 4 subsequences, at indices [0, 2, 4], [0, 3, 4], [1, 2, 4] and [1, 3, 4].
 * 
 * Example 2    :
 * Input        : s = "L"
 * Output       : 0
 * Explanation  : Since it is not possible to obtain the subsequence "LCT" 
 *                by inserting a single letter, the result is 0.
 *
 * https://leetcode.com/problems/maximum-number-of-subsequences-after-one-inserting/description/
*/

// ! Prefix Sum + Greedy

#include <vector>
#include <iostream>

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

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
typedef long long ll;
long long numOfSubsequences(string s) {
	int n = s.length();
	
	ll lct_cnt = 0;
	ll l_cnt = 0, lc_cnt = 0;
	vector<ll> prefixL(n + 1, 0), prefixLC(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'L') { l_cnt++; }
		else if (s[i] == 'C') { lc_cnt += l_cnt; }
		else if (s[i] == 'T') { lct_cnt += lc_cnt; }

		prefixL[i + 1] = l_cnt;
		prefixLC[i + 1] = lc_cnt;
	}
	// printArr(prefixL);
	// printArr(prefixLC);

	ll t_cnt = 0, ct_cnt = 0;
	vector<ll> suffixT(n + 1, 0), suffixCT(n + 1, 0);
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == 'T') { t_cnt++; }
		else if (s[i] == 'C') { ct_cnt += t_cnt; }

		suffixT[i + 1] = t_cnt;
		suffixCT[i + 1] = ct_cnt;
	}
	// printArr(suffixT);
	// printArr(suffixCT);

	ll old_answer = lct_cnt;
	ll ans1 = suffixCT[1] + old_answer; // * put 'L' at beginning
	ll ans2 = prefixLC[n] + old_answer; // * put 'T' at last
	ll ans3 = 0;
	for (int i = 1; i <= n; ++i) {
		ans3 = max(ans3, prefixL[i] * suffixT[i + 1]);
	}

	return max({ans1, ans2, ans3 + old_answer});
}

int main(void) {
	// * testcase 1
	// string s = "LMCT";

	// * testcase 2
	string s = "LCCT";

	cout << s << endl;

	int ans = numOfSubsequences(s);

	cout << ans << endl;
	return 0;
}

// * Run the code
// * g++ --std=c++20 20-max-no-of-subseq-after-one-inserting.cpp -o output && ./output
