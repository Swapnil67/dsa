/*
* Given an integer array of size n,
*/

#include<set>
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

// * TIME COMPLEXITY O(N^4) x log(no of quadruplets) = O(N^4) x log(m)
// * SPACE COMPLEXITY 2 x O(no of quadruplets)
vector<vector<int>> bruteForce(vector<int> arr) {
  int n = arr.size();
  set<vector<int>> st;

  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      for(int k=j+1; k<n; k++) {
        for(int l=k+1; l<n; l++) {
          long long sum = arr[i] + arr[j];
          sum += arr[k];
          sum += arr[l];
          if(sum == 0) {
            vector<int> temp = { arr[i], arr[j], arr[k], arr[l] };
            // * Preventing duplicates
            sort(temp.begin(), temp.end());
            st.insert(temp);
          }
        }
      }
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------
// * If the following is true
//* arr[i] + arr[j] + arr[k] + arr[l] = target 
// * Then we can also derive the following
//* arr[l] = target - (arr[i] + arr[j] + arr[k]);

// * TIME COMPLEXITY O(N^3) x log(size of set) = O(N^3) x log(m)
/*
 * O(N^3) => Three for loop
 * log(m) => hashset
*/
// * SPACE COMPLEXITY O(N) x O(no of quadruplets) x 2
/*
 * O(N) => hashset
 * O(no of quadruplets) => st
 * O(no of quadruplets) => ans
*/
vector<vector<int>> betterApproach(vector<int> arr, int target) {
  int n = arr.size();
  set<vector<int>> st;

  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      set<long long> hashset;
      for(int k=j+1; k<n; k++) {
        long long sum = arr[i] + arr[j] + arr[k];
        long long l =  target - sum;
        if(hashset.find(l) != hashset.end()) {
          vector<int> temp = { arr[i], arr[j], arr[k], (int)l };
          // * Preventing duplicates
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
        hashset.insert(arr[k]);
      }
    }
  }

  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------

vector<vector<int>> optimalApproach(vector<int> arr, int target) {
  sort(arr.begin(), arr.end());
  int n = arr.size();
  vector<vector<int>> ans;
  for(int i=0; i<n; i++) {
    if(i>0 && arr[i] == arr[i-1]) continue;
    for(int j=i+1; j<n; j++) {
      if(j != (i+1) && arr[j] == arr[j-1]) continue;
      int k = j+1;
      int l = n-1;
      while(k < l) {
        long long sum = arr[i];
        sum += arr[j];
        sum += arr[k];
        sum += arr[l];
        if(sum == target) {
          vector<int> temp = { arr[i], arr[j], arr[k], arr[l] };
          ans.push_back(temp);
          k++, l--;
          while(k < l && arr[k] == arr[k-1]) k++;
          while(k < l && arr[l] == arr[l+1]) l--;
        } 
        else if(sum > target) {
          l--;
        }
        else {
          k++;
        }
      }
    }
  }
  return ans;
}

int main() {
  vector<int> arr = { 1,0,-1,0,-2,2 };
  vector<vector<int>> ans;
  // ans = bruteForce(arr);
  // ans = betterApproach(arr, 0);
  ans = optimalApproach(arr, 0);
  cout<<"--------- Quads --------- "<<endl;

  printMatrix(ans);
  return 0;
}