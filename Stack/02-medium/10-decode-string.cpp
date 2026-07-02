/*
 * Leetcode - 394
 * Decode String
 * 
 * Example 1
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * 
 * Example 2
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * 
 * Example 3
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * 
 * https://leetcode.com/problems/decode-string/description/
 * https://www.naukri.com/code360/problems/decode-string_696319
 * https://www.geeksforgeeks.org/problems/decode-the-string2444/1
*/

#include <stack>
#include <iostream>

using namespace std;

string decodeString(string s) {
  int n = s.size();
  int j = 0;
  
  stack<char> st;

  for (char &ch : s) {
    if (ch == ']') {

      // * Get the string
      string temp = "";
      while (!st.empty() && st.top() != '[') {
        temp = st.top() + temp;
        st.pop();
      }
      st.pop(); // * pop the '[' bracket

      // * Get the number
      string num_str = "";
      while(!st.empty() && isdigit(st.top())) {
        num_str = st.top() + num_str;
        st.pop();
      }

      // * 3 x a = "aaa" (do this here)
      string temp2 = "";
      for(int j = 0; j < stoi(num_str); ++j) {
        temp2 += temp;
      }
      // * Push the result string back to stack
      for (char &c : temp2)
        st.push(c);

      // cout << num_str << " -> " << temp << " = " << temp2 << endl;
    }
    else {
      st.push(ch);
    }
  }

  string ans = "";
  while(!st.empty()) {
    ans = st.top() + ans;
    st.pop();
  }

  return ans;
}

int main() {
  // * testcase 1
  string s = "3[a]2[bc]";

  // * testcase 2
  // string s = "3[a2[c]]";

  // * testcase 3
  // string s = "2[abc]3[cd]ef";

  cout << "Input String: " << s << endl;

  string ans = decodeString(s);
  cout << "Decoded String: " << ans << endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 10-decode-string.cpp -o output && ./output