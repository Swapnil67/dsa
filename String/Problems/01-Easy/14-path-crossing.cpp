/**
 * * Maximum Score After Splitting a String
 * * Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty 
 * * substrings (i.e. left substring and right substring).

 * * Example 1
 * * Input  : s = "011101"
 * * Output : 5
 * * Explanation : When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
 * 
 * * Example 2
 * * Input  : s = "1111"
 * * Output : 3
 * 
 * * https://leetcode.com/problems/path-crossing/description/
*/

#include<set>
#include<iostream>
#include<unordered_map>

using std::string;

std::unordered_map<char, std::vector<int>> dir = {
  {'N', {0, 1}},
  {'S', {0, -1}},
  {'E', {1, 0}},
  {'W', {-1, 0}}
};

bool isPathCrossing(string path) {
  int x = 0, y = 0;
  std::set<std::vector<int>> visitedPos;
  for(char c : path) {
    visitedPos.insert({x, y});
    std::vector<int> pos = dir[c];
    x = x + pos[0];
    y = y + pos[1];
    if (visitedPos.find({x, y}) != visitedPos.end())
      return true;
  }
  return false;
}

int main() {
  string path = "NES";
  // string path = "NESWW";
  bool isVisited= isPathCrossing(path);
  std::cout << "Is Path Crossing " << isVisited << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 14-path-crossing.cpp -o 14-path-crossing && ./14-path-crossing