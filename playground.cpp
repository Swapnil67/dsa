#include <iostream>
using namespace std;

int sumOfArray(vector<int>&arr) {
  int arrSum = 0;
  for(int i=0; i<arr.size(); i++) {
    arrSum += arr[i];
  } 
  return arrSum;
}

int maxOfArray(vector<int>&arr) {
  int arrMax = 0;
  for(int i=0; i<arr.size(); i++) {
    arrMax = max(arrMax, arr[i]);
  } 
  return arrMax;
}

bool canAssignPages(vector<int>&books, int students, int maxPages) {
  int pageAssigned = books[0], studentsAssigned = 1;
  for(int i=1; i<=books.size(); i++) {
      // cout<<"pageAssigned "<<pageAssigned<<endl;
    if(pageAssigned + books[i] <= maxPages) {
      pageAssigned += books[i];
    }
    else {
      pageAssigned = books[i];
      studentsAssigned++;
    }
    if(studentsAssigned > students) {
      // cout<<"studentsAssigned "<<studentsAssigned<<endl;
      return false;
    }
  }
  return true;
}

int allocateBook(vector<int>& books, int students) {
  int arrSum = sumOfArray(books);
  int arrMax = maxOfArray(books);
  for(int i=arrMax; i<=arrSum; i++) {
    bool isMinPages = canAssignPages(books, students, i);
    if(isMinPages) {
      return i;
    }
  }
  return -1;
}

int allocateBookOptimal(vector<int>& books, int students) {
  int arrSum = sumOfArray(books);
  int arrMax = maxOfArray(books);
  int low = arrMax, high = arrSum;
  while(low <= high) {
    int mid = low + (high - low) / 2;
    bool isMinPages = canAssignPages(books, students, mid);
    if(isMinPages == 0) {
      low = mid+1;
    }
    else {
      high = mid - 1;
    }
  }
  return low;
}

int main() {
  vector<int> books = { 25, 46, 28, 49, 24 };
  int students = 4;
  int minPages = allocateBookOptimal(books, students);
  cout<<"minPages "<<minPages<<endl;
  return 0;
}