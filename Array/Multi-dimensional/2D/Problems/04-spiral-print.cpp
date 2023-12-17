/*
 * For a given 2D array of size nxm print arr in a spiral form
 * Input
 * 1 2 3
 * 4 5 6
 * 7 8 9
 
 * Output
 * 1 2 3 6 9 8 7 4 5
*/

#include<iostream>
#include<vector>

using namespace std;

void printMDArray(int arr[][3], int totalRows, int totalCols) {
  cout<<"---------- Matrix ---------- "<<endl;
  for(int row=0; row<totalRows; row++) {
    for(int col=0; col<totalCols; col++) {
      cout<<arr[row][col]<<" ";
    }
    cout<<endl;
  }
}

void printSpiral(int arr[][3], int totalRows, int totalCols) {
  int count = 0;
  int total = totalCols*totalCols;

  // * index initialization
  int startingRow = 0;
  int startingCol = 0;
  int endingRow = totalRows-1;
  int endingCol = totalCols-1;

  while(count < total) {
    // * Starting Row
    for(int i=startingCol; count < total && i<=endingCol; i++) {
      cout<<arr[startingRow][i]<<" ";
      count++;
    }
    startingRow++;

    // * Ending Col
    for(int i=startingRow; count < total && i<=endingRow; i++) {
      cout<<arr[i][endingCol]<<" ";
      count++;
    }
    endingCol--;

    // * Ending Row
    for(int i=endingCol; count < total && i>=startingCol; i--) {
      cout<<arr[endingRow][i]<<" ";
      count++;
    }
    endingRow--;

    // * Starting Col
    for(int i=endingRow; count < total && i>=startingRow; i--) {
      cout<<arr[i][startingCol]<<" ";
      count++;
    }
    startingCol++;
  }

}

int main() {
  int arr[3][3];
  cout<<"Enter Array elements: "<<endl;
  for(int row=0; row<3; row++) {
    for(int col=0; col<3; col++) {
      cin>>arr[row][col];
    }
  }

  printMDArray(arr, 3, 3);
  cout<<"----------- Print Spiral Pattern -----------"<<endl;
  printSpiral(arr, 3, 3);
  return 0;
}