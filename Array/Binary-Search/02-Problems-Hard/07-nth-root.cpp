/*
 * Square Root of a number
 
 * Example 1:
 * Input: n = 3, m = 37
 * Output: 3

 * Example 2:
 * Input: n = 4, m = 69
 * Output: -1


 * https://www.youtube.com/watch?v=rjEJeYCasHs&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=54&t=181s
*/

#include<iostream>
using namespace std;

// * return 1 if == m
// * return 0 if < m
// * return 2 if > m
int checkRoot(int val, int root, int m) {
  int ans = 0;
  long long n_root = val;
  for(int i=1; i<root; i++) {
    n_root *= val;
    if(n_root > m) {
      return 2;
    }
  }

  if(n_root == m) return 1;
  return ans;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

int bruteForce(int n, int m) {  
  for (int i = 1; i <= m; i++) {
    int ans = checkRoot(i, n, m);
    // cout<<"ans: "<<ans<<endl;
    if(ans == 1) {
      return i;
    }
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------

int optimalApproach(int n, int m) {
  int low = 0, high = m-1;

  while(low <= high) {
    int mid = low + (high - low) / 2;
    int ans = checkRoot(mid, n, m);
    // cout<<"ans "<<ans<<endl;
    // cout<<"mid "<<mid<<endl;
    if(ans == 1) {
      return mid;
    }
    if(ans == 2) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return -1;
}

int main() {
  int n = 3, m = 27;
  // int n = 4, m = 69;
  int n_root = bruteForce(n,m);
  // int n_root = optimalApproach(n,m);
  cout<<"Nth Root of "<<m<<" is "<<n_root<<endl;
  return 0;
}