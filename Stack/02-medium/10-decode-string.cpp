/*
 * Leetcode - 394
 * Decode String

 * Example 1
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"

 * Example 2
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"

 * Example 3
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * 
 * https://leetcode.com/problems/decode-string/description/
*/

#include <stack>
#include <iostream>

std::string decodeString(std::string s) {
  int n = s.size();
  int j = 0;
  
  std::stack<char> st;

  for (char &ch : s) {
    if (ch == ']') {

      // * Get the string
      std::string temp = "";
      while (!st.empty() && st.top() != '[') {
        temp = st.top() + temp;
        st.pop();
      }

      // * pop the '[' bracket
      st.pop();

      // * Get the number
      std::string num_str = "";
      while(!st.empty() && isdigit(st.top())) {
        num_str = st.top() + num_str;
        st.pop();
      }

      // * 3 x a = "aaa" (do this here)
      std::string temp2 = "";
      for(int j = 0; j < std::stoi(num_str); ++j) {
        temp2 += temp;
      }

      // * Push the result string back to stack
      for(char &c : temp2) {
        st.push(c);
      }

      // std::cout << num_str << " -> " << temp << " = " << temp2 << std::endl;
    }
    else {
      st.push(ch);
    }
  }

  std::string ans = "";
  while(!st.empty()) {
    ans = st.top() + ans;
    st.pop();
  }

  return ans;
}

int main() {
  std::string s = "3[a]2[bc]";
  // std::string s = "3[a2[c]]";
  // std::string s = "2[abc]3[cd]ef";

  std::cout << "Input String: " << s << std::endl;

  std::string ans = decodeString(s);
  std::cout << "Decoded String: " << ans << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 10-decode-string.cpp -o output && ./output