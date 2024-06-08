/*
* Allocate Books
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
