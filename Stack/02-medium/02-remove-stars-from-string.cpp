/*
* Removing Stars From a String
* You are given a string s, which contains stars *.
* In one operation, you can:
  * Choose a star in s.
  * Remove the closest non-star character to its left, as well as remove the star itself.
  * 
* Return the string after all stars have been removed.
* https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
*/

#include <iostream>
#include <stack>

// * ------------------------- APPROACH 1A: Optimal Approach -------------------------`
// * Using stack
std::string removeStars(std::string s) {
  int n = s.size();
  std::stack<char> st;
  for (int i = n - 1; i >= 0; --i) {
    // std::cout << i << " " << s[i] << std::endl;
    if(s[i] == '*') {
      st.push(s[i]);
    }
    else {
      // * lower case alphabet
      // * check if top has '*'
      if (!st.empty() && st.top() == '*') {
        st.pop();
      }
      else {
        st.push(s[i]);
      }
    }
  }

  std::string ans = "";
  while(!st.empty()) {
    ans += st.top();
    st.pop();
  }

  return ans;
}

// * ------------------------- APPROACH 1B: Optimal Approach -------------------------`
// * Without using stack
std::string removeStars2(std::string s) {
  int i = 0;
  for (char ch : s) {
    if(ch == '*') {
      if(i > 0) {
        i--;
      }
    }
    else {
      s[i] = ch;
      i++;
    }
  }

  return s.substr(0, i);
}

int main() {
  std::string s = "leet**cod*e";
  // std::string s = "erase*****";
  std::cout << "Input String: " << s << std::endl;
  // std::string ans = removeStars(s);
  std::string ans = removeStars2(s);
  std::cout << "Ans: " << ans << std::endl;
  return 0;
}

// * Run the code
// * $CXX 02-remove-stars-from-string.cpp -o output && ./output 
