/*
 * For a given 2D array of rotate it to 90 degree

 * Example 
 * Input
 * 1 2 3
 * 4 5 6
 * 7 8 9

 * Output
 * 7 4 1
 * 8 5 2
 * 9 6 3
 
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

void print(vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------

// * Space Complexity O(n^2)
// * Time Complexity O(n^2)
// * Brute Force Approach (My Approach)
void rotateMatrix(int arr[][3], int totalRows, int totalCols) {
  int total = totalRows*totalCols;
  vector<int> a;

  for(int col=0; col<totalCols; col++) {
    for(int row=totalRows-1; row>=0; row--) {
      a.push_back(arr[row][col]);
    }
  }

  int idx = 0;
  for(int row=0; row<totalRows; row++) {
    for(int col=0; col<totalCols; col++) {
      arr[row][col] = a[idx++];
    }
  }

  printMDArray(arr, 3, 3);
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------

// * Space Complexity O(n^2)
// * Time Complexity O(n^2)
// * Brute Froce Approach (Online)
void rotateMatrix2(int arr[][3], int totalRows, int totalCols) {
  int total = totalRows*totalCols;
  vector<int> a;
  int n = 3;
  int arr_reverse[3][3];

  // * Column to Row Approach
  // for(int i=0; i<totalRows; i++) {
  //   for(int j=0; j<totalCols; j++) {
  //     // cout<<j<<" "<<i<<" => "<<i<<" "<<(n-1)-j<<endl;
  //     arr_reverse[i][(n-1)-j] = arr[j][i];
  //   }
  //   // cout<<endl;
  // }

  // * Row to Column Approach
  for(int i=0; i<totalRows; i++) {
    for(int j=0; j<totalCols; j++) {
      // cout<<i<<" "<<j<<" => "<<i<<" "<<(n-1)-i<<endl;
      arr_reverse[j][(n-1)-i] = arr[i][j];
    }
    // cout<<endl;
  }


  printMDArray(arr_reverse, 3, 3);
}


// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------


// * Space Complexity O(n^2)
// * Time Complexity O(1)
// * Optimized Approach (Online)
void rotateMatrix3(int arr[][3], int totalRows, int totalCols) {
  int total = totalRows*totalCols;
  int n = 3;
  
  // * Transpose of matrix
  for(int i=0; i<n-1; i++) {
    for(int j=i+1; j<n; j++) {
      // cout<<i<<" "<<j<<endl;
      swap(arr[i][j], arr[j][i]);
    }
  } 

  // * Reverse the matrix
  for(int i=0; i<n; i++) {
    int s = 0, e = n-1;
    while(s<=e) {
      swap(arr[i][s], arr[i][e]);
      s++;
      e--;
    }
  }

  printMDArray(arr, 3, 3);
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
  // rotateMatrix(arr, 3, 3);
  // rotateMatrix2(arr, 3, 3);
  rotateMatrix3(arr, 3, 3);

  return 0;
}