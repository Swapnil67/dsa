#include<iostream>
using namespace std;

int main() {
  // * 1-D  Array
  cout<<"------------------- 1-D Array -------------------"<<endl;
  cout<<"Enter the elements for 1-D Array: "<<endl;
  int* arr = new int[5];
  for(int i=0; i<5; i++) {
    cin>>arr[i];
  }
  for(int i=0; i<5; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  cout<<"------------------- 2-D Array -------------------"<<endl;
  // cout<<"Enter the elements for 2-D Array: "<<endl;
  int row, col;
  cout<<"Enter the row count: "<<endl;
  cin>>row;
  cout<<"Enter the column count: "<<endl;
  cin>>col;

  cout<<"Enter "<<row*col<<" elements of 2D array: "<<endl;

  // * 2-D Array
  int** arr2d = new int*[row];
  for(int i=0; i<row; i++) {
    arr2d[i] = new int[col];
  }

  for(int i=0; i<row; i++) {
    for(int j=0; j<col; j++) {
      cin>>arr2d[i][j];
    }
  }
  
  for(int i=0; i<row; i++) {
    for(int j=0; j<col; j++) {
      cout<<arr2d[i][j]<<" ";
    }
    cout<<endl;
  }

  // * Releasing Memory
  for(int i=0; i<row; i++){
    delete [] arr[i];
  }
  delete []arr;

  return 0;
}