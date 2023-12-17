// * WAP to return the sum of rows & colums in a MD array
/*
 * Input
 * 3 4 11
 * 1 12 1 
 * 7 8 7  
 
 * Output
 * 18 14 22
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

void sumOfRows(int arr[][3], int totalRows, int totalCols) {
  int sum = 0;
  for(int row=0; row<2; row++) {
    sum = 0;
    for(int col=0; col<3; col++) {
      sum += arr[row][col];
    }
    cout<<sum<<" ";
  }
}

void sumOfCols(int arr[][3], int totalRows, int totalCols) {
  int sum = 0;
  for(int col=0; col<3; col++) {
    sum = 0;
    for(int row=0; row<2; row++) {
      sum += arr[row][col];
    }
    cout<<sum<<" ";
  }
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
  sumOfRows(arr, 2, 3);

  // * Sum of columns
  cout<<"\n------------ Sum of columns ------------"<<endl;
  sumOfCols(arr, 2, 3);

  return 0;
}