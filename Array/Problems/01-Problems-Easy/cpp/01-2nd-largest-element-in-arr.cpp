/**
 * * Largest Element in the Array
 * * You have been given an array ‘a’ of ‘n’ unique non-negative integers.
 * * Find the second largest and second smallest element from the array.

 * * Example 1
 * * Input  : ‘n’ = 5, ‘a’ = [1, 2, 3, 4, 5]
 * * Output : [4, 2]

 * * https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279
*/
#include<iostream>

// * Second Largest Element
int findSecondLargestEle(std::vector<int> arr) {
  if(!arr.size()) return -1;

  int largest = arr[0], secondLargest = -1;

  for(int i=1; i<arr.size(); i++) {
    if(arr[i] > largest) {
      secondLargest = largest;
      largest = arr[i];
    }
    else if (arr[i] < largest && arr[i] > secondLargest) {
      secondLargest = arr[i];
    }
  }
  return secondLargest;
}

// * Second Smallest Element
int findSecondSmallestEle(std::vector<int> arr) {
  if(!arr.size()) return -1;

  int smallest = arr[0], secondSmallest = INT_MAX;

  for(int i=1; i<arr.size(); i++) {
    if(arr[i] < smallest) {
      secondSmallest = smallest;
      smallest = arr[i];
    }
    else if(arr[i] > smallest && arr[i] < secondSmallest) {
      secondSmallest = arr[i];
    }
  }
  return secondSmallest;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = { 1 };
  // * testcase 2
  // std::vector<int> arr = { 1,2,3,4,5 }; // * [4, 2]
  // * testcase 3
  // std::vector<int> arr = { 3,1,2,7,10 }; // * [7, 2]


  int secondLargest = findSecondLargestEle(arr);
  std::cout<<"Second Largest Element "<<secondLargest<<std::endl;
  int secondSmallest = findSecondSmallestEle(arr);
  std::cout<<"Second Smallest Element "<<secondSmallest<<std::endl;
}

// * Run the code
// * g++ --std=c++17 01-2nd-largest-element-in-arr.cpp -o 01-2nd-largest-element-in-arr && ./01-2nd-largest-element-in-arr