#include<iostream>

// * TIME COMPLEXITY O(SQRT(N))
// * SPACE COMPLEXITY O(1)
bool isPrime(int n) {
  for (int i = 2; i <= std::sqrt(n); ++i) {
    if (i != n && n % i == 0)
      return false;
  }
  return true;
}

// * TIME COMPLEXITY O(N) * O(SQRT(N)) 
// * SPACE COMPLEXITY O(1)
void primeNumbers(int n) {
  int i = 1, p = 1;
  while(true) {
    if(isPrime(i)) {
      std::cout << i << " ";
      p++;
    }
    i++;
    if(p == n) 
      break;
  }
  std::cout << std::endl;
}

int main() {
  primeNumbers(10);
  return 0;
}

// * run the code
// * g++ --std=c++17 01-find-prime.cpp -o output && ./output