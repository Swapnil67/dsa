/*
 * Print all Divisors of a number
 * Given an integer ‘N’, your task is to write a program that returns all the divisors of ‘N’ in ascending order.
 * 
 * Example 1:
 * Input: n = 10
 * Output: 1 2 5 10
 * 
 * Example 2:
 * Input: n = 6
 * Output: 1 2 3 5

 * https://www.naukri.com/code360/problems/print-all-divisors-of-a-number_1164188
*/

#include<iostream>
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

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
vector<int> bruteForce(int n) {
  vector<int> factors;
  for (int i = 1; i <= 12; ++i) {
    if (n % i == 0)
      factors.push_back(i);
  }
  return factors;
}

// * TIME COMPLEXITY O(sqrt(N))
// * SPACE COMPLEXITY O(1)
vector<int> printDivisors(int n) {
  vector<int> factors;
  for (int i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      factors.push_back(i);
      if (n / i != i) {
        factors.push_back(n / i);
      }
    }
  }
  return factors;
} 

int main() {
  // int n = 10;
  int n = 36;

  // std::vector<int> ans = bruteForce(n);
  std::vector<int> ans = printDivisors(n);
  printArr(ans);
  return 0;
}

// * run the code
// * g++ --std=c++17 04-all-divisors.cpp -o output && ./output