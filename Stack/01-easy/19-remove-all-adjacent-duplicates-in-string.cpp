/*
 * Leetcode - 1047
 * Remove All Adjacent Duplicates In String
 *
 * You are given a string s consisting of lowercase English letters. A duplicate removal consists 
 * of choosing two adjacent and equal letters and removing them.
 *
 * We repeatedly make duplicate removals on s until we no longer can.
 * 
 * Return the final string after all such duplicate removals have been made. 
 * It can be proven that the answer is unique.
 * 
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
*/

#include <stack>
#include <iostream>


// * ------------------------- APPROACH 1: Brute Force -------------------------`
// ! TLE
// * Using stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
std::string bruteForce(std::string s) {
  std::stack<char> st;
  for (char &c : s) {
    if (!st.empty() && st.top() == c) {
      st.pop();
    } else {
      st.push(c);
    }
  }

  std::string ans = "";
  while (!st.empty()) {
    ans = st.top() + ans;
    st.pop();
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using string as stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::string removeDuplicates(std::string s) {
  std::string ans = "";
  for (char &c: s) {
      if (ans.size() && ans.back() == c) {
          ans.pop_back();
      } else {
          ans.push_back(c);
      }
  }
  return ans;
}


int main(void) {
  // * testcase 1
  std::string s = "abbaca";

  // * testcase 2
  // std::string s = "azxxzy";

  std::cout << "s: " << s << std::endl;
  // std::string ans = bruteForce(s);
  std::string ans = removeDuplicates(s);

  std::cout << "Remove All Adjacent Duplicates In String: " << ans << std::endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 19-remove-all-adjacent-duplicates-in-string.cpp -o output && ./output