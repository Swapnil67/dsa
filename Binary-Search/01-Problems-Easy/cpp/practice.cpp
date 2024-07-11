#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}


// * ------------- Binary Search -------------
int binarySearch(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while(l <= r) {
    int m = (l + r) / 2;
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


// * ------------- Lower Bound -------------
int findLowerBound(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1, ans = n;
  while(l <= r) {
    int m = (l + r) / 2;
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

// * ------------- Upper Bound -------------
int findUpperBound(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1, ans = n;
  while(l <= r) {
    int m = (l + r) / 2;
    if(arr[m] > target) {
      r = m - 1;
      ans = m;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

// * ------------- Search Index -------------
int findInsertIndex(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1, ans = n;
  while(l <= r) {
    int m = (l + r) / 2;
    if(arr[m] >= target) {
      r = m - 1;
      ans = m;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

// * ------------- Find Floor & Ceil -------------
int findFloor(std::vector<int> arr, int n, int x) {
  int l = 0, r = n - 1, ans = n;
  while(l <= r) {
    int m = (l + r) / 2;
    if(arr[m] == x) {
      return arr[m];
    }
    else if(arr[m] < x) {
      ans = m;
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return ans;
}

int findCeil(std::vector<int> arr, int n, int x) {
  int l = 0, r = n - 1, ans = n;
  while(l <= r) {
    int m = (l + r) / 2;
    if(arr[m] > x) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

std::pair<int, int> getFloorAndCeil(std::vector<int> arr, int x) {
  int n = arr.size();
  int floor = findFloor(arr, n , x);
  int ceil = findCeil(arr, n , x);
  return {floor, ceil};
}

// * ------------- Find First & Last -------------

int findFirstOccurence(std::vector<int> arr, int n, int x) {
  int l = 0, r = n - 1, ans = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] >= x) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

int findlastOccurence(std::vector<int> arr, int n, int x) {
  int l = 0, r = n - 1, ans = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] <= x) {
      ans = m;
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return ans;
}

std::pair<int, int> getFirstAndLastOccurence(std::vector<int> arr, int x)  {
  int n = arr.size();
  int first = findFirstOccurence(arr, n, x);
  if(first == -1) {
    return {-1, -1};
  }
  int last = findlastOccurence(arr, n, x);
  return {first, last};
}

// * ----------- Search In Rotated Sorted Array -----------

int searchInRotatedSortedA(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] == target) {
      return m;
    }
    else if(arr[l] <= arr[m]) {
      // * Left part is sorted
      if(arr[l] <= target && target <= arr[m]) {
        r = m - 1;
      }
      else {
        l = m + 1;
      }
    }
    else {
      // * Right part is sorted
      if(arr[m] <= target && target <= arr[r]) {
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
  }
  return -1;
}

int main() {
  // * Problem 1
  // * Binary Search
  // std::vector<int> arr = {-1, 0, 3, 5, 9, 12};
  // int target = 5;
  // printArr(arr);
  // int idx = binarySearch(arr, target);
  // std::cout<< target <<" exists on index "<<idx<<std::endl;

  // * Problem 2
  // * Lower Bound
  // std::vector<int> arr = {1, 2, 2, 3, 3, 5, 6};
  // int target = 3;
  // printArr(arr);
  // int lowerBound = findLowerBound(arr, target);
  // std::cout<<"Lower Bound of "<<target<<" is "<<lowerBound<<std::endl;

  // * Problem 3
  // * Upper Bound
  // std::vector<int> arr = {1, 2, 2, 3, 3, 5, 6};
  // int target = 3;
  // printArr(arr);
  // int lowerBound = findUpperBound(arr, target);
  // std::cout<<"Upper Bound of "<<target<<" is "<<lowerBound<<std::endl;

  // * Problem 4
  // * Search Insert Index
  // * This is same as lower bound
  // int target = 2;
  // std::vector<int> arr = {1, 2, 4, 7};
  // printArr(arr);
  // int insertIndex = findInsertIndex(arr, target);
  // std::cout<<"Insert Index: "<<insertIndex<<std::endl;

  // * Problem 5
  // * Find Floor & Ceil
  // std::vector<int> arr = {1, 2, 3, 4, 8, 10, 10, 12, 19};
  // int x = 4;
  // printArr(arr);
  // std::pair<int, int> ans = getFloorAndCeil(arr,x);
  // std::cout << "Floor of " << x << " is: " << ans.first << std::endl;
  // std::cout << "Ceil of " << x << " is: " << ans.second << std::endl;
  
  // * Problem 6
  // * Find First & Last
  // int x = 10;
  // std::vector<int> arr = { 0, 1, 1, 5 };
  // printArr(arr);
  // std::pair<int, int> ans = getFirstAndLastOccurence(arr,x);
  // std::cout << "First Occurence of " << x << " is " << ans.first << std::endl;
  // std::cout << "Last Occurence of " << x << " is " << ans.second << std::endl;

  // * Problem 7
  // * Search In Rotated Sorted Array (A)
  // std::cout << "----------- Search In Rotated Sorted Array I -----------" << std::endl;
  // int target = 0;
  // std::vector<int> arr = {4, 5, 6, 0, 1, 2};
  // int target = 8;
  // std::vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
  // ! Below testcase will fail 
  // int target = 1;
  // std::vector<int> arr = {3, 1, 2, 3, 3, 3, 3};
  // printArr(arr);
  // int idx = searchInRotatedSortedA(arr, target);
  // std::cout << "Index " << idx << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice

