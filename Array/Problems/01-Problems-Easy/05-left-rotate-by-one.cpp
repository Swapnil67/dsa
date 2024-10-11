/**
 * * Left Rotate an Array by One
 * * Rotating the array left by one means shifting all elements by one place to the left and 
 * * moving the first element to the last position in the array.

 * * Example 1
 * * Input  : 'n' = 5, 'arr' = [1, 2, 3, 4, 5]
 * * Output : [2, 3, 4, 5, 1]
 * 
 * * Example 2
 * * Input  : ‘n’ = 4, ‘a’ = [5 7 3 2]
 * * Output : [7 3 2 5]

 * * https://www.naukri.com/code360/problems/left-rotate-an-array-by-one_5026278
*/

#include<set>
#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
void leftRotate(std::vector<int> &arr) {
  // * Size of array
  int n = arr.size();

  // * keep the 1st element saved
  int firstEle = arr[0];

  // * Start the loop from '1' index
  for (int i = 1; i < n; i++) {
    // * Shift the current index to previous index
    arr[i - 1] = arr[i];
  }

  // * Put the first element in last position
  arr[n - 1] = firstEle;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {1, 2, 3, 4, 5};

  // * testcase 2
  // std::vector<int> arr = {5, 7, 3, 2};

  // * testcase 3
  std::vector<int> arr = {5};
  std::cout << "Before Rotation" << std::endl;
  printArr(arr);
  
  leftRotate(arr);
  std::cout << "After Rotation" << std::endl;
  printArr(arr);
}


// * Run the code
// * g++ --std=c++17 05-left-rotate-by-one.cpp -o 05-left-rotate-by-one && ./05-left-rotate-by-one
