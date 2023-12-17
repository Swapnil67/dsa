#include<iostream>
using namespace std;

int main() {
  int i = 5;
  int *ptr = &i;
  int **dptr = &ptr;
  
  cout<<"i: "<<i<<endl;
  cout<<"ptr: "<<ptr<<endl;
  cout<<"dptr: "<<dptr<<endl;

  cout<<"--------------------------------------------\n";

  cout<<"*ptr: "<<*ptr<<endl;
  cout<<"*dptr: "<<*dptr<<endl; // * Contains Address in ptr block (Not of ptr block)
  cout<<"**dptr: "<<**dptr<<endl; // * returns the value at Address of ptr pointer

  cout<<"--------------------------------------------\n";
  int first = 110;
  int *f = &first;
  int **ff = &f;
  int second = (**ff)++ + 9;
  cout<<"First: "<<first<<" | Second: "<<second<<endl;

}