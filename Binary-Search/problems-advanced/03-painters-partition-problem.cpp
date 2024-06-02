// * Painter's partition problem
/*
* Given an array list of length 'N' where the arraylist represents the boards and each element of 
* the given arraylist represents the length of each board. Some 'K' number of painters are available to paint
* these boards. Consider that each unit of board takes 1 unit of time to paint.

* You are supposed to return the area of the minimum time to get this job done of painting all the 'N'
* boards under a constraint that any painter will only paint the contigious sections of boards
*/
 
#include<iostream>
#include<vector>

using namespace std;

bool isPossible(vector<int> boards, int painters, int mid) {
  int painterCount = 1, timeSum = 0;
  for(int i=0; i<boards.size(); i++) {
    if(timeSum+boards[i] <= mid) {
      timeSum = timeSum+boards[i];
    } else {
      painterCount++;
      if(painterCount > painters) {
        return false;
      }
      timeSum = boards[i];
    }
  }
  return true;
}

int minimumTime(vector<int> boards, int painters) {
  int ans = 0, sum = 0;
  for(int i=0; i<boards.size(); i++) {
    sum += boards[i];
  }
  int s = 0, e = sum;
  while(s<=e) {
    int mid = s+(e-s)/2;
    if(isPossible(boards, painters, mid)) {
      ans = mid;
      e = mid-1;
    } else {
      s = mid+1;
    }
  }
  return ans;
} 

int main() {
  vector<int> boards;
  boards.push_back(10);
  boards.push_back(20);
  boards.push_back(30);
  boards.push_back(40);
  // boards.push_back(50);

  int painters = 2;

  int minTime = minimumTime(boards, painters);
  cout<<"minTime: "<<minTime<<endl;
  return 0;
}