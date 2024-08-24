/*
 * Maximum Product of the Length of Two Palindromic Subsequences 
 * Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized.
 * The two subsequences are disjoint if they do not both pick a character at the same index.
 * 
 * Return the maximum possible product of the lengths of the two palindromic subsequences.

 * Example 1:
 * Input: s = "leetcodecom"
 * Output: 9
 * Explantion: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
 *            The product of their lengths is: 3 * 3 = 9.

 * Example 2:
 * Input: s = "accbcaxxcxx"
 * Output: 25
 * Explantion: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
 *            The product of their lengths is: 5 * 5 = 25.

 * https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/
*/

#include<map>
#include<iostream>

bool checkPalindrome(std::string s, int n, int i) {
  if (i >= n / 2)
    return true;

  // cout << "s[i] " << s[i] << " s[n-i-1] " << s[n - i - 1] << endl;

  if (s[i] != s[n - i - 1])
    return false;
  return checkPalindrome(s, n, i + 1);
}

// * TIME COMPLEXITY (2^N)+ O(Nˆ2)
// * SPACE COMPLEXITY (2^N)
int maxProduct(std::string s) {
  int n = s.size();
  std::map<int, int> bitmaskMap;

  int maxBits = 1 << n; // * (2^n)
  // std::cout << maxBits << std::endl;
  for (int mask = 0; mask < maxBits; ++mask) {
    std::string subseq = "";
    for (int j = 0; j < n; ++j) {
      if (mask & (1 << j)){
        subseq += s[j];
      }
      // std::cout << mask << " & " << (1 << j) << " -> " << (mask & (1 << j)) << std::endl;
    }
    int subseq_len = subseq.length();
    if(checkPalindrome(subseq, subseq_len, 0)) {
      bitmaskMap[mask] = subseq_len;
    }
  }

  int res = 0;
  // * O(Nˆ2)
  for(auto it1: bitmaskMap) {
    // std::cout << it.first << " " << it.second << std::endl;
    for(auto it2: bitmaskMap) {
      // * Disjoint Palindrome
      if((it1.first & it2.first) == 0) {
        res = std::max(res, it1.second * it2.second);
      }
    }
  }

  return res;
}

int main() {
  std::string s = "leetcodecom";
  // std::string s = "accbcaxxcxx";
  // std::string s = "fbuubfxmeemx";

  std::cout << "Input String: " << s << std::endl;
  int ans = maxProduct(s);
  std::cout << "Max length: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 02-max-product-of-len-of-two-palindromic-subsequence.cpp -o output && ./output