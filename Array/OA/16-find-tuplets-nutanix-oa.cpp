/*
 * Find Tuplets
 * 
 * A,B,C,D,E  all of size “N” 
 * 
 * Find the number of tuplets (i,j,k,l,m) such that 
 * - a[i] + b[j] + c[k] + d[l] + e[m] = 0

 * 
 * Constraints:
 * Element in the array can range from [-10^9……….10^9]
 * 
 * https://docs.google.com/document/d/1kBBhraTmmds4ntp3qr7DXcDETn0YGSSIrrpz5nmIN4E/edit?tab=t.0 
 * https://drive.google.com/file/d/1TybYcv8dO3oY_-3jhDJtOPqZdBVKojiH/view
*/

// ! OA
// ! nutanix

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

// Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

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

// * TIME COMPLEXITY O(N^5)
// * SPACE COMPLEXITY O(1)
int bruteForce(vi A, vi B, vi C, vi D, vi E) {
  int n = A.size();

  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          for (int m = 0; m < n; m++) {
            if (A[i] + B[j] + C[k] + D[l] + E[m] == 0) {
              cout << A[i] << " " << B[j] << " " << C[k] << " " << D[l] << " " << E[m] << "\n";
              count += 1;
            }
          }
        }
      }
    }
  }

  return count;
}

// ! Hashmap
// * TIME COMPLEXITY O(N^4)
// * SPACE COMPLEXITY O(N)
// * A[i] + B[j] + C[k] + D[l] + E[m] = 0
// * E[m] = -(A[i] + B[j] + C[k] + D[l])
int betterApproach(vi A, vi B, vi C, vi D, vi E) {
  int n = A.size();

  // * Store the frequency of each element of 'E' vector
  unordered_map<int, int> e_freq;
  for (auto &x : E)
    e_freq[x]++;
  
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          int check = -(A[i] + B[j] + C[k] + D[l]);
          if (e_freq.count(check)) {
            count += e_freq[check];
            cout << A[i] << " " << B[j] << " " << C[k] << " " << D[l] << " " << check << "\n";
            count += 1;
          }
        }
      }
    }
  }

  return count;
}

// ! Meet in the middle
// * TIME COMPLEXITY O(N^3)
// * SPACE COMPLEXITY O(N)
// * A[i] + B[j] + C[k] + x + y = 0
// * x + y = -(A[i] + B[j] + C[k])
int optimalApproach(vi A, vi B, vi C, vi D, vi E) {
  int n = A.size();
  // * Sum of all elements from D & E vector i.e., {sum, freq}
  unordered_map<int, int> sum_freq;
  for (int l = 0; l < n; ++l) {
    for (int m = 0; m < n; ++m) {
      sum_freq[D[l] + E[m]]++;
    }
  }
  
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        int check = -(A[i] + B[j] + C[k]);
        if (sum_freq.count(check))
          count += sum_freq[check];
      }
    }
  }

  return count;
}

int main(void) {
  vi A = {2, 5};
  vi B = {3, 8};
  vi C = {-5, 8};
  vi D = {5, 10};
  vi E = {-10, 100};

  cout << "A: ";
  printArr(A);
  cout << "B: ";
  printArr(B);
  cout << "C: ";
  printArr(C);
  cout << "D: ";
  printArr(D);
  cout << "E: ";
  printArr(E);

  // int ans = bruteForce(A, B, C, D, E);
  // int ans = betterApproach(A, B, C, D, E);
  int ans = optimalApproach(A, B, C, D, E);

  cout << ans << "\n";

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 16-find-tuplets-nutanix-oa.cpp.cpp -o output && ./output

// * testcase 
/*

*/