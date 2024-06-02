#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * Binary Search
int binarySearch(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] == target) {
      return m;
    }
    else if(arr[m] > target) {
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return -1;
}

// * Lower Bound
int findLowerBound(std::vector<int> arr, int target) {
  int n = arr.size();
  int ans = n, l = 0, r = n - 1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] >= target) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

// * Upper Bound
int findUpperBound(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1, ans = n;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] > target) {
      std::cout << "m " << m << std::endl;
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

// * Floor of value
// * Floor = Greatest element smaller than x
int findFloor(std::vector<int>arr, int n, int target) {
  int l = 0, r = n - 1;
  int ans = -1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] <= target) {
      ans = m;
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return ans;
}

// * Ceil of value (Lower Bound)
// * Ceil = Smallest element greater than x
int findCeil(std::vector<int>arr, int n, int target) {
  int l = 0, r = n - 1;
  int ans = -1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] >= target) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

// * Floor & Ceil
std::pair<int, int> getFloorAndCeil(std::vector<int> arr, int target) {
  int n = arr.size();
  int floorIdx = findFloor(arr, n, target);
  int ceilIdx = findCeil(arr, n, target);
  std::pair<int, int> ans(floorIdx, ceilIdx);
  return ans;
}

// * First Occurence
int findFirstOccurence(std::vector<int> arr, int n, int target) {
  int l = 0, r = n - 1;
  int ans = -1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] >= target) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

// * Last Occurence
int findLastOccurence(std::vector<int> arr, int n, int target) {
  int l = 0, r = n - 1;
  int ans = -1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] <= target) {
      ans = m;
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return ans;
}

// * First & Last Occurence
std::pair<int, int> getFirstAndLastOccurence(std::vector<int> arr, int target) {
  int n = arr.size();
  int firstOccurence = findFirstOccurence(arr, n, target);
    // * If k not found
  if(firstOccurence == -1) {
    return { -1, -1 };
  }
  int lastOccurence = findLastOccurence(arr, n, target);
  std::pair<int, int> ans(firstOccurence, lastOccurence);
  return ans;
}

// * Search In Rotated Sorted Array (A)
// ! Array does not have duplicates
int searchInRotatedSortedA(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] == target) {
      return m;
    }
    else if(arr[l] <= arr[m]) {
      // * Left part is sorted
      if(arr[l] <= target && target <= arr[m]) {
        // * Element is present in LHS
        r = m - 1;
      }
      else {
        // * Element is present in RHS
        l = m + 1;
      }
    }
    else {
      // * Right part is sorted
      if(arr[m] <= target && target <= arr[r]) {
        // * Element is present in RHS
        l = m + 1;
      }
      else {
        // * Element is present in LHS
        r = m - 1;
      }
    }
  }
  return -1;
}

// * Search In Rotated Sorted Array (B)
// ! Array has duplicates
int searchInRotatedSortedB(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while(l <= r) {
    int m = l + (r - l)/2;

    // * If arr[l] == arr[m] == arr[r]
    if(arr[l] == arr[m] && arr[m] == arr[r]) {
      l++, r--;
      continue;
    }

    if(arr[m] == target) {
      return m;
    }
    else if(arr[l] <= arr[m]) {
      // * Left part is sorted
      if(arr[l] <= target && target <= arr[m]) {
        // * target exists in LHS
        r = m - 1;
      }
      else {
        // * target exists in RHS
        l = m + 1;
      }
    }
    else {
      // * Right part is sorted
      if(arr[m] <= target && target <= arr[r]) {
        // * target exists in RHS
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
  }
  return -1;
}

// * Find minimum in rotated sorted array
int minInRotatedSorted(std::vector<int> arr) {
  int n = arr.size();
  int l = 0, r = n - 1;
  int minEle = INT_MAX;
  while(l <= r) {
    int m = l + (r - l) / 2;

    // * Search space is sorted
    if(arr[l] <= arr[r]) {
      minEle = std::min(minEle, arr[l]);
      break;
    }

    if(arr[l] <= arr[m]) {
      // * Left part is sorted
      minEle = std::min(minEle, arr[l]);
      l = m + 1;
    }
    else {
      // * Right part is sorted
      minEle = std::min(minEle, arr[m]);
      r = m - 1;
    }
  }
  return minEle;
}

int main() {
  // * Problem 1
  // * Binary Search
  // std::vector<int> arr = {-1, 0, 3, 5, 9, 12};
  // int target = 5;
  // printArr(arr);
  // int idx = binarySearch(arr, target);
  // std::cout<<"Index "<<idx<<std::endl;

  // * Problem 2
  // * Lower Bound
  // std::vector<int> arr = {1, 2, 2, 3, 3, 5, 6};
  // int target = 6;
  // printArr(arr);
  // int lowerBound = findLowerBound(arr, target);
  // std::cout<<"Lower Bound of "<<target<<" is "<<lowerBound<<std::endl;

  // * Problem 3
  // * Upper Bound
  // std::vector<int> arr = {1, 2, 2, 3, 3, 5, 6};
  // int target = 5;
  // printArr(arr);
  // int lowerBound = findUpperBound(arr, target);
  // std::cout<<"Lower Bound of "<<target<<" is "<<lowerBound<<std::endl;

  // * Problem 4
  // * Search Insert Index
  // * This is same as lower bound

  // * Problem 5
  // * Find Floor & Ceil
  // std::vector<int> arr = {1, 2, 3, 4, 8, 10, 10, 12, 19};
  // int x = 5;
  // printArr(arr);
  // std::pair<int, int> ans = getFloorAndCeil(arr,x);
  // std::cout << "Floor Element: " << ans.first << std::endl;
  // std::cout << "Ceil Element: " << ans.second << std::endl;
  
  // * Problem 6
  // * Find First & Last
  // std::vector<int> arr = { 0, 1, 1, 5 };
  // int x = 1;
  // printArr(arr);
  // std::pair<int, int> ans = getFirstAndLastOccurence(arr,x);
  // std::cout << "First Occurence: " << ans.first << std::endl;
  // std::cout << "Last Occurence: " << ans.second << std::endl;

  // * Problem 7
  // * Search In Rotated Sorted Array (A)
  // std::vector<int> arr = {4, 5, 6, 0, 1, 2};
  // int target = 0;
  // std::vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
  // int target = 8;
  // std::vector<int> arr = {3, 1, 2, 3, 3, 3, 3};
  // int target = 1;
  // printArr(arr);
  // int idx = searchInRotatedSortedA(arr, target);
  // std::cout<<"Index "<<idx<<std::endl;
  
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
  std::vector<int> arr = {2, 3, 4, 1};
  // std::vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
  // std::vector<int> arr = {25, 30, 5, 10, 15, 20};
  printArr(arr);
  int minEle = minInRotatedSorted(arr);
  std::cout<<"Minimum in rotated sorted: "<<minEle<<std::endl;

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

