/**
 * * Make The String Great
 * 
 * * Example 1
 * * Input  : s = "leEeetcode"
 * * Output : "leetcode"
 * 
 * * Example 2
 * * Input  : s = "abBAcC"
 * * Output : ""
 * 
 * * Example 3
 * * Input  : s = "Pp"
 * * Output : ""
 * 
 * * Example 4
 * * Input  : s = "cK"
 * * Output : "cK"
 * 
 * * https://leetcode.com/problems/make-the-string-great/description/
*/

#include<stack>
#include<string>
#include<iostream>

void reverseString(std::string &s) {
  int i = 0, j = s.size() - 1;
  while(i < j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    i++;
    j--;
  }
}

char toUpperCase(char ch) {
  if(ch >= 'A' && ch <= 'Z')
    return ch;
  return (ch - 'a') + 'A';
}

void matchedCharacters(std::stack<int> &st, char ch) {
  if(ch == st.top()) {
    st.pop();
  } else {
    st.push(ch);
  } 
}

std::string makeGood(std::string s) {
  int n = s.size();
  std::stack<int> st;
  for(char ch: s) {
    if(ch >= 'A' && ch <= 'Z') {
      if(!st.empty()) {
        if(st.top() >= 'A' && st.top() <= 'Z') {
          st.push(ch); 
        }
        else {
          char top_upper_ch = toUpperCase(st.top());
          // std::cout << st.top() << " " << top_upper_ch << std::endl;
          ch == top_upper_ch ? st.pop() : st.push(ch);
        }
      }
      else {
        st.push(ch);
      }
    } else {
      if(!st.empty()) {
        if(st.top() >= 'A' && st.top() <= 'Z') {
          if (ch >= 'a' && ch <= 'z') {
            char cur_upper_ch = toUpperCase(ch);
            st.top() == cur_upper_ch ? st.pop() : st.push(ch);
          }
        } else {
          char top_upper_ch = toUpperCase(st.top());
          ch == top_upper_ch ? st.pop() : st.push(ch);
        }
      } else {
        st.push(ch);
      }
    }
  }

  std::string ans = "";
  while(!st.empty()) {
    ans += st.top();
    st.pop();
  }

  reverseString(ans);
  return ans;
}

int main() {
  std::cout << "leEeetcode: " << makeGood("leEeetcode") << std::endl;
  std::cout << "kkdsFuqUfSDKK: " << makeGood("kkdsFuqUfSDKK") << std::endl;
  std::cout << "abBAcC: " << makeGood("abBAcC") << std::endl;
  std::cout << "Pp: " << makeGood("Pp") << std::endl;
  std::cout << "mC: " << makeGood("mC") << std::endl;
  std::cout << "s: " << makeGood("s") << std::endl;

  return 0;
}

// * Run the code
// * $CXX 11-make-string-great.cpp -o output && ./output