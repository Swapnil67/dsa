/*
 * NAME: 1913B - Swap and Delete
 * 
 * Description:
 * You are given a binary string s (consisting only of '0' and/or '1'). You can perform two operations:
 * 1. Remove a character from s (costs 1 coin).
 * 2. Swap any pair of characters in s (costs 0 coins).
 * 
 * You can perform these operations in any order and any number of times to get a new string t.
 * The string t is "good" if for every index i, t[i] != s[i] (compared with the initial s).
 * Find the minimum total cost (deletions) to make a modified string t good.
 * 
 * Constraints:
 * 1 <= t <= 10^4 (number of test cases)
 * 1 <= |s| <= 2 * 10^5 (length of binary string s)
 * The sum of |s| over all test cases does not exceed 2 * 10^5.
 * 
 * Example 1    :
 * Input        : s = "0"
 * Output       : 1
 * Explanation  : You have to delete the character from s to get an empty string t, which costs 1 coin.
 * 
 * Example 2    :
 * Input        : s = "011"
 * Output       : 1
 * Explanation  : Delete the second character to get "01", then swap them to get t = "10". 
 *                Since t[0] != s[0] and t[1] != s[1], t is good. Total cost is 1 coin.
 *
 * https://codeforces.com/problemset/problem/1913/B
*/


// * Run the code
// * g++ --std=c++20 02-chemistry.cpp -o output && ./output

// * testcases
/*
4
0
011
0101110001
111100

*/


// * Output
/*
1
1
0
4
*/