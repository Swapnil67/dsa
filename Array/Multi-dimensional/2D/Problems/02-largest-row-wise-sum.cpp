// * WAP in cpp to return the largest row index
/*
 * Input
 * 3 4 11 => 18 
 * 1 12 1 => 14
 * 7 8 7  => 22
 
 * Output
 * row => 2
*/

#include<iostream>
using namespace std;

void printMDArray(int arr[][3], int totalRows, int totalCols) {
  for(int row=0; row<totalRows; row++) {
    for(int col=0; col<totalCols; col++) {
      cout<<arr[row][col]<<" ";
    }
    cout<<endl;
  }
}

int largestRow(int arr[][3], int totalRows, int totalCols) {
  int sum=0, temp=INT_MIN, largestIdx = -1;
  for(int row=0; row<2; row++) {
    sum = 0;
    for(int col=0; col<3; col++) {
      sum += arr[row][col];
    }
    if(sum > temp) {
      temp = sum;
      largestIdx = row;
    }
    cout<<sum<<" ";
  }
  cout<<endl;
  return largestIdx;
}

int main() {
  int arr[2][3];
  cout<<"Enter Array elements: "<<endl;
  for(int row=0; row<2; row++) {
    for(int col=0; col<3; col++) {
      cin>>arr[row][col];
    }
  }

  // * Print
  cout<<"------------ 2D array ------------"<<endl;
  printMDArray(arr, 2, 3);

  // * Sum of rows
  cout<<"------------ Sum of rows ------------"<<endl;
  int rowIdx = largestRow(arr, 2, 3);
  cout<<"Largest row index: "<<rowIdx;

  return 0;
}