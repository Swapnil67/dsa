/**
 * * Largest Substring Between Two Equal Characters
 * * Given a string s, return the length of the longest substring between two equal characters, 
 * * excluding the two characters. If there is no such substring return -1.

 * * Example 1
 * * Input  : s = "aa"
 * * Output : 0
 * * Explanation : The optimal substring here is an empty substring between the two 'a's.
 * 
 * * Example 2
 * * Input  : s = "abca"
 * * Output : 2
 * * Explanation: The optimal substring here is "bc".
 * 
 * * https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/
*/

#include<map>
#include<iostream>

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::string s) {
  int n = s.size();
  if (n <= 1)
    return -1;
  int longest = -1;
  for (int i = 0; i < n; ++i) {
    bool found = false;
    int c = -1;
    for (int j = i + 1; j < n; ++j) {
      if(s[i] != s[j]) {
        c++;
      }
      else {
        found = true;
        c++;
      }
    }
    if(found) {
      longest = std::max(longest, c);
    }
  }
  return longest;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxLengthBetweenEqualCharacters(std::string s) {
  int n = s.size();
  std::map<char, int> charMap;
  int longest = -1;
  for (int i = 0; i < n; ++i) {
    char ch = s[i];
    if(charMap.find(ch) != charMap.end()) {
      int len = (i - charMap[ch]) - 1;
      longest = std::max(longest, len); 
    }
    else {
      charMap[ch] = i;
    }
  }

  return longest;
} 


int main() {
  // std::string s = "aa";
  std::string s = "abca";
  // std::string s = "abcawerweqra";
  // std::string s = "cbzxy";
  std::cout << s << std::endl;
  // int ans = bruteForce(s);
  int ans = maxLengthBetweenEqualCharacters(s);
  std::cout << "Largest substring b/w characters is " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 ./17-largest-substr-bw-chars.cpp -o 17-largest-substr-bw-chars && ./17-largest-substr-bw-chars