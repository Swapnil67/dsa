/*
* Reverse Number

* https://www.naukri.com/code360/problems/reverse-of-a-number_624652
*/

#include<iostream>

// * TIME COMPLEXITY O(Log10(N))
// * SPACE COMPLEXITY O(1)
int reverse(int n) {
  int rev = 0;
  while(n > 0) {
    int last = n % 10;
    n = n / 10;
    rev = (rev * 10) + last;
  }
  return rev;
}

int main() {
  int n = 67;
  std::cout << "Input Number: " << n << std::endl;
  int c = reverse(n);
  std::cout << "Reverse Number: " << c << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 02-reverse.cpp -o output && ./output
