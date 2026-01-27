/*
 * 
*/

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
