/*
 * Group Anagrams
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

 * https://leetcode.com/problems/group-anagrams/
*/

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


int main() {
  std::cout<<"Vector of strings"<<std::endl;
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

  printVectorString(strs);
  // std::vector<std::vector<std::string>> ans = bruteForce(strs);
  // std::vector<std::vector<std::string>> ans = optimalApproach(strs);

  // std::cout<<"Anagram Groups"<<std::endl;
  // printAnagramGroups(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++17 0-group-anagrams.cpp -o 0-group-anagrams && ./0-group-anagrams
