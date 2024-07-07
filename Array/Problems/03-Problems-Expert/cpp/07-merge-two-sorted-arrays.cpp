/**
 * * Merge Two Sorted Arrays Without Extra Space
 * * Given two non-decreasing sorted arrays, ‘A’ and ‘B’, having ‘N’ and ‘M’ elements, respectively.
 * * You must merge these arrays, ‘A’ and ‘B’, into a sorted array without using extra space.
 * * Of all the 'N + M' sorted elements, array 'A' should contain the first 'N' elements, and array 'B' 
 * * should have the last 'M' elements. 
 * 
 * * Note
 * * You must perform the merge operation in place and must not allocate any extra space to merge the two arrays.
 *
 * * Example 1
 * * Input  :  ‘A’ = {1, 8, 8}, ‘B’ = {2, 3, 4, 5}
 * * Output : A = {1, 2, 3} & B = {4, 5, 8, 8} and Merged = {1, 2, 3, 4, 5, 8, 8},

 * * https://www.naukri.com/code360/problems/merge-two-sorted-arrays-without-extra-space_6898839
*/

#include<iostream>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// * ------------------------- APPROACH 1: Brute Approach -------------------------`
// * Create a merged array
// * TIME COMPLEXITY O(n1 + n2) + O(n1 + n2) 
// * SPACE COMPLEXITY O(n1 + n2)
void bruteForce(std::vector<int> &a, std::vector<int> &b) {
  int n1 = a.size(), n2 = b.size();
  std::vector<int> mergedArr;
  // * O(n1 + n2)
  // * Merge two arrays in one
  int i = 0, j = 0;
  while(i < n1 && j < n2) {
    if(a[i] < b[j]) {
      mergedArr.push_back(a[i++]);
    }
    else {
      mergedArr.push_back(b[j++]);
    }
  }

  while(i < n1) {
    mergedArr.push_back(a[i++]);
  }

  while(j < n2) {
    mergedArr.push_back(b[j++]);
  }

  printArr(mergedArr);

  // * O(n1 + n2)
  // * Fill a
  for (int i = 0; i < n1; i++) {
    a[i] = mergedArr[i];
  }

  // * Fill b
  for (int i = n1; i < n1 + n2; i++) {
    b[i-n1] = mergedArr[i];
  }
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Two Pointers & Swap
// * TIME COMPLEXITY O(min(n1, n2)) + O(n1logn) + O(n2logn)
/*
 * O(min(n1, n2)) => Whichever breaks first
 * O(n1logn) => To sort arr1
 * O(n2logn) => To sort arr2
*/
// * SPACE COMPLEXITY O(1)
void mergeTwoSortedArraysWithoutExtraSpaceA(std::vector<int> &a, std::vector<int> &b) {
  int n1 = a.size(), n2 = b.size();
  int l = n1 - 1, r = 0;
  while(l > 0 && r < n2) {
    if(a[l] > b[r]) {
      swap(a[l], b[r]);
      l--;
      r++;
    }
    else {
      // * Rest will be sorted
      break;
    }
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
}

int main() {
  std::vector<int> a = {1, 8, 8}, b = {2, 3, 4, 5};
  std::cout<<"A vector: ";
  printArr(a);
  std::cout<<"B vector: ";
  printArr(b);

  // bruteForce(a, b);
  mergeTwoSortedArraysWithoutExtraSpaceA(a, b);
  std::cout << "After Merging" << std::endl;

  std::cout<<"A vector: ";
  printArr(a);
  std::cout<<"B vector: ";
  printArr(b);
  return 0; 
}

// * Run the code
// * g++ --std=c++17 07-merge-two-sorted-arrays.cpp -o 07-merge-two-sorted-arrays && ./07-merge-two-sorted-arrays
