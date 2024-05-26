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

int findSecondLargestEle(std::vector<int> arr) {
  int n = arr.size();
  int maxI = INT_MIN, secondMax = INT_MIN;
  for(int i=0; i<n; i++) {
    if(arr[i] > maxI) {
      secondMax = maxI;
      maxI = arr[i];
    }
    else if(arr[i] > secondMax) {
      secondMax = arr[i];
    }
  }
  return secondMax;
}

int findSecondSmallestEle(std::vector<int> arr) {
  int n = arr.size();
  int minI = INT_MAX, secondMin = INT_MAX;
  for(int i=0; i<n; i++) {
    if(arr[i] < minI) {
      secondMin = minI;
      minI = arr[i];
    }
    else if(arr[i] < secondMin) {
      secondMin = arr[i];
    }
  }
  return secondMin;
}

// * Remove Duplicates
int removeDuplicates(std::vector<int> &arr) {
  int n = arr.size();
  int i=0;
  for(int j=1; j<n; j++) {
    if(arr[i] != arr[j]) {
      arr[i+1] = arr[j];
      i++;
    }
  }
  return i+1;
}

// * Rotate the array by one place
void rotateByOne(std::vector<int> &arr) {
  int n = arr.size();
  int firstEle = arr[0];
  int i = 1;
  for(i=1; i<n; i++) {
    arr[i-1] = arr[i];
  }
  arr[n-1] = firstEle;
}

// * Rotate the array by k places
void rotateByKPlaces(std::vector<int> &arr, int k) {
  // TODO Tomorrow
}

// * Move zeros to end
void moveZerosToEnd(std::vector<int> &arr) {
  int n = arr.size();
  int j = -1;
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

// * Merge 2 Sorted Array
std::vector<int> mergeSortedArrays(std::vector<int> a, std::vector<int> b) {
  int i = 0, j = 0;
  int n1 = a.size(), n2 = b.size();
  int last = -1;
  std::vector<int> ans;

  while(i < n1 && j < n2) {
    // std::cout << i << " -> " << a[i] << " " << j << " -> " << b[j] << std::endl;
    if(a[i] >= b[j]) {
      if(last != b[j]) {
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

  // * Check if any elements remaining in 'a'
  while(i < n1) {
    if(last != a[i]) {
      ans.push_back(a[i]);
      last = a[i];
    }
    i++;
  }

  // * Check if any elements remaining in 'b'
  while(j < n2) {
    if(last != b[j]) {
      ans.push_back(b[j]);
      last = b[j];
    }
    j++;
  }

  return ans;
}


// * Missing Number
int findMissingNumber(std::vector<int> arr) {
  int maxEle = INT_MIN;
  int n = arr.size();
  for(int i=0; i<n; i++) {
    maxEle = std::max(maxEle, arr[i]);
  }

  std::vector<int> hashedArr(maxEle, 0);
  for(int i=0; i<n; i++) {
    hashedArr[arr[i]] = 1;
  }
  
  for(int i=0; i<hashedArr.size(); i++) {
    if(hashedArr[i] == 0) return i;
  }

  return -1;
}

// * Max Consecutive Ones
int maxConsecutiveOnes(std::vector<int> arr) {
  int n = arr.size();
  int maxOnes = INT_MIN, sum = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] == 1) {
      sum++;
      maxOnes = std::max(maxOnes, sum);
    }
    else {
      sum = 0;
    }
  }
  return maxOnes;
}

// * Find the single number
int findSingleNumber(std::vector<int> arr) {
  int n = arr.size();
  int l = 0, r = n-1;
  while(l <= r) {
    int m = (l+r)/2;
    if (arr[m] != arr[m - 1] && arr[m] != arr[m + 1]) {
      return arr[m];
    }
    else if (m % 2 == 1 && arr[m] == arr[m - 1]) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return -1;
}

// * Longest Subarray With Sum K
// * Prefix Sum
int findLongestSubarraySumV1(std::vector<int> arr, int k) {
  int n = arr.size();
  std::map<int, int> sumMap;
  int prefixSum = 0, longestCount = INT_MIN;
  for(int i=0; i<n; i++) {
    prefixSum += arr[i];
    if(prefixSum == k) {
      longestCount = std::max(longestCount, i+1);
    }

    int rem = prefixSum - k;
    if(sumMap.find(rem) != sumMap.end()) {
      longestCount = std::max(longestCount, (i-sumMap[rem]));
    }

    if(sumMap.find(prefixSum) == sumMap.end()) {
      sumMap[prefixSum] = i;
    }
  }

  return longestCount;
}

// * Longest Subarray With Sum K
// * Two Pointer
int findLongestSubarraySumV2(std::vector<int>arr, int k) {
  int n = arr.size();
  int i = 0, j = 0, sum = 0, count = 0;

  while(j < n) {
    if(j < n)
      sum += arr[j];

    while(sum > k) {
      sum -= arr[i];
      i++;
    }

    if(sum == k) {
      count = std::max(count, (j-i)+1);
    }

    j++;
  } 
  return count;
}

std::vector<int> findTwoSum(std::vector<int> arr, int target) {
  int n = arr.size();
  std::map<int, int>hash;
  for(int i=0; i<n; i++) {
    int rem = target - arr[i];
    if(hash.find(rem) != hash.end()) {
      return { hash[rem], i };
    }
    hash[arr[i]] = i;
  }
  return {};
}

int main() {
  // * Problem 1
  // std::vector<int> arr = {8, 3, 7, 2, 6};
  // int secondLargestEle = findSecondLargestEle(arr);
  // std::cout<<"2nd Largest Element: "<<secondLargestEle<<std::endl;
  // int secondSmallestEle = findSecondSmallestEle(arr);
  // std::cout<<"2nd Smallest Element: "<<secondSmallestEle<<std::endl;
  
  // * Problem 2
  // std::vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 5, 5};
  // printArr(arr);
  // int uniqueElements = removeDuplicates(arr);
  // std::cout<<"Unique Element: "<<uniqueElements<<std::endl;

  // * Problem 3
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // printArr(arr);
  // rotateByOne(arr);
  // printArr(arr);

  // * Problem 5
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // printArr(arr);
  // rotateByKPlaces(arr, 3);
  // printArr(arr);

  // * Problem 6
  // std::vector<int> arr = {1, 2, 0, 0, 2, 3};
  // std::vector<int> arr = {1, 0, 2, 3, 0, 0, 4};
  // printArr(arr);
  // moveZerosToEnd(arr);
  // printArr(arr);

  // * Problem 7
  // std::vector<int> a = {1, 2, 2, 3, 3, 3, 4, 6, 7, 7, 7}, b = {2, 3, 5};
  // printArr(a);
  // printArr(b);
  // std::vector<int> ans = mergeSortedArrays(a, b);
  // printArr(ans);

  // * Problem 8
  // std::vector<int> arr = {3, 0, 1};
  // std::vector<int> arr = { 4, 6, 7, 9, 2, 1, 8, 11, 10, 3, 0 };
  // printArr(arr);
  // int missingNumber = findMissingNumber(arr);
  // std::cout<<"Missing Number "<<missingNumber<<std::endl;

  // * Problem 9
  // std::vector<int> arr = {1, 1, 0, 1, 1, 1};
  // std::vector<int> arr = {1, 0, 1, 1, 0, 1};
  // printArr(arr);
  // int maxOnes = maxConsecutiveOnes(arr);
  // std::cout<<"Max Consecutive Ones "<<maxOnes<<std::endl;

  // * Problem 10
  // std::vector<int> arr = { 1, 1, 2, 2, 3, 3, 6, 6, 7, 9, 9 };
  // std::vector<int> arr = { 1, 1, 2, 3, 3, 4, 4 };
  // printArr(arr);
  // int singleNumber = findSingleNumber(arr);
  // std::cout<<"Single Number "<<singleNumber<<std::endl;

  // * Problem 11
  // std::vector<int> arr = {1, 2, 3, 1, 1, 1};
  // std::vector<int> arr = {2, 0, 0, 0, 0, 3};
  // int k = 3;
  // printArr(arr);
  // int longestSubarray = findLongestSubarraySumV1(arr, k);
  // int longestSubarray = findLongestSubarraySumV2(arr, k);
  // std::cout << "Longest subarray sum " << longestSubarray << std::endl;


  // * Problem 12
  // std::vector<int> arr = {3, 4, 5, 6};
  // int target = 7;
  // std::vector<int> arr = {4, 5, 3, 6};
  // int target = 10;
  // printArr(arr);
  // std::vector<int> ans = findTwoSum(arr, target);
  // printArr(ans);

  

}

// * Run the code
// * g++ --std=c++17 practice2.cpp -o practice2 && ./practice2