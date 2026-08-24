
/*
 * Leetcode - 639
 * Decode Ways II
 *
 *
 * Example 1    :
 * Input        : s = "*"
 * Output       : 9
 * Explanation  : The encoded message can represent any of the encoded messages "1", "2", "3", "4", "5", "6", "7", "8", or "9".
 *
 * Example 2    :
 * Input        : s = "1*"
 * Output       : 18
 * Explanation  : The encoded message can represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19".
 * Each of these encoded messages have 2 ways to be decoded (e.g. "11" can be decoded to "AA" or "K").
 * Hence, there are a total of 9 * 2 = 18 ways to decode "1*".
 * 
 * Example 3    :
 * Input        : s = "2*"
 * Output       : 15
 * Explanation  : The encoded message can represent any of the encoded messages "21", "22", "23", "24", "25", "26", "27", "28", or "29".
 * "21", "22", "23", "24", "25", and "26" have 2 ways of being decoded, but "27", "28", and "29" only have 1 way.
 * Hence, there are a total of (6 * 2) + (3 * 1) = 12 + 3 = 15 ways to decode "2*".
 *
 * https://leetcode.com/problems/decode-ways-ii/description/
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void printArr(vector<T> &arr)
{
	int n = arr.size();
	cout << "[ ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
		if (i != n - 1)
			cout << ", ";
	}
	cout << " ]" << endl;
}

long long MOD = 1000000007;

long long decodeHelper(int i, const string &s, vector<long long> &memo) {
	int n = s.length();

	// *  Base case: Reached the end, successfully found 1 valid path
	if (i == n)
		return 1;

	// *  Base case: Leading zero is invalid
	if (s[i] == '0')
		return 0;

	// *  Return already cached result
	if (memo[i] != -1)
		return memo[i];

	long long ways = 0;

	// *  -----------------------------------------------------------------
	// *  OPTION 1: Parse ONE Character at s[i]
	// *  -----------------------------------------------------------------
	if (s[i] == '*') {
		// *  '*' can be any digit from 1 to 9 (9 possibilities)
		ways = (9 * decodeHelper(i + 1, s, memo)) % MOD;
	} else {
		// *  s[i] is a regular digit from '1' to '9' (1 possibility)
		ways = decodeHelper(i + 1, s, memo) % MOD;
	}

	// *  -----------------------------------------------------------------
	// *  OPTION 2: Parse TWO Characters at s[i] and s[i+1]
	// *  -----------------------------------------------------------------
	if (i + 1 < n) {
		char first = s[i];
		char second = s[i + 1];

		if (first == '*' && second == '*') {
			// *  "**" can be:
			// *  11-19 (9 ways) or 21-26 (6 ways) -> 15 total possibilities
			ways = (ways + 15 * decodeHelper(i + 2, s, memo)) % MOD;
		} 
		else if (first == '*') {
			// *  "*X" where X is a digit
			if (second <= '6') {
				// *  Can be 1X or 2X (2 possibilities: e.g., if X='3', 13 or 23)
				ways = (ways + 2 * decodeHelper(i + 2, s, memo)) % MOD;
			} else {
				// *  Can only be 1X (1 possibility: e.g., if X='7', only 17 is valid)
				ways = (ways + 1 * decodeHelper(i + 2, s, memo)) % MOD;
			}
		}
		else if (second == '*') {
			// *  "1*" -> can be 11 to 19 (9 possibilities)
			if (first == '1') {
				ways = (ways + 9 * decodeHelper(i + 2, s, memo)) % MOD;
			}
			// *  "2*" -> can be 21 to 26 (6 possibilities)
			else if (first == '2') {
				ways = (ways + 6 * decodeHelper(i + 2, s, memo)) % MOD;
			}
		}
		else {
			// *  Regular digits: "XY" (No wildcards)
			// *  Must form a valid number between 10 and 26
			if (first == '1' || (first == '2' && second <= '6')) {
				ways = (ways + decodeHelper(i + 2, s, memo)) % MOD;
			}
		}
	}

	return memo[i] = ways;
}

int numDecodings(string s) {
	int n = s.length();
	if (n == 0)
		return 0;

	// *  Use long long for memo table to prevent integer overflow during multiplications
	vector<long long> memo(n, -1);
	return decodeHelper(0, s, memo);
}

int main(void) {
	return 0;
}

// *  * Run the code
// *  * g++ --std=c++20 practice.cpp -o output && ./output
