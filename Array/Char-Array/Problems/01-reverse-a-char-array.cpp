#include<iostream>
using namespace std;

int getLengthOfStr(char str[]) {
  int c = 0;
  for(int i=0; str[i] != '\0'; i++) {
    c++;
  }
  return c;
}

void swap(char &a, char &b) {
  char temp = a;
  a = b;
  b = temp;
}

void reverse(char str[]) {
  int s = 0;
  int e = getLengthOfStr(str)-1;
  while(s<=e) {
    swap(str[s++], str[e--]);
  }
}

int main() {
  char name[20];
  cout<<"Enter your name "<<endl;
  cin>>name;
  cout<<"Your name is "<<name<<endl;
  reverse(name);
  cout<<"Your name in reverse is "<<name;
  return 0;
}