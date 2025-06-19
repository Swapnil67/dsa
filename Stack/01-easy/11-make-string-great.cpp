/**
 * * Make The String Great
 * 
 * * Example 1
 * * Input  : s = "leEeetcode"
 * * Output : "leetcode"
 * 
 * * Example 2
 * * Input  : s = "abBAcC"
 * * Output : ""
 * 
 * * Example 3
 * * Input  : s = "Pp"
 * * Output : ""
 * 
 * * Example 4
 * * Input  : s = "cK"
 * * Output : "cK"
 * 
 * * https://leetcode.com/problems/make-the-string-great/description/
*/

#include <stack>
#include <string>
#include <iostream>
#include <algorithm>


// * ------------------------- APPROACH 1: Better Approach -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
std::string makeGood(std::string s) {
  int n = s.size();
  std::stack<char> st;
  for (char &ch : s) {
    if(ch >= 'A' && ch <= 'Z') {
      if (!st.empty() && (int)st.top() == ch + 32) {
        st.pop();
      } else {
        st.push(ch);
      }
    }
    else if (ch >= 'a' && ch <= 'z') {
      if (!st.empty() && (int)st.top() == ch - 32) {
        st.pop();
      } else {
        st.push(ch);
      }
    }
  }

  std::string ans = "";
  while(!st.empty()) {
    ans += st.top();
    st.pop();
  }
  std::reverse(ans.begin(), ans.end());
  return ans;
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::string makeGood2(std::string s) {
  int n = s.size();
  std::stack<char> st;
  std::string ans = "";

  for (char &ch : s) {
    if(ch >= 'A' && ch <= 'Z') {
      if (ans.size() && (int)ans.back() == ch + 32) {
        ans.pop_back();
      } else {
        ans += ch;
      }
    }
    else if (ch >= 'a' && ch <= 'z') {
      if (ans.size() && (int)ans.back() == ch - 32) {
        ans.pop_back();
      } else {
        ans += ch;
      }
    }
  }

  return ans;
}

int main() {
  std::cout << "leEeetcode: " << makeGood("leEeetcode") << std::endl;
  std::cout << "kkdsFuqUfSDKK: " << makeGood("kkdsFuqUfSDKK") << std::endl;
  std::cout << "abBAcC: " << makeGood("abBAcC") << std::endl;
  std::cout << "Pp: " << makeGood("Pp") << std::endl;
  std::cout << "mC: " << makeGood("mC") << std::endl;
  std::cout << "s: " << makeGood("s") << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 11-make-string-great.cpp -o output && ./output