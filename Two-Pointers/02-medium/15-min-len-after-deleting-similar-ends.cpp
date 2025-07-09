/*
 * Leetcode - 1750
 * Minimum Length of String After Deleting Similar Ends
 * Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm 
 * on the string any number of times:

 * 1. Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
 * 2. Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
 * 3. The prefix and the suffix should not intersect at any index.
 * 4. The characters from the prefix and suffix must be the same.
 * 5. Delete both the prefix and the suffix
 * 
 * Example 1
 * Input  : s = "cabaabac"
 * Output : 0
 *  
 * Example 2
 * Input  : s = "aabccabba"
 * Output : 3
 * Explanation: the remaining string is "cca"

 * https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/
*/

#include <iostream>

int minimumLength(std::string s) {
  int n = s.size();
  int i = 0, j = n - 1;
  while(i < j) {
    // std::cout << i << " " << j << std::endl;
    if(s[i] != s[j]) {
      break;
    }
    
    // * move both pointers once
    i++;
    j--;

    // * check if prefix are equal
    while (i < j && s[i] == s[i - 1]) {
      i++;
    }

    // * check if suffix are equal
    while (j >= i && s[j] == s[j + 1]) {
      j--;
    }
  }
  return j - i + 1;
}

int main() {
  // * testcase 1
  // std::string s = "cabaabac";

  // * testcase 2
  // std::string s = "aabccabba";
  
  // * testcase 3
  std::string s = "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb";

  std::cout << s << std::endl;
  int length = minimumLength(s);
  std::cout << length << std::endl;
}

// * Run the code
// * g++ --std=c++17 15-min-len-after-deleting-similar-ends.cpp -o output && ./output