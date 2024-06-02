// * Book Allocation Problem

#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> arr, int m, int mid) {
  int studentCount = 1, pageSum = 0;

  for(int i=0; i<arr.size(); i++) {
    if(pageSum + arr[i] <= mid) {
      pageSum += arr[i];
    } 
    else {
      studentCount++;
      if(studentCount > m || arr[i] > mid) {
        return false;
      }
      pageSum = arr[i];
    }
  }
  return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
  int ans = -1, sum = 0;
  for(int i=0;i<arr.size(); i++) {
    sum = sum + arr[i];
  }

  int s = 0;
  int e = sum;

  while(s<=e) {
    int mid = s + (e-s)/2;
    cout<<"mid: "<<mid<<endl;
    if(isPossible(arr, m, mid)) {
      ans = mid;
      e = mid-1;
    } else {
      s = mid+1;
    }
  }

  return ans;
}

int main() {
  vector<int> arr;
  arr.push_back(10);
  arr.push_back(20);
  arr.push_back(30);
  arr.push_back(40);
  arr.push_back(50);

  int books = 5;
  int students = 2;

  int minPages = allocateBooks(arr, books, students);
  cout<<"minPages: "<<minPages<<endl;
  return 0;
}