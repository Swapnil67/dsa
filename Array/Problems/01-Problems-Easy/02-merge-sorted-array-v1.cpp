#include<iostream>
#include<vector>
using namespace std;

// * arr1: [1 3 5 7 9 0 0]
// * arr2: [2 4 6 10 11]

void print(vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void merge(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)  {
  int i=0, j=0, k=0;
  while(i<arr1.size() && j<arr2.size()) {
    if(arr1[i] < arr2[j]) {
      if(arr2[i] != 0) {
        arr3.push_back(arr1[i]);
      }
      k++;
      i++; 
    } else {
      if(arr2[j] != 0) {
        arr3.push_back(arr2[j]);
      }
      k++;
      j++;
    }
  }

  while(i<arr1.size()) {
    arr3.push_back(arr1[i]);
    k++;
    i++;
  }
 
  while(j<arr2.size()) {
    arr3.push_back(arr2[j]);
    k++;
    j++;
  }
}

int main() {
  vector<int> arr1;
  arr1.push_back(1);
  arr1.push_back(2);
  arr1.push_back(3);
  arr1.push_back(0);
  arr1.push_back(0);
  arr1.push_back(0);

  vector<int> arr2;
  arr2.push_back(2);
  arr2.push_back(5);
  arr2.push_back(6);

  vector<int> arr3;
  merge(arr1, arr2, arr3);
  cout<<"----------------- Array: 1 -----------------"<<endl;
  print(arr1);
  cout<<"----------------- Array: 2 -----------------"<<endl;
  print(arr2);
  cout<<"----------------- Merged Arrays -----------------"<<endl;
  print(arr3);
  return 0;
}