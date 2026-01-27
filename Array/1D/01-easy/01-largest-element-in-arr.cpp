/**
 * *  Largest Element in the Array
 * * Given an array ‘arr’ of size ‘n’ find the largest element in the array.

 * * Example 1
 * * Input  :  'n' = 5, 'arr' = [1, 2, 3, 4, 5]
 * * Output : 5

 * * https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279
*/
#include <vector>
#include <iostream>

int findLargestEle(std::vector<int> arr) {
  if(!arr.size()) return -1;
  int maxEle = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    maxEle = std::max(arr[i], maxEle);
  }
  return maxEle;
}

int main() {
  // * testcase 1
  std::vector<int> arr = { 1 };
  
  // * testcase 2
  // std::vector<int> arr = { 1,2,3,4,5 };

  int largestEle = findLargestEle(arr);
  std::cout<<"Largest Element "<<largestEle<<std::endl;
}

// * Run the code
// * g++ --std=c++17 01-largest-element-in-arr.cpp -o 01-largest-element-in-arr && ./01-largest-element-in-arr