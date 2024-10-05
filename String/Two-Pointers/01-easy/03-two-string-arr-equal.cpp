/*
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

#include<iostream>

void printVectorString(std::vector<std::string> strs) {
  int n = strs.size();
  std::cout << "[ "; 
  for (std::string s : strs) {
    std::cout << s << ", ";
  }
  std::cout << "]" << std::endl;
}


std::string getValidString(std::vector<std::string> word_arr) {
  std::string s = "";
  for(std::string str : word_arr) {
    s += str;
  }
  return s;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Create string from input array
// * TIME COMPLEXITY O(n + m)
// * SPACE COMPLEXITY O(n)
bool bruteForce(std::vector<std::string> word1, std::vector<std::string> word2) {
  std::string s = getValidString(word1);
  std::string t = getValidString(word2);
  std::cout << "Word 1: " << s << ", Word 2: " << t << std::endl;
  return s == t;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * loop from end k string
// * TIME COMPLEXITY O(n) + O(m)
// * SPACE COMPLEXITY O(1)
bool arrayStringsAreEqual(std::vector<std::string> word1, std::vector<std::string> word2) {
  int n1 = word1.size(), n2 = word2.size();
  int w1 = 0, w2 = 0; // * Index of word
  int i = 0, j = 0;   // * Index of char

  while (w1 < n1 && w2 < n2) {
    if(i < word1[w1].size() && j < word2[w2].size()) {
      if(word1[w1][i] != word2[w2][j]) {
        return false;
      }
      i++, j++;
    }
    else {
       // * i goes out of bound
      if (i >= word1[w1].size() && w1 < n1) {
        w1++;
        i = 0;
      }
      // * j goes out of bound
      if (j >= word2[w2].size() && w2 < n2) {
        w2++;
        j = 0;
      }
    }
  }

  std::cout << "i: " << i << ",\tj: " << j << std::endl;
  std::cout << "w1: " << w1 << ",\tw2: " << w2 << std::endl;

  // * Check if both arrays have ended
  if(w1 != n1 || w2 != n2) {
    return false;
  }
  return true;
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
// * g++ --std=c++17 03-two-string-arr-equal.cpp -o output && ./output