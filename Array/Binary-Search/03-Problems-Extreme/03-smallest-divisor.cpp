// TODO Add question

#include<cmath>
#include<iostream>
using namespace std;

// * ------------------------- Utility Function -------------------------`
int findMaxInArray(vector<int> arr) {
  int max_ele = INT_MIN;
  for(int i=0; i<arr.size(); i++) {
    max_ele = max(max_ele, arr[i]);
  }
  return max_ele;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

int bruteForce(vector<int> arr, int limit) {
  int max_ele = findMaxInArray(arr);
  int counter = 1, min_divisor = INT_MAX;
  while(counter <= max_ele) {
    int sum = 0;
    for(int i=0; i<arr.size(); i++) {
      float res = float(arr[i])/float(counter);
      // cout<<ceil(res)<<endl;
      sum += ceil(res);
    }
    min_divisor = min(min_divisor, sum);
    // cout<<"counter: "<<counter<<", sum: "<<sum<<endl;
    counter++;
  }
  return min_divisor;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
int optimalApproach(vector<int> arr, int limit) {
  int max_ele = findMaxInArray(arr);
  // cout<<"max_ele: "<<max_ele<<endl;

  int min_divisor = INT_MAX;
  int low = 1, high = max_ele;
  while(low <= high) {
    int mid = low + (high - low)/2;
    // cout<<"mid: "<<mid<<endl;
    int sum = 0;
    for(int i=0; i<arr.size(); i++) {
      float res = float(arr[i])/float(mid);
      sum += ceil(res);
    }
    // cout<<"sum: "<<sum<<endl;


    if(sum <= limit) {
      high = mid - 1;
      min_divisor = min(min_divisor, mid);
    }
    else {
      low = mid+1;
    }
  }
  return min_divisor;
}

int main() {
  // vector<int> arr = {1,2,5,9};
  // int limit = 6;
  vector<int> arr = { 8, 4, 2, 3 };
  int limit = 10;
  // int minimum_divisor = bruteForce(arr, limit);
  int minimum_divisor = optimalApproach(arr, limit);
  cout<<"Minimum Divisor: "<<minimum_divisor<<endl;
  return 0;
}