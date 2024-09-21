/**
 * * Move Zero's to End
 * * Given an array 'arr' of 'n' non-negative integers, your task is to move all the zeros to the end of the array while keeping 
 * * the non-zero elements at the start of the array in their original order. Return the modified array.

 * * Example 1
 * * Input  : 'k' = 1, 'arr '= [1, 2, 0, 0, 2, 3]
 * * Output : [1, 2, 2, 3, 0, 0]
 * 
 * * Example 2
 * * Input  : 'k' = 4, 'arr '= [0, 0, 0, 1]
 * * Output : [1, 0, 0, 0]

 * * https://www.naukri.com/code360/problems/ninja-and-the-zero-s_6581958
*/

#include<iostream>

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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Create new array
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
void bruteForce(std::vector<int> &arr) {
  int n = arr.size();
  std::vector<int> temp;
  
  // * Get the non-zero elements for arr
  for(int i=0; i<n; i++) {
    if(arr[i] > 0) {
      temp.push_back(arr[i]);
    }
  }

  // * Store the non-zero elements to the array
  int tempSize = temp.size();
  for(int i=0; i<tempSize; i++) {
    arr[i] = temp[i];
  }

  // * Now put the zero elements after tempSize
  for(int i=tempSize; i<n; i++) {
    arr[i] = 0;
  }

}


// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
void better(std::vector<int> &arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) {
    if(arr[i] != 0) {
      continue;
    } 
    else {
      for(int j=i+1; j<n; j++) {
        if(arr[j] != 0) {
          // std::cout << "arr[i] " << arr[i] << " arr[j] " << arr[j] << std::endl;
          swap(arr[i], arr[j]);
          break;
        }
      }
    }
  }
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
void optimal(std::vector<int> &arr) {
  int n = arr.size();

  // * Place j at first 0 elements
  int j = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      j = i;
      break;
    }
  }

  // * No 0 found in array
  if (j == -1)
    return;

  // * Now loop from j+1 and replace non-zero elements with zero elements
  for (int i = j + 1; i < n; i++) {
    if (arr[i] != 0) {
      swap(arr[j], arr[i]);
      j++;
    }
  }
}

int main() {

  std::vector<int> arr = {1, 2, 0, 0, 2, 3};
  // std::vector<int> arr = {0, 0, 0, 1};
  // std::vector<int> arr = {8, 6, 9};

  std::cout<<"Before Moving Zero's"<<std::endl;
  printArr(arr);

  std::cout<<"After Moving Zero's"<<std::endl;
  // bruteForce(arr);
  // better(arr);
  optimal(arr);
  printArr(arr);

  return 0;
}

// * Run the code
// * g++ --std=c++17 07-move-zero-to-end.cpp -o 07-move-zero-to-end && ./07-move-zero-to-end