/*
* Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/

#include<map>
#include<iostream>
using namespace std;


// * ------------------------- UTILITY FUNCTIONS -------------------------`

void print1dArray(vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

bool linearSearch(vector<int> arr, int p) {
  for(int i=0; i<arr.size(); i++) {
    if(arr[i] == p) return true;
  }
  return false;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

vector<int> bruteForce(vector<int> arr) {
  vector<int> ans;
  int n = arr.size();
  int oocurrence = n/3;
  cout<<"oocurrence "<<oocurrence<<endl;
  for(int i=0; i<n; i++) {
    int c = 0;
    for(int j=0; j<n; j++) {
      if(arr[i] == arr[j]) c++;
    }
    if(c > oocurrence) {
      if(linearSearch(ans, arr[i]) == false) {
        cout<<"arr[i] "<<arr[i]<<endl;
        ans.push_back(arr[i]);
      }
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------`
vector<int> betterApproach(vector<int> arr) {
  vector<int> ans;
  int n = arr.size();
  map<int, int> cmap;
  int oocurrence = n/3;
  cout<<"oocurrence: "<<oocurrence<<endl;
  for(int i=0; i<n; i++) {
    cmap[arr[i]]++;
    if(cmap[arr[i]] > oocurrence) {
      ans.push_back(arr[i]);
    }
  }

  // for(auto it: cmap) {
  //   // cout<<"it.first "<<it.first<<" | it.second "<<it.second<<endl;
  //   if(it.second > oocurrence) {
  //     ans.push_back(it.first);
  //   }
  // }
  return ans;
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH -------------------------`

// * Moore's Voting Algorithm
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
vector<int> optimalApproach(vector<int> arr) {
  vector<int> ans;
  int c1 = 0, c2 = 0;
  int ele1 = 0, ele2 = 0;
  int n = arr.size();

  for(int i=0; i<n; i++) {
    if(c1 == 0 && ele2 != arr[i]) {
      c1 = 1;
      ele1 = arr[i];
    }
    else if(c2 == 0 && ele1 != arr[i]) {
      c2 = 1;
      ele2 = arr[i];
    } 
    else if(arr[i] == ele1) c1++;
    else if(arr[i] == ele2) c2++;
    else {
      c1--;
      c2--;
    } 
  }

  // cout<<"ele1 "<<ele1<<endl;
  // cout<<"ele2 "<<ele2<<endl;

  c1 = 0, c2 = 0;
  for(int i=0; i<n; i++) {
    if(ele1 == arr[i]) c1++;
    if(ele2 == arr[i]) c2++;
  }

  int mini = (int)(n/3);
  // cout<<"mini "<<mini<<endl;;
  if(c1 > mini) ans.push_back(ele1);
  if(c2 > mini) ans.push_back(ele2);
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  // vector<int> nums {2,2,1,1,1,1,2,2};
  // vector<int> nums {1,1,1,2,2,2};
  vector<int> nums { 3,3,4 };
  vector<int> ans;

  // ans = bruteForce(nums);
  // ans = betterApproach(nums);
  ans = optimalApproach(nums);
  print1dArray(ans);

  return 0;
}