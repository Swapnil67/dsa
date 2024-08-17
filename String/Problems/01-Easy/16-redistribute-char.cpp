/**
 * * Redistribute Characters to Make All Strings Equal
 * * You are given an array of strings words (0-indexed).
 * * In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, 
 * * and move any character from words[i] to any position in words[j].
 * * Return true if you can make every string in words equal using any number of operations, and false otherwise.

 * * Example 1
 * * Input  : words = ["abc","aabc","bc"]
 * * Output : true
 * * Explanation : Move the first 'a' in words[1] to the front of words[2],
 * * to make words[1] = "abc" and words[2] = "abc".
 * * All the strings are now equal to "abc", so return true.
 * 
 * * Example 2
 * * Input  : words = ["ab","a"]
 * * Output : false
 * * Explanation: It is impossible to make all the strings equal using the operation.
 * 
 * * https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/
*/

#include<map>
#include<iostream>

void printVectorString(std::vector<std::string> strs) {
  int n = strs.size();
  std::cout << "[ ";
  for (std::string s : strs) {
    std::cout << s << ", ";
  }
  std::cout << "]" << std::endl;
}

bool makeEqual(std::vector<std::string> words) {
  int n = words.size();
  int charArr[26] = {0};
  for(std::string s : words) {
    for(char c : s) {
      charArr[c - 'a']++;
    }

  }
  for(auto &it: charArr) {
    if (it % n != 0)
      return false;
  }
  return true;
}

int main() {
  std::vector<std::string> words = {"abc", "aabc", "bc"};
  // std::vector<std::string> words = {"ab", "a"};
  printVectorString(words); 
  bool ans = makeEqual(words);
  std::cout << "Answer " << ans << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++17 16-redistribute-char.cpp -o 16-redistribute-char && ./16-redistribute-char