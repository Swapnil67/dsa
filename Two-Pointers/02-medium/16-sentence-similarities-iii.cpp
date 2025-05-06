/*
 * Leetcode - 1813
 
 * Sentence Similarity III
 * You are given two strings sentence1 and sentence2, each representing a sentence composed of words. 
 * A sentence is a list of words that are separated by a single space with no leading or trailing spaces. 
 * Each word consists of only uppercase and lowercase English characters.
 * 
 * Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty)
 * inside one of these sentences such that the two sentences become equal. 
 * Note that the inserted sentence must be separated from existing words by spaces.
 * 
 * Example: 1
 * Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
 * Output: true
 * Explanation: sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".
 * 
 * Example: 2
 * Input: sentence1 = "of", sentence2 = "A lot of words"
 * Output: false
 * Explanation: No single sentence can be inserted inside one of the sentences to make it equal to the other.

 * Example: 2
 * Input: sentence1 = "Eating right now", sentence2 = "Eating"
 * Output: true
 * Explanation: sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.

 * https://leetcode.com/problems/sentence-similarity-iii/description/
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

std::vector<std::string> getStringVector(std::string sentence) {
  std::string word = "";
  std::vector<std::string> vec;
  for(char &ch : sentence) {
    if (ch == ' ') {
      vec.push_back(word);
      word = "";
    } else {
      word += ch;
    }
  }
  vec.push_back(word);
  return vec;
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------`
// * TIME COMPLEXITY O(s1) + O(s2)
// * SPACE COMPLEXITY O(s1 + s2)
bool areSentencesSimilar(std::string s1, std::string s2) {
  int n1 = s1.size(), n2 = s2.size();
  if(n1 < n2) {
    return areSentencesSimilar(s2, s1);
  }

  // * create vector string of words of s1
  std::vector<std::string> vec1 = getStringVector(s1);

  // * create vector string of words of s2
  std::vector<std::string> vec2 = getStringVector(s2);

  // * for debug
  // printVectorString(vec1);
  // printVectorString(vec2);

  int i = 0, j = vec1.size() - 1; // * for s1
  int l = 0, r = vec2.size() - 1; // * for s2

  while (l < vec2.size() && i < vec1.size() && vec1[i] == vec2[l]) {
    // std::cout << vec1[i] << " " << vec2[k] << std::endl;
    i++;
    l++;
  }

  while (j >= 0 && r >= 0 && (vec1[j] == vec2[r])) {
    // std::cout << vec1[j] << " " << vec2[l] << std::endl;
    j--;
    r--;
  }

  // std::cout << k << " " << l << std::endl;
  return l > r;
}

int main() {
  // * testcase 1
  std::string s1 = "My name is Haley", s2 = "My Haley";

  // * testcase 2
  // std::string s1 = "of", s2 = "of course";

  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;

  bool ans = areSentencesSimilar(s1, s2);
  std::cout << "Is similar sentences: " << ans << std::endl;
}

// * Run the code
// * g++ --std=c++17 16-sentence-similarities-iii.cpp -o output && ./output