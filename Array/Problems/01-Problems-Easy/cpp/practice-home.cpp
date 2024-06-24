#include<map>
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

// * Reverse array
void reverseArray(std::vector<int> &arr) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while(l < r) {
    swap(arr[l++], arr[r--]);
  }
}

// * Largest Element
int largestElementInArray(std::vector<int> &arr) {
  int n = arr.size(), largest = INT_MIN;
  for (int i = 0; i < n; i++) {
    if(arr[i] > largest) {
      largest = arr[i];
    }
  }
  return largest;
}

// * Second Largest & Smallest in array
std::pair<int, int> findSecondLargestAndSmallestElement(std::vector<int> &arr) {
  int n = arr.size(), largest = INT_MIN, secondLargest = INT_MIN;
  // * Second Largest
  for (int i = 0; i < n; i++) {
    if(arr[i] > largest) {
      secondLargest = largest;
      largest = arr[i];
    }
    else if(arr[i] > secondLargest) {
      secondLargest = arr[i];
    }
  }
  
  // * Second Smallest
  int smallest = INT_MAX, secondSmallest = INT_MAX;
  for (int i = 0; i < n; i++) {
    if(arr[i] < smallest) {
      secondSmallest = smallest;
      smallest = arr[i];
    }
    else if(arr[i] < secondSmallest) {
      secondSmallest = arr[i];
    }
  }


  return {secondLargest, secondSmallest};
}

// * Check array is sorted
bool checkArraySorted(std::vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n-1; i++) {
    if(arr[i] > arr[i+1]) {
      return false;
    }
  }
  return true;
}

// * Remove duplicates
int removeDuplicates(std::vector<int> &arr) {
  int n = arr.size(), i = 0, uniqueElements = 0;
  for (int j = 1; j < n; j++) {
    if(arr[i] != arr[j]) {
      arr[i + 1] = arr[j];
      i++;
      j++;
      uniqueElements++;
    }
  }
  return uniqueElements+1;
}

// * Left Rotate By One
void leftRotateByOne(std::vector<int> &arr) {
  int n = arr.size();
  if(n == 1) return;
  int firstEle = arr[0];
  for (int i = 1; i < n; i++) {
    arr[i - 1] = arr[i];
  }
  arr[n - 1] = firstEle;
}

// * Left Rotate By k
void leftRotateByK(std::vector<int> &arr, int k) {
  int n = arr.size();
  int d = k % n;
  if(d == 0) return;
  // std::cout << "d " << d << std::endl;

  // * Fill the temp arr
  std::vector<int> temp;
  for (int i = 0; i < d; i++) {
    temp.push_back(arr[i]);
  }

  // * Shift elements after d
  for (int i = d; i < n; i++) {
    arr[i-d] = arr[i];
  }

  // * Put the temp array back to array
  for (int i = n - d; i < n; i++) {
    arr[i] = temp[i - (n - d)];
  }
}

// * Move zeros to end Brute Force
void moveZerosToEndBrute(std::vector<int> &arr) {
  int n = arr.size();
  int zc = 0;
  std::vector<int> temp;
  for (int i = 0; i < n; i++) {
    if(arr[i] == 0) zc++;
    else temp.push_back(arr[i]);
  }
  for (int i = 0; i < temp.size(); i++) {
    arr[i] = temp[i];
  }
  for (int i = temp.size(); i < n; i++) {
    arr[i] = 0;
  }
}

// * Move zeros to end
void moveZerosToEnd(std::vector<int> &arr) {
  int n = arr.size();
  int zeroIdx = -1;
  // * Find first zero Idx
  for (int i = 0; i < n; i++) {
    if(arr[i] == 0) {
      zeroIdx = i;
      break;
    }
  }
  if(zeroIdx == -1) return;
  for (int i = zeroIdx + 1; i < n; i++) {
    if(arr[i] != 0) {
      swap(arr[zeroIdx], arr[i]);
      zeroIdx++;
    }
  }
}

// * Merge two sorted arrays
std::vector<int> mergeTwoSortedArrays(std::vector<int> a, std::vector<int> b)  {
  int n1 = a.size(), n2 = b.size(), lastPushed = INT_MIN;
  std::vector<int> mergedArr;
  int l = 0, r = 0;
  while(l < n1 && r < n2) {
    if(a[l] > b[r]) {
      if(lastPushed != b[r]) {
        lastPushed = b[r];
        mergedArr.push_back(lastPushed);
      }
      r++;
    }
    else {
      if(lastPushed != a[l]) {
        lastPushed = a[l]; 
        mergedArr.push_back(lastPushed);
      }
      l++;
    }
  }

  // * Push remaining from a
  while (l < n1) {
    if(lastPushed != a[l]) {
      lastPushed = a[l]; 
      mergedArr.push_back(lastPushed);
    }
    l++;
  }

  // * Push remaining from b
  while (r < n2) {
    if(lastPushed != b[r]) {
      lastPushed = b[r];
      mergedArr.push_back(lastPushed);
    }
    r++;
  }

  return mergedArr;
}

int main() {
  // * Problem 0
  // std::cout << "Reverse an array" << std::endl;
  // std::vector<int> arr = {1, 2, 3, 4};
  // std::cout << "Before" << std::endl;
  // printArr(arr);
  // reverseArray(arr);
  // std::cout << "After" << std::endl;
  // printArr(arr);

  // * Problem 1
  // std::cout << "Largest in array" << std::endl;
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // printArr(arr);
  // int largest = largestElementInArray(arr);
  // std::cout << "Largest element in array: " << largest << std::endl;

  // * Problem 2
  // std::cout << "Second Largest & Smallest in array" << std::endl;
  // std::vector<int> arr = {1, 2, 3, 4, 5}; // * [4, 2]
  // std::vector<int> arr = {3, 1, 2, 7, 5}; // * [5, 2]
  // printArr(arr);
  // std::pair<int, int> ans = findSecondLargestAndSmallestElement(arr);
  // std::cout << "Second Largest element in array: " << ans.first << std::endl;
  // std::cout << "Second Smallest element in array: " << ans.second << std::endl;

  // * Problem 3
  // std::cout << "Check sorted array" << std::endl;
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // std::vector<int> arr = {4, 5, 4, 4, 4};
  // printArr(arr);
  // bool isSorted = checkArraySorted(arr);
  // std::cout << "Is sorted array: " << isSorted << std::endl;

  // * Problem 4
  // std::cout << "Remove duplicates" << std::endl;
  // std::vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 5, 5};
  // printArr(arr);
  // int uniqueElements = removeDuplicates(arr);
  // std::cout << "Unique Elements: " << uniqueElements << std::endl;
 
  // * Problem 5
  // std::cout << "Left rotate by one" << std::endl;
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // std::vector<int> arr = {5, 7, 3, 2};
  // printArr(arr);
  // leftRotateByOne(arr);
  // printArr(arr);

  // * Problem 5
  // int k = 3;
  // std::cout << "Left rotate by " << k << " elements." << std::endl;
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // printArr(arr);
  // leftRotateByK(arr, k);
  // printArr(arr);

  // * Problem 6
  // std::cout << "Move zeros to end" << std::endl;
  // std::vector<int> arr = { 1, 2, 0, 0, 2, 3 };
  // std::vector<int> arr = { 0, 0, 0, 1 };
  // printArr(arr);
  // moveZerosToEndBrute(arr);
  // moveZerosToEnd(arr);
  // printArr(arr);

  // * Problem 7 
  // std::cout << "Merge two sorted arrays" << std::endl;
  // std::vector<int> a = {3, 3, 4, 5, 6, 7, 8, 9, 9, 9};
  // std::vector<int> b = {2, 4, 10, 10};
  // std::cout<<"a = ";
  // printArr(a);
  // std::cout<<"b = ";
  // printArr(b);
  // std::vector<int> ans = mergeTwoSortedArrays(a, b);
  // std::cout<<"Merged = ";
  // printArr(ans);

  // * Problem 8
  // std::cout << "Missing number" << std::endl;
  // std::vector<int> arr = { 4, 6, 7, 9, 2, 1, 8, 11, 10, 3, 0 };
  // printArr(arr);
  // int missingNumber = findMissingNumber(arr);
  // std::cout << "Missing Number " << missingNumber << std::endl;

  // * Problem 9
  // std::cout << "Maximum consecutive ones" << std::endl;
  // std::vector<int> arr = {1, 1, 0, 1, 1, 1};
  // printArr(arr);
  // int maxOnes = findMaxConsecutiveOnes(arr);
  // std::cout<<"Maximum consecutive ones "<<maxOnes<<std::endl;

  // * Problem 10
  // std::cout << "Single Number" << std::endl;
  // std::vector<int> arr = { 1, 1, 2, 3, 3, 4, 4 };
  // printArr(arr);
  // int singleNumber = findSingleNumber(arr);
  // std::cout<<"Single number "<<singleNumber<<std::endl;

  // * Problem 11
  // std::cout << "Longest subarray with sum k" << std::endl;
  // std::vector<int> arr = { 1,2,3,1,1,1,1 };
  // int k = 3;
  // printArr(arr);
  // int longestSubarray = findLongestSubarraySumkA(arr, k);
  // int longestSubarray = findLongestSubarraySumkB(arr, k);
  // std::cout<<"Longest subarray "<<longestSubarray<<std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 practice-home.cpp -o practice-home && ./practice-home