/*
* Allocate Books
* There are ‘m’ number of students, and the task is to allocate all the books to the students.

* Allocate books in such a way that:

* 1. Each student gets at least one book.
* 2. Each book should be allocated to only one student.
* 3. Book allocation should be in a contiguous manner.

* You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.


* Example 1:
* Input: books = [12, 34, 67, 90], s = 2
* Output: 113

* Example 2:
* Input: books = [25 46 28 49 24], h = 4
* Output: 71

* Example 3:
* Input: books = [25 46 28 49 24], h = 6
* Output: -1

* https://www.codingninjas.com/studio/problems/allocate-books_1090540 
*/

#include <iostream>
using namespace std;

// * ------------------------- Utility Functions -------------------------`

int findMax(vector<int> &books) {
  int max_page = INT_MIN;
  for (int i = 0; i < books.size(); i++)
  {
    max_page = max(max_page, books[i]);
  }
  return max_page;
}

int findSumOfVector(vector<int> &books) {
  int sum = 0;
  for (int i = 0; i < books.size(); i++)
  {
    sum += books[i];
  }
  return sum;
}

bool assignBooks(vector<int> &books, int students, int max_page) {
  int assignedCount = 1, assignedPages = books[0];
  for (int i = 1; i < books.size(); i++) {
    // cout<<"assignedPages "<<assignedPages<<endl;
    if (assignedPages + books[i] <= max_page) {
      assignedPages += books[i];
    } else {
      assignedCount++;
      assignedPages = books[i];
    }
  }
  // cout<<"assignedCount "<<assignedCount<<endl;
  if (assignedCount <= students) {
    return true;
  }
  else {
    return false;
  }
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(max-sum) * O(N) = O(N^2) 
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int>&books, int students) {

  if(books.size() < students) {
    return -1;
  }

  int max_page = findMax(books);
  int total_pages = findSumOfVector(books);
  // cout << "max_page: " << max_page << endl;
  // cout << "total_pages: " << total_pages << endl;

  int ans = total_pages;
  // *  O(max-sum)
  while (max_page <= total_pages) {
    // * O(N)
    if (assignBooks(books, students, max_page) == true) {
      // cout<<"max_page "<<max_page<<endl;
      ans = max_page;
      break;
    }
    else {
      // cout<<"Cannot Allocate "<<max_page<<endl;
      max_page++;
    }
  }
  return max_page;
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(max-sum) * O(N) = O(N^2) 
// * SPACE COMPLEXITY O(1)
int optimalApproach(vector<int>&books, int students) {
  if(books.size() < students) {
    return -1;
  }

  int max_page = findMax(books);
  int total_pages = findSumOfVector(books);

  int ans = total_pages;
  int low = max_page, high = total_pages;
  // *  logn(max-sum)
  while(low <= high) {
    int mid = low + (high - low)/2;
    // cout<<"low "<<low<<" high "<<high<<endl;
    // cout<<"mid "<<mid<<endl;
    // * O(N)
    if (assignBooks(books, students, mid) == true) {
      // cout<<"Allocated "<<mid<<endl;
      high = mid-1;
    } 
    else {
      low = mid+1;
    }
  }
  return low;
}

int main() {

  vector<int> books = {10, 20, 30, 40};
  int students = 2;

  // vector<int> books = { 25, 46, 28, 49, 24 };
  // int students = 4;

  // int max_page = bruteForce(books, students);
  int max_page = optimalApproach(books, students);
  cout << "Maximum Pages: " << max_page << endl;

  return 0;
}
