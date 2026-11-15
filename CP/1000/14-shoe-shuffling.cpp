/*
 * B. Shoe Shuffling
 * 
 * There are n students in a class. You are given an array s sorted in 
 * non-decreasing order, where s[i] represents the shoe size of the i-th student.
 * 
 * A shuffling of shoes is valid if and only if:
 * 1. No student gets their own shoes back (p[i] != i).
 * 2. Every student gets shoes of a size greater than or equal to their own 
 *    original shoe size (s[p[i]] >= s[i]).
 * 
 * Find any valid permutation p of the numbers {1, 2, ..., n} representing the indices 
 * of the shoes assigned to each student. If no valid shuffling exists, return -1.
 * 
 * Constraints:
 * - 1 <= t <= 1000 (Number of test cases)
 * - 1 <= n <= 10^5 (Number of students per test case)
 * - 1 <= s[i] <= 10^9 (Shoe size of the i-th student)
 * - The elements of array s are sorted in non-decreasing order.
 * - The sum of n over all test cases does not exceed 10^5.
 * 
 * Example 1    :
 * Input        : nums = [1, 1, 1, 1, 1]
 * Output       : [5, 1, 2, 3, 4]
 * Explanation  : All students have the same shoe size. By assigning student 1 the shoes of 
 *                student 5, student 2 the shoes of student 1, and so on, no student receives 
 *                their own shoes, yet everyone gets an equal shoe size.
 * 
 * Example 2    :
 * Input        : nums = [3, 6, 8, 13, 15, 21]
 * Output       : -1
 * Explanation  : Every student has a unique shoe size. Since the elements are strictly increasing, 
 *                it can be shown that no valid shuffling is possible without violating the conditions.
 *
 * https://codeforces.com/problemset/problem/1691/B
*/

// ! Observations
/*
* If any size is unique, output −1. Otherwise, rotate indices within equal-size groups to ensure no student 
* keeps their shoes.

* Eg 1:
* s = [1 2 5 7 10]
* Above sizes we'll return -1 since we don't have anyone to shuffle with shoe with size 10.

* Eg 2:
* s = [1 1 2 2 2 5 5 7 7 7 10 10 10 10]
* Here [1, 1] will shuffle shoes with each other
* Here [2, 2] will shuffle shoes with each other
* Similarly [5, 5], [7, 7, 7] & [10, 10, 10, 10] will shuffle shoes with each other
*
* P = [1 2 3 4 5 6 7 8 9 10 11 12 13 14]
* s = [1 1 2 2 2 5 5 7 7 7 10 10 10 10]
* P = [2 1 4 5 3 7 6 9 10 8 12 13 14 11]
* 
* [1 2] => rotate left [2 1]
* [3 4 5] => rotate left [4 5 3]
* [6 7] => rotate left [7 6]
* [8 9 10] => rotate left [9 10 8]
* [10 10 10 10] => rotate left [12 13 14 11]
* 
*/

#include <map>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

using namespace std;
typedef long long ll;
typedef vector<int> vi;

// Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]


vector<ll> solve(void) {
  ll n;
  cin >> n;
  
  VEC(sizes, n, ll); READ_VEC(sizes);
  
  // * Map to store frequency of each shoe size
  map<ll, ll> freq_mp;
  for (auto &x: sizes) freq_mp[x]++;
  // * If any shoe size appears only once, shuffling is not possible
  for (auto &it: freq_mp) {
    if (it.second == 1)
      return {-1};
  }
  
  VEC(students, n, ll); // * Vector to store the permutation of students
  iota(all(students), 1); // * 0....n
  
  ll l = 0, r = 0;
  while (r < n) {
    if (sizes[l] == sizes[r]) {
      r++;
    } else {
			// * Rotate the segment of students to ensure no student gets their own shoes
      rotate(students.begin() + l, students.begin() + l + 1, students.begin() + r);
      l = r;
    }
  }
  // * Rotate the last segment
  rotate(students.begin() + l, students.begin() + l + 1, students.begin() + r);
  
  return students;
}

// ! Greedy with Two Pointers
// * Time Complexity (TC): O(nlogn) = O(10^5*log2(10^5)) = O(10^5*17) = O(10^6)
// * Space Complexity (SC): O(n) = O(10^5)
int main(void) {
  ll t;
  cin >> t;
  
  while (t--) {
    vector<ll> students = solve();
    for (auto &s: students) 
      cout << s << " ";
    cout << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 13-luke-is-a-foodie.cpp -o output && ./output

// * testcases
/*
2
5
1 1 1 1 1
6
3 6 8 13 15 21

*/

// * Output
/*
5 1 2 3 4 
-1
*/