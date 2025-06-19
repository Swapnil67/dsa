/*
 * Leetcode - 2109
 * Adding Spaces to a String
 * 
 * Example 1
 * Input  : s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
 * Output : "Leetcode Helps Me Learn"
 * 
 * Example 2
 * Input  : s = "icodeinpython", spaces = [1,5,7,9]
 * Output : "i code in py thon"
 * 
 * Example 3
 * Input  : s = "spacing", spaces = [0,1,2,3,4,5,6]
 * Output : " s p a c i n g"
 * 
 * https://leetcode.com/problems/adding-spaces-to-a-string
*/

#include <vector>
#include <iostream>

std::string addSpaces(std::string s, std::vector<int> spaces) {
  int m = s.length();
  int n = spaces.size();
  int j = 0;

  std::string ans = "";
  for (int i = 0; i < m; ++i) {
    // * check if the current char is space
    if (j < n && i == spaces[j]) {
      ans += ' ';
      j++;
    }
    ans += s[i];
  }
  return ans;
}

int main() {
  // * testcase 1
  std::string s = "LeetcodeHelpsMeLearn";
  std::vector<int> spaces = {8, 13, 15};
  
  // * testcase 2
  // std::string s = "icodeinpython";
  // std::vector<int> spaces = {1, 5, 7, 9};
  
  // * testcase 3
  // std::string s = "spacing";
  // std::vector<int> spaces = {0, 1, 2, 3, 4, 5, 6};

  std::string ans = addSpaces(s, spaces);
  std::cout << ans << std::endl;
}

// * Run the code
// * g++ --std=c++20 18-add-spaces-to-str.cpp -o output && ./output
