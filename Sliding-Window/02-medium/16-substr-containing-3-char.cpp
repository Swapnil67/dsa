/**
 * * Leetcode - 1358
 * * Number of Substrings Containing All Three Characters
 * * Given a string s consisting only of characters a, b and c.
 * * Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 * * Example 1
 * * Input  : s = "abcabc"
 * * Output : 10
 * * Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", 
 * * "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again)

 * * Example 2
 * * Input  : s = "aaacb"
 * * Output : 3
 * * Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

 * * https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
*/

#include <iostream>
#include <bits/stdc++.h>

int bruteForce(std::string s) {
  int n = s.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    std::vector<int> hash(3, 0);
    for (int j = i; j < n; ++j) {
      hash[s[j] - 'a'] = 1;
      if(hash[0] + hash[1] + hash[2] == 3) {
        // std::cout << n - j << std::endl;
        ans = ans + (n - j);
        break;
      }
    }
  }
  return ans;
}

int numberOfSubstrings(std::string s) {
  int n = s.size();
  int i = 0, j = 0, ans = 0;
  std::vector<int> hash(3, 0);
  while(j < n) {
    hash[s[j] - 'a']++;

    while (hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
      ans = ans + (n - j);
      hash[s[i] - 'a']--;
      i++;
    }

    j++;
  }
  return ans;
}

int numberOfSubstrings2(std::string s) {
  int n = s.size();
  int ans = 0;
  std::vector<int> hash(3, -1);
  for (int i = 0; i < n; ++i) {
    hash[s[i] - 'a'] = i;
    int window_min_idx = *(std::min_element(hash.begin(), hash.end()));
    ans = ans + (window_min_idx + 1);
  }
  return ans;
}


int main() {
  std::string s = "abcabc";
  std::cout << "Input String: " << s << std::endl;
  // int ans = bruteForce(s);
  int ans = numberOfSubstrings(s);
  std::cout << "Number of Substrings Containing All Three Characters: " << ans << std::endl;
  
  return 0;
}
