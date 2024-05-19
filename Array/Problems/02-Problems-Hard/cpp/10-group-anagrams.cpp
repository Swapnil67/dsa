/*
 * Group Anagrams
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

 * https://leetcode.com/problems/group-anagrams/
*/

#include<map>
#include<string>
#include<iostream>

void printVectorString(std::vector<std::string> arr) {
  std::cout<<"[ ";
  for(std::string s: arr) {
    std::cout<<s;
    std::cout<<", ";
  }
  std::cout<<"]\n";
}

void printAnagramGroups(std::vector<std::vector<std::string>> ans) {
  for(int i=0; i<ans.size(); i++) {
    printVectorString(ans[i]);
  }
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

// * TIME COMPLEXITY O(M) + O(N)
/*
* M -> number of strings
* N -> keys in StringMap
*/
// * SPACE COMPLEXITY O(N) // * For Answer
std::vector<std::vector<std::string>> bruteForce(std::vector<std::string> strs) {
  std::map<std::vector<int>, std::vector<std::string>> stringMap;
  // * O(M) M -> number of strings
  for(std::string s: strs) {
    std::vector<int> alphabets(26, 0);
    for(char c: s) {
      alphabets[int(c) - int('a')]++;
    }
    stringMap[alphabets].push_back(s);
  }
  std::vector<std::vector<std::string>> ans;

  // * O(N) N -> keys in StringMap
  for(auto it: stringMap) {
    ans.push_back(it.second);
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
std::vector<std::vector<std::string>> optimalApproach(std::vector<std::string> strs) {
  std::map<std::string, std::vector<std::string>> hash;

  for(std::string s: strs) {
    std::string t = s;
    std::sort(t.begin(), t.end());
    hash[t].push_back(s);
  }

  std::vector<std::vector<std::string>> ans;
  for(auto & [k, v]: hash) {
    ans.push_back(v);
  }
  return ans;
}

int main() {
  std::cout<<"Vector of strings"<<std::endl;
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

  printVectorString(strs);
  // std::vector<std::vector<std::string>> ans = bruteForce(strs);
  std::vector<std::vector<std::string>> ans = optimalApproach(strs);

  std::cout<<"Anagram Groups"<<std::endl;
  printAnagramGroups(ans);

  return 0;
}

// * Run the file
// * g++ --std=c++17 10-group-anagrams.cpp -o 10-group-anagrams && ./10-group-anagrams