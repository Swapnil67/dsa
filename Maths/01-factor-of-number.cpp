/*
 * Find factors of a number
 * 
 * 
 * Example 1    :
 * Input        : n = 12
 * Output       : [ 1, 2, 3, 4, 6, 12 ]
 * 
 * Example 2    :
 * Input        : n = 50
 * Output       : [ 1, 2, 5, 10 ]
 * 
 * https://drive.google.com/file/d/1ginV-ZWVf-iE_KBSRWeWaoMhnER0hTq0/view
 * https://docs.google.com/document/d/15ZFZuxIGZgwbrT9NeBfUT00c-6KMjpuN-M7JRl8HFVI/edit?tab=t.0
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

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
vector<ll> bruteForce(int n) {
  vector<ll> factors;
  for (int i = 1; i <= 12; ++i) {
    if (n % i == 0)
      factors.push_back(i);
  }
  return factors;
}

// * TIME COMPLEXITY O(sqrt(N))
// * SPACE COMPLEXITY O(1)
vector<ll> findFactors(int n) {
  vector<ll> factors;
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

int main(void) {
  // int n = 12;
  int n = 50;

  vector<ll> factors = bruteForce(n);
  // vector<ll> factors = findFactors(n);

  cout << "Factors of " << n << endl;
  printArr(factors);
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-factor-of-number.cpp -o output && ./output
