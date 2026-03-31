// ! Binary Search Easy Practice 

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &nums) {
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * 09 - Square Root of a number
// int findSquareRoot(int n) {
// TODO
// }

// * 10 - Kth Missing Positive Number 
// int findKthMissingNumber(vector<int> &nums, int k) {
// TODO
// }

// * -----------------------------------------------------------------------------

// * 01 - Binary Search
// int binarySearch(vector<int> nums, int target) {
// TODO
// }

// * 02 - Lower Bound
int findLowerBound(vector<int> &nums, int x) {
  int n = nums.size();
  int l = 0, r = n - 1;
  int ans = n;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] >= x) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return ans;
}

// * 03 - Upper Bound
int findUpperBound(vector<int> &nums, int x) {
  int n = nums.size();
  int l = 0, r = n - 1;
  int idx = n;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] > x) {
      idx = m - 1;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return idx;
}

// * 04 - Search Insert Position
// int findInsertIndex(vector<int> nums, int x) {
// TODO
// }

// * 05 - Ceil The Floor
// pair<int, int> getFloorAndCeil(vector<int> &nums, int x) {
// TODO
// }

// * 06 - First and Last Position of an Element In Sorted Array
// pair<int, int> firstAndLastOccurence(vector<int> &nums, int k) {
// TODO
// }

// * 07 - Count Occurences
// int countOccurences(std::vector<int> &nums, int x) {
// TODO
// }

// * 08 - Square Root of a number
// int findSquareRoot(int n) {
// TODO
// }

// * 08 - Square Root of a number
// int findSquareRoot(int n) {
// TODO
// }

int main() {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output