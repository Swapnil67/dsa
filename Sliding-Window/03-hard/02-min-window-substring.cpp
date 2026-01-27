/**
 * * Minimum Window Substring
 * * Example 1
 * * Input  : s = "ADOBECODEBANC", t = "ABC"
 * * Output : "BANC"
 * * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

 * * Example 2
 * * Input  : s = "a", t = "a"
 * * Output : 'a'
 * * Explanation: The entire string s is the minimum window.
 * 
 * * Example 3
 * * Input  : s = "a", t = "aa"
 * * Output : 1
 * * Explanation: Both 'a's from t must be included in the window.
 * * Since the largest window of s only has one 'a', return empty string.
 * 
 * * https://leetcode.com/problems/minimum-window-substring/description/
*/

#include <vector>
#include <string>
#include <climits>
#include <iostream>

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Check all possible substrings
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(256)
std::string bruteForce(std::string s, std::string t) {
  int n1 = s.length(), n2 = t.length();

  int start_i = -1, min_window_size = INT_MAX;

  // * Create 't' char frequency vector
  std::vector<int> t_vec_saved(256, 0);
  for(char &c: t) {
    t_vec_saved[c]++;
  }

  for(int i = 0; i <= n1 - n2; ++i) {

    // * use the pre-savaed t_vec
    std::vector<int> hash = t_vec_saved;

    int cur_count = 0;
    for(int j = i; j < n1; ++j) {
      if (hash[s[j]] > 0)
        cur_count++;
      
      hash[s[j]]--;
      if(cur_count == n2) {
        int cur_window = j - i + 1;
        if(cur_window < min_window_size) {
          min_window_size = cur_window;
          start_i = i;
        }
        break;
      }
    }
  }

  return start_i == -1 ? "" : s.substr(start_i, min_window_size);

}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * sliding window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(256)
std::string minWindow(std::string s, std::string t) {
  int n1 = s.length(), n2 = t.length();

  if (n2 > n1)
    return "";

  // * calculate the frequency map for string 't'
  std::vector<int> t_vec(256, 0);
  for (char &ch : t)
    t_vec[ch]++;

  int countRequired = n2, start_i = -1;
  int i = 0, j = 0, min_window_size = INT_MAX;
  while(j < n1) {
    // * If char is present in 't' the decr countRequired
    if (t_vec[s[j]] > 0) {
      countRequired--;
    }

    // * Decrment the char frequency
    t_vec[s[j]]--;

    // * found substring now shrink the window
    while (countRequired == 0) {
      // std::cout << i << " " << j << std::endl;

      // * get the substring count
      if((j - i + 1) < min_window_size) {
        start_i = i;
        min_window_size = (j - i + 1);
      }
      
      // * Add the ith char to vector
      t_vec[s[i]]++;
      
      // * if s[i] exists in 't' string then incr countRequired
      if (t_vec[s[i]] > 0)
        countRequired++;

      i++;
    }
    j++;
  }
  return start_i == -1 ? "" : s.substr(start_i, min_window_size);
}

int main() {
  // * testcase 1
  // std::string s = "ADOBECODEBANC", t = "ABC";

  // * testcase 2
  // std::string s = "flight", t = "it";

  // * testcase 3
  std::string s = "ninjas", t = "sin";

  std::cout << "s: " << s << std::endl;
  std::cout << "t: " << t << std::endl;

  // std::string ans = bruteForce(s, t);
  std::string ans = minWindow(s, t);

  std::cout << "Minimum Window Substring: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 02-min-window-substring.cpp -o output && ./output