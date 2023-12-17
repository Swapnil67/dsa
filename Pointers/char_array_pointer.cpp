#include<iostream>
using namespace std;

// * Note that "cout" implementation for integer array is different for char array

int main() {
  int arr[5] = { 1,2,3,4,5 };
  char ch[6] = "hello";
  
  cout<<"arr: "<<arr<<endl;
  cout<<"ch: "<<ch<<endl;

  cout<<"--------------------------------------------\n";

  int *a_ptr = arr;
  char *c_ptr = ch;

  cout<<"a_ptr: "<<a_ptr<<endl;
  cout<<"c_ptr: "<<c_ptr<<endl;

  cout<<"--------------------------------------------\n";

  char ch2[20];

  int i = 0;
  for(i=0; i<10; i++) {
    *(ch2+i) = 65+i;
  }
  *(ch2+i) = '\0';
  cout<<"ch2: "<<ch2<<endl;

  char *ch2_p = ch2;
  cout<<"*ch2_p: "<<*ch2_p<<endl;
  cout<<"ch2_p: "<<ch2_p<<endl;
  cout<<"ch2_p+1: "<<ch2_p+1<<endl; // * Not points from 2nd 
  cout<<"ch2_p+2: "<<ch2_p+2<<endl; // * Not points from 3rd
}