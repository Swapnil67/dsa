// ? WAP to reverse a sting with Stack Data Structure

#include<stack>
#include<iostream>
using namespace std;

int main() {
  string str = "Jujutsu";
  cout << "Before Reversing: " << str << endl;

  stack<char> s;
  for(int i=0; i<str.length(); i++) {
    s.push(str[i]);
  }

  string reverse_str = "";
  while (!s.empty()) {
    char ch = s.top();
    reverse_str.push_back(ch);
    s.pop();
  }

  cout<<"After Reversing: "<<reverse_str<<endl;
  
  return 0;
}