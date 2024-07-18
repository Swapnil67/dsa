/**
 * * Valid Anagram
 * * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
 * * typically using all the original letters exactly once.

 * * Example 1
 * * Input  : s = "anagram", t = "nagaram"
 * * Output : true

 * * Example 2
 * * Input  : s = "rat", t = "car"
 * * Output : false

 * * https://leetcode.com/problems/valid-anagram/description/
 * * https://www.naukri.com/code360/problems/anagram-pairs_626517
*/


#include<iostream>
#include<unordered_map>

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Hashmap
// * TIME COMPLEXITY O(s) + O(t) [Unordered Map]
// * SPACE COMPLEXITY O(s)
bool bruteForce(std::string s, std::string t) {
  std::unordered_map<char, int> charMap;
  for(char ch : s) {
    charMap[ch]++;
  }

  for(char ch : t) {
    if (charMap.find(ch) != charMap.end() && charMap[ch] > 0) {
      charMap[ch]--;
    }
    else {
      return false;
    }
  }
  return true;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Hashed Array
// * TIME COMPLEXITY O(S) + O(t)
// * SPACE COMPLEXITY O(1)
bool validAnagram(std::string s, std::string t) {
  std::vector<int> alphabets(26, 0);
  for(char ch : s) {
    int idx = (int)ch - (int)'a';
    alphabets[idx]++;
  }

  for (char ch : t) {
    int idx = (int)ch - (int)'a';
    if (alphabets[idx] <= 0)
      return false;
    alphabets[idx]--;
  }
  return true;
}

int main() {
  // * testcase 1
  // std::string s = "anagram", t = "nagaram";
  // * testcase 2
  std::string s = "aacc", t = "ccac";
  std::cout << "s = " << s << " t = " << t << std::endl;
  // bool isValid = bruteForce(s, t);
  bool isValid = validAnagram(s, t);
  std::cout << "Is valid anagram " << isValid << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 05-valid-anagram.cpp -o 05-valid-anagram && ./05-valid-anagram
