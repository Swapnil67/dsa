#include <map>
#include <iostream>
#include <numeric>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void reverse(std::vector<int> &arr, int l, int r) {
  int n = arr.size();
  while(l < r) {
    swap(arr[l++], arr[r--]);
  }
}

// * ------------ Rotate array by K places ---------------

void rotateByKPlacesBrute(std::vector<int> &arr, int k) {
  int n = arr.size();
  int d = k % n;
  std::cout << "Rotation count " << d << std::endl;
  if(d == 0) return;

  // * Create a temp array of 1 elements
  std::vector<int> temp;
  for (int i = 0; i <= d; i++) {
    temp.push_back(arr[i]);
  }

  // * Shift the elements after k position
  for (int i = k; i < n; i++) {
    arr[i - k] = arr[i];
  }

  // * put temp back into array
  for (int i = n - d; i < n; i++) {
    // * base = n - k
    arr[i] = temp[i - (n - d)] ;
  }
}

void rotateByKPlaces(std::vector<int> &arr, int k) {
  int n = arr.size();
  int d = k % n;
  if (d == 0)
    return;
  reverse(arr, 0, d - 1);
  reverse(arr, d, n - 1);
  reverse(arr, 0, n - 1);
}

// * ------------ Move Zeros To End ---------------

void moveZerosToEnd(std::vector<int> &arr) {
  int n = arr.size();
  int j = -1;
  // * get the first index of zeros
  for (int i = 0; i < n; i++) {
    if(arr[i] == 0) {
      j = i;
      break;
    }
  }

  if(j == -1) return;

  for (int i = j + 1; i < n; i++) {
    if(arr[i] != 0) {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}

// * ------------ Merge two sorted arrays ---------------

std::vector<int> mergeTwoArrays(std::vector<int> a, std::vector<int> b) {
  int n1 = a.size(), n2 = b.size();
  int last = INT_MAX;
  int i = 0, j = 0;
  std::vector<int> ans;
  while (i < n1 && j < n2) {
    if(a[i] < b[j]) {
      if (a[i] != last) {
        ans.push_back(a[i]);
        last = a[i];
      }
      i++;
    }
    else {
      if(b[j] != last) {
        ans.push_back(b[j]);
        last = b[j];
      }
      j++;
    }
  }

  while(i < n1) {
    if (a[i] != last) {
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

// * ------------ Missing Number ---------------

int missingNumberBetter(std::vector<int> arr) {
  int n = arr.size();
  int maxEle = *std::max_element(arr.begin(), arr.end());

  std::vector<int> hashArr(maxEle+1, 0);
  for (int i = 0; i <= n; i++) {
    hashArr[arr[i]]++;
  }

  for (int i = 0; i < hashArr.size(); i++) {
    if (hashArr[i] == 0)
      return i;
  }
  return -1;
}

int findMissingNumber(std::vector<int> arr) {
  int n = arr.size(); 
  int total = accumulate(arr.begin(), arr.end(), 0);
  int sumN = (n * (n + 1)) / 2;
  return sumN - total;
}

// * ------------ Max Consecutive Ones ---------------

int maxConsecutiveOnes(std::vector<int> arr) {
  int n = arr.size(), c = 0, maxC = INT_MIN;
  for (int i = 0; i < n; i++) {
    if(arr[i] == 1) {
      c++;
    }
    else {
      maxC = std::max(maxC, c);
      c = 0;
    }
  }
  return c;
}

// * ------------ Single Number ---------------

int findSingleNumberBetter(std::vector<int> arr) {
  int n = arr.size();
  int maxEle = *std::max_element(arr.begin(), arr.end());
  std::map<int, int> countMap;

  for (int i = 0; i < n; i++) {
    countMap[arr[i]]++;
  }

  for(auto it : countMap) {
    if (it.second == 1)
      return it.first;
  }
  return -1;
}

// * Array is not sorted
// * Use XOR
int findSingleNumberA(std::vector<int> arr) {
  int n = arr.size();
  int singleNumber = 0;
  for (int i = 0; i < n; i++) {
    singleNumber = singleNumber ^ arr[i];
  }
  return singleNumber;
}

// * Array is sorted
// * Use Binary Search
int findSingleNumberB(std::vector<int> arr) {
  int n = arr.size();
  int l = 0, r = n - 1;

  if (n == 0)
    return -1;
  if (n == 1)
    return arr[0];
  else if (arr[0] != arr[1])
    return arr[0];
  else if (arr[r] != arr[r - 1])
    return arr[r];

  while (l <= r) {
    int m = l + (r - l) / 2;
    // * Unique Element
    if (arr[m] != arr[m - 1] && arr[m] != arr[m + 1]) {
      return arr[m];
    }
    else if ((m % 2 == 1 && arr[m] == arr[m - 1]) || (m % 2 == 0 && arr[m] == arr[m + 1])) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return -1;
}

// * ------------ Longest Subarray With Sum K ---------------

int subarraySumKBetter(std::vector<int> arr, int k) {
  long long sum = 0;
  int n = arr.size(), maxLen = 0;
  std::map<int, int> prefixSumMap;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if(sum == k) {
      maxLen = std::max(maxLen, i + 1);
    }

    // * find in prefix sum
    int rem = sum - k;
    if(prefixSumMap.find(rem) != prefixSumMap.end()) {
      int len = i - prefixSumMap[rem];
      maxLen = std::max(maxLen, i - len);
    }

    // * Add sum to prefixSumMap
    if(prefixSumMap.find(sum) == prefixSumMap.end()) {
      prefixSumMap[sum] = i;
    }
  }

  return maxLen;
}

int subarrySumK(std::vector<int> arr, int k) {
  int n = arr.size();
  long long sum = 0;
  int i = 0, maxLen = INT_MIN;
  for (int j = 0; j < n; j++) {
    sum = sum + arr[j];
    while(sum > k) {
      sum -= arr[i];
      i++;
    }
    if(sum == k) {
      maxLen = std::max(maxLen, j - i + 1);
    }
  }
  return maxLen;
}

// * ------------ Two Sum ---------------

std::vector<int> twoSumBrute(std::vector<int> arr, int target) {
  int n = arr.size();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && (arr[i] + arr[j]) == target) {
        return {arr[i], arr[j]};
      }
    }
  }
  return {-1, -1};
}

std::vector<int> twoSumBetter(std::vector<int> arr, int target) {
  int n = arr.size();
  int sum = 0;
  std::map<int, int> prefixMap;
  for (int i = 0; i < n; i++) {
    int val = target - arr[i]; 
    if(prefixMap.find(val) != prefixMap.end()) {
      return {prefixMap[val], i};
    }
    prefixMap[arr[i]] = i;
  }
  return { -1, -1 };
}

int main() {

  // * Problem 1
  // int k = 3;
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // int k = 1;
  // std::vector<int> arr = { 7,1,2,3,4,5,6 };
  // std::cout<<"Before Rotation"<<std::endl;
  // printArr(arr);
  // rotateByKPlacesBrute(arr, k);
  // rotateByKPlaces(arr, k);
  // std::cout<<"After Rotation"<<std::endl;
  // printArr(arr);

  // * Problem 2
  // std::cout << "Move Zeros To End" << std::endl;
  // std::vector<int> arr = {1, 2, 0, 0, 2, 3};
  // printArr(arr);
  // moveZerosToEnd(arr);
  // printArr(arr);

  // * Problem 3
  // std::cout << "Merge two sorted arrays" << std::endl;
  // std::vector<int> a = {1, 2, 3, 4, 6};
  // std::vector<int> b = {2, 3, 5};
  // std::cout << "a: ";
  // printArr(a);
  // std::cout << "b: ";
  // printArr(b);
  // std::vector<int> unionArr = mergeTwoArrays(a, b);
  // std::cout<<"Union ";
  // printArr(unionArr);

  // * Problem 4
  // std::cout << "Missing number" << std::endl;
  // std::vector<int> arr = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  // int missingNumber = missingNumberBetter(arr);
  // int missingNumber = findMissingNumber(arr);
  // std::cout << "Missing Number: " << missingNumber << std::endl;

  // * Problem 5
  // std::cout << "Max Consecutive Ones" << std::endl;
  // std::vector<int> arr = {1, 1, 0, 1, 1, 1};
  // printArr(arr);
  // int ans = maxConsecutiveOnes(arr);
  // std::cout << "Max Consecutive Ones: " << ans << std::endl;

  // * Problem 6
  // std::cout << "Single Number A" << std::endl;
  // std::vector<int> arr = {7, 3, 5, 4, 5, 3, 4};
  // printArr(arr);
  // int singleNumber = findSingleNumberBetter(arr);
  // int singleNumber = findSingleNumberA(arr);
  // std::cout << "Single Number " << singleNumber << std::endl;

  // * Problem 7
  // std::cout << "Single Number B" << std::endl;
  // std::vector<int> arr = {1, 1, 2, 2, 3, 3, 6, 6, 7, 9, 9};
  // printArr(arr);
  // int singleNumber = findSingleNumberBetter(arr);
  // int singleNumber = findSingleNumberB(arr);
  // std::cout << "Single Number " << singleNumber << std::endl;

  // * Problem 8
  // std::cout << "Longest Subarray With Sum K" << std::endl;
  // int k = 3;
  // std::vector<int> arr = {1, 2, 3, 1, 1, 1, 1};
  // printArr(arr);
  // int longestSubArrLength = subarraySumKBetter(arr, k);
  // int longestSubArrLength = subarrySumK(arr, k);
  // std::cout << "Sub array with max length " << longestSubArrLength << std::endl;

  // * Problem 9
  std::cout << "Two Sum" << std::endl;
  int target = 9;
  std::vector<int> arr = {2, 15, 11, 7};
  printArr(arr);
  // std::vector<int> ans = twoSumBrute(arr, target);
  std::vector<int> ans = twoSumBetter(arr, target);
  printArr(ans); 
  
  return 0;
}


// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice