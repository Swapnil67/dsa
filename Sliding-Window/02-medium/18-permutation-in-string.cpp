/**
 * * Leetcode - 567
 * * Permutation in String
 * * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 * * to any other uppercase English character. You can perform this operation at most k times.
 * 
 * * Example 1
 * * Input  : s1 = "ab", s2 = "eidbaooo"
 * * Output : true
 * * Explanation: s2 contains one permutation of s1 ("ba").

 * * Example 2
 * * Input  : s1 = "ab", s2 = "eidboaoo"
 * * Output : false

 * * https://leetcode.com/problems/permutation-in-string/description/
*/
#include <vector>
#include <iostream>
#include <algorithm>

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * TIME COMPLEXITY O(n! * n)
// TODO

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Sort the string s1
// * Check all substring of length string s1 in string s2 
// * TIME COMPLEXITY O(m - n) * O(nlogn)
// * SPACE COMPLEXITY O(n)
bool betterApproach(std::string s1, std::string s2) {
  int n1 = s1.size(), n2 = s2.size();

  // * This is not possible
  if (n1 > n2)
    return false;
  
  std::sort(s1.begin(), s1.end()); // * Sort the s1 string

  for (int i = 0; i < n2 - n1; ++i) {
    // * take n1 len of substrings from s2
    std::string temp = s2.substr(i, n1);
    std::sort(temp.begin(), temp.end());
    // std::cout << temp << " -> " << s1.compare(temp) << std::endl;
    if (s1.compare(temp) == 0)
      return true;
  }

  return false;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * Calculate character frequency vector of s1 string
// * Compare frequecy vectors of s1 & s2 using sliding window approach
// * TIME COMPLEXITY O(m + n)
// * SPACE COMPLEXITY O(26)
bool checkInclusion(std::string s1, std::string s2) {
  int n1 = s1.size(), n2 = s2.size();

  // * Calculate s1 string character frequency
  std::vector<int> s1_freq_vec(26, 0);
  for(char &ch : s1) {
    s1_freq_vec[ch - 'a']++;
  }

  int i = 0, j = 0;
  std::vector<int> s2_freq_vec(26, 0);
  while (j < n2) {
    s2_freq_vec[s2[j] - 'a']++;

    // * Shrink window
    if (j - i + 1 > n1) {
      s2_freq_vec[s2[i] - 'a']--;
      i++;
    }

    // * compare two vectors
    if (s1_freq_vec == s2_freq_vec)
      return true;

    j++;
  }

  return false;
}


int main() {
  // * testcase 1
  // std::string s1 = "ab", s2 = "eidbaooo";

  // * testcase 2
  std::string s1 = "ab", s2 = "eidboaoo";

  std::cout << "String 1: " << s1 << std::endl;
  std::cout << "String 2: " << s2 << std::endl;

  bool ans = betterApproach(s1, s2);
  // bool ans = checkInclusion(s1, s2);
  std::cout << "Permutation in String: " << ans << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 18-permutation-in-string.cpp -o output && ./output