/*
* You have given two integer sorted arrays arr1 & arr2, sorted in non-descending order and two integers m & n
* representing number of elements in arr1 & arr2 respectively
* The final sorted array should not be returned by function but instead be stored inside the array arr1.
* To accomodate this arr1 has length of m+n, where the first n elements denotes the elements that should be merged
* and the last n elements are set to 0 and should be ignored. arr2 has length of n
*/
// * INPUT: arr1 = [1 2 3 0 9 0 0] & arr2: [2 5 6]
// * OUTPUT: arr1 = [1 2 2 3 5 6]

#include<iostream>
#include<vector>
using namespace std;


void print(vector<int> arr, int s) {
  for(int i=0; i<s; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void merge2(vector<int> &arr1, int arr1_size, vector<int> &arr2, int arr2_size)  {
  int i=0, j=0, k=0;
  while(i<arr1_size && j<arr2_size) {
    if(arr1[i] >= arr2[j]) {
      if(arr2[i] != 0) {
        arr1.insert(arr1.begin() + i, arr2[j]);
        j++;
      }
      k++;
    } 
    i++; 
  }

  while(i<arr1_size) {
    arr1.push_back(arr1[i]);
    k++;
    i++;
  }
 
  while(j<arr2.size()) {
    arr1.insert(arr1.begin() + arr1_size + j, arr2[j]);
    k++;
    j++;
  }
}


int main() {
  vector<int> arr1;
  int arr1_size = 3;
  arr1.push_back(1);
  arr1.push_back(2);
  arr1.push_back(3);
  arr1.push_back(0);
  arr1.push_back(0);
  arr1.push_back(0);

  vector<int> arr2;
  int arr2_size = 3;
  arr2.push_back(2);
  arr2.push_back(5);
  arr2.push_back(6);

  vector<int> arr3;
  merge2(arr1, arr1_size, arr2, arr2_size);
  cout<<"----------------- Array: 1 -----------------"<<endl;
  print(arr1, arr1_size);
  cout<<"----------------- Array: 2 -----------------"<<endl;
  print(arr2, arr2_size);
  cout<<"----------------- Merged Arrays -----------------"<<endl;
  int final_size = arr1_size+arr2_size;
  print(arr1, final_size);
  return 0;
}