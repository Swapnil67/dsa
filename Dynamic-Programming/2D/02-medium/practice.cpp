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

// * 24 - Print Longest Common Subsequence
// string findLCS(string &s, string &t) {
// TODO
// }

// * 25 - Longest Common Substring
// string longCommSubstr(string &s, string &t) {
// TODO
// }

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
