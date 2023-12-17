// * WAP to find square root of number using binary search

// ! Approach
// * Here we are finding the answer by minimizing the search space
// * Eg for n = 36, my search space = [0,1,2,3.........,,35,36]

#include<iostream>
using namespace std;

// * Square root without precision
long long int squareRoot(int n) {
  int s = 0;
  int e = n;
  long long int ans = -1;
  while(s<=e) {
    long long int mid = s+(e-s)/2;
    long long int square = mid*mid;
    if(square == n) {
      return mid;
    } else if(square > n) {
      e = mid-1;
    } else {
      ans = mid;
      s = mid+1;
    }
  }
  return ans;
}

// * Square root with precision
double morePrecision(int n, int precision,  int baseSoln) {
  double factor = 1;
  double ans = baseSoln;
  for(int i=0;i<precision;i++) {
    factor = factor/10;
    for(double j=baseSoln; j*j<n; j=j+factor) {
      ans = j;
    }
  }
  return ans;
}

int main() {
  int n = 37;
  long long int root = squareRoot(n);
  cout<<"Square root: "<<root<<endl;

  double rootPrecision = morePrecision(n, 3, root);
  cout<<"Square root with precesion: "<<rootPrecision;
  return 0;
}