// * coordinate compression
/*
* Also known as discretization, is a technique used in computer science to map large, 
* sparse data ranges into a smaller, continuous range while strictly preserving their relative order
*/

// ! Important Points
// * It's a space reduction technique.
// * Ask = Do I really need the entire space.
// * Use when indexes range is huge but the no. of distinct indexes is small.

#include <iostream>
#include <vector>
#include <algorithm>

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
  cout << " ]" << "\n";
}

int main() {
  vector<int> a = {1005, 99999999, 99999999, 42, 42, 500000};
  cout << "Before compression: ";
  printArr(a);

  // * 1. Create a copy and sort it
  vector<int> vals = a;
  sort(vals.begin(), vals.end());

  // * 2. Remove duplicates
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  // vals.resize(unique(vals.begin(), vals.end()) - vals.begin()); // * OR

  // * 3. Transform the original array using binary search
  vector<int> compressed(a.size());
  for (size_t i = 0; i < a.size(); ++i) {
    compressed[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
  }

  // * Output: 1 3 0 0 2
  cout << "After compression: ";
  printArr(compressed);

  return 0;
}

// * Run the code
// * g++ --std=c++20 coordinate-compression.cpp -o output && ./output
