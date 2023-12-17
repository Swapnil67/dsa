#include<iostream>
using namespace std;

long long climbStairs(long long n) {
  // * Base cases
  if(n < 0) {
    return 0;
  }

  if(n == 0) {
    return 1;
  }

  // * Recursive Relation
  long long ans = climbStairs(n-1) + climbStairs(n-2);
  return ans;
}

int main() { 
  long long n;
  cout<<"Enter a number: ";
  cin>>n;
  long long ans = climbStairs(n);
  cout<<"ans: "<<ans<<endl;
  return 0;
}