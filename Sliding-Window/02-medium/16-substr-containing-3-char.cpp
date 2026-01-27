/*
 * Leetcode - 1358
 * Number of Substrings Containing All Three Characters
 * 
 * Given a string s consisting only of characters a, b and c.
 * Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 * Example 1
 * Input  : s = "abcabc"
 * Output : 10
 * Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", 
 * "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again)

 * Example 2
 * Input  : s = "aaacb"
 * Output : 3
 * Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

 * https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
 * https://www.geeksforgeeks.org/problems/count-substring/1
*/

#include <vector>
#include <iostream>

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

// * ------------------------- APPROACH 2A: Optimal Approach -------------------------`
// * Classic sliding window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int numberOfSubstrings(std::string s) {
  int n = s.size();
  int i = 0, j = 0, ans = 0;
  std::vector<int> hash(3, 0);
  while (j < n) {
    hash[s[j] - 'a']++;

    // * While all 3 characters are present
    while (i <= j && hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
      ans = ans + (n - j);
      hash[s[i] - 'a']--;
      i++;
    }

    j++;
  }
  return ans;
}

int main() {
  // * testcase 1
  std::string s = "abcabc";

  // * testcase 2
  // std::string s = "aaacb";

  std::cout << "Input String: " << s << std::endl;
  // int ans = bruteForce(s);
  int ans = numberOfSubstrings(s);
  std::cout << "Number of Substrings Containing All Three Characters: " << ans << std::endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 16-substr-containing-3-char.cpp -o output && ./output