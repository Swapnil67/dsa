/*
 * Leetcode - 1190
 * Reverse Substrings Between Each Pair of Parentheses
 * 
 * You are given a string s that consists of lower case English letters and brackets.

 * * Example 1
 * * Input  : s = "(abcd)"
 * * Output : "dcba"
 * 
 * * Example 2
 * * Input  : s = "(u(love)i)"
 * * Output : "iloveu"
 * 
 * * Example 2
 * * Input  : s = "(ed(et(oc))el)"
 * * Output : "leetcode"

 * https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
*/

// ! Amazon, Meta

#include <stack>
#include <iostream>

using namespace std;

// * ------------------------- APPROACH 1: Optimal Approach -------------------------
// * Using stack
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
string reverseParentheses(string s) {
  int n = s.size();
  stack<char> st;

  for (char &ch : s) {
    if (ch == ')') {
      string temp = "";
      // * get the string b/w '()' brackets
      while(!st.empty() && st.top() != '(') {
        temp += st.top();
        st.pop();
      }

      // * Remove the '(' paranthesis
      st.pop();

      // * Push the string again on top of stack
      for (char &c : temp) {
        st.push(c);
      }
      // cout << temp << endl;
    }
    else {
      st.push(ch);
    }
  }

  // * build the answer string
  string ans = "";
  while (!st.empty()) {
    ans = st.top() + ans;
    st.pop();
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * Using string as stack
// * TIME COMPLEXITY O(N) 
// * SPACE COMPLEXITY O(1)
string reverseParentheses2(string s) {
  string ans = "";
  for (char &ch : s) {
    if (ch == ')') {
      string temp = "";
      while (!ans.empty() && ans.back() != '(') {
        temp += ans.back();
        ans.pop_back();
      }
      ans.pop_back(); // * pop -> '('

      for(char &c: temp)
        ans.push_back(c);

    } else {
      ans.push_back(ch);
    }
  }

  return ans;
}

int main() {
  // * testcase 1
  // string s = "(u(love)i)";

  // * testcase 2
  string s = "(ed(et(oc))el)";
  
  cout << s << endl;

  // string ans = reverseParentheses(s);
  string ans = reverseParentheses2(s);
  cout << ans << endl;
  
  return 0;
}


// * Run the code
// * g++ --std=c++20 15-reverse-substr-bw-parenthesis.cpp -o output && ./output
