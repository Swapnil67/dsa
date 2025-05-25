/*
* Leetcode - 2390
* Removing Stars From a String
* You are given a string s, which contains stars *.
* In one operation, you can:
  * Choose a star in s.
  * Remove the closest non-star character to its left, as well as remove the star itself.
  * 
* Return the string after all stars have been removed.

 * * Example 1
 * * Input  : s = "leet**cod*e";
 * * Output : lecoe
 * 
 * * Example 2
 * * Input  : s = "erase*****";
 * * Output : 

* https://leetcode.com/problems/removing-stars-from-a-string/description/
*/

#include <iostream>
#include <stack>

// * ------------------------- APPROACH 1A: Optimal Approach -------------------------`
// * Using stack
std::string removeStars(std::string s) {
  int n = s.size();
  std::stack<char> st;
  for (int i = n - 1; i >= 0; --i) {
    // std::cout << i << " " << s[i] << std::endl;
    if(s[i] == '*') {
      st.push(s[i]);
    }
    else {
      // * lower case alphabet
      // * check if top has '*'
      if (!st.empty() && st.top() == '*') {
        st.pop();
      }
      else {
        st.push(s[i]);
      }
    }
  }

  std::string ans = "";
  while(!st.empty()) {
    ans += st.top();
    st.pop();
  }

  return ans;
}

// * ------------------------- APPROACH 1B: Optimal Approach -------------------------`
// * Using string as stack
std::string removeStars2(std::string s) {
  int n = s.size();
  std::string ans = "";
  std::stack<char> st;
  for (char &ch : s) {
    if(ch == '*') {
      ans.pop_back();
    } else {
      ans += ch;
    }
  }

  return ans;
}

// * ------------------------- APPROACH 1B: Optimal Approach -------------------------`
// * Using Two Pointer
std::string removeStars3(std::string s) {
  int i = 0;
  for (char ch : s) {
    if(ch == '*') {
      if(i > 0) {
        i--;
      }
    }
    else {
      s[i] = ch;
      i++;
    }
  }

  return s.substr(0, i);
}

int main() {
  std::string s = "leet**cod*e";
  // std::string s = "erase*****";
  std::cout << "Input String: " << s << std::endl;
  // std::string ans = removeStars(s);
  std::string ans = removeStars2(s);
  std::cout << "Ans: " << ans << std::endl;
  return 0;
}

// * Run the code
// * $CXX 02-remove-stars-from-string.cpp -o output && ./output 
