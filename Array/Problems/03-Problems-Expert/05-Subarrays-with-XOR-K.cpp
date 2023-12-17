#include<map>
#include<iostream>
using namespace std;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForceApproach(vector<int> arr, int b) {
  int n = arr.size();
  int count = 0;
  for(int i=0; i<n; i++) {
    int xr = arr[i] ^ arr[i];
    for(int j=i; j<n; j++) {
      xr = xr ^ arr[j];
      // cout<<xr<<endl;
      if(xr == b) count++;
    }
  }
  return count;
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(N)
/*
* Best Case => O(N)
* Worst Case => O(NlogN) Depending on map
*/
// * SPACE COMPLEXITY O(logn) (For Map)
int optimalApproach(vector<int> arr, int k) {
  int n = arr.size();
  int xr = 0, count = 0;
  map<int,int> xr_map;
  xr_map[xr]++; // * { 0, 1 } Default
  for(int i=0; i<n; i++) {
    xr = xr ^ arr[i];
    int x = xr ^ k;
    count += xr_map[x];
    xr_map[xr]++;
  }
  return count;
}


int main() {
  // int b = 6;
  // vector<int> arr = { 4,2,2,6,4 };

  int b = 2;
  vector<int> arr = { 1,2,3,4 };

  // int b = 3;
  // vector<int> arr = { 1,2,3,3 };
  // int count = bruteForceApproach(arr, b);
  int count = optimalApproach(arr, b);
  cout<<"count: "<<count<<endl;
  return 0;
}