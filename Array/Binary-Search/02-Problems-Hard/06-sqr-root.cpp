/*
 * Square Root of a number
 
 * Example 1:
 * Input: number = 7
 * Output: 2

 * Example 2:
 * Input: number = 100
 * Output: 10


 * https://www.codingninjas.com/studio/problems/square-root-integral_893351?leftPanelTab=0%3Futm_source%3Dyoutube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
*/

#include<iostream>
using namespace std;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int bruteForce(long long n) {  
  long long sqrt = 1;
  for(long long i=1; i<=n; i++) {
    if(i*i <= n) {
      sqrt = i;
    }
    else {
      break;
    }
  }
  return sqrt;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------

// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int optimalApproach(long long n) {
  long long low = 1, high = n;
  long long sqrt = low;
  while(low <= high) {
		long long mid = (low + (high - low)/2);
		long long val = mid * mid;
    // cout<<mid<<endl;
    if(mid * mid <= n) {
      low = mid + 1;
      sqrt = mid;
    }
    else {
      high = mid - 1; 
    }
  }
  return sqrt;
}

int main() {
  int n = 99;
  // int sqrt = bruteForce(n);
  int sqrt = optimalApproach(n);
  cout<<"Square Root of "<<n<<" is "<<sqrt<<endl;
  return 0;
}