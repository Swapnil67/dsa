#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}


void dutchNationalFlagBrute(std::vector<int> &arr) {
  int n = arr.size();
  int zeroCount = 0, oneCount = 0, twoCount = 0;
  for (int i = 0; i < n; i++) {
    if(arr[i] == 0) zeroCount++;
    if(arr[i] == 1) oneCount++;
    if(arr[i] == 2) twoCount++;
  }

  for (int i = 0; i < zeroCount; i++) {
    arr[i] = 0;
  }

  if(oneCount) {
    for (int i = zeroCount; i < zeroCount + oneCount; i++) {
      arr[i] = 1;
    }
  }

  if(twoCount) {
    for (int i = zeroCount + oneCount; i < n; i++) {
      arr[i] = 2;
    }
  }
}

void dutchNationalFlag(std::vector<int> &arr)  {
  int n = arr.size();
  int l = 0, m = 0, h = n - 1;
  while (l < h) {
    if(arr[m] == 0) {
      swap(arr[l], arr[m]);
      l++, m++;
    }
    else if(arr[m] == 1) {
      m++;
    }
    else if(arr[m] == 2) {
      swap(arr[m], arr[h]);
      h--;
    }
  }
}

// *  0 0 0 0   1 1 1 1  2 1 0 2   2 2 2 2
// * 0     low-1      low      mid        high

int main() {
  // * Problem 1
  std::cout << "Sort 0s, 1s and 2s" << std::endl;
  std::vector<int> arr = {2, 2, 2, 2, 0, 0, 1, 0};
  printArr(arr);
  // dutchNationalFlagBrute(arr);
  dutchNationalFlag(arr);
  printArr(arr);
  // printArr(arr);

  // * Problem 2
  // std::cout << "Majority element n/2" << std::endl;
  // std::vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  // std::vector<int> arr = {58, 58, 28, 95, 58, 15, 58, 58 };
  // printArr(arr);
  // int majorityEle = majorityElementA(arr);
  // std::cout << "Majority Element n/2 times is " << majorityEle << std::endl;

  // * Problem 3
  // std::cout << "Maximum Subarray Sum" << std::endl;
  // std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // * 6
  // printArr(arr);
  // std::vector<int> points = maxSubarraySum(arr);
  // std::cout << "Maximum subarray sum exists between " << points[0] << " to " << points[1] << std::endl;

  // * Problem 4
  // std::cout << "Maximum Subarray Sum Circular" << std::endl;
  // std::vector<int> arr = {5, -3, 5}; // * 10
  // std::vector<int> arr = {-2, -3, -1}; // * -1
  // printArr(arr);
  // int maxSum = maxSubarraySumCircular(arr);
  // std::cout << "Maximum subarray sum in circular array is " << maxSum << std::endl;

  // * Problem 5
  // std::cout << "Rearrange Array Elements by Sign" << std::endl;
  // std::vector<int> arr = {1, 2, -4, -5};
  // std::vector<int> ans = reArrangeElementsA(arr);
  // printArr(arr);
  // std::vector<int> arr = {-1, 2, 3, 4, -3, 1};
  // std::vector<int> arr = {3, 1, -2, -5, 2, -4, -7, -8, 3, -9};
  // std::vector<int> ans = reArrangeElementsB(arr);
  // printArr(ans);

  // * Problem 6
  // std::cout << "Superior Elements" << std::endl;
  // std::vector<int> arr = {1, 2, 2, 1};
  // std::vector<int> arr = {1, 2, 3, 2};
  // printArr(arr);
  // std::vector<int> ans = superiorELementsBrute(arr);
  // std::vector<int> ans = superiorElements(arr);
  // printArr(ans);

  // * Problem 7
  // std::cout << "Replace elements with greatest" << std::endl;
  // std::vector<int> arr = {17, 18, 5, 4, 6, 1};
  // printArr(arr);
  // replaceGreatest(arr);
  // printArr(arr);

  // * Problem 8
  // std::cout << "Longest Consecutive Sequence" << std::endl;
  // std::vector<int> arr = {100, 4, 200, 1, 3, 2};
  // std::vector<int> arr = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  // std::vector<int> arr = {15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3}; // * o/p = 6
  // printArr(arr);
  // int longestSequence = longestConsecutiveBrute(arr);
  // int longestSequence = findlongestConsecutiveBetter(arr);
  // int longestSequence = findlongestConsecutive(arr);
  // std::cout << "Longest consecutive sequence is " << longestSequence << std::endl;
  
  return 0;
}
// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice