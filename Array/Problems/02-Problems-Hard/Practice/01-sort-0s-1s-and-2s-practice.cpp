// * WAP to sort 0's, 1's and 2's in an array
// * INPUT: arr = [0,1,2,0,1,2,1,2,0,0,0,1] // 0 1 2 0 1 2 1 2 0 0 0 1
// * OUTPUT: arr = [0,0,0,0,0,1,1,1,1,2,2,2]

#include<iostream>
using namespace std;

void print(vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main() {
  vector<int> arr = { 0,1,2,0,1,2,1,2,0,0,0,1 };
  print(arr);
  return 0;
}

