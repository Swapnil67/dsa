// * Aggressive Cow Problem

#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &stalls, int cows, int mid) {
  sort(stalls.begin(), stalls.end());

  // * Keep the first cow at first positionf
  int cowCount = 1;
  int lastPos = stalls[0];
  for(int i=0; i<stalls.size(); i++) {
    if(stalls[i] - lastPos >= mid) {
      cowCount++;
      if(cowCount == cows) {
        return true;
      }
      lastPos = stalls[i];
    }
  }

  return false;
}

int aggressiveCows(vector<int> arr, int c) {
  int s = 0, ans = -1;
  int maxi = -1;
  for(int i=0; i<arr.size(); i++) {
    if(arr[i] > maxi) maxi = arr[i];
  }
  int e = maxi;
  // cout<<"s "<<s<<" e "<<e;
  while(s<=e) {  
    int mid = s+(e-s)/2;
    cout<<mid<<" ";
    if(isPossible(arr, c, mid)) {
      ans = mid;
      s = mid+1;
    } else {
      e = mid-1;
    }
  }
  cout<<endl;
  return ans;
}

int main() {
  vector<int> arr;
  arr.push_back(4);
  arr.push_back(2);
  arr.push_back(1);
  arr.push_back(3);
  arr.push_back(6);

  int cows = 2;
  int maxDistance = aggressiveCows(arr, cows);
  cout<<"maxDistance "<<maxDistance;

  return 0;
}

/*
* stalls = 4 2 1 3 6
* sorted stalls = 1 2 3 4 5 6
*  s = 0, e = 6, mid = 3 
*
*/