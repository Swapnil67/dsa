/*
 * Leetcode - 2696
 * Minimum String Length After Removing Substrings
 * You are given a string s consisting only of uppercase English letters.
 * You can apply some operations to this string where, in one operation, you can remove any occurrence 
 * of one of the substrings "AB" or "CD" from s.
 * 
 * Return the minimum possible length of the resulting string that you can obtain.
 * Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.
 * 
 * Example 1
 * input  : s = "ABFCACDB"
 * output : 2
 * 
 * Example 1
 * input  : s = "ACBBD"
 * output : 5
 * 
 * https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/
*/

#include <stack>
#include <iostream>

// * ------------------------- APPROACH 1: Optimal Approach -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int minLength(std::string s) {
  int n = s.length();

  std::stack<char> st;
  for(char &ch : s) {
    if(ch == 'D') {
      if(!st.empty() && st.top() == 'C') {
        st.pop();
      } else {
        st.push(ch);
      }
    }
    else if (ch == 'B') {
      if(!st.empty() && st.top() == 'A') {
        st.pop();
      } else {
        st.push(ch);
      }
    } else {
      st.push(ch);
    }
  }

  return st.size();
}

int main() {
  // std::string s = "ABFCACDB";
  std::string s = "ACBBD";
  int ans = minLength(s);
  std::cout << "Minimum String Length After Removing Substrings " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 17-min-str-after-removing-substr.cpp -o output && ./output