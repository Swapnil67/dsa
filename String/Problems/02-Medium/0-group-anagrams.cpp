/*
 * Group Anagrams
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

 * https://leetcode.com/problems/group-anagrams/
 * https://www.naukri.com/code360/problems/group-anagrams_800285
*/

#include <map>
#include <string>
#include <iostream>

void printVectorString(std::vector<std::string> arr) {
  std::cout<<"[ ";
  for(std::string s: arr) {
    std::cout<<s;
    std::cout<<", ";
  }
  std::cout<<"]\n";
}

void printAnagramGroups(std::vector<std::vector<std::string>> ans) {
  for (int i = 0; i < ans.size(); i++) {
    printVectorString(ans[i]);
  }
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(M x C) + O(N)
/*
* M -> number of strings
* C -> number of characters
* N -> keys in StringMap
*/
// * SPACE COMPLEXITY O(N) // * For Answer
std::vector<std::vector<std::string>> bruteForce(std::vector<std::string> strs) {
  std::vector<std::vector<std::string>> ans;
  std::map<std::vector<int>, std::vector<std::string>> strMap;

  // * O(M) M -> number of strings
  for (std::string s : strs) {
    std::vector<int> alphabets(26, 0);
    for (char ch : s) {
      int idx = (int)ch - (int)'a';
      alphabets[idx]++;
    }
    strMap[alphabets].push_back(s);
  }

  // * O(N) N -> keys in StringMap
  for (auto it : strMap) {
    ans.push_back(it.second);
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(MlogN) + O(N)
/*
* M -> number of strings
* logN -> For sorting
* N -> keys in strMap
*/
// * SPACE COMPLEXITY O(N) // * For Answer
std::vector<std::vector<std::string>> bruteForce(std::vector<std::string> strs) {
  std::map<std::string, std::vector<std::string>> strMap;
  // * O(MlogN)
  for (std::string s : strs) {
    std::string t = s;
    std::sort(t.begin(), t.end());
    strMap[t].push_back(s);
  }

  // * O(N)
  std::vector<std::vector<std::string>> ans;
  for(auto &[k, v] : strMap) {
    ans.push_back(v);
  }

  return ans;
}

int main() {
  std::cout << "Vector of strings" << std::endl;
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

  printVectorString(strs);
  // std::vector<std::vector<std::string>> ans = bruteForce(strs);
  std::vector<std::vector<std::string>> ans = optimalApproach(strs);

  std::cout<<"Anagram Groups"<<std::endl;
  printAnagramGroups(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++17 0-group-anagrams.cpp -o 0-group-anagrams && ./0-group-anagrams
