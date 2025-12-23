/*
 * Leetcode - 1249
 * Minimum Remove to Make Valid Parentheses
 * 
 * Given a string s of '(' , ')' and lowercase English characters.
 *
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the 
 * resulting parentheses string is valid and return any valid string.
 * 
 * Formally, a parentheses string is valid if and only if:
 * 
 * - It is the empty string, contains only lowercase characters, or
 * - It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * - It can be written as (A), where A is a valid string.
 * 
 * Example 1:
 * Input       : s = "lee(t(c)o)de)"
 * Output      : "lee(t(c)o)de"
 * Explanation : "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 * 
 * Example 2:
 * Input : s = "a)b(c)d"
 * Output: "ab(c)d"
 * 
 * Example 3:
 * Input       : s = "))())("
 * Output      : ""
 * Explanation : An empty string is also valid.

 * https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
 * 
*/

// ! Amazon, Google, Microsoft, Meta, Adobe

#include <stack>
#include <iostream>
#include <unordered_set>


// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * Use stack to identify what extra brackets we should remove
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
std::string bruteForce(std::string s) {
  int n = s.size();
  std::stack<int> st; // * to track indexes of extra open brackets
  std::unordered_set<int> remove_set;

  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (c == '(') {
      st.push(i);
    } else if (c == ')') {
      if (st.empty()) {
        remove_set.insert(i);
      } else { 
        // * here we have a open bracket at top of stack
        st.pop();
      }
    } 
  }
  // std::cout << st.size() << std::endl;

  // * Add all the extra brackets index to unordered_set
  while (!st.empty()) {
    remove_set.insert(st.top());
    st.pop();
  }

  std::string ans = "";
  for (int i = 0; i < n; ++i) {
    if (remove_set.count(i))
      continue;
    ans.push_back(s[i]);
  }
  return ans;
} 

// * ------------------------- Approach 2: Optimal Approach -------------------------
// * total_open - extra_opens = keep
// * Count extra_opens
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
std::string minRemoveToMakeValid(std::string s) {
  int extra_opens = 0;
  int total_opens = 0;

  std::string temp = "";
  for (auto &c: s) {
    if (c =='(') {
      extra_opens++;
      temp += c;
      total_opens++;
    }
    else if (c == ')') {
      if (extra_opens == 0) {
        continue;
      }
      extra_opens--;
      temp += c;
    }
    else {
      temp += c;
    }
  }
  // std::cout << "temp: " << temp << std::endl;
  // std::cout << "total_opens: " << total_opens << std::endl;
  // std::cout << "extra_opens: " << extra_opens << std::endl;
  int keep = total_opens - extra_opens; // * Final Ans should have only 'keep' number of open brackets
  // std::cout << "keep open: " << keep << std::endl;

  std::string ans = "";
  for (auto &c: temp) {
    if (c == '(') {
      if (keep == 0) 
        continue;
      keep--;
    }
    ans += c;
  }

  return ans;
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * total_open - extra_opens = keep
// * In place (Follow up question)
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
std::string minRemoveToMakeValid2(std::string s) {
  int extra_opens = 0;
  int total_opens = 0;

  std::string temp = "";
  int j = 0;
  for (auto &c: s) {
    if (c == ')') {
      if (extra_opens == 0) {
        continue;
      }
      extra_opens--;
    }
    else if (c =='(') {
      extra_opens++;
      total_opens++;
    }
    s[j++] = c; 
  }
  
  int length = j;
  j = 0;
  int keep = total_opens - extra_opens; // * Final Ans should have only 'keep' number of open brackets

  for (int i = 0; i < length; ++i) {
    char c = s[i];
    if (c == '(') {
      if (keep == 0) 
        continue;
      keep--;
    }
    s[j++] = c;
  }

  std::string ans = s.substr(0, j);
  return ans;
}

int main() {
  // * testcase 1
  // std::string s = "lee(t(c)o)de)";

  // * testcase 2
  // std::string s = "a)b(c)d";

  // * testcase 3
  // std::string s = "))((";

  // * testcase 4
  std::string s = ")())m(s)(";

  std::cout << "Input string: " << s << std::endl;
  // std::string ans = bruteForce(s);
  // std::string ans = minRemoveToMakeValid(s);
  std::string ans = minRemoveToMakeValid2(s);
  std::cout << "Ans: " << ans << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 27-min-remove-to-make-valid-parentheses.cpp -o output && ./output