/*
 * Leetcode - 2390
 * Removing Stars From a String
 * 
 * You are given a string s, which contains stars *.
 * In one operation, you can:
   * Choose a star in s.
   * Remove the closest non-star character to its left, as well as remove the star itself.
 * Return the string after all stars have been removed.

 * Example 1
 * Input  : s = "leet**cod*e";
 * Output : lecoe
 * 
 * Example 2
 * Input  : s = "erase*****";
 * Output : 

* https://leetcode.com/problems/removing-stars-from-a-string/
*/

// ! Microsoft

using namespace std;

#include <stack>
#include <iostream>

// * ------------------------- APPROACH 1A: Optimal Approach -------------------------
// ! TLE
// * Using stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
string removeStars(string s) {
  int n = s.size();
  stack<char> st;
  for (auto &c: s) {
    if (c == '*' && !st.empty()) {
      st.pop();
    } else {
      st.push(c);
    }
  }

  string ans = "";
  while(!st.empty()) {
    ans = st.top() + ans;
    st.pop();
  }

  return ans;
}

// * ------------------------- APPROACH 1B: Optimal Approach -------------------------
// * Using string as stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
string removeStars2(string s) {
  int n = s.size();

  string ans = "";
  for (char &ch : s) {
    if(ch == '*') {
      ans.pop_back();
    } else {
      ans += ch;
    }
  }

  return ans;
}
  
// * ------------------------- APPROACH 1C: Optimal Approach -------------------------`
// * Using Two Pointer
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
string removeStars3(string s) {
  int i = 0;
  for (char ch : s) {
    if (ch == '*') {
      if (i > 0) {
        i--;
      }
    } else {
      s[i] = ch;
      i++;
    }
  }

  return s.substr(0, i);
}

int main() {
  string s = "leet**cod*e";
  // string s = "erase*****";
  
  cout << "Input String: " << s << endl;
  // string ans = removeStars(s);
  string ans = removeStars2(s);
  cout << "Ans: " << ans << endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 02-remove-stars-from-string.cpp -o output && ./output 
