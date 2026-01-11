/*
 * Leetcode - 844
 * Backspace String Compare
 * 
 * Given two strings s and t, return true if they are equal when both are typed into empty text editors.
 * '#' means a backspace character.
 * Note that after backspacing an empty text, the text will continue empty.
 * 
 * Example 1
 * Input  : s = "ab#c", t = "ad#c"
 * Output : true
 * Explanation : Both s and t become "ac".
 * 
 * Example 2
 * Input  : s = "ab##", t = "c#d#"
 * Output : true
 * Explanation : Both s and t become "".
 * 
 * Example 3
 * Input  : s = "a#c", t = "b"
 * Output : false
 * Explanation : s becomes "c" while t becomes "b".

 * https://leetcode.com/problems/backspace-string-compare/description/
*/

#include <stack>
#include <iostream>

std::string getValidString(std::string s) {
  int n = s.size();
  std::stack<char> st;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '#') {
      st.pop();
    } else {
      st.push(s[i]);
    }
  }

  std::string s_temp = "";
  while (!st.empty()) {
    s_temp += st.top();
    st.pop();
  }

  // std::cout << s_temp << " " << std::endl;
  return s_temp;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Use Stack DS
// * TIME COMPLEXITY O(n + m) + O(n + m)
// * SPACE COMPLEXITY O(n)
bool bruteForce(std::string s, std::string t) {
  return getValidString(s) == getValidString(t);
}

char getNextValidChar(int &i, std::string s) {
  int n = s.size();
  int backspace = 0;
  while (i >= 0) {
    if(s[i] == '#') {
      backspace++;
      i--;
    }
    else if(backspace > 0) {
      backspace--;
      i--;
    } else {
      // * Found character
      break;
    }
  }
  return i < 0 ? '$' : s[i];
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * loop from end of string
// * TIME COMPLEXITY O(n) + O(m)
// * SPACE COMPLEXITY O(1)
bool backspaceCompare(std::string s, std::string t) {
  int n1 = s.size(), n2 = t.size();
  int i = n1 - 1, j = n2 - 1;
  while(i >= 0 || j >= 0) {
    char ch1 = getNextValidChar(i, s);
    char ch2 = getNextValidChar(j, t);
    std::cout << ch1 << " " << ch2 << std::endl;
    if (ch1 != ch2)
      return false;

    i--;
    j--;
  }
  return true;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Two Pointer Approach
// * TIME COMPLEXITY O(n) 
// * SPACE COMPLEXITY O(1)
bool backspaceCompare2(std::string s, std::string t) {
  int n1 = s.size(), n2 = t.size();
  int i = n1 - 1, j = n2 - 1;
  int back = 0;
  while (true) {
    back = 0;
    while (i >= 0 && (back > 0 || s[i] == '#')) {
      back += (s[i] == '#') ? 1 : -1;
      i--;
    }

    back = 0;
    while (j >= 0 && (back > 0 || t[j] == '#')) {
      back += (t[j] == '#') ? 1 : -1;
      j--;
    }

    if (i >= 0 && j >= 0 && s[i] == t[j]) {
      i--, j--;
    }
    else {
      break;
    }
  }
  return i == -1 && j == -1; // * OR
  // return i < 0 && j < 0;
}

int main() {
  // * testcase 1
  std::string word1 = "ab#c", word2 = "ad#c";
  
  // * testcase 2
  // std::string word1 = "ab##", word2 = "c#d#";

  std::cout << word1 << " " << word2 << std::endl;

  // bool ans = bruteForce(word1, word2);
  bool ans = backspaceCompare(word1, word2);
  std::cout << ans << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++17 13-backspace-string-compare.cpp -o output && ./output