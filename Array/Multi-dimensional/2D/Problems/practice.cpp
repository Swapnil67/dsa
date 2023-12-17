#include<vector>
#include<iostream>
using namespace std; 

void printMatrix(vector<vector<int>>&mat) {
  int n = mat.size();
  int m = mat[0].size();
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
}
void print(vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// vector<int> spiralMatrix(vector<vector<int>>&mat) {
//   vector<int> ans;
//   int n = mat.size();
//   int m = mat[0].size();

//   int startRow = 0;
//   int endRow = n;
//   int startCol = 0;
//   int endCol = m;

//   int count = 0;
//   int total = n*m;

//   while(count < total) {

//     for(int i=startRow; count < total && i<endCol; i++) {
//       cout<<mat[startRow][i]<<" ";
//       ans.push_back(mat[startRow][i]);
//       count++;
//     }
//     startRow++;

//     cout<<endl;
//     cout<<"startRow "<<startRow<<endl;
//     cout<<"endRow "<<endRow<<endl;

//     for(int i=startRow; count < total && i<endRow; i++) {
//       cout<<mat[i][endRow]<<" ";
//       ans.push_back(mat[i][endRow]);
//       count++;
//     }
//     endCol--;

//     for(int i=endCol-1; count < total && i>=startCol; i--) {
//       cout<<mat[endRow-1][i]<<" ";
//       ans.push_back(mat[endRow-1][i]);
//       count++;
//     }
//     endRow--;

//     for(int i=endRow-1; count < total && i>=startRow; i--) {
//       cout<<mat[i][startCol]<<" ";
//       ans.push_back(mat[i][startCol]);
//       count++;
//     }
//     startCol++;

//   }

//   return ans;
// }


vector<int> spiralMatrix(vector<vector<int>>&mat) {
  vector<int> ans;
  int n = mat.size();
  int m = mat[0].size();

  int startRow = 0;
  int endRow = n-1;
  int startCol = 0;
  int endCol = m-1;

  int count = 0;
  int total = n*m;

  while(count < total) {

    for(int i=startRow; count < total && i<=endCol; i++) {
      cout<<mat[startRow][i]<<" ";
      ans.push_back(mat[startRow][i]);
      count++;
    }
    startRow++;
  

    for(int i=startRow; count < total && i<=endRow; i++) {
      cout<<mat[i][endRow]<<" ";
      ans.push_back(mat[i][endRow]);
      count++;
    }
    endCol--;

    for(int i=endCol; count < total && i>=startCol; i--) {
      cout<<mat[endRow][i]<<" ";
      ans.push_back(mat[endRow][i]);
      count++;
    }
    endRow--;

    for(int i=endRow; count < total && i>=startRow; i--) {
      cout<<mat[i][startCol]<<" ";
      ans.push_back(mat[i][startCol]);
      count++;
    }
    startCol++;

  }

  return ans;
}


int main() {
  // vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
  vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  cout<<"\n------------------ Matrix Print ------------------ \n";
  printMatrix(mat);
  cout<<"\n------------------ Spiral Print ------------------ \n";
  vector<int> spiralArr = spiralMatrix(mat);
  cout<<endl;
  // print(spiralArr);
  return 0;
}