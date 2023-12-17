#include<vector>
#include<iostream>
using namespace std;

bool isPossibleDistance(vector<int>stalls, int c, int mid) {
  int cowCount = 1;
  int lastPos = stalls[0];
  for(int i=0; i<stalls.size(); i++) {
    if(stalls[i] - lastPos >= mid) {
      cowCount++;
      if(cowCount == c) {
        return true;
      }
      lastPos = stalls[i];
    }
  }
  return false;
}

int findMaxDistance(vector<int> stalls, int c) {
  sort(stalls.begin(), stalls.end());
  int maxi = -1, ans = 0;
  for(int i=0; i<stalls.size(); i++) {
    maxi = max(maxi, stalls[i]);
  }
  int s = 0, e = maxi;
  while(s<=e) {
    int mid = s+(e-s)/2;
    if(isPossibleDistance(stalls, c, mid)) {
      ans = mid;
      s = mid+1;
    } else {
      e = mid-1;
    }
  }
  return ans;
}

int main() {
  vector<int> stalls;
  stalls.push_back(4);
  stalls.push_back(2);
  stalls.push_back(1);
  stalls.push_back(3);
  stalls.push_back(6);

  int cows = 2;
  int maxDistance = findMaxDistance(stalls, cows);
  cout<<"maxDistance: "<<maxDistance;

  return 0;
}