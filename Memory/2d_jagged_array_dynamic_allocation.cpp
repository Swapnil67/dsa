#include<iostream>
using namespace std;

int main() {
  int row, col;
  cout<<"Enter the row count: "<<endl;
  cin>>row;

  // * 2-D Array
  int** arr2d = new int*[row];
  int* cols = new int[row];

  for(int i=0; i<row; i++) {
    cout<<"Enter cols for row "<<i<<" : ";
    cin>>col;
    cols[i] = col;
    arr2d[i] = new int[col];
  }

  // for(int i=0; i<row; i++) {
  //   cout<<cols[i]<<" ";
  // }

  for(int i=0; i<row; i++) {
    cout<<"Enter "<<cols[i]<<" elements."<<endl;
    for(int j=0; j<cols[i]; j++) {
      cin>>arr2d[i][j];
    }
  }
  
  cout<<"----------------- Jagged Array ---------------\n";

  for(int i=0; i<row; i++) {
    for(int j=0; j<cols[i]; j++) {
      cout<<arr2d[i][j]<<" ";
    }
    cout<<endl;
  }

  // * Releasing Memory
  // for(int i=0; i<row; i++){
  //   delete [] arr[i];
  // }
  // delete []arr;

  return 0;
}