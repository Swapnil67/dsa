/**
 * * Leetcode - 1456
 * * Maximum Number of Vowels in a Substring of Given Length
 * * YGiven a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
 * 
 * * Example 1
 * * Input  : s = "abciiidef", k = 3
 * * Output : 3
 * * Explanation: The substring "iii" contains 3 vowel letters.

 * * Example 2
 * * Input  : s = "leetcode", k = 3
 * * Output : 2
 * * Explanation: "lee", "eet" and "ode" contain 2 vowels.

 * * https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
*/

#include<iostream>
#include<bits/stdc++.h>

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Check all possible substrings of less than k
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(26)
int bruteForce(std::string s, int k) {
  int n = s.size();
  int ans = INT_MIN;
  std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  for (int i = 0; i < n; ++i) {
    std::string temp = "";
    for (int j = i; (k + i < n && j < k + i); ++j) {
      if(vowels.count(s[j])) {
        temp += s[j];
      }
      else {
        break;
      }
    }
    ans = std::max(ans, (int)temp.size());
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Keep count c for cur vowel substring length
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxVowels(std::string s, int k) {
  int n = s.size();
  int max_vowels_cnt = INT_MIN;
  int i = 0, j = 0, vowel_cnt = 0;
  std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  while(j < n) {
    // * Check if vowel
    if (vowels.count(s[j])) {
      vowel_cnt++;
    }

    // * Minimize window
    if ((j - i + 1) > k) {
      if(vowels.count(s[i])) {
        vowel_cnt--;
      }
      i++;
    }
    else {
      // * count vowels substring
      max_vowels_cnt = std::max(max_vowels_cnt, vowel_cnt);
    }
    j++;
  }
  return max_vowels_cnt;
}


int main() {
  // int k = 3;
  // std::string s = "abciiidef";
  int k = 2;
  std::string s = "aeiou";
  // int k = 3;
  // std::string s = "leetcode";
  std::cout << "k: " << k << std::endl;
  std::cout << "Input String: " << s << std::endl;

  // int ans = bruteForce(s, k);
  int ans = maxVowels(s, k);
  std::cout << "Maximum Number of Vowels: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 19-max-vowels.cpp -o output && ./output