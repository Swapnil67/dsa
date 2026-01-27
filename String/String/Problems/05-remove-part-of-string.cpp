/*
* Given two strings str & part, perform the following operation on str until all occurrences of the substring part are removed
* Find the leftmost occurrence of the substring part and remove it from str
* A substring is a contigusous sequence of characters in a string
*/
// * Input : "daabcbaabcbc" | Output : 'dab'

#include<iostream>
#include<string>
using namespace std;

void replacePart(string &s, string part) {
  while(s.length() != 0 && s.find(part) < s.length()) {
    // cout<<s.find(part)<<" "<<part.length()<<endl;
    s.erase(s.find(part), part.length());
  }
}

int main() {
  string str = "daabcbaabcbc";
  string part = "abc";
  cout<<"Before Removing: "<<str<<endl;
  replacePart(str, part);
  cout<<"After Removing: "<<str;
  return 0;
}