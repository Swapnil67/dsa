/**
 * * Rotate array by K places
 * * Given an array 'arr' with 'n' elements, the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.

 * * Example 1
 * * Input  : 'k' = 1, 'arr '= [1,2,3,4,5]
 * * Output : [2, 3, 4, 5, 1]
 * 
 * * Example 2
 * * Input  : 'k' = 2, 'arr '= [1,2,3,4,5]
 * * Output : [3, 4, 5, 1, 2]

 * * Example 3
 * * Input  : 'k' = 3, 'arr '= [1,2,3,4,5]
 * * Output : [4, 5, 1, 2, 3]

 * * https://www.naukri.com/code360/problems/rotate-array_1230543
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
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
  int d = k % n; // * Number of rotations

  // * 360 rotations results in same array
  if(d == 0) return;

  // * Make a temp array of k elements
  // * O(d)
  std::vector<int> temp;
  for (int i = 0; i <= d; i++) {
    // std::cout << i << " -> " << arr[i] << std::endl;
    temp.push_back(arr[i]);
  }

  // * From d index shift the elements
  // * O(n - d)
  for (int i = k; i < n; i++) {
    arr[i - k] = arr[i];
  }

  // * Now put the temp elements back to array
  // * O(d)
  for (int i = n - d; i < n; i++) {
    // std::cout << i << " -> " << arr[i] << std::endl;
    // * base = n - d
    arr[i] = temp[i - (n - d)];
    // j++;
  }
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`

void reverse(std::vector<int> &arr, int low, int high) {
  int l = low, r = high;
  // std::cout<<"Low "<<l<<" High "<<r<<std::endl; 
  while(l < r) {
    swap(arr[l++], arr[r--]);
  }
}

void optimal(std::vector<int> &arr, int k) {
  int n = arr.size(); // * size of array
  int d = k % n;      // * Number of rotations

  // * Reverse from 0 to d
  reverse(arr, 0, d - 1);

  // * Reverse from d+1 to n
  reverse(arr, d, n - 1);

  // * Reverse the complete arr
  reverse(arr, 0, n - 1);
}

int main() {
  // * testcase 1
  int k = 4;
  std::vector<int> arr = {1, 2, 3, 4, 5};

  // * testcase 2
  // int k = 1;
  // std::vector<int> arr = {7, 1, 2, 3, 4, 5, 6};
  std::cout<<"Before Rotation"<<std::endl;
  printArr(arr);

  // bruteForce(arr, k);
  optimal(arr, k);
  std::cout<<"After Rotation"<<std::endl;
  printArr(arr);
  return 0;
}

// * Run the code
// * g++ --std=c++17 06-rotate-array-by-k-places.cpp -o 06-rotate-array-by-k-places && ./06-rotate-array-by-k-places