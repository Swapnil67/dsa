// * WAP to find square root of number using binary search

// ! Approach
// * Here we are finding the answer by minimizing the search space
// * Eg for n = 36, my search space = [0,1,2,3.........,,35,36]

#include<iostream>
using namespace std;

int squareRoot(int n) {
  int s = 0, e = n;
  int ans = -1;
  while(s<=e) {
    int mid = s+(e-s)/2;
    int sqr = mid*mid;
    if(sqr == n) {
      return mid;
    } else if(sqr > n) {
      e = mid-1;
    } else {
      ans = mid;
      s = mid+1;
    }
  }
  return ans;
} 

double morePrecision(int n, int tempSoln, int fac) {
  double ans = tempSoln;
  double factor = 1;
  for(int i=0; i<fac; i++) {
    factor = factor/10; // * For 0.1, 0.01, 0.001
    for(double j=ans; j*j<n; j=j+factor) {
      ans = j;
    }
  }
  return ans;
}

int main() {
  int n = 37;
  int root = squareRoot(n);
  cout<<"Root "<<root<<endl;
  double rootPrecision = morePrecision(n, root, 3);
  cout<<"rootPrecision "<<rootPrecision;
  return 0;
}