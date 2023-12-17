#include<set>
#include<iostream>
using namespace std;

void printMatrix(vector<vector<int>> arr) {
  int r = arr.size();
  int c = arr[0].size();
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
}

vector<vector<int>> bruteForce(vector<int>nums) {
  set<vector<int>> st;
  int n = nums.size();
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      for(int k=j+1; k<n; k++) {
        int sum = nums[i]+nums[j]+nums[k];
        if(sum == 0) {
          // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
          vector<int> temp = { nums[i], nums[j], nums[k] };
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
      }
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

vector<vector<int>> betterApproach(vector<int>nums) {
  set<vector<int>> st;
  int n = nums.size();
  for(int i=0; i<n; i++) {
    set<int> hashset;
    for(int j=i+1; j<n; j++) {
      int k = -(nums[i]+nums[j]);
      if(hashset.find(k) != hashset.end()) {
        vector<int> temp = { nums[i], nums[j], k };
        sort(temp.begin(), temp.end());
        st.insert(temp);
      }
      hashset.insert(nums[j]);
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

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
  vector<int> nums = { -1, -1, 2, 0, 1 };
  // vector<vector<int>> ans = bruteForce(nums);
  // vector<vector<int>> ans = betterApproach(nums);
  vector<vector<int>> ans = optimalApproach(nums);
  printMatrix(ans);
  return 0;
}