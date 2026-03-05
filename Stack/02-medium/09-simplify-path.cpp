/*
 * Leetcode - 71
 * Simplify Path
 
 * Example 1
 * Input: s = "/home/"
 * Output: "/home"

 * Example 2
 * Input: s = "/home//foo/"
 * Output: "/home/foo"

 * Example 3
 * Input: s = "/home/user/Documents/../Pictures"
 * Output: "/home/user/Pictures"
 * 
 * Example 4
 * Input: s = "/.../a/../b/c/../d/./"
 * Output: "/.../b/d"
 * 
 * https://leetcode.com/problems/simplify-path/description/
*/

#include <stack>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

// * Using stringstream for tokenizing string into tokens
string simplifyPath(string s) {
  int n = s.size();

  string token = "";
  stringstream ss(s);

  stack<string> st;

  while(getline(ss, token, '/')) {
    if (token == "." || token == "")
      continue;

    if (token == "..") { // * go pop one directory
      if (!st.empty())
        st.pop();
    } else {
      st.push(token);
    }
  }

  if (st.empty())
    return "/";

  string ans= "";
  while(!st.empty()) {
    ans = "/" + st.top() + ans;
    st.pop();
  }
  return ans;
}

int main() {
  cout << "Simplified Path: " << simplifyPath("/home/user/Documents/../Pictures") << endl;
  cout << "Simplified Path: " << simplifyPath("/../") << endl;
  cout << "Simplified Path: " << simplifyPath("/..hidden/") << endl;
  cout << "Simplified Path: " << simplifyPath("/home//foo/") << endl;
  cout << "Simplified Path: " << simplifyPath("/.../a/../b/c/../d/./") << endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 09-simplify-path.cpp -o output && ./output