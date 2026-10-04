/*
* Count digits

* https://www.naukri.com/code360/problems/number-of-digits_9173
*/

#include<iostream>

// * TIME COMPLEXITY O(Log10(N))
// * SPACE COMPLEXITY O(1)
int approach1(int n) {
  int c = 0;
  while(n > 0) {
    n = n / 10;
    c++;
  }
  return c;
}

int approach2(int n) {
  return (int)std::log10(n) + 1;
}

int main() {
  int n = 10;
  int c = approach1(n);
  // int c = approach2(n);
  std::cout << "Number of digits are " << c << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 00-count-digits.cpp -o output && ./output
