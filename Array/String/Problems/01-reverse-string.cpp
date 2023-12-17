#include<iostream>
#include<string>
using namespace std;

void swap(char &a, char &b) {
  char temp = a;
  a = b;
  b = temp;
}

string reverse(string str) {
  int s = 0;
  int e = str.length()-1;
  while(s<=e) {
    swap(str[s++], str[e--]);
  }
  return str;
}

void reverse1(string str) {
  for(string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit) {
    cout<<*rit;
  }
  cout<<endl;
}

int main() { 
  string str;
  cout<<"Enter a string "<<endl;
  cin>>str;
  cout<<"Entered String "<<str<<endl;
  str = reverse(str);
  cout<<"Reverse String "<<str<<endl;
  cout<<"Reversing again ";
  reverse1(str);
  return 0;
}