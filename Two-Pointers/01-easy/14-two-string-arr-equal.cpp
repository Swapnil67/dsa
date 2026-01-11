/*
 * Leetcode - 1662
 * Check If Two String Arrays are Equivalent
 * Given two string arrays word1 and word2, return true if the two arrays represent the same string, 
 * and false otherwise.
 * 
 * Example 1
 * Input  : word1 = ["ab", "c"], word2 = ["a", "bc"]
 * Output : true
 * 
 * Example 2
 * Input  : word1 = ["a", "cb"], word2 = ["ab", "c"]
 * Output : false

 * https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/
*/

#include <vector>
#include <iostream>

void printVectorString(std::vector<std::string> strs) {
  int n = strs.size();
  std::cout << "[ "; 
  for (std::string s : strs) {
    std::cout << s << ", ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Create string from input array
// * TIME COMPLEXITY O(n + m)
// * SPACE COMPLEXITY O(n)
bool bruteForce(std::vector<std::string> word1, std::vector<std::string> word2) {
  std::string s1 = "";
  for (auto &w : word1)
    s1 += w;
  std::string s2 = "";
  for (auto &w : word2)
    s2 += w;
  return (s1 == s2);
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * n1 - size of word1, n2 - size of word2
// * TIME COMPLEXITY O(n1) + O(n2)
// * SPACE COMPLEXITY O(1)
bool arrayStringsAreEqual(std::vector<std::string> word1, std::vector<std::string> word2) {
  int n1 = word1.size(), n2 = word2.size();
  int i = 0, j = 0; 
  int m = 0, n = 0; // * Index of word
  while (m < n1 && n < n2) {
    if (i >= word1[m].size()) {
      m += 1;
      i = 0; // * reset word index
    }
    
    if (j >= word2[n].size()) {
      n += 1;
      j = 0; // * reset word index
    }

    if (m < n1 && n < n2 && word1[m][i] != word2[n][j]) {
      return false;
    }
    i++, j++;
  }
  return (m >= n1 && n >= n2);
}

int main() {
  // * testcase 1
  // std::vector<std::string> word1 = {"ab", "c"}, word2 = {"a", "bc"};
  // std::vector<std::string> word1 = {"a", "cb"}, word2 = {"ab", "c"};
  std::vector<std::string> word1 = {"abc", "d", "defg"}, word2 = {"abcddef"};
  // std::vector<std::string> word1 = {"a"}, word2 = {"a", "b"};

  printVectorString(word1);
  printVectorString(word2);

  // bool ans = bruteForce(word1, word2);
  bool ans = arrayStringsAreEqual(word1, word2);
  std::cout << ans << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++17 14-two-string-arr-equal.cpp -o output && ./output