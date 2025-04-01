// * WAP in Cpp 
// * Where a string containing '{' or '}' is called a valid if all the brackets are balanced.
// * Formally for each opening bracket, there must be a closing bracket right to it.

#include<string>
#include<stack>
#include<iostream>

using namespace std;

int findMinimumCost(string str) {
  if (str.length() % 2 != 0)
  {
    return -1;
  }
  stack<char> st;
  for(int i=0; i<str.length(); i++) {
    char ch = str[i];
    if(ch == '{') {
      st.push(ch);
    } else {
      if(ch == '}') {
        if(!st.empty() && st.top() == '{') {
          st.pop();
        } else {
          st.push(ch);
        }
      }
    }
  }

  if(st.empty()) {
    return 0;
  } else {
    int a = 0, b = 0;
    while(!st.empty()) {
      if(st.top() == '{') {
        b++;
      } else {
        a++;
      }
      st.pop();
    }
    // cout<<"a "<<a<<" b "<<b<<endl;
    int ans = ((a+1)/2 + (b+1)/2);
    return ans;
  }
}

int main() {

  // * Eg "{}}}}}", "{{{{}", "}}}{{{"
  string str = "}}}{{{";
  int minCost = findMinimumCost(str);
  cout<<"minCost: "<<minCost;
  return 0;
}

// * valid string = {{}}
// * invalid string = {{{}