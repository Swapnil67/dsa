#include<iostream>
using namespace std;

int main() {
  char ch = 'a';
  char *ch_ptr = &ch;
  ch++;
  cout<<"ch: "<<ch<<endl;
  cout<<"ch_ptr: "<<ch_ptr<<endl;
  cout<<"*ch_ptr: "<<*ch_ptr<<endl;
}