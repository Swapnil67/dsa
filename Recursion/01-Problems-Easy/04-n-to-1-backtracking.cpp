#include<iostream>
using namespace std;
 
void printNto1(int i, int n) {
  if(i>n) {
    return;
  }
  printNto1(i+1, n);
  cout<<i<<" "; // * Backtracking
}

int main() {
  int n;
  cout<<"Enter a number: ";
  cin>>n;
  int i = 1;
  printNto1(i, n);
  cout<<endl;
  return 0;
}

/*
* n = 5
* f(1, 5) cout<<1;
* f(2, 5) cout<<2;
* f(3, 5) cout<<3;
* f(4, 5) cout<<4;
* f(5, 5) cout<<5;
*/