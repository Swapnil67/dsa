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

// * 00 - Fibonacci Number
// int get_fib(int num, vector<int> &dp) {
// TODO
// }

// * 01 - Climbing Stairs
// int get_fib(int num, vector<int> &dp) {
// TODO
// }

// * 02 - Climbing Stairs
// int get_fib(int num, vector<int> &dp) {
// TODO
// }

// * 03 - N-th Tribonacci Number
// int get_fib(int num, vector<int> &dp) {
// TODO
// }

// * 04 - Best Time to Buy and Sell Stock - i
// int maxProfit(std::vector<int>& prices) {
// TODO
// }

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
