#include<iostream>
using namespace std;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// TODO


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int optimalApproach(vector<int> arr) {
  int n = arr.size();
  int maxi = INT_MIN;
  int prefix = 1, suffix = 1;
  for(int i=0; i<n; i++) {
    if(prefix == 0) prefix = 1;
    if(suffix == 0) suffix = 1;

    prefix = prefix * arr[i];
    suffix = suffix * arr[n - i - 1];
    maxi = max(maxi, max(prefix, suffix));
  }
  return maxi;
}

int main() {
  vector<int> arr = { 2,3, -2,4 };
  int maxi = optimalApproach(arr);
  cout<<"maximum product subarray: "<<maxi<<endl;
  return 0;
}