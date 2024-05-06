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
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N) + O(d)
// * SPACE COMPLEXITY O(d)
void bruteForce(std::vector<int> &arr, int k) {
  int n = arr.size();
  int d = n % k; // * Number of rotations

  // * Make a temp array of k elements
  // * O(d)
  std::vector<int> temp;
  for(int i=0; i<=d; i++) {
    temp.push_back(arr[i]);
  }

  // * From d index shift the elements
  // * O(n-d)
  for(int i=d; i<n; i++) {
    arr[i-k] = arr[i];
  }

  // * Now put the temp elements back to array
  // * O(d)
  for(int i=n-k; i<n; i++) {
    arr[i] = temp[i-(n-k)];
  }
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void reverse(std::vector<int> &arr, int low, int high) {
  int l = low, r = high;
  // std::cout<<"Low "<<l<<" High "<<r<<std::endl; 
  while(l < r) {
    swap(arr[l++], arr[r--]);
  }
}

void optimal(std::vector<int> &arr, int k) {
  int n = arr.size(); // * size of array
  int d = n % k; // * Number of rotations

  // * Reverse from 0 - d
  reverse(arr, 0, d);

  // * Reverse from d+1 - n
  reverse(arr, d+1, n-1);

  // * Reverse the complete arr
  reverse(arr, 0, n-1);
}

int main() {
  // int k = 2;
  // std::vector<int> arr = { 1,2,3,4,5 };
  int k = 3;
  std::vector<int> arr = { 1,2,3,4,5 };
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