#include<iostream>
using namespace std;

// * ------------------------- UTILITY FUNCTIONS -------------------------`

// * Time Complexity O(N^2)
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


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(NlogN) + O(2N)
/*
 * O(nlogn) => sorting the md array
 * O(2N) => Nested loop (the jth loop only runs for 2 elements)
*/
// * SPACE COMPLEXITY O(N)
vector<vector<int>> bruteForce(vector<vector<int>> arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;
  for(int i=0; i<n; i++) {
    int start = arr[i][0];
    int end = arr[i][1];

    if(!ans.empty() && ans.back()[1] >= end) {
      continue;
    }

    for(int j=i+1; j<n; j++) {
      if(end >= arr[j][0]) {
        end = max(end, arr[j][1]);
      } else {
        break;
      }
    }
    ans.push_back({ start, end });
    // cout<<start<<" "<<end<<endl;
  }
  return ans;
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(NlogN) + O(N)
/*
 * O(nlogn) => sorting the md array
 * O(N) => Single loop
*/
// * SPACE COMPLEXITY O(N)
vector<vector<int>> optimalApproach(vector<vector<int>> arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;
  for(int i=0; i<n; i++) {
    if(ans.empty() || ans.back()[1] < arr[i][0]) {
      ans.push_back({ arr[i] });
    } else {
      ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
  }
  return ans;
}

int main() {
  vector<vector<int>> arr = {{1,4}, {4,5}};
  // vector<vector<int>> arr = {{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
  // printMatrix(arr);

  // vector<vector<int>> ans = bruteForce(arr);
  vector<vector<int>> ans = optimalApproach(arr);
  printMatrix(ans);
  return 0;
}