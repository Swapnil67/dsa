/*
 * Interesting Pairs of Numbers
 * 
 * Given an array of size “N” ; find the number of unordered-pairs (i, j) such that:
 * |a[i]-a[j]| + |a[i]+a[j]| = target 
 * 
 * If pair(i,j) is valid, then pair(j,i) is also valid. 
 * Questions is asking to check unordered-pair hence -> you will count both of them as only 1 
 * 
 * Constraints:
 * 
 * Example 1    :
 * Input        : nums = [1,4,-1,2], target = 4
 * Output       : 2
 * Explanation  : pairs (0,3) & (2,3) are valid
 * 
 * Example 2    :
 * Input        : nums = [-6,2,5,-2,-7,-1,3], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 *
 * https://www.desiqna.in/17097/de-shaw-oa-sde-coding-questions-set-69 
 * https://drive.google.com/file/d/1oWhKERO3L0yBC4h6ziLGO-Xq_l3FmqsP/view
*/

// ! OA
// ! DeShaw

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

// Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]
#define INPUT_VEC(type, name, size) \
    vector<type> name(static_cast<size_t>(size)); \
    for(size_t i = 0; i < name.size(); ++i) cin >> name[i]

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

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int bruteForce(vi a, int target) {
  int n = a.size();
  int pairs = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (abs(a[i] - a[j]) + abs(a[i] + a[j]) == target)
        pairs++;
    }
  }
  return pairs;
}

int main(void) {
  int target = 4;
  vi nums = {1, 4, -1, 2};
  cout << "nums: "; 
  printArr(nums);

  int pairs = bruteForce(nums, target);
  cout << "Special Pairs: " << pairs << "\n";

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 12-interesting-pairs-of-numbers-de-shaw-oa.cpp -o output && ./output
