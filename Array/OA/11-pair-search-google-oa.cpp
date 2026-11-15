/*
 * Pair Search
 * 
 * You are given an array A of N integers. You have to find the number of special pairs in array A.
 * A pair of two indexes i and j are called special if the following 2 conditions are satisfied.
 *  - i < j
 *  - A[A[A[i]]] = A[A[A[j]]]
 * 
 * Find out the number of special pairs present in array A. 
 * 
 * Constraints:
 * 1 <= N <= 10^5
 * 1 <= A[i] <= N
 * 
 * Example 1    :
 * Input        : nums = [4,2,1,2]
 * Output       : 6
 * Explanation  : (1, 2), (1, 3), (1, 4), (2, 3), (2, 4) and (3, 4) are special pairs.
 * 
 * https://www.desiqna.in/13820/google-oa-sde2-jan-2023
 * https://drive.google.com/file/d/1u5GeKNKo-96xkprqOMD_lIFXLcIjpp74/view
*/

// ! OA

// ! Google

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

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
// * SPACE COMPLEXITY O(1)
int bruteForce(vi a) {
  a.insert(a.begin(), 0); // * Make array 1-based
  int n = a.size();

  int count = 0; // * count of special pairs
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (a[a[a[i]]] == a[a[a[j]]]) {
        count += 1;
      }
    }
  }
  return count;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int pairSearch(vi a) {
  a.insert(a.begin(), 0); // * Make array 1-based
  int n = a.size();

  int count = 0; // * count of special pairs
  unordered_map<int, int> mp;
  for (int i = 1; i <= n; ++i) {
    int cur = a[a[a[i]]];
    if (mp.count(cur)) {
      count += mp[cur];
    }
    mp[cur]++;
  }

  return count;
}

int main(void) {
  vi nums = {4, 2, 1, 2};
  cout << "nums: ";
  printArr(nums);

  // int pairs = bruteForce(nums);
  int pairs = pairSearch(nums);
  cout << "Special Pairs: " << pairs << "\n";
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 11-pair-search-google-oa.cpp -o output && ./output

