/*
 * For a given 2D array of size nxm print arr in a sine wave order.
 * Input
 * 1 2 3
 * 4 5 6
 * 7 8 9
 
 * Output
 * 1 4 7 8 5 2 3 6 9
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

void wavePrint(int arr[][3], int totalRows, int totalCols) {
  for(int col=0; col<totalCols; col++) {
    if(col&1) {
      // * Bottom to top => ODD columns
      for(int row=totalRows-1; row>=0; row--) {
        cout<<arr[row][col]<<" ";
      }
    } else {
      // * top to Bottom => EVEN columns
      for(int row=0; row<totalRows; row++) {
        cout<<arr[row][col]<<" ";
      }
    }
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

  cout<<"Wave Print"<<endl;

  wavePrint(arr, 3, 3);
  return 0;
}

