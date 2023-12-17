// * Book Allocation Problem
#include<vector>
#include<iostream>
using namespace std;

bool isPossible(vector<int> books, int m, int mid) {
  int studentCount = 1, pageSum = 0;
  for(int i=0; i<books.size(); i++) {
    if(pageSum+books[i] <= mid) {
      pageSum = pageSum+books[i];
    } else {
      studentCount++;
      if(studentCount > m || books[i] > mid) {
        return false;
      }
      pageSum = books[i];
    } 
  }
  return true;
}

int bookAllcation(vector<int> books, int m) {
  int sum = 0, ans = 0;
  for(int i=0; i<books.size(); i++) {
    sum += books[i];
  }
  int s = 0, e = sum;
  while(s<=e) {
    int mid = s+(e-s)/2;
    if(isPossible(books, m, mid)) {
      ans = mid;
      e = mid-1;
    } else {
      s = mid+1;
    }
  }
  return ans;
}

int main() {
  vector<int> books;
  books.push_back(10);
  books.push_back(20);
  books.push_back(30);
  books.push_back(40);
  books.push_back(50);
  int students = 2;
  int minPage = bookAllcation(books, students);
  cout<<minPage;
  return 0;
}