/**
 * * Minimum Number of Flips to Make the Binary String Alternating
 * * Example 1
 * * Input  : s = "111000"
 * * Output : 2

 * * Example 2
 * * Input  : s = "01001001101"
 * * Output : 2
 * 
 * * Example 3
 * * Input  : s = "010"
 * * Output : 0

 * * https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/
*/

#include<iostream>
#include<climits>

int minFlips(std::string s) {
  int n = s.size();
  s = s + s;
  std::string alt1 = "", alt2 = "";

  for (int i = 1; i <= s.size(); ++i) {
    if(i % 2 == 0)  {
      alt1 += '0';
      alt2 += '1';
    } else {
      alt1 += '1';
      alt2 += '0';
    }
  }
  std::cout << "Alternating 1: " << alt1 << " Alternating 2: " << alt2 << std::endl;

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
      // std::cout << alt1_flips << " " << alt2_flips << std::endl;
      ans = std::min(ans, std::min(alt1_flips, alt2_flips));
    }

    j++;
  }

  return ans;
}


int main() {
  // std::string s = "111000";
  // std::string s = "01001001101";
  std::string s = "010";
  std::cout << "Input String: " << s << std::endl;
  int ans = minFlips(s);
  std::cout << "Minimum Number of Flips to Make the Binary String Alternating " << ans << std::endl;
  return 0;
}


// * Run the code
// * $CXX --std=c++17 07-min-flips-to-alternating-str.cpp -o output && ./output