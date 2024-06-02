/*
 * Ceil The Floor
 * You're given a sorted array 'a' of 'n' integers and an integer 'x'.
 * Find the floor and ceiling of 'x' in 'a[0..n-1]'.

 * Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
 * Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.

 * 
 * Example 1:
 * Input: arr = [3, 4, 7, 8, 8, 10],  x = 5
 * Output: [4,8]

 * Example 2:
 * Input: arr = [ 3, 4, 4, 7, 8, 10 ], x = 2
 * Output: [-1,3]
 * 
 * https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401
*/

// * Floor = Greatest element smaller than x
// * Ceil = Smallest element greater than x

#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * Smallest element greater than equal x
// * TIME COMPLEXITY O(logn)
int findCeil(std::vector<int> arr, int x) {
  int n = arr.size();
  int l = 0, r = n-1;
  int ceilEle = -1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] >= x) {
      ceilEle = arr[m];
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }

  return ceilEle;
}


// * Floor = Greatest element smaller than x
// * TIME COMPLEXITY O(logn)
int findFloor(std::vector<int> arr, int x) {
  int n = arr.size();
  int l = 0, r = n - 1;
  int floor_ele = -1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] == x) {
      return arr[m];
    }
    else if(arr[m] < x) {
      floor_ele = arr[m];
      l = m + 1;
    }
    else {
      // * Element greater than x
      r = m - 1;
    }
  }
  return floor_ele;
}

// * TIME COMPLEXITY O(2logn)
std::pair<int, int> getFloorAndCeil(std::vector<int>arr, int x) {
  int floorEle = findFloor(arr, x);
  int ceilEle = findCeil(arr, x);
  std::pair<int, int> ans(floorEle, ceilEle);
  return ans;
}

int main() {
  std::vector<int> arr = {1, 2, 3, 4, 8, 10, 10, 12, 19};
  int x = 5;
  // std::vector<int> arr = {3, 4, 4, 7, 8, 10};
  // int x = 2;
  printArr(arr);
  std::pair<int, int> ans = getFloorAndCeil(arr, x);
  std::cout<<"Floor Element: "<<ans.first<<std::endl;
  std::cout<<"Ceil Element: "<<ans.second<<std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 05-find-floor-and-ceil.cpp -o 05-find-floor-and-ceil && ./05-find-floor-and-ceil