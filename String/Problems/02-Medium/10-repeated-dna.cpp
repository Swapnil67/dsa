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
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * Output: ["AAAAACCCCC","CCCCCAAAAA"]
 * 
 * Example 2:
 * Input: s = "AAAAAAAAAAAAA"
 * Output: ["AAAAAAAAAA"]

 * https://www.naukri.com/code360/problems/repeated-substrings_1387094
 * https://leetcode.com/problems/repeated-dna-sequences/description/
*/

#include<set>
#include<iostream>

// ! Challenge
// TODO Solve this using bit manipulation

void printVectorString(std::vector<std::string> strs) {
  int n = strs.size();
  std::cout << "[ "; 
  for (std::string s : strs) {
    std::cout << s << ", ";
  }
  std::cout << "]" << std::endl;
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Find all possible 10 char substring
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
std::vector<std::string> repeatedSubstring(std::string s) {
  int n = s.size();

  std::set<std::string> seen;
  std::set<std::string> ansSet;

  for (int i = 0; i < n; ++i) {
    std::string t = "";
    for (int j = 0; j < 10; ++j) {
      if ((i + j) < n)
          t += s[i + j];
    }

    if(t.size() == 10) {
      if(seen.count(t))
        ansSet.insert(t);
      seen.insert(t);
    }
  }
  std::vector<std::string> ans(ansSet.begin(), ansSet.end());
  return ans;
}

int main() {
  std::string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  std::cout << str << std::endl;
  std::vector<std::string> ans = repeatedSubstring(str);
  printVectorString(ans); 
  return 0;
}

// * run the code
// * g++ --std=c++17 10-repeated-dna.cpp -o output && ./output