#include<iostream>
using namespace std;


// * ------------------------- APPROACH 1 -------------------------`

void generateFibonacci1(int a, int b, int n) {
  if(n == 0) {
    return;
  }
  n--;
  int c = a+b;
  cout<<c<<" ";
  a = b;
  b = c;
  generateFibonacci1(a, b, n);
}

// * ------------------------- APPROACH 1 -------------------------`

int generateFibonacci2(int n) {
  if(n == 0) {
    return 0;
  }
  if(n == 1) {
    return 1;
  }
  int ans = generateFibonacci2(n-1) + generateFibonacci2(n-2);
  return ans;
}


int main() {
  int a = 0;
  int b = 1;
  int n;
  cout<<"Enter number: ";
  cin>>n;

  // * Apporact 1
  // cout<<a<<" "<<b<<" ";
  // generateFibonacci1(a, b, n-2);

  // * Apporact 2
  int ans = generateFibonacci(n);
  cout<<ans;

  cout<<endl;
  return 0;
}