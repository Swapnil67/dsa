/**
 * * Leetcode - 2516
 * * Take K of Each Character From Left and Right
 * * You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. 
 * * Each minute, you may take either the leftmost character of s, or the rightmost character of s.
 * 
 * * Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it 
 * * is not possible to take k of each character.
 * 
 * * Example 1
 * * Input  : s = "aabaaaacaabc", k = 2
 * * Output : 8
 * * Explanation: Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
 * * Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
 * * A total of 3 + 5 = 8 minutes is needed.

 * * https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/
*/

#include <vector>
#include <climits>
#include <iostream>

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Classic Sliding Window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int takeCharacters(std::string s, int k) {
  int n = s.length();

  // * Calculate total number of 'a', 'b' & 'c' characters
  std::vector<int> char_freq(3, 0); // * a, b, c
  for (char &ch : s) {
    char_freq[ch - 'a']++;
  }

  // * Not possible to delete 'k' characters
  if (char_freq[0] < k || char_freq[1] < k || char_freq[2] < k) {
    return -1;
  }

  int max_window = 0, i = 0, j = 0;
  while (j < n) {
    char_freq[s[j] - 'a']--;

    // * Shrink from left
    while (i <= j && char_freq[s[j] - 'a'] < k) {
      char_freq[s[i] - 'a']++;
      i++;
    }

    // * 'a' >= k || 'b' >= k || 'c' >= k
    if (char_freq[0] >= k && char_freq[1] >= k && char_freq[2] >= k) {
      max_window = std::max(max_window, (j - i + 1));
    }
    j++;    
  }
  // std::cout << max_window << std::endl;

  return n - max_window; // * minutes 
}

int main() {
  // int k = 2;
  // std::string s = "aabaaaacaabc";

  int k = 1;
  std::string s = "a";

  // int k = 1;
  // std::string s = "abc";

  std::cout << "Input String: " << s << std::endl;
  int ans = takeCharacters(s, k);
  std::cout << "Minimum number of minutes needed: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 28-take-k-of-each-char-from-left-or-right.cpp -o output && ./output