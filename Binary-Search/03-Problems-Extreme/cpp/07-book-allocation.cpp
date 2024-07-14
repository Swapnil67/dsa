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

#include<iostream>

// * ------------------------- Utility Functions -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * Returns the students assigned for given pages
int findStudentsAssigned(std::vector<int> books, int pages) {
  // * Start with first student and zero pages
  int assignedStudents = 1, assignedPages = 0;
  for (int i = 0; i < books.size(); i++) {
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
int bruteForce(std::vector<int> books, int s) {
  if(s > books.size()) return -1;
  int maxPages = *std::max_element(books.begin(), books.end());
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
int findMaxPagesAssigned(std::vector<int> books, int s) {
  if(s > books.size()) return -1;
  int l = *std::max_element(books.begin(), books.end());
  int r = accumulate(books.begin(), books.end(), 0); 
  while(l <= r) {
    int mid = l + (r - l) / 2;
    int studentsAssigned = findStudentsAssigned(books, mid);
    // std::cout << "pages " << mid << " students assigned " << studentsAssigned << std::endl;
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
  // std::vector<int> books = {12, 34, 67, 90};

  // * testcase 2
  int s = 4; 
  std::vector<int> books = {25, 46, 28, 49, 24};
  
  printArr(books);
  // int maxPagesAssigned = bruteForce(books, s);
  int maxPagesAssigned = findMaxPagesAssigned(books, s);
  std::cout << "maximum number of pages assigned to a student " << maxPagesAssigned << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 07-book-allocation.cpp -o 07-book-allocation && ./07-book-allocation
