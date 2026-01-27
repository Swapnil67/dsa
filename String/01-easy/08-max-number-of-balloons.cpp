/**
 * * Leetcode - 1189
 * * Maximum Number of Balloons
 * * Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

 * * You can use each character in text atmost once. Return the maximum number of instances that can be formed.

 * * Example 1
 * * Input  : text = "nlaebolko"
 * * Output : 1

 * * Example 2
 * * Input  : text = "loonbalxballpoon"
 * * Output : 2

 * * https://leetcode.com/problems/maximum-number-of-balloons/description/
*/

#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

// * ------------------------- Utility -------------------------`

bool findStringInMap(std::string str, std::unordered_map<char, int> &charCount) {
  for(char c : str) {
    if (charCount.find(c) != charCount.end() && charCount[c] > 0) {
      charCount[c]--;
    }
    else {
      return false;
    }
  }
  return true;
}

bool findStringInArr(std::string str, std::vector<int> &alphabets) {
  for(char c : str) {
    int idx = (int)(c) - (int)'a';
    if(alphabets[idx] > 0) {
      alphabets[idx]--; 
    }
    else {
      return false;
    }
  }
  return true;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Use Hashmap and count characters
// * TIME COMPLEXITY O(N) + O(N * no of balloons)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::string str, std::string findStr) {
  std::unordered_map<char, int> charCount;
  for(char c : str) {
    charCount[c]++;
  }

  int c = 0;
  while(findStringInMap(findStr, charCount)) {
    c++;
  }

  return c;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------`
// * Use Hash Array and count characters
// * TIME COMPLEXITY O(N) + O(N * no of balloons)
// * SPACE COMPLEXITY O(1)
int betterApproach(std::string str, std::string findStr) {
  std::vector<int> alphabets(26, 0);
  for(char c : str) {
    int idx = (int)(c) - (int)'a';
    // std::cout << "Idx of " << c << " is " << idx << std::endl;
    alphabets[idx]++;
  }

  int c = 0;
  while(findStringInArr(findStr, alphabets)) {
    c++;
  }

  return c;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * Use Basic Maths
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxNumberOfBalloons(std::string str, std::string findStr) {
  // * Create find string char count map
  std::unordered_map<char, int> findStrMap;
   for(char ch : findStr) {
    findStrMap[ch]++;
  } 
  
  // * Create Input string char count map
  std::unordered_map<char, int> strMap;
  for (char ch : str) {
    if (findStrMap.find(ch) != findStrMap.end()) {
      strMap[ch]++;
    }
  }

  int cnt = INT_MAX;
  for(char ch: findStr) {
    int ans = strMap[ch] / findStrMap[ch];
    // std::cout << ch << " -> " << ans << std::endl;
    if(ans < cnt) {
      cnt = ans;
    }
  }

  return cnt;
}

int main() {
  // * testcase 1
  // std::string str = "nlaebolko";

  // * testcase 2
  std::string str = "loonbalxballpoon";

  // * testcase 3
  // std::string str = "leetcode";
  
  std::string findStr = "balloon";
  // int ans = bruteForce(str, findStr);
  // int ans = betterApproach(str, findStr);
  int ans = maxNumberOfBalloons(str, findStr);
  std::cout << "There are " << ans << " " << findStr << " in " << str << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 08-max-number-of-balloons.cpp -o 08-max-number-of-balloons && ./08-max-number-of-balloons