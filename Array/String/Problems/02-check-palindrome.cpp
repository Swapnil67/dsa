// * WAP in cpp to reverse a char array 
// * Note char are not case sensitive & consider alphabets and numbers only and ignore the symbols & whitespaces.
// * INPUT = c1 O$d@eeD o1c | OUTPUT: true

#include<iostream>
#include<string>
using namespace std;

char toLowerCase(char ch) {
  if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
    return ch;
  } else if(ch >= 'A' && ch <= 'Z') {
    char lower_ch = ch - 'A' + 'a';
    return lower_ch;
  }
}

bool isValidChar(char ch) {
  if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
    return 1;
  } else {
    return 0;
  }
}

string validString(string str) {
  string temp = "";
  for(int i=0; i<str.length(); i++) {
    if(isValidChar(str[i])) {
      temp.push_back(toLowerCase(str[i]));
    }
  }
  return temp;
}

bool checkIsPalindrome(string str) {
  int s = 0;
  int e = str.length() - 1;
  while(s<=e) {
    if(str[s] != str[e]) {
      cout<<str[s]<<" "<<str[e]<<endl;
      return false;
    } else {
      s++;
      e--;
    }
  }
  return true;
}


int main() {
  string str;
  cout<<"Enter a string "<<endl;
  getline(cin, str);
  str = validString(str);
  bool isPalindrome = checkIsPalindrome(str);
  cout<<"isPalindrome "<<isPalindrome<<endl;
  return 0;
}
