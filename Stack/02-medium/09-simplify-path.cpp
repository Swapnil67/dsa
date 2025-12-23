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

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>


// * Using stringstream for tokenizing string into tokens
std::string simplifyPath(std::string s) {
  int n = s.size();

  std::string token = "";
  std::stringstream ss(s);

  std::stack<std::string> st;

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

  std::string ans= "";
  while(!st.empty()) {
    ans = "/" + st.top() + ans;
    st.pop();
  }
  return ans;
}

int main() {
  std::cout << "Simplified Path: " << simplifyPath("/home/user/Documents/../Pictures") << std::endl;
  std::cout << "Simplified Path: " << simplifyPath("/../") << std::endl;
  std::cout << "Simplified Path: " << simplifyPath("/..hidden/") << std::endl;
  std::cout << "Simplified Path: " << simplifyPath("/home//foo/") << std::endl;
  std::cout << "Simplified Path: " << simplifyPath("/.../a/../b/c/../d/./") << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 09-simplify-path.cpp -o output && ./output