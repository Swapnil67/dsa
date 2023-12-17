#include<iostream>
using namespace std;

// * ------------------------- APPROACH 1: Paramaterised Approach -------------------------`
// * Paramaterised Approach does not returns anything it just prints

void approachOne(int n, int fact) {
  if(n == 0) {
    cout<<"Factorial: "<<fact<<endl;
    return;
  }
  approachOne(n-1, fact*n);
}

// * ------------------------- APPROACH 2: Functional Approach -------------------------`
// * Funtional Approach returns a value

int approachTwo(int n) {
  if(n == 0) return 1;
  return n * approachTwo(n-1);
}


int main() {
  int n;
  cout<<"Enter a number ";
  cin>>n;

  
  // * Parameterized Approach
  // approachOne(n, 1);

  // * Functional Approach
  int fact = 1;
  fact = approachTwo(n);
  cout<<"Factorial: "<<fact<<endl;
  
  return 0;
}