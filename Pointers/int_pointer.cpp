#include<iostream>
using namespace std;

int main() {
  int a = 5;
  int *a_ptr = &a;
  cout<<"a: "<<a<<endl;
  cout<<"a_ptr: "<<a_ptr<<endl;
  cout<<"*a_ptr: "<<*a_ptr<<endl;
  a++;
  cout<<"a: "<<a<<endl;
  cout<<"a_ptr: "<<a_ptr<<endl;
  cout<<"*a_ptr: "<<*a_ptr<<endl;
  (*a_ptr)++;
  cout<<"a: "<<a<<endl;
  cout<<"a_ptr: "<<a_ptr<<endl;
  cout<<"*a_ptr: "<<*a_ptr<<endl;
}