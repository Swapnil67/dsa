/*
 * Gray Code
 * 
 * https://cses.fi/problemset/task/1755
*/

#include <vector>
#include <iostream>
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

vector<string> grayCode(int n) {
  if (n == 1)
    return {"0", "1"};
  
  vector<string> a = grayCode(n - 1);
  vector<string> b = a;
  reverse(begin(b), end(b));
  for (auto &s: a) {
    s += '0';
  }
  for (auto &s : b) {
    s += '1';
  }

  // printArr(a); printArr(b);
  a.insert(a.end(), begin(b), end(b));
  return a;
}

// * TIME COMPLEXITY O(n * 2^n)
// * SPACE COMPLEXITY O(n)
int main() {
  int n;
  cin >> n;
  vector<string> ans = grayCode(n);
  for (auto &gc : ans)
    cout << gc << "\n";
  return 0;
}

// * Run the code
// * g++ --std=c++20 13-gray-code.cpp -o output && ./output

/*
Input:
2

Output:
00
01
11
10
*/
