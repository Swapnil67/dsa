// * WAP in cpp to reverse a char array 
// * Note char are not case sensitive.

// * INPUT = ['B', 'o', 'b'], isPalindrome = true
// * INPUT = ['Z', 'o', 'R', 'o'], isPalindrome = false

#include<iostream>
using namespace std;

int getLengthOfStr(char str[]) {
  int c = 0;
  for(int i=0; str[i]!='\0'; i++) {
    c++;
  }
  return c;
}

char toLowerCase(char ch) {
  if(ch >= 'a' && ch <= 'z') {
    return ch;
  } 
  else {
    char temp = ch - 'A' + 'a';
    return temp;
  }
}

bool shouldCompare(char ch) {
  if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
    return true;
  } else {
    return false;
  }
}

bool checkPalindrome(char str[]) {
  int s = 0;
  int e = getLengthOfStr(str)-1;
  while(s<=e) {
    if(toLowerCase(str[s]) != toLowerCase(str[e])) {
      return false;
    } else {
      s++;
      cout<<shouldCompare(str[s])<<endl;
      if(!shouldCompare(str[s])) {
        s++;
      }
      e--;
      cout<<shouldCompare(str[e])<<endl;
      if(!shouldCompare(str[e])) {
        e--;
      }
    }
  }
  return true;
}

int main() {
  char str[10];
  cout<<"Enter a string: "<<endl;
  cin>>str;
  cout<<"Checking palindrone..."<<endl;
  bool isPalindrome = checkPalindrome(str);
  cout<<"Palindrome "<<isPalindrome;
  return 0;
}