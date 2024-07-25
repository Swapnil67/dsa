/**
 * * Find Words That Can Be Formed by Characters
 * * You are given an array of strings words and a string chars.
 * * A string is good if it can be formed by characters from chars (each character can only be used once).
 * * Return the sum of lengths of all good strings in words.

 * * Example 1
 * * Input  : words = ["cat","bt","hat","tree"], chars = "atach"
 * * Output : 6
 * * Explanation : The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

 * * Example 2
 * * Input  : words = ["hello","world","leetcode"], chars = "welldonehoneyr"
 * * Output : 10
 * * Explanation : The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

 * * https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/
*/

#include<iostream>
#include<unordered_map>

void printVectorString(std::vector<std::string> words) {
  for(std::string s: words) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
}


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Use Hashed Map
// * TIME COMPLEXITY O(N) + O(N x M)
// * N -> chars & M -> words
// * SPACE COMPLEXITY O(N * M) // * For Answer
int bruteForce(std::vector<std::string> words, std::string chars) {
  std::unordered_map<char, int> globalCharMap; 
  for(char c : chars) {
    globalCharMap[c]++;
  }

  int c = 0;
  for (std::string s : words) { 
    bool found = true;
    std::unordered_map<char, int> charMap;
    for(char c : s) {
      charMap[c]++;
      if(charMap.find(c) == charMap.end() || charMap[c] > globalCharMap[c]) {
        found = false;
        break;
      }
    }
    if(found) {
      c += s.size();
    } 
  }

  return c;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Use Hashed Array
// * TIME COMPLEXITY O(N) + O(N x M)
// * N -> chars & M -> words
// * SPACE COMPLEXITY O(1) // * For Answer
int countCharacters(std::vector<std::string> words, std::string chars) {
  std::vector<int> charVector(26, 0);
  for (char c : chars) {
    int idx = (int)(c) - (int)'a';
    charVector[idx]++;
  }
  
  int c = 0;
  for (std::string s : words) { 
    bool found = true;
    std::vector<int> curVector(26, 0);
    for(char c : s) {
      int idx = (int)(c) - (int)'a';
      curVector[idx]++;
      if(charVector[idx] == 0 || curVector[idx] > charVector[idx]) {
        found = false;
        break;
      }
    }
    if(found) {
      c += s.size();
    } 
  }

  return c;
}

int main() {
  std::vector<std::string> words = {"cat", "bt", "hat", "tree"};
  std::string chars = "atach";
  printVectorString(words);
  int ans = bruteForce(words, chars);
  // int ans = countCharacters(words, chars);
  std::cout << "Answer " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 10-find-words-formed-by-string.cpp -o 10-find-words-formed-by-string && ./10-find-words-formed-by-string