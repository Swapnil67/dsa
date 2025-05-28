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

bool isAlphanumeric(char ch) {
  return (
    ((int)ch >= (int)'A' && (int)ch <= (int)'Z') || 
    ((int)ch >= (int)'a' && (int)ch <= (int)'z') || 
    ((int)ch >= 0 && (int)ch <= 9));
}

// * Creating tokens from scratch
// * Doesn't works for some test cases (eq, "/..hidden/")
std::string bruteForce(std::string s) {
  int n = s.length();
  std::vector<std::string> path_vector;
  std::string ans = "";
  int j = 0;
  for (int i = 0; i < n; ++i) {
    std::string cur = "";
    if(s[j] == '/' && j < n)  {
      // * Loop through all slashes
      while(s[j] == '/') {
        cur += s[j];
        j++;
      }
      if(cur.length() > 1) {
        cur = "/";
      }
      if (cur != "") {
        if(path_vector.size() && path_vector[path_vector.size() - 1] == "/") {
        }
        else {
          path_vector.push_back(cur);
        }
        std::cout << cur << std::endl;
      }
      cur = "";
    }
    else if(s[j] == '.') {
      while(s[j] == '.' && j < n) {
        cur += s[j];
        j++;
      }

      if(cur == ".") {
      }
      else if(cur == "..") {
        if(path_vector.size() > 1) {
          path_vector.pop_back();
        }
        if(path_vector.size() > 1) {
          path_vector.pop_back();
        }
        if(path_vector.size() > 1) {
          path_vector.pop_back();
        }
        continue;
      }
      else {
        path_vector.push_back(cur);
      }
      std::cout << cur << std::endl;
      cur = "";
    }
    else if(isAlphanumeric(s[j])) {
      while(isAlphanumeric(s[j]) && j < n) {
        cur += s[j];
        j++;
      }
      if (cur != "") {
        path_vector.push_back(cur);
        std::cout << cur << std::endl;
      }
      cur = "";
    }
  }

  std::cout << path_vector.size() << std::endl;

  for(int i = 0; i < path_vector.size(); ++i) {
    if (i == path_vector.size() - 1) {
      std::cout << "Here " << path_vector[i] << std::endl;
      if(path_vector[i] == "/") {
        break;
      } else {
        ans += path_vector[i];
      }
    } else {
      ans += path_vector[i];
    }
  }

  return ans == "" ? "/" : ans;
}

// * Using stringstream for tokenizing string into tokens
std::string simplifyPath(std::string s) {
  int n = s.size();

  std::string token = "";
  std::stringstream ss(s);

  std::stack<std::string> st;

  while(getline(ss, token, '/')) {
    if (token == "." || token == "")
      continue;

    if (token == "..") {
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
  // std::string s = "/home//foo/";
  std::string s = "/home/user/Documents/../Pictures";
  // std::string s = "/../";
  // std::string s = "/.../a/../b/c/../d/./";
  // std::string s = "/..hidden/";
  std::cout << "Path: " << s << std::endl;

  // std::string ans = bruteForce(s);
  std::string ans = simplifyPath(s);
  std::cout << "Simplified Path: " << ans << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 09-simplify-path.cpp -o output && ./output