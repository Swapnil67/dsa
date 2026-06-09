/*
 * Leetcode - 301
 * Remove Invalid Parentheses
 * 
 * Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to
 * make the input string valid.
 * 
 * Return a list of unique strings that are valid with the minimum number of removals. You may return 
 * the answer in any order.
 * 
 * Example 1    :
 * Input        : s = "()())()"
 * Output       : ["(())()","()()()"]
 * 
 * Example 2    :
 * Input        : s = "(a)())()"
 * Output       : ["(a())()","(a)()()"]
 * 
 * Example 3    :
 * Input        : s = ")("
 * Output       : [""]
 * 
 * https://leetcode.com/problems/remove-invalid-parentheses
*/

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

void dfs(int idx, string &s, string &cur, int &max_str_len, int left,
         int right, unordered_set<string> &st)
{
  if (idx >= s.length())
  {
    if (left == right) {
      cout << cur << " \t---> l: " << left << ", r: " << right << endl;
      // * since we need to remove min brackets so we'll give priority to the longest answer.
      if ((int)cur.length() > max_str_len) { 
        max_str_len = cur.length();
        st.clear();
        st.insert(cur);
      }
      else if ((int)cur.length() == max_str_len) {
        st.insert(cur);
      }
    }
  }
  else
  {
    char ch = s[idx];
    if (ch == '(') {
      // * take
      cur.push_back(ch);
      dfs(idx + 1, s, cur, max_str_len, left + 1, right, st);

      // * not take
      cur.pop_back();
      dfs(idx + 1, s, cur, max_str_len, left, right, st);
    }
    else if (ch == ')') {
      // *  not take
      dfs(idx + 1, s, cur, max_str_len, left, right, st);

      // * only take if we have enough left brackets to close this righ.
      if (left > right) {
        cur.push_back(ch);
        dfs(idx + 1, s, cur, max_str_len, left, right + 1, st);
        cur.pop_back();
      }
    }
    else { // * a - z
      cur.push_back(ch);
      dfs(idx + 1, s, cur, max_str_len, left, right, st);
      cur.pop_back();
    }
  }
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
vector<string> removeInvalidParentheses(string s) {
  int max_str_len = -1;
  unordered_set<string> st;
  string cur = "";
  dfs(0, s, cur, max_str_len, 0, 0, st);
  return vector<string>(begin(st), end(st));
}

int main(void) {
  // * testcase 1
  string s = "()())()";
  
  // * testcase 2
  // string s = "(a)())()";

  // * testcase 3
  // string s = ")(";
  
  cout << "Input string: " << s << endl;
  
  vector<string> ans = removeInvalidParentheses(s);
  
  cout << "Answer: " << s << endl;
  printArr(ans);
  return 0;
}
 
// * Run the code
// * g++ --std=c++17 05-remove-invalid-parentheses.cpp -o output && ./output
