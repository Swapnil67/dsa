#include<iostream>
using namespace std;

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void print1dArray(vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void print2dArray(vector<vector<int>> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) {
    for(int j=0; j<arr[i].size(); j++) {
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}

// * ------------------------- Return Element -------------------------`


// * TIME COMPLEXITY O(R) 
// * SPACE COMPLEXITY O(1)
int getValue(int n, int r) {
  int res = 1;
  for(int i=0; i<r; i++) {
    res = res * (n-i);
    res = res/(i+1);
  }
  return res;
}

// * ------------------------- Return Row -------------------------`

vector<int> generatePascalRow(int r) {
  vector<int> ansRow;;
  long long res = 1;
  ansRow.push_back(res);
  for(int i=1; i<r; i++) {
    res = res * (r-i);
    res = res/i;
    ansRow.push_back(res);
  }
  return ansRow;
}

// * ------------------------- Pascal Triangle -------------------------`

vector<vector<int>> pascalTriange(int r) {
  vector<vector<int>> pascalTriangleMatrix;
  for(int i=1; i<=r; i++) {
    vector<int> row = generatePascalRow(i);
    pascalTriangleMatrix.push_back(row);
  }
  return pascalTriangleMatrix;
}

int main() {
  int val = getValue(4, 2);
  cout<<"Val: "<<val<<endl;
  vector<int> sixthRow = generatePascalRow(6);
  cout<<"Sixth row: ";
  print1dArray(sixthRow);
  cout<<"----------- Pascal Triangle -----------\n";
  vector<vector<int>> pt = pascalTriange(6);
  print2dArray(pt);
  return 0;
}