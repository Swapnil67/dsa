/**
 * * Leetcode 424
 * * Longest Repeating Character Replacement
 * * You are given a string s and an integer k. You can choose any character of the string and change it
 * * to any other uppercase English character. You can perform this operation at most k times.
 * 
 * * Example 1
 * * Input  : s = "ABAB", k = 2
 * * Output : 4
 * * Explanation: Replace the two 'A's with two 'B's or vice versa.

 * * Example 2
 * * Input  : s = "AABABBA", k = 1
 * * Output : 4
 * * Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".

 * * https://leetcode.com/problems/longest-repeating-character-replacement/description/
*/

#include <vector>
#include <iostream>

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Check all possible substrings
// * use => replacements = len_of_substr - max_frequency
// *                        (j - i + 1) - max_frequency
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(26)
int bruteForce(std::string s, int k) {
  int n = s.size(), max_len = 0;
  for (int i = 0; i < n; ++i) {
    int max_freq = 0;
    std::vector<int> char_hash(26, 0);
    int j = i;
    for (; j < n; ++j) {
      // * Incr the current character frequency
      char_hash[s[j] - 'A']++;
      // * check if max frequency of character changed
      max_freq = std::max(max_freq, char_hash[s[j] - 'A']);
      int replacements = (j - i) - max_freq;
      if (replacements >= k)
        break;
    }
    max_len = std::max(max_len, (j - i));
  }

  return max_len;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Keep char frequency vector
// * keep max_frequency character and find replacing characters by following formula
// * replacements = len_of_substr - max_frequency
// *                (j - i + 1) - max_frequency
// * Re-calcuate max_freq here
// * TIME COMPLEXITY O(2N) * O(26)
// * SPACE COMPLEXITY O(26)
int betterApproach(std::string s, int k) {
  int n = s.size();
  int i = 0, j = 0;
  int max_len = 0, max_freq = 0;
  std::vector<int> char_hash(26, 0);
  while(j < n) {
    // * Incr the current character frequency
    char_hash[s[j] - 'A']++;

    // * check if max frequency of character changed
    max_freq = std::max(max_freq, char_hash[s[j] - 'A']);

    // * While number of replacement required are greater than the max replacements
    // * Shrink window from left
    while ((j - i + 1) - max_freq > k) {
      char_hash[s[i] - 'A']--;
      max_freq = 0;
      // * find new max_freq
      for (int p = 0; p < 26; ++p) {
        max_freq = std::max(max_freq, char_hash[p]);
      }
      i++; // * Incr the left pointer
    }

    max_len = std::max(max_len, j - i + 1);

    j++; // * Incr the right pointer
  }
  return max_len;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * Keep char frequency vector
// * keep max_frequency character and find replacing characters by following formula
// * replacements = len_of_substr - max_frequency
// *                (j - i + 1) - max_frequency
// * Do not re-calcuate max_freq here
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(26)
int characterReplacement(std::string s, int k) {
  int n = s.size();
  int i = 0, j = 0;
  int max_len = 0, max_freq = 0;
  std::vector<int> char_hash(26, 0);
  while(j < n) {
    char_hash[s[j] - 'A']++;
    max_freq = std::max(max_freq, char_hash[s[j] - 'A']);

    // * if number of replacement required are greater than the max replacements
    if ((j - i + 1) - max_freq > k) {
      // * Shrink the window from left
      char_hash[s[i] - 'A']--;
      max_freq = 0;
      i++;
    }
    else {
      max_len = std::max(max_len, (j - i + 1));
    }

    j++;
  }
  return max_len;
}


int main() {
  // * testcase 1
  // int k = 1;
  // std::string s = "AABABBA";
  
  // * testcase 2
  int k = 2;
  std::string s = "ABAB";
  
  std::cout << "Input String: " << s << std::endl;
  int ans = bruteForce(s, k);
  // int ans = betterApproach(s, k);
  // int ans = characterReplacement(s, k);
  std::cout << "Longest Repeating Character Replacement: " << ans << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 17-longest-repeating-char-replacement.cpp -o output && ./output