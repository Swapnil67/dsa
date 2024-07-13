#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

int checkNthRoot(int power, int mid, int m) {
  long long nthRoot = 1;
  for (int i = 1; i <= power; i++) {
    nthRoot = mid * nthRoot;
    if(nthRoot > m) {
      return 1;
    }
  }

  if (nthRoot == (long long)m) {
    return 0;
  }
  return 2;
}

// * ----------- Search In Rotated Sorted Array -----------

int searchInRotatedSortedB(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == target) {
      return m;
    }
    if(arr[l] == arr[m] && arr[r] == arr[m]) {
      // * Shrink here
      l++, r--;
    }
    else if(arr[l] <= arr[m]) {
      // * Left part is sorted
      if(arr[l] <= target && target <= arr[m]) {
        // * Exists in left part
        r = m - 1;
      }
      else {
        l = m + 1;
      }
    }
    else {
      // * Right part is sorted
      if(arr[m] <= target && target <= arr[r]) {
        // * Exists in right
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
  }
  return -1;
}

// * ----------- Minimum in rotated sorted array -----------

int minInRotatedSorted(std::vector<int> arr)  {
  int n = arr.size();
  if(n == 1) return arr[0];
  int l = 0, r = n - 1;
  int low = INT_MAX;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if(arr[l] == arr[m] && arr[m] == arr[r]) {
      l++, r--;
    }
    else if(arr[l] <= arr[m]) {
      // * left part is sorted
      low = std::min(arr[l], low);
      l = m + 1;
    }
    else {
      // * right part is sorted
      low = std::min(arr[m], low);
      r = m - 1;
    }
  }
  return low;
}

// * ----------- count of rotation -----------

int countRotation(std::vector<int> arr) {
  int n = arr.size();
  int l = 0, r = n - 1;
  int low = INT_MAX, c = INT_MAX;

  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[l] <= arr[m]) {
      if(arr[l] < low) {
        low = arr[l];
        c = l;
      }
      l = m + 1;
    }
    else {
      if(arr[m] < low) {
        low = arr[m];
        c = m;
      }
      r = m - 1;
    }
  }
  return c;
}

// * ----------- Peak Element -----------

int findPeakElement(std::vector<int> arr) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1]) {
      return arr[m];
    }
    else if (arr[m] > arr[m - 1]) {
      // * Increasing curve
      l = m + 1;
    }
    else {
      // * Decreasing curve
      r = m - 1;
    }
  }
  return -1;
}

// * ----------- Square Root -----------

int findSquareRoot(int n) {
  int l = 1, r = n;
  int ans = n;
  while (l <= r) {
    int m = l + (r - l) / 2;
    int val = m * m;
    if(val == n) {
      ans = m;
      break;
    }
    if(val <= n) {
      ans = m;
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return ans;
}

// * ----------- nth Root -----------

int findNthRoot(int n, int m) {
  int l = 1, r = m;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    int check = checkNthRoot(n, mid, m);
    if(check == 0) {
      return mid;
    }
    else if(check == 1) {
      r = mid - 1;
    }
    else {
      l = m  + 1;
    }
  }
  return -1;
} 

// * ----------- Single Element -----------

int singleElement(std::vector<int> arr) {
  int n = arr.size();
  if(n == 1) return arr[0];
  else if(arr[0] != arr[1]) {
    return arr[0];
  }
  else if(arr[n-1] != arr[n-2]) {
    return arr[n-1];
  }
  int l = 0, r = n - 1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] != arr[m - 1] && arr[m] != arr[m + 1]) {
      return arr[m];
    }
    else if ((m % 2 == 0 && arr[m] == arr[m + 1]) || (m % 2 == 1 && arr[m] == arr[m - 1])) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }

  return -1;

}


int main() {

  // * Problem 1
  // * Search In Rotated Sorted Array (B)
  // std::cout << "----------- Search In Rotated Sorted Array II -----------" << std::endl;
  // * testcase 1
  // int target = 1;
  // std::vector<int> arr = {3, 1, 2, 3, 3, 3, 3};
  // * testcase 2
  // int target = 8;
  // std::vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
  // * testcase 3
  // int target = 0;
  // std::vector<int> arr = {2, 5, 6, 0, 0, 1, 2};
  // printArr(arr);
  // int idx = searchInRotatedSortedB(arr, target);
  // std::cout << "Index " << idx << std::endl;

  // * Problem 2
  // * Find Minimum in rotated sorted array
  // std::cout << "Minimum in rotated sorted array" << std::endl;
  // std::vector<int> arr = {10, 1, 10, 10, 10};
  // std::vector<int> arr = {2, 3, 4, 1};
  // std::vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
  // std::vector<int> arr = {25, 30, 5, 10, 15, 20};
  // printArr(arr);
  // int minEle = minInRotatedSorted(arr);
  // std::cout << "Minimum in rotated sorted: " << minEle << std::endl;

  // * Problem 3
  // * Count of rotation
  // std::cout << "Count of rotation" << std::endl;
  // std::vector<int> arr = {2, 3, 4, 1};
  // std::vector<int> arr = {5, 6, 0, 1, 2};
  // printArr(arr);
  // int count = countRotation(arr);
  // std::cout << "Rotation Count " << count << std::endl;

  // * Problem 4
  // * Peak Element
  // std::cout << "Peak Element" << std::endl;
  // std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
  // std::vector<int> arr = {1, 10, 13, 7, 6, 5, 4, 2, 1, 0};
  // printArr(arr);
  // int peakEle = findPeakElement(arr);
  // std::cout << "Peak Element: " << peakEle << std::endl;

  // * Problem 5
  // * Sqr Root
  // int n = 7;
  // std::cout << "Square Root" << std::endl;
  // int sqRoot = findSquareRoot(n);
  // std::cout<<"Square root of "<<n<<" is "<<sqRoot<<std::endl;

  // * Problem 6
  // * nth Root
  // int n = 9, m = 1953125;
  // int n = 5, m = 32768;
  // int n = 3, m = 27;
  // std::cout << "nth Root" << std::endl;
  // int nthRoot = findNthRoot(n, m);
  // std::cout << n << " Root of " << m << " is " << nthRoot << std::endl;

  // * Problem 7
  // * Single Element
  std::cout << "Single Element" << std::endl;
  // std::vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  std::vector<int> arr = {1, 2, 2, 3, 3};
  printArr(arr);
  int ans = singleElement(arr);
  std::cout << "Single Element " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice

