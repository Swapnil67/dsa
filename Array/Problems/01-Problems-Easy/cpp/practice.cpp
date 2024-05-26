#include<map>
#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
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

// * 2nd largest element
int findSecondLargestElement(std::vector<int> arr) {
  int n = arr.size();
  int maxEle = INT_MIN, secondMax = INT_MIN;
  for(int i=0; i<n; i++) {
    if(arr[i] > maxEle) {
      secondMax = maxEle;
      maxEle = arr[i];
    }
    else if(arr[i] > secondMax) {
      secondMax = arr[i];
    }
  }
  return secondMax;
}

// * 2nd Smallest element
int findSecondSmallestElement(std::vector<int> arr) {
  int n = arr.size();
  int minEle = INT_MAX, secondMin = INT_MAX;
  for(int i=0; i<n; i++) {
    if(arr[i] < minEle) {
      secondMin = minEle;
      minEle = arr[i];
    }
    else if(arr[i] < secondMin) {
      secondMin = arr[i];
    }
  }
  return secondMin;
}

// * Remove Duplicates
void removeDuplicates(std::vector<int> &arr) {
  int n = arr.size();
  int i = 0, j = 1;
  for(int j=1; j<n; j++) {
    if(arr[i] != arr[j]) {
      arr[i+1] = arr[j];
      i++;
    }
  }
}

// * Rotate by one
void rotateByOne(std::vector<int> &arr) {
  int n = arr.size();
  int firstEle = arr[0];
  for(int i=1; i<n; i++) {
    arr[i-1] = arr[i];
  }
  arr[n-1] = firstEle;
}

// * Rotate by k places
void rotateByKPlaces(std::vector<int> &arr, int k) {
  int n = arr.size();
  std::vector<int> temp;
  int d = k % n;

  if(d == 0) return;

  // std::cout<<"d = "<<d<<std::endl;

  // * Put first k elements in temp
  for(int i=0; i<d; i++) {
    // std::cout<<i<<" -> "<<arr[i]<<std::endl;
    temp.push_back(arr[i]);
  }
  
  // * Now shift (k+1 - n) to start
  for(int i=d; i<n; i++) {
    arr[i-d] = arr[i];
  }

  // * Put temp back to array after (k+1 - n)
  for(int i=n-d; i<n; i++) {
    // std::cout<<i<<" -> "<<arr[i]<<std::endl;
    arr[i] = temp[i-(n-d)];
  }
}

// * Rotate by k places
void rotateByKPlacesOptimal(std::vector<int> &arr, int k) {
  int n = arr.size();
  int d = k % n;
  if(d == 0) return;

  // * Reverse 0 - d;
  reverse(arr, 0, d-1);
  // printArr(arr);
  
  // * Reverse d n;
  reverse(arr, d, n-1);
  // printArr(arr);

  // * Reverse whole arr;
  reverse(arr, 0, n-1);
}

// * Move zeros to end
void moveZerosToEnd(std::vector<int> &arr) {
  int n = arr.size();

  // * Get the index of first zero element
  int j = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] == 0) {
      j = i;
      break;
    }
  }

  for(int i=j+1; i<n; i++) {
    if(arr[i] != 0) {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}

// * Merge two sorted arrays
std::vector<int> mergeTwoSortedArrays(std::vector<int> a, std::vector<int> b) {
  int n1 = a.size(), n2 = b.size();
  int i = 0, j = 0, last = -1;
  // std::cout<<n1<<" "<<n2<<std::endl;
  std::vector<int> ans;
  while(i < n1 && j < n2) {
    if(a[i] > b[j]) {
      if(b[j] != last) {
        ans.push_back(b[j]);
        last = b[j];
      }
      j++;
    }
    else {
      if(last != a[i]) {
        ans.push_back(a[i]);
        last = a[i];
      }
      i++;
    }
  }

  // * Put remaining a
  while(i < n1) {
    if(last != a[i]) {
      ans.push_back(a[i]);
      last = a[i];
    }
    i++;
  }

  // * Put remaining b
  while(j < n2) {
    if(last != b[j]) {
      ans.push_back(b[j]);
      last = b[j];
    }
    j++;
  }

  return ans;
}

// * Find Missing Number
int findMissingNumber(std::vector<int> arr) {
  int n = arr.size();

  // * Find the largest element in array
  int maxEle = INT_MIN;
  for(int i=0; i<n; i++) {
    maxEle = std::max(maxEle, arr[i]);
  }

  // * Create an array of length maxEle containing 0
  std::vector<int> hashArr(maxEle, 0);

  // * Fill the hashed array with array elements
  for(int i=0; i<n; i++) {
    hashArr[arr[i]] = 1;
  }

  // * Loop through the hashArr and return missing element
  for(int i=0; i<maxEle; i++) {
    if(hashArr[i] == 0) {
      return i;
    }
  }

  return -1;
}

// * Max Consecutive Ones
int findMaxConsecutiveOnes(std::vector<int> arr) {
  int n = arr.size();
  int maxOnes = 0, ones = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] == 1) {
      ones++;
      maxOnes = std::max(ones, maxOnes);
    }
    else {
      ones = 0;
    }
  }
  return maxOnes;
}

// * Single Number
int findSingleNumber(std::vector<int> arr) {
  int n = arr.size();
  int l = 0, r = n-1;
  while(l <= r) {
    int m = l + (r-l)/2;
    if(arr[m] != arr[m+1] && arr[m] != arr[m-1]) {
      return arr[m];
    }
    else if((m % 2 == 0 && arr[m] == arr[m+1]) || (m % 2 == 1 && arr[m] == arr[m-1])) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return -1;
}

// * two Single Number
std::vector<int> findSingleNumber2(std::vector<int> a) {
  int n = a.size();
  int l=0, r=n-1;
  std::vector<int> ans;
  while(l <= r) {
    int m = l + (r-l)/2;
    std::cout<<m<<" ";
    if(a[m] != a[m-1] && a[m] != a[m+1]) {
      ans.push_back(a[m]);
    }
    else if((m%2==0 && a[m] == a[m+1]) || (m%2==1 && a[m] == a[m-1])) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return ans;

}

// * Longest Subarray With Sum K
int findLongestSubarraySumV1(std::vector<int> arr, int k) {
  int n = arr.size(), prefixSum = 0, cnt = 0;
  std::map<int, int> prefixMap;
  for(int i=0; i<n; i++) {
    prefixSum += arr[i];
    if(prefixSum == k) {
      cnt = std::max(cnt, i+1);
    }
    int rem = prefixSum - k;
    if(prefixMap.find(rem) != prefixMap.end()) {
      cnt = std::max(cnt, i-prefixMap[rem]);
    }
    if(prefixMap.find(prefixSum) == prefixMap.end()) {
      prefixMap[prefixSum] = i;
    }
  }
  return cnt;
}

// * Longest Subarray With Sum K
int findLongestSubarraySumV2(std::vector<int> arr, int k) {
  int n = arr.size();
  int j = 0, sum = 0, cnt = 0;
  for(int i=0; i<n; i++) {

    while(sum > k) {
      sum -= arr[j];
      j++;
    }

    sum += arr[i];
    if(sum == k) {
      cnt = std::max(cnt, i-j+1);
    }

  }
  return cnt;
}

int main() {
  // * Problem 1 
  // std::vector<int> arr = {8, 3, 7, 2, 6};
  // printArr(arr);
  // int secondLargestEle = findSecondLargestElement(arr);
  // std::cout<<"2nd Largest Element: "<<secondLargestEle<<std::endl;
  // int secondSmallestEle = findSecondSmallestElement(arr);
  // std::cout<<"2nd Smallest Element: "<<secondSmallestEle<<std::endl;

  // * Problem 2
  // std::vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 5, 5};
  // printArr(arr);
  // removeDuplicates(arr);
  // printArr(arr);

  // * Problem 3
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // printArr(arr);
  // rotateByOne(arr);
  // printArr(arr);

  // * Problem 4
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // int k = 7;
  // printArr(arr);
  // rotateByKPlaces(arr, k);
  // rotateByKPlacesOptimal(arr, k);
  // printArr(arr);

  // * Problem 5
  // std::vector<int> arr = {1, 2, 0, 0, 2, 3};
  // std::vector<int> arr = {0, 0, 0, 1};
  // printArr(arr);
  // moveZerosToEnd(arr);
  // printArr(arr);

  // * Problem 6
  // std::vector<int> a = {3, 3, 4, 5, 6, 7, 8, 9, 9, 9};
  // std::vector<int> b = {2, 4, 10, 10};
  // std::cout<<"Array B = ";
  // printArr(a);
  // std::cout<<"Array A = ";
  // printArr(b);
  // std::vector<int> ans = mergeTwoSortedArrays(a, b);
  // std::cout<<"Merged Array = ";
  // printArr(ans);

  // * Problem 7
  // std::vector<int> arr = {3, 0, 1};
  // std::vector<int> arr = {4, 6, 7, 9, 2, 1, 8, 11, 10, 3, 0};
  // printArr(arr);
  // int missingNumber = findMissingNumber(arr);
  // std::cout<<"Missing Number "<<missingNumber<<std::endl;

  // * Problem 8
  // std::vector<int> arr = {1, 1, 0, 1, 1, 1};
  // printArr(arr);
  // int maxOnes = findMaxConsecutiveOnes(arr);
  // std::cout<<"Max Consecutive Ones "<<maxOnes<<std::endl;

  // * Problem 9
  // std::vector<int> arr = { 1, 1, 2, 2, 3, 3, 6, 6, 7, 9, 9 };
  // std::vector<int> arr = {1, 2, 1, 1};
  // printArr(arr);
  // int singleNumber = findSingleNumber(arr);
  // std::cout<<"Single Number "<<singleNumber<<std::endl;

  // TODO Problem 10
  // std::vector<int> arr = { 2, 4, 6, 8, 10, 2, 6, 10 };
  // printArr(arr);
  // std::vector<int> ans = findSingleNumber2(arr);
  // printArr(ans);

  // * Problem 11
  // std::vector<int> arr = { 1, 2, 3, 1, 1, 1, 1 };
  // int k = 3;
  // std::vector<int> arr = {2, 2, 4, 1, 2};
  // int k = 2;
  // printArr(arr);
  // int longestSubarray = findLongestSubarraySumV1(arr, k);
  // int longestSubarray = findLongestSubarraySumV2(arr, k);
  // std::cout << "Longest subarray sum " << longestSubarray << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice