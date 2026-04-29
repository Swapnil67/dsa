/*
 * Leetcode - 1541
 * Minimum Insertions to Balance a Parentheses String
 * 
 * Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:
 *
 * - Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
 * - Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
 * 
 * You can insert the characters '(' and ')' at any position of the string to balance it if needed.
 * 
 * Return the minimum number of insertions needed to make s balanced.
 * 
 * Example 1:
 * Input : s = "(()))"
 * Output: 1
 * Explanation :  The second '(' has two matching '))', but the first '(' has only ')' matching. 
 *                We need to add one more ')' at the end of the string to be "(())))" which is balanced.
 * 
 * Example 2:
 * Input : s = "())"
 * Output: 0
 * Explanation : The string is already balanced.
 * 
 * Example 3:
 * Input : s = "))())("
 * Output: 3
 * Explanation : Add '(' to match the first '))', Add '))' to match the last '('.

 * https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/
 * 
*/

// ! Google, Amazon, Meta

#include <stack>
#include <iostream>

using namespace std;


// * Intuition
// * Whenever popping make sure we have '()' on the top of stack
int minInsertions(string s) {
  stack<char> st;
  int insertions = 0;
  for (char &c : s) {
    if (c == '(') { // * Two Cases
      if (st.empty()) {
        st.push(c);
      }
      else {
        if (st.top() != '(') {
          // * here we are missing one ')'
          insertions++;
          st.pop();
          st.pop();
        }
        st.push(c);
      }
    } else { // * Two Cases
      if (st.empty()) {
        // * you need to make '()'
        insertions++; // * Since you manually added to balance
        st.push('('); // * Add '('
        st.push(c);   // * Add ')'
      }
      else { // * Two Cases
        if (st.top() == '(') {
          st.push(c);
        }
        else {
          // * Here we have gurantee that last two stack elements
          // * ['(', ')'] (top)
          st.pop();
          st.pop();
        }
      }
    }
  }

  while (!st.empty()) { // * Two Cases
    if (st.top() == '(') {
      insertions += 2;
    }
    else {
      // * here we have ['(', ')'] (top)
      insertions += 1;
      st.pop();
    }
    st.pop();
  }

  return insertions;
}

int main() {
  // * testcase 1
  // string s = "(()))";

  // * testcase 2
  // string s = "())";

  // * testcase 3
  string s = "))())(";

  cout << "Input string: " << s << endl;
  int ans = minInsertions(s);
  cout << "Minimum Insertions to Balance a Parentheses String is " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 26-min-insertions-to-balance-a-parentheses-str.cpp -o output && ./output