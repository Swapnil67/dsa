/*
 * Zero Matrix
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
 * You must do it inplace
 * 
 * Example 1:
 * Input: nums = [5,8,3,2,1,4]
 * Output: 5
 * Explanation: The resultant sequence can be 1,2,3,4,5 therefore its length 5
*/

#include<vector>
#include<iostream>
using namespace std;


void print(vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// * Time Complexity O(N^2)
void printMDArray(int arr[][3], int totalRows, int totalCols) {
  cout<<"---------- Matrix ---------- "<<endl;
  for(int row=0; row<totalRows; row++) {
    for(int col=0; col<totalCols; col++) {
      cout<<arr[row][col]<<" ";
    }
    cout<<endl;
  }
}

// * Time Complexity O(N)
void markRow(int arr[][3], int row, int totalCols, int markVal) {
  for(int i=0; i<totalCols; i++) {
    if(arr[row][i] != 0) {
      arr[row][i] = -1;
    }
  }
}

// * Time Complexity O(N)
void markCol(int arr[][3], int col, int totalRows, int markVal) {
  for(int j=0; j<totalRows; j++) {
    if(arr[j][col] != 0) {
      arr[j][col] = -1;
    }
  }
}

// * Time Complexity O(N^2)
void markZeros(int arr[][3], int totalRows, int totalCols) {
  for(int i=0; i<totalRows; i++) {
    for(int j=0; j<totalCols; j++) {
      if(arr[i][j] == -1) {
        arr[i][j] = 0;
      }
    }
  }
}

// * Time Complexity O(N^2)
void markZerosUsingReference(int arr[][3], int mr[], int mc[], int totalRows, int totalCols) {
  for(int i=0; i<totalRows; i++) {
    for(int j=0; j<totalCols; j++) {
      if(mr[i] || mr[j]) {
        arr[i][j] = 0;
      }
    }
  }
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------

// * TIME COMPLEXITY O(N^3)
// * SPACE COMPLEXITY O(1)
void bruteForce(int arr[][3], int totalRows, int totalCols) {
  for(int i=0; i<totalCols; i++) {
    for(int j=0; j<totalCols; j++) {
      if(arr[i][j] == 0) {
        markRow(arr, i, totalRows, -1);
        markCol(arr, j, totalCols, -1);
      }
    }
  }
  markZeros(arr, totalRows, totalCols);
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------
// * TIME COMPLEXITY O(2xNxM) or 0(2xN^2)
// * SPACE COMPLEXITY O(n) + O(m)
void betterApproach(int arr[][3], int totalRows, int totalCols) {
  int markerRow[3] = {0};
  int markerCol[3] = {0};
  
  for(int i=0; i<totalRows; i++) {
    for(int j=0; j<totalCols; j++) {
      if(arr[i][j] == 0) {
        markerRow[i] = 1;
        markerRow[j] = 1;
      }
    }
  }

  markZerosUsingReference(arr, markerRow, markerCol, totalRows, totalCols);
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// TODO


int main() {
  int arr[3][3], n = 3, m = 3;
  cout<<"Enter Array elements: "<<endl;
  for(int row=0; row<3; row++) {
    for(int col=0; col<3; col++) {
      cin>>arr[row][col];
    }
  }

  printMDArray(arr, n, m);

  // * Approach 1
  // bruteForce(arr, n , m);
  betterApproach(arr, n , m);
  cout<<"--------------- Zero Matrix --------------- "<<endl;
  printMDArray(arr, n, m);

}