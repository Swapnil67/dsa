/**
 * * Longest Common Prefix
 * * Write a function to find the longest common prefix string amongst an array of strings.

 * * Example 1
 * * Input : strs = ["flower","flow","flight"]
 * * Output : "fl"

 * * Example 2
 * * Input : strs = ["dog","racecar","car"]
 * * Output : ""
 * * Explanation: There is no common prefix among the input strings.

 * * https://leetcode.com/problems/longest-common-prefix/description/
 * * https://www.naukri.com/code360/problems/longest-common-prefix_2090383
*/

#include<unordered_map>
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

// * TIME COMPLEXITY O(M x N)
/*
* M = length of first string
* N = Number of strings in arrays
*/
// * SPACE COMPLEXITY O(1)
std::string longestCommonPrefix(std::vector<std::string> strs) {
  int n = strs.size();
  std::string res = "";
  if (n == 0)
    return res;
    
  // * Loop over the first string in array
  for (int i = 0; i < strs[0].length(); i++) {
    char ch = strs[0][i];

    // * Loop over rest of strings
    bool match = true;
    for (int j = 1; j < n; j++) {
      if (strs[j][i] != ch) {
        match = false;
        break;
      }
    }

    if(match == false) {
      break;
    }
    res += ch;
  } 
  return res;
}

// TODO Solve this problem using trie data-structure

int main() {
  std::vector<std::string> strs = {"flower", "flow", "flight"};
  printVectorString(strs);
  std::string commonPrefix = longestCommonPrefix(strs);
  std::cout << "Longest Common Prefix is = " << commonPrefix << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-longest-common-prefix.cpp -o 04-longest-common-prefix && ./04-longest-common-prefix