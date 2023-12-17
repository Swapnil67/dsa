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

// * TIME COMPLEXITY O(N^3) x log(no of triplets) = O(N^3) x log(m)
/*
 * O(N^3) => Three for loop
 * log(m) => sorting vector of 3
*/
// * SPACE COMPLEXITY 2 x O(no of triplets)
vector<vector<int>> bruteForce(vector<int> arr) {
  set<vector<int>> st;
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    for(int j=i+1; j<n; j++) {
      for(int k=j+1; k<n; k++) {
        if((arr[i] + arr[j] + arr[k]) == 0) {
          // cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
          // * Create a ans vector
          vector<int> temp = { arr[i], arr[j], arr[k] };
          // * Preventing duplicates
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
      }
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------
// * If the following is true
//* arr[i] + arr[j] + arr[k] = 0 
// * Then we can also derive the following
//* arr[k] = -(arr[i] + arr[j]);

// * TIME COMPLEXITY O(N^2) x log(size of set) = O(N^2) x log(m)
/*
 * O(N^2) => Two for loop
 * log(m) => hashset
*/
// * SPACE COMPLEXITY O(N) x O(no of triplets) x 2
/*
 * O(N) => hashset
 * O(no of triplets) => st
 * O(no of triplets) => ans
*/
vector<vector<int>> betterApproach(vector<int> arr) {
  set<vector<int>> st;
  int n = arr.size();
  for(int i=0; i<n; i++) {
    set<int> hashset;
    for(int j=i+1; j<n; j++) {
      int k = -(arr[i] + arr[j]);
      if(hashset.find(k) != hashset.end()) {
        vector<int> temp = { arr[i], arr[j], k };
        // * Preventing duplicates
        sort(temp.begin(), temp.end());
        st.insert(temp);
      } 
      hashset.insert(arr[j]);
    }
  }  
  vector<vector<int>> ans(st.begin(), st.end()); 
  return ans;
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH (TWO POINTERS) -------------------------
// * TIME COMPLEXITY O(nlogn) + O(N^2)
/*
 * O(nlogn) => Sort the initial array
 * O(N^2) => Two for loop
*/
// * SPACE COMPLEXITY O(no of triplets)
// * O(no of triplets) => ans
vector<vector<int>> optimalApproach(vector<int>nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  int n = nums.size();
  for(int i=0; i<n; i++) {
    if(i > 0 && nums[i] != nums[i]-1) continue;
    int j = i+1, k = n-1;
    while(j < k) {
      int sum = nums[i] + nums[j] + nums[k];
      if(sum == 0) {
        vector<int> temp = { nums[i], nums[j], nums[k] };
        ans.push_back(temp);
        j++;
        k--;
        while(nums[k] == nums[k+1]) k--;
        while(nums[j] == nums[j+1]) j++;
      } 
      else if(sum > 0) {
        while(nums[k] == nums[k+1]) k--;
      }
      else { // * sum < 0
        while(nums[j] == nums[j+1]) j++;
      }
    }
  }
  return ans;
}

int main() {
  vector<int> arr = { -1, -1, 0, 2, 1 };
  // vector<vector<int>> ans = bruteForce(arr);
  // vector<vector<int>> ans = betterApproach(arr);
  vector<vector<int>> ans = optimalApproach(arr);
  cout<<"--------- Triplets --------- "<<endl;
  printMatrix(ans);
  return 0;
}