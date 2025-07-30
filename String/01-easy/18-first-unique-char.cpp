/**
 * * First Unique Character in a String
 * * Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 * * Example 1
 * * Input  : s = "leetcode"
 * * Output : 0
 * 
 * * Example 2
 * * Input  : s = "loveleetcode"
 * * Output : 2
 * 
 * * Example 3
 * * Input  : s = "aabb"
 * * Output : -1

 * * https://leetcode.com/problems/first-unique-character-in-a-string/description/
*/

#include <iostream>


// * ------------------------- APPROACH 1: BRUTE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int firstUniqCharBrute(std::string s) {
  int n = s.size();
  if(n == 0) return -1;
  if(n == 1) return 1;

  for (int i = 0; i < n; ++i) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (i != j && s[i] == s[j])
        found = true;
    }
    if(!found) 
      return i;
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Hashmap
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int firstUniqChar(std::string s) {
  int alphabets[26] = {0};
  for (char ch : s) {
    int i = ch - 'a';
    alphabets[i]++;
  }

  for (int i = 0; i < s.size(); ++i) {
    char ch = s[i];
    int idx = ch - 'a';
    if (alphabets[idx] == 1)
      return i;
  }
  return -1;
}

int main() {
  std::string s = "leetcode";
  // std::string s = "loveleetcode";
  // std::string s = "aabb";
  int ans = firstUniqChar(s);
  std::cout << s << std::endl;
  std::cout << "First unique character in string is at " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 18-first-unique-char.cpp -o 18-first-unique-char && ./18-first-unique-char