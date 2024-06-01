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

void reverseArray(std::vector<int> &arr) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while(l <= r) {
    swap(arr[l], arr[r]);
    l++, r--;
  }
}

// * Largest element in array
int largestElementInArray(std::vector<int> arr) {
  int n = arr.size();
  int largest = INT_MIN;
  for(int i=0; i<n; i++) {
    largest = std::max(largest, arr[i]);
  }
  return largest;
}

// * Find Second largest element
int findSecondLargestEle(std::vector<int> arr, int n) {
  int L = INT_MIN, SL = INT_MIN;
  for(int i=0; i<n; i++) {
    if(arr[i] > L) {
      SL = L;
      L = arr[i];
    }
    else if(arr[i] > SL) {
      SL = arr[i];
    }
  }
  return SL;
}

// * Find Second Smallest element
int findSecondSmallestEle(std::vector<int> arr, int n) {
  int L = INT_MAX, SL = INT_MAX;
  for(int i=0; i<n; i++) {
    if(arr[i] < L) {
      SL = L;
      L = arr[i];
    }
    else if(arr[i] < SL) {
      SL = arr[i];
    }
  }
  return SL;
}

std::pair<int, int> findSecondLargestAndSmallestElement(std::vector<int> arr) {
  int n = arr.size();
  int secondLargest = findSecondLargestEle(arr, n);
  int secondSmallest = findSecondSmallestEle(arr, n);
  std::pair<int, int> ans(secondLargest, secondSmallest);
  return ans;
}

// * Check array is sorted
bool checkArraySorted(std::vector<int> arr) {
  bool isSorted = true;
  int n = arr.size();

  // * Element with single array is always sorted
  if(n == 1) return isSorted;

  for(int i=1; i<n; i++) {
    if(arr[i] < arr[i-1]) {
      isSorted = false;
      break;
    }
  }
  return isSorted;

}

// * Remove duplicates
void removeDuplicates(std::vector<int> &arr) {
  int n = arr.size();
  int i = 0;
  for (int j = 1; j < n; j++) {
    if(arr[i] != arr[j]) {
      arr[i+1] = arr[j];
      i++;
    }
  }
}

// * Left rotate by one
void leftRotateByOne(std::vector<int> &arr) {
  int n = arr.size();
  if(n == 0 || n == 1) return;
  int firstEle = arr[0];
  for (int i = 1; i < n; i++) {
    arr[i-1] = arr[i];
  }
  arr[n-1] = firstEle;
}

// * Left rotate by k
void leftRotateByK(std::vector<int> &arr, int k) {
  int n = arr.size();
  // * get the number of rotations
  int d = k % n;
  // int d = n % k;
  std::cout << "Rotation Count " << d << std::endl;
  if(d == 0) return;

  // * Create a temp array of first d elements
  std::vector<int> temp;
  for (int i = 0; i < d; i++) {
    temp.push_back(arr[i]);
  }

  // * Shift the elements after d
  for (int i = d; i < n; i++) {
    arr[i-d] = arr[i];
  }

  // * Put the temp back into array
  for (int i = n - d; i < n; i++) {
    arr[i] = temp[i - (n - d)];
  }
}

// * Move zeros to end
void moveZerosToEnd(std::vector<int> &arr) {
  int n = arr.size();

  // * find the first zero index 
  int j = -1;
  for(int i=0; i<n; i++) {
    if(arr[i] == 0) {
      j = i;
      break;
    }
  }

  // * Checks if any zero exists
  if(j == -1) return;

  for (int i = j + 1; i < n; i++) {
    if(arr[i] != 0) {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}

// * Merge two sorted arrays
std::vector<int> mergeTwoSortedArrays(std::vector<int> a, std::vector<int> b) {
  int n1 = a.size(), n2 = b.size();
  int i = 0, j = 0, last = INT_MIN;
  std::vector<int> ans;
  while(i < n1 && j < n2) {
    if(a[i] < b[j]) { 
      if(a[i] != last) {
        ans.push_back(a[i]);
        last = a[i];
      }
      i++;
    } else {
      if(b[j] != last) {
        ans.push_back(b[j]);
        last = b[j];
      }
      j++;
    }
  }

  while(i < n1) {
    if(a[i] != last) {
      ans.push_back(a[i]);
      last = a[i];
    }
    i++;
  }
  
  while(j < n2) {
    if(b[j] != last) {
      ans.push_back(b[j]);
      last = b[j];
    }
    j++;
  }
  return ans;
}

// * Missing numbers 
// * TIME COMPLEXITY = O(3N)
// * SPACE COMPLEXITY = O(N)
int findMissingNumber(std::vector<int> arr) {
  int n = arr.size();
  // * get the largest element in array
  int largest = INT_MIN;

  // * O(N)
  for(int i=0; i<n; i++) {
    largest = std::max(largest, arr[i]);
  }

  std::vector<int> hashArr(largest, 0);

  // * O(N)
  for(int i=0; i<n; i++) {
    hashArr[arr[i]]++;
  }

  // * O(N)
  for(int i=0; i<largest; i++) {
    if(hashArr[i] == 0) {
      return i;
    }
  }

  return -1;
}

// * Maximum consecutive ones
int findMaxConsecutiveOnes(std::vector<int> arr) {
  int n = arr.size();
  int maxOnes = INT_MIN, cnt = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] == 1) {
      cnt++;
      maxOnes = std::max(maxOnes, cnt);
    }
    else {
      cnt = 0;
    }
  }
  return maxOnes;
}

// * Single number
// * Binary search
int findSingleNumber(std::vector<int> arr) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] != arr[m-1] && arr[m] != arr[m+1]) {
      return arr[m];
    }
    if ((m % 2 == 0 && arr[m] == arr[m + 1]) || (m % 2 == 1 && arr[m] == arr[m - 1])) {
      // * Left side of single number
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return -1;
}


int findLongestSubarraySumkA(std::vector<int> arr, int k) {
  int n = arr.size();
  std::map<int, int> prefixSumMap;
  int sum = 0, len = 0;
  for(int i=0; i<n; i++) {
    sum += arr[i];
    if(sum == k) {
      len = std::max(len, i+1);
    }

    // * Does hasharray contains rem
    int rem = sum - k;
    if(prefixSumMap.find(rem) != prefixSumMap.end()) {
      len = std::max(len, i-prefixSumMap[rem]);
    }

    // * add the current sum to map
    if(prefixSumMap.find(sum) == prefixSumMap.end()) {
      prefixSumMap[sum] = i;
    }
  }
  return len;
}

int findLongestSubarraySumkB(std::vector<int> arr, int k) {
  int n = arr.size();
  int l = 0, r = 0, len = 0;
  int sum = 0;
  while(l <= r) {
    sum = sum + arr[l];
    
    if(sum > k) {
      while(sum < k) {
        sum = sum - arr[r];
        r++;
      }
    }

    if(sum == k) {
      len = std::max(len, l-r);
    }
    l++;
  }
  return len;
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
  // std::cout << "Second Largest in array" << std::endl;
  // std::vector<int> arr = {1, 2, 3, 4, 5}; // * [4, 2]
  // std::vector<int> arr = { 3,1,2,7,10 }; // * [7, 2]
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
  // removeDuplicates(arr);
  // printArr(arr);

  // * Problem 5
  // std::cout << "Left rotate by one" << std::endl;
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // std::vector<int> arr = {5, 7, 3, 2};
  // printArr(arr);
  // leftRotateByOne(arr);
  // printArr(arr);

  // * Problem 5
  // std::cout << "Left rotate by k" << std::endl;
  // int k = 4;
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // printArr(arr);
  // leftRotateByK(arr, k);
  // printArr(arr);

  // * Problem 6
  // std::cout << "Move zeros to end" << std::endl;
  // std::vector<int> arr = { 1, 2, 0, 0, 2, 3 };
  // std::vector<int> arr = { 0, 0, 0, 1 };
  // printArr(arr);
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
  std::cout << "Longest subarray with sum k" << std::endl;
  std::vector<int> arr = { 1,2,3,1,1,1,1 };
  int k = 3;
  printArr(arr);
  // int longestSubarray = findLongestSubarraySumkA(arr, k);
  int longestSubarray = findLongestSubarraySumkB(arr, k);
  std::cout<<"Longest subarray "<<longestSubarray<<std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 practice-cafe.cpp -o practice-cafe && ./practice-cafe