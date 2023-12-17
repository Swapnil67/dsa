#include<iostream>
using namespace std;

// * ------------------------- APPROACH 1: Paramaterised Approach -------------------------`
// * Paramaterised Approach does not returns anything it just prints

void approachOne(int n, int sum) {
  if(n < 1) {
    cout<<"Sum: "<<sum<<endl;
    return;
  }
  sum = n+sum;
  n = n-1;
  approachOne(n, sum);
}

// * ------------------------- APPROACH 2: Functional Approach -------------------------`
// * Funtional Approach returns a value

int approachTwo(int n) {
  if(n == 0) return 0;
  // cout<<n<<" ";
  return n + approachTwo(n-1);
}

int main() {
  int n;
  cout<<"Enter a number: ";
  cin>>n;
  int sum = 0;

  // * Parameterized 
  // approachOne(n, sum);

  // * Functional 
  sum = approachTwo(n);
  cout<<"Sum: "<<sum<<endl;
  return 0;
}