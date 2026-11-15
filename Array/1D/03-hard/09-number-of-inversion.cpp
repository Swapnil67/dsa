/*
 * Number of Inversions 
 * 
 * Number of inversions in an array can be defined as the number of pairs of 'i', 'j' 
 * such that 'i' < 'j' and A[i] > A[j]
 * 
 * Example 1:
 * Input: nums = [5, 3, 2, 1, 4]
 * Output: 7
 * Explanation: Number of inversions (5, 3), (5, 2), (5, 1), (5, 4), (3, 2), (3, 1), (2, 1)
 * 
 * https://www.naukri.com/code360/problems/number-of-inversions_6840276
 * https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
 * https://codeforces.com/gym/101853/problem/C
*/

// ! Flipkart, Amazon, Microsoft, Adobe

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
  cout << " ]" << "\n";
}

// * Merge Arrays In sorted way & count pairs
int merge(int low, int mid, int high, vector<int> &arr) {
  vector<int> temp;
  int i = low, j = mid + 1, cnt = 0;
  while (i <= mid && j <= high) {
    if (arr[i] >= arr[j]) {
      // * Count the pairs
      cnt = cnt + (mid - i + 1);
      temp.push_back(arr[j++]);
    }
    else {
      temp.push_back(arr[i++]);
    }
  }

  while (i <= mid) temp.push_back(arr[i++]);

  while (j <= high) temp.push_back(arr[j++]);

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
  return cnt;
}

int mergeSort(int l, int r, vector<int> &arr) {
  int c = 0;
  if (l == r) return c;
  int mid = (l + r) / 2;
  c += mergeSort(l, mid, arr);
  c += mergeSort(mid + 1, r, arr);
  c += merge(l, mid, r, arr);
  return c;
}

// * ------------------------- APPROACH 1: Brute Approach -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> arr) {
  int n = arr.size(), cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        cnt++;
      }
    }
  }
  return cnt;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Merge Sort & Count Pairs
// * TIME COMPLEXITY O(NLogN)
// * SPACE COMPLEXITY O(N)
// * Here we are altering the given input
int numberOfInversions(vector<int> arr) {
  int n = arr.size();
  int c = mergeSort(0, n - 1, arr);
  return c;
}

int main() {
  // vector<int> arr = {3, 2, 1};
  vector<int> arr = {10, 10, 10};
  // vector<int> arr = {5, 4, 3, 2, 1};
  // vector<int> arr = {5, 3, 2, 1, 4};

  cout << "Input arr: ";
  printArr(arr);

  // int inversions = bruteForce(arr);
  int inversions = numberOfInversions(arr);
  cout << "Number of inversions is " << inversions << endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 09-number-of-inversion.cpp -o output && ./output
