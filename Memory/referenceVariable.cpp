#include<iostream>
using namespace std;

int main() {
  int i = 10;
  // * Create reference variable
  int& j = i;
  cout<<"i: "<<i<<endl;
  i++;
  cout<<"i: "<<i<<endl;
  j++;
  cout<<"i: "<<i<<endl;
  return 0;
}