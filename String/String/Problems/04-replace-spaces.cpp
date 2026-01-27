/*
* Given a string str. The task is to replace all the spaces b/w words with @40
*/
// * Input : "Hello World" | Output : 'Hello@40World'

#include<iostream>
#include<string>
using namespace std;

// * TIME COMPLEXITY = O(N)
// * SPACE COMPLEXITY = O(N)
// * Replaces the string using extra space
string replaceSpace(string str) {
  string temp = "";
  for(int i=0; i<str.length(); i++) {
    char ch = str[i];
    if(ch == ' ') {
      temp.push_back('@');
      temp.push_back('4');
      temp.push_back('0');
    } else {
      temp.push_back(ch);
    }
  }
  return temp;
}


// * TIME COMPLEXITY = O(N)
// * SPACE COMPLEXITY = O(1)
// * Replaces the string without using extra space
void replaceSpaceInPlace(string &str) {
  for (int i = 0; i < str[i] != '\0'; i++) {
    char ch = str[i];
    if(ch == ' ') {
      str.replace(i, 1, "@40");
    }
  }
}

int main() {
  string str ("Hello World");
  string ans1 = replaceSpace(str);
  cout<<ans1<<endl;
  replaceSpaceInPlace(str);
  cout<<str;
  return 0;
}