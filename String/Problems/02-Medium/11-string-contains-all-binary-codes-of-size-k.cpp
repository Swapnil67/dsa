/*
 * Repeated DNA Sequences
 * The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
 * For example, "ACGAATTCCG" is a DNA sequence.
 * 
 * When studying DNA, it is useful to identify repeated sequences within the DNA.
 * Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings)
 * that occur more than once in a DNA molecule. You may return the answer in any order.
 * 
 * Example 1:
 * Input: s = "00110110", k = 2
 * Output: true
 * Explanation: The binary codes of length 2 are "00", "01", "10" and "11".
 * They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
 * 
 * Example 2:
 * Input: s = "0110", k = 1
 * Output: true
 * Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
 * 
 * Example 3:
 * Input: s = "0110", k = 2
 * Output: false
 * Explanation: The binary code "00" is of length 2 and does not exist in the array.

 * https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/
*/

#include<set>
#include<iostream>

// * Sliding Window Approach
// * TIME COMPLEXITY O(s * k)
// * SPACE COMPLEXITY O(s * k)
bool hasAllCodes(std::string s, int k) {
  // * all possible binary codes
  int possibleBinaryCodes = std::pow((long double)2, (long double)k);

  std::set<std::string> binarySubstrSet;

  int n = s.size();

  // * get all possible binary codes of size two
  for (int i = 0; i < n; ++i) {
    std::string b = "";
    for (int j = 0; j < k; ++j) {
      if ((i + j) < n)
        b += s[i + j];
    }
    if (b.size() == k)
      binarySubstrSet.insert(b);
  }

  // * possible binary codes
  // for(std::string s : binarySubstrSet) {
  //   std::cout << s << std::endl;
  // }

  return binarySubstrSet.size() == possibleBinaryCodes;
}

int main() {
  std::string s = "0110";
  int k = 2;
  std::cout << s << std::endl;
  bool ans = hasAllCodes(s, k);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 11-string-contains-all-binary-codes-of-size-k.cpp -o output && ./output