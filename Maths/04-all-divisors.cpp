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

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(int n) {
  std::vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if(n % i == 0) {
      ans.push_back(i);
    }
  }
  return ans;
} 

// * TIME COMPLEXITY O(SQRT(N))
// * SPACE COMPLEXITY O(1)
std::vector<int> printDivisors(int n) {
  std::vector<int> ans;
  for (int i = 1; i <= std::sqrt(n); ++i) {
    if(n % i == 0) {
      ans.push_back(i);
      if (n / i != i)
        ans.push_back(n / i);
    }
  }
  return ans;
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