/*
 * Find Triplets
 * 
 * Given an array of size “N”; find the number of triplets, such that 
 * - A[i] > A[j] < A[k] 
 * - i < j < k 
 * 
 * Follow up 
 * - A[i] > A[j] < A[k] > A[l]
 * - i < j < k < l
 *
 * Example 1    :
 * Input        : nums = [8, 1, 2, 3, 4, 5]
 * Output       : 10
 *
 * Example 2    :
 * Input        : nums = [10, 8, 5, 8, 4, 3, 2, 1]
 * Output       : 2  -> [(10, 5, 8), (8, 5, 8)]
 * 
 * https://docs.google.com/document/d/1LthiOPD4CvHTu9d0_h_XKJF9U9BYdjYYetnjjAPQLpo/edit?tab=t.0
 * https://drive.google.com/file/d/1P5NclN3LIzFjeglP7IN-trsg86Bskr7G/view
*/

// ! OA

// ! Google

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))

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

// * TIME COMPLEXITY O(N^3)
// * SPACE COMPLEXITY O(1)
int bruteForce(vi a) {
  int n = a.size();
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (a[i] > a[j] && a[j] < a[k]) {
          count += 1;
        }
      }
    }
  }
  return count;
}

// ! A[i] > A[j] < A[k] 
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int optimal(vi a) {
  int n = a.size();
  
  // * Create a prefix array for a[i] > a[j] for every 'j'
  VEC(p, n, int);
  for (int j = 1; j < n; ++j) {
    int c = 0;
    for (int i = 0; i < j; ++i) {
      if (a[i] > a[j]) c++;
    }
    p[j] = c;
  }
  // printArr(p);

  // * Create a suffix array for a[j] < a[k] for every 'j'
  VEC(s, n + 1, int);
  s[n] = 0;
  for (int j = n - 1; j >= 0; --j) {
    int c = 0;
    for (int k = j + 1; k < n; ++k) {
      if (a[j] < a[k])
        c++;
    }
    s[j] = c;
  }
  // printArr(s);

  int triplets = 0;
  for (int j = 0; j < n; ++j) {
    triplets = triplets + p[j] * s[j];
  }
  return triplets;
}

// ! A[i] > A[j] < A[k] > A[l]
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int optimal2(vi a) {
  int n = a.size();
  
  // * Create a prefix array for a[i] > a[j] for every 'j'
  VEC(p, n, int);
  for (int j = 1; j < n; ++j) {
    int c = 0;
    for (int i = 0; i < j; ++i) {
      if (a[i] > a[j]) c++;
    }
    p[j] = c;
  }
  // printArr(p);

  // * Create a suffix array for a[k] > a[l] for every 'j'
  VEC(s, n + 1, int);
  s[n] = 0;
  for (int k = n - 1; k >= 0; --k) {
    int c = 0;
    for (int l = k + 1; l < n; ++l) {
      if (a[k] > a[l])
        c++;
    }
    s[k] = c;
  }
  // printArr(s);

  // * Fix 'j' and 'k' 
  int quadruplets = 0;
  for (int j = 1; j < n; ++j) {
    for (int k = j + 1; k < n; ++k) {
      if (a[j] < a[k]) {
        quadruplets = quadruplets + p[j] * s[k];
      }
    }
  }
  return quadruplets;
}

int main(void) {
  // * testcase 1
  // vi nums = {8, 1, 2, 3, 4, 5};

  // * testcase 2
  vi nums = {10, 8, 5, 8, 4, 3, 2, 1};

  cout << "nums: ";
  printArr(nums);
  
  // int ans = bruteForce(nums);
  int ans = optimal(nums);
  cout << "Valid Triplets: " << ans << "\n";

  // * testcase 1
  // vi nums2 = {1, 5, 2, 11, 5};

  // * testcase 2
  vi nums2 = {5, 2, 6, 3, 7, 4};

  // * testcase 3
  // vi nums2 = {4, 3, 2, 1 };

  ans = optimal2(nums2);

  cout << "nums: ";
  printArr(nums2);
  cout << "Valid Quadruplets: " << ans << "\n";
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 15-find-triplets-google-oa.cpp -o output && ./output
