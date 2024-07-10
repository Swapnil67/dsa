#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}


int main() {


  // * Problem 8
  // * Search In Rotated Sorted Array (B)
  // std::vector<int> arr = {3, 1, 2, 3, 3, 3, 3};
  // int target = 1;
  // std::vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
  // int target = 8;
  // std::vector<int> arr = {2, 5, 6, 0, 0, 1, 2};
  // int target = 0;
  // printArr(arr);
  // int idx = searchInRotatedSortedB(arr, target);
  // std::cout<<"Index "<<idx<<std::endl;

  // * Problem 9
  // * Find Minimum in rotated sorted array
  // std::vector<int> arr = {2, 3, 4, 1};
  // std::vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
  // std::vector<int> arr = {25, 30, 5, 10, 15, 20};
  // printArr(arr);
  // int minEle = minInRotatedSorted(arr);
  // std::cout<<"Minimum in rotated sorted: "<<minEle<<std::endl;

  // * Problem 10
  // * Count of rotation
  // std::vector<int> arr = {2, 3, 4, 1};
  // std::vector<int> arr = {5, 6, 0, 1, 2};
  // printArr(arr);
  // int count = countRotation(arr, target);
  // std::cout<<"Rotation Count "<<count<<std::endl;
   
  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice

