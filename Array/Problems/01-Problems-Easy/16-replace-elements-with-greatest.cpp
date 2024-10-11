/**
 * * Replace Elements with Greatest Element on Right Side
 * * Given an array arr, replace every element in that array with the greatest element among the elements
 * * to its right, and replace the last element with -1.
 * 
 * * Example 1
 * * Input  : arr = [17,18,5,4,6,1]
 * * Output : [18,6,6,6,1,-1]

 * * https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/description/
*/

#include<iostream>


void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: Burte Force APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
void bruteForce(std::vector<int> &arr) {
  int n = arr.size();
  if(n == 1) {
    arr[0] = -1;
    return;
  }
  for (int i = 0; i < n; i++) {
    if(i == n-1) {
      arr[i] = -1;
      break;
    }
    int greatest = arr[i+1];
    for (int j = i + 1; j < n; j++) {
      greatest = std::max(greatest, arr[j]);
    }
    if(i == n-1) greatest = -1;
    arr[i] = greatest;
  }
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Loop from back
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
void replaceElements(std::vector<int> &arr) {
  int n = arr.size(), maxEle = -1;
  for (int i = n - 1; i >= 0; i--) {
    int newMax = std::max(maxEle, arr[i]);
    arr[i] = maxEle;
    maxEle = newMax;
  }
}

int main() {
  std::vector<int> arr = {17, 18, 5, 4, 6, 1};
  printArr(arr);
  // bruteForce(arr);
  replaceElements(arr);
  printArr(arr);

  return 0;
}

// * Run the code
// * g++ --std=c++17 16-replace-elements-with-greatest.cpp -o 16-replace-elements-with-greatest && ./16-replace-elements-with-greatest