/*
 * Optimal Partition of String 
 * Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. 
 * That is, no letter appears in a single substring more than once.
 * 
 * Return the minimum number of substrings in such a partition.
 * Note that each character should belong to exactly one substring in a partition.

 * Example 1:
 * Input: s = "abacaba"
 * Output: 4
 * Explanation: Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
 * It can be shown that 4 is the minimum number of substrings needed.
 * 
 * Example 2:
 * Input: s = "ssssss"
 * Output: 6
 * Explanation: The only valid partition is ("s","s","s","s","s","s").
 * 
 * https://leetcode.com/problems/optimal-partition-of-string/description/
*/

#include<iostream>

int partitionString(std::string s) {
  int n = s.size();
  int sub_strings_cnt = 1;
  std::bitset<26> bitSet;
  for (int i = 0; i < n; ++i) {
    // * check if bit for cur char already set
    if(bitSet[s[i] - 'a']) {
      sub_strings_cnt++;
      bitSet.reset();
    }
    bitSet.set(s[i] - 'a');
  }

  return sub_strings_cnt;
}

int main() {
  // * testcase 1
  // std::string s = "abacaba";
  // * testcase 2
  std::string s = "aaababcc";
  std::cout << s << std::endl;
  
  int ans = partitionString(s);
  std::cout << ans << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 12-optimal-partition-of-str.cpp -o output && ./output