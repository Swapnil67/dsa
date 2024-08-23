#include<iostream>


void sieve_of_eratosthenes(int n) {
  std::vector<bool> is_primes(n + 1, true);
  is_primes[0] = false, is_primes[1] = false;
  for (int i = 2; i < n; ++i) {
    if (is_primes[i] && (long long)i * i <= n) {
      for (int j = i * i; j <= n; j += i) {
        // std::cout << i << " -> " << j << std::endl;
        is_primes[j] = false;
      }
    }
  }

  for (int i = 0; i < is_primes.size(); ++i) {
    if (is_primes[i])
      std::cout << i << " ";
  }
  std::cout << std::endl;
}


int main() {
  int n = 10;
  sieve_of_eratosthenes(n);
  return 0;
}





// * run the code
// * g++ --std=c++17 02-sieve-of-eratosthenes.cpp -o output && ./output