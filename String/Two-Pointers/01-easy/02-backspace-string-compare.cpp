/*
 * Merge Strings Alternately
 * You are given two strings word1 and word2. Merge the strings by adding letters in alternating order,
 * starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
 * 
 * Example 1
 * Input  : word1 = "abc", word2 = "pqr"
 * Output : "apbqcr"
 * 
 * Example 2
 * Input  : word1 = "ab", word2 = "pqrs"
 * Output : "apbqrs"

 * https://leetcode.com/problems/merge-strings-alternately/description/
*/

#include<stack>
#include<iostream>

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
  while(!st.empty()) {
    s_temp += st.top();
    st.pop();
  }

  // std::cout << s_temp << " " << std::endl;
  return s_temp;
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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Use Stack DS
// * TIME COMPLEXITY O(n + m) + O(n + m)
// * SPACE COMPLEXITY O(n)
bool bruteForce(std::string s, std::string t) {
  return getValidString(s) == getValidString(t);
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
    if(ch1 != ch2)
      return false;

    i--;
    j--;
  }
  return true;
}


int main() {
  // * testcase 1
  // std::string word1 = "ab#c", word2 = "ad#c";
  // * testcase 2
  std::string word1 = "ab##", word2 = "c#d#";
  std::cout << word1 << " " << word2 << std::endl;

  // bool ans = bruteForce(word1, word2);
  bool ans = backspaceCompare(word1, word2);
  std::cout << ans << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++17 02-backspace-string-compare.cpp -o output && ./output