/**
 * * Leetcode - 189
 * * Rotate array by K places
 * * Given an array 'arr' with 'n' elements, the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.

 * * Example 1
 * * Input  : 'k' = 1, 'arr '= [1,2,3,4,5]
 * * Output : [2, 3, 4, 5, 1]
 * 
 * * Example 2
 * * Input  : 'k' = 3, 'arr '= [1,2,3,4,5]
 * * Output : [3, 4, 5, 1, 2]

 * * Example 3
 * * Input  : 'k' = 3, 'arr '= [1,2,3,4,5]
 * * Output : [4, 5, 1, 2, 3]

 * * https://leetcode.com/problems/rotate-array/
 * * https://www.naukri.com/code360/problems/rotate-array_1230543
*/

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N) + O(d)
// * SPACE COMPLEXITY O(d)
void bruteForce(std::vector<int> &arr, int k) {
  int n = arr.size();
  k = k % n; // * Number of rotations

  // * 360 rotations results in same array
  if (k > n || k == 0)
    return;

  // * Make a temp array of elements after n - k to n
  // * O(n - k)
  std::vector<int> temp(k);
  for (int i = n - k; i < n; i++) {
    temp[i - (n - k)] = arr[i];
  }

  // * Now shift first k elements to right by k steps
  // * O(n - k - 1)
  for (int i = n - k - 1; i >= 0; --i) {
    arr[i + k] = arr[i];
  }

  // * Now put the temp elements back to array
  // * O(k)
  for (int i = 0; i < k; ++i) {
    arr[i] = temp[i];
  }
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`

void reverse(std::vector<int> &arr, int low, int high) {
  int l = low, r = high;
  while (l < r) {
    swap(arr[l++], arr[r--]);
  }
}

void rotate(std::vector<int> &arr, int k) {
  int n = arr.size(); // * size of array
  k = k % n;      // * Number of rotations

  // * Reverse the complete arr
  reverse(arr, 0, n - 1);

  // * Reverse from 0 to k
  reverse(arr, 0, k - 1);

  // * Reverse from k to n
  reverse(arr, k, n - 1);

}

int main() {
  // * testcase 1
  int k = 4;
  std::vector<int> arr = {1, 2, 3, 4, 5};

  // * testcase 2
  // int k = 3;
  // std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

  std::cout << "Before Rotation" << std::endl;
  printArr(arr);

  bruteForce(arr, k);
  // rotate(arr, k);
  
  std::cout << "After Rotation" << std::endl;
  printArr(arr);
  return 0;
}

// * Run the code
// * g++ --std=c++17 13-rotate-array-by-k-places.cpp -o output && ./output