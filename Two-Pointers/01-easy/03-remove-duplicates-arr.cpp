/*
 * Leetcode - 26
 * Remove Duplicates from Sorted Array
 * You are given a sorted integer array 'arr' of size 'n'.
 * You need to remove the duplicates from the array such that each element appears only once.

 * Example 1
 * Input  : ‘n’ = 5, ‘a’ = [1 2 2 2 3].
 * Output : [1 2 3]
 * 
 * Example 2
 * Input  : ‘n’ = 10, ‘a’ = [1 2 2 3 3 3 4 4 5 5]
 * Output : [1 2 3 4 5]

 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 * https://www.naukri.com/code360/problems/remove-duplicates-from-sorted-array_1102307
*/

// ! Amazon, Meta, Google, MIcrosoft, Apple, Uber

#include <set>
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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Set Data Structure
// * TIME COMPLEXITY O(NLogN) + O(N)
// * SPACE COMPLEXITY O(N)
int bruteForce(vector<int> arr) {
  set<int> st;
  int n = arr.size();
  // * O(N)
  for (int i = 0; i < n; i++) {
    // * logN
    st.insert(arr[i]);
  }

  int idx = 0;
  // * O(N)
  for (int x: st) {
    arr[idx++] = x;
  }

  return idx;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int removeDuplicates(vector<int> arr) {
  int n = arr.size();
  int i = 0, j = 1;
  while (j < n) {
    if (arr[j] != arr[i]) {
      arr[i + 1] = arr[j];
      i++;
    }
    j++;
  }
  return i + 1;
}

int main() {
  vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 5, 5};
  cout << "Input Vector " << endl;
  printArr(arr);
  // int uniqueElements = bruteForce(arr);
  int uniqueElements = removeDuplicates(arr);
  cout << "Unique Elements " << uniqueElements << endl;
}


// * Run the code
// * g++ --std=c++17 03-remove-duplicates-arr.cpp -o output && ./output
