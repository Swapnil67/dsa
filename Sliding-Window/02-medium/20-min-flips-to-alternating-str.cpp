/*
 * Leetcode - 1888
 * Minimum Number of Flips to Make the Binary String Alternating
 * 
 * You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:
 *   Type-1: Remove the character at the start of the string s and append it to the end of the string.
 *   Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
 * 
 * Return the minimum number of type-2 operations you need to perform such that s becomes alternating.
 * 
 * Example 1
 * Input  : s = "111000"
 * Output : 2
 * 
 * Example 2
 * Input  : s = "01001001101"
 * Output : 2
 * 
 * Example 3
 * Input  : s = "010"
 * Output : 0
 * 
 * https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/
 * 
*/

#include <iostream>
#include <climits>

using namespace std;

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Append string to itself
// * create two alternating string possiblilites and count flips within window
// * Classic Sliding window
// * TIME COMPLEXITY O(2N) * 2
// * SPACE COMPLEXITY O(2N)
int minFlips(string s) {
  int n = s.size();
  s = s + s;
  string alt1 = "", alt2 = "";

  // * Create two alternating strings of size n
  // * alt1 starts with '0' & alt2 starts with '1'
  for (int i = 1; i <= s.size(); ++i) {
    if(i % 2 == 0)  {
      alt1 += '0';
      alt2 += '1';
    } else {
      alt1 += '1';
      alt2 += '0';
    }
  }
  // cout << "Alternating 1: " << alt1 << " Alternating 2: " << alt2 << endl;

  int i = 0, j = 0;
  int ans = INT_MAX;
  int alt1_flips = 0, alt2_flips = 0;
  while(j < s.size()) {
    // * Count diff for alt1
    if(s[j] != alt1[j]) {
      alt1_flips++;
    }
    // * Count diff for alt2
    if(s[j] != alt2[j]) {
      alt2_flips++;
    }

    // * Shrink the window
    if ((j - i + 1) > n) {
      if(s[i] != alt1[i]) {
        alt1_flips--;
      }
      if(s[i] != alt2[i]) {
        alt2_flips--;
      }
      i++;
    }

    // * Get min flips b/2 alt1 & alt2
    if ((j - i + 1) == n) {
      // cout << alt1_flips << " " << alt2_flips << endl;
      ans = min(ans, min(alt1_flips, alt2_flips));
    }

    j++;
  }

  return ans;
}


int main() {
  // * testcase 1
  // string s = "111000";

  // * testcase 2
  string s = "01001001101";
  
  // * testcase 3
  // string s = "010";

  cout << "Input String: " << s << endl;
  int ans = minFlips(s);
  cout << "Minimum Number of Flips to Make the Binary String Alternating " << ans << endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 20-min-flips-to-alternating-str.cpp -o output && ./output


// * IDEA
// * 111000
// *                   1 1 1 0 0 0 1 1 1 0 0 0
// *                      /                \
// * 1 0 1 0 1 0 1 0 1 0 1 0   or   0 1 0 1 0 1 0 1 0 1 0 1

