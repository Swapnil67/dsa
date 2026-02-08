/*
 * Leetcode - 2517
 * Maximum Tastiness of Candy Basket
 * 
 * Example 2    :
 * Input        : price = [13,5,1,8,21,2], k = 3
 * Output       : 8
 * Explanation  : 
 * 
 * Example 1    :
 * Input        : price = [1,3,1], k = 2
 * Output       : 2
 * Explanation  : 
 * 
 * Example 1    :
 * Input        : price = [7,7,7,7], k = 2
 * Output       : 0
 * Explanation  : 
 * 
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int is_valid(vector<int> &price, int min_diff, int &k) {
  int n = price.size();
  int prev = price[0];
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (price[i] - prev >= min_diff) {
      cnt++;
      prev = price[i];
    }
  }

  if (cnt >= k)
    return true;

  return false;
}

int maximumTastiness(vector<int> &price, int k)
{
  int n = price.size();
  sort(begin(price), end(price));
  int l = 0, r = price[n - 1] - price[0];

  int ans = 0;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (is_valid(price, m, k)) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  return ans;
}

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

