/*
 * D. Stas and the Queue at the Buffet
 * 
 * 
 * Example 1    :
 * Input        : students = {{4, 2}, {2, 3}, {6, 1}};
 * Output       : 12
 * 
 * Example 2    :
 * Input        : students = {{2, 4}, {3, 3}, {7, 1}, {2, 3}}
 * Output       : 25
 *
 * https://codeforces.com/contest/1151/problem/D
 * https://drive.google.com/file/d/1WGZ1_QyhTFS4qHYD9PurOmlpzz7WCTKv/view
 * https://docs.google.com/document/d/1h-3UTy-lnT1wtBLn_YU6WVzgpSuitS2Gh12_lvZOCNE/edit?tab=t.0
*/

// ! Codeforces
// ! Greedy Exchange Argument Lemma

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}


// ! Math Intuition
// * a(j - 1) + b(n - j)
// * a*j - a + b*n - b*j
// * a*j - b*j + b*n - a
// * j(a - b) + b*n - a

// * j*(a - b) -> variable
// * b*n - a  -> constant

// * Greedy
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int solve(vector<pair<int, int>> students) {
  int n = students.size();

  vector<int> constant; // * vector of (b*n - a)
  vector<int> A;        // * vector of (a - b)
  vector<int> B;        // * vector of student position
  for (int i = 0; i < n; ++i) {
    int a = students[i].first, b = students[i].second;
    constant.push_back((b * n) - a);
    A.push_back(a - b);
    B.push_back(i + 1);
  }

  // printArr(A);
  // printArr(B);
  // printArr(constant);

  // * This trick is used to find the min sum of product of all elements of two arrays
  // * This will always return min sum.
  sort(begin(A), end(A));
  sort(rbegin(B), rend(B));

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += ((A[i] * B[i]) + constant[i]);
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // vector<pair<int, int>> students = {{4, 2}, {2, 3}, {6, 1}};

  // * testcase 2
  vector<pair<int, int>> students = {{2, 4}, {3, 3}, {7, 1}, {2, 3}};
  
  // * testcase 3
  // vector<pair<int, int>> students = {{5, 10}, {12, 4}, {31, 45}, {20, 55}, {30, 17}, {29, 30}, {41, 32}, {7, 1}, {5, 5}, {3, 15}};

  int ans = solve(students);
  cout << "minimum total dissatisfaction: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-min-sum-of-products.cpp -o output && ./output
