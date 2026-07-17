/*
* Allocate Books
* Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
* There are ‘m’ number of students, and the task is to allocate all the books to the students.

* Allocate books in such a way that:

* 1. Each student gets at least one book.
* 2. Each book should be allocated to only one student.
* 3. Book allocation should be in a contiguous manner.

* You have to allocate the book to ‘s’ students such that the maximum number of pages assigned to a student is minimum.

* Example 1:
* Input: books = [12, 34, 67, 90], s = 2
* Output: 113

* Example 2:
* Input: books = [25 46 28 49 24], s = 4
* Output: 71

* Example 3:
* Input: books = [25 46 28 49 24], s = 6
* Output: -1

* https://www.naukri.com/code360/problems/allocate-books_1090540
*/

// ! Binary Search on Min/Max

#include <iostream>
#include <numeric>

using namespace std;

template <typename T>
void printArr(vector<T> &nums) {
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}


// * ------------------------- Utility Functions -------------------------`

void printArr(vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// * Returns the students assigned for given pages
int findStudentsAssigned(vector<int> books, int pages) {
  // * Start with first student and books[0] pages
  int assignedStudents = 1, assignedPages = books[0];
  for (int i = 1; i < books.size(); i++) {
    if(assignedPages + books[i] <= pages) {
      assignedPages += books[i];
    }
    else {
      // * Start assigning to next students
      assignedStudents++;
      assignedPages = books[i];
    }
  }
  return assignedStudents;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(sum - max+1) * O(N) 
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> books, int s) {
  if(s > books.size()) return -1;
  int maxPages = *max_element(books.begin(), books.end());
  int totalPages = accumulate(books.begin(), books.end(), 0); 
  int ans = -1;
  // * O(sum - max+1)
  for(int i=maxPages; i<=totalPages; i++) {
    int pages = i;
    // * O(N) 
    int studentsAssigned = findStudentsAssigned(books, pages);
    if(studentsAssigned == s) {
      ans = pages;
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(log(total - max)) * O(N) 
// * SPACE COMPLEXITY O(1)
int findMaxPagesAssigned(vector<int> books, int s) {
  if(s > books.size()) return -1;
  int l = *max_element(books.begin(), books.end());
  int r = accumulate(books.begin(), books.end(), 0); 
  while(l <= r) {
    int mid = l + (r - l) / 2;
    int studentsAssigned = findStudentsAssigned(books, mid);
    // cout << "pages " << mid << " students assigned " << studentsAssigned << endl;
    if(studentsAssigned <= s) {
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  return l;
}

int main() {
  // * testcase 1
  // int s = 2;
  // vector<int> books = {12, 34, 67, 90};

  // * testcase 2
  int s = 4; 
  vector<int> books = {25, 46, 28, 49, 24};
  
  printArr(books);
  // int maxPagesAssigned = bruteForce(books, s);
  int maxPagesAssigned = findMaxPagesAssigned(books, s);
  cout << "maximum number of pages assigned to a student " << maxPagesAssigned << endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 07-book-allocation.cpp -o 07-book-allocation && ./07-book-allocation
