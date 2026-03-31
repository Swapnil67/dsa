/*
* Leetcode - 4
* Median of Two Sorted Arrays
*
* Given two sorted arrays nums1 and nums2 of size m and n respectively,
* return the median of the two sorted arrays.
*
* Example 1:
* Input: nums1 = [1,2], nums2 = [3,4]
* Output: 2.5
* Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5
*
* Example 2:
* Input: nums1 = [1, 3, 4, 7, 10, 12], nums2 = [2, 3, 6, 15]
* Output: 5
* Explanation: merged array = [1,2,3,3,4,6,7,10,12,15] and median is (6 + 4) / 2 = 5
*
* https://www.naukri.com/code360/problems/median-of-two-sorted-arrays_985294
* https://leetcode.com/problems/median-of-two-sorted-arrays/description/ 
*/

// ! Amazon, Google, Meta, Microsoft, Adobe, IBM, Apple, Oracle

#include <vector>
#include <climits>
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

vector<int> mergeTwoSortedArrays(vector<int> arr1, vector<int> arr2) {
  int n1 = arr1.size(), n2 = arr2.size();
  vector<int> ans;
  int i = 0, j = 0;
  while(i < n1 && j < n2) {
    if(arr1[i] <= arr2[j])
      ans.push_back(arr1[i++]);
    else
      ans.push_back(arr2[j++]);
  }

  // * Put the remaining elements for arr1 
  while(i < n1) {
    ans.push_back(arr1[i++]);
  }

  // * Put the remaining elements for arr2
  while(j < n2) {
    ans.push_back(arr2[j++]);
  }

  return ans;
}

pair<int, int> returnMedianPositions(vector<int> a, vector<int> b) {
  int n1 = a.size(), n2 = b.size();
  int n3 = n1 + n2;
  int idx2 = n3 / 2;
  int idx1 = idx2 - 1;
  int i = 0, j = 0, cnt = 0;
  int ele1, ele2;
  while (i < n1 && j < n2) {
    if(a[i] < b[j]) {
      if (cnt == idx1) ele1 = a[i];
      if (cnt == idx2) ele2 = a[i];
      i++;
    } else {
      if (cnt == idx1) ele1 = b[j];
      if (cnt == idx2) ele2 = b[j];
      j++;
    }
    cnt++;
  }

  while(i < n1) {
    if (cnt == idx1) ele1 = a[i];
    if (cnt == idx2) ele2 = a[i];
    cnt++;
    i++; 
  }

  while(j < n2) {
    if (cnt == idx1) ele1 = b[j];
    if (cnt == idx2) ele2 = b[j];
    cnt++;
    j++;
  }
  return { ele1, ele2 };
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Merge two sorted arrays
// * TIME COMPLEXITY O(n1 + n2)
// * SPACE COMPLEXITY O(n1 + n2)
double bruteForce(vector<int> arr1, vector<int> arr2) {
  vector<int> merged_arr = mergeTwoSortedArrays(arr1, arr2);
  int n = merged_arr.size();
  if (n % 2 == 1) {  // * Odd Arr
    return merged_arr[n / 2];
  }
  // * Even Arr
  return (double)((double)merged_arr[n / 2] + double(merged_arr[n / 2 - 1])) / 2.0;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------
// * Not using extra array (Merged Array)
// * TIME COMPLEXITY O(n1 + n2) * O(N) 
// * SPACE COMPLEXITY O(1)
double betterApproach(vector<int> arr1, vector<int> arr2) {
  int n1 = arr1.size(), n2 = arr2.size();
  auto [ele1, ele2] = returnMedianPositions(arr1, arr2);
  
  int n = n1 + n2;
  if (n % 2 == 1)
    return ele1;

  return (double)((double)(ele1 + ele2) / 2.0);
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------
// * Find Valid Symmetry
// * TIME COMPLEXITY O(log(min(n1, n2)))
// * SPACE COMPLEXITY O(1)
double findMedian(vector<int> arr1, vector<int> arr2) {
  int n1 = arr1.size(), n2 = arr2.size();
  if (n1 > n2)
    findMedian(arr2, arr1);

  int left = (n1 + n2 + 1) / 2;
  int n = n1 + n2;
  
  int l = 0, r = n1;
  while (l <= r) {
    cout << "l: " << l << ", r: " << r << endl;
    int m1 = l + (r - l) / 2;
    int m2 = left - m1;

    int l1 = m1 > 0 ? arr1[m1 - 1] : INT_MIN;
    int l2 = m2 > 0 ? arr2[m2 - 1] : INT_MIN;
    int r1 = (m1 < n1) ? arr1[m1] : INT_MAX;
    int r2 = (m2 < n2) ? arr2[m2] : INT_MAX;
    
    cout << "m1: " << m1 << ", m2: " << m2 << endl;
    cout << "l1: " << l1 << ", l2: " << l2 << endl;
    cout << "r1: " << r1 << ", r2: " << r2 << endl;
    cout << "-------------" << endl;

    if (l1 <= r2 && l2 <= r1) {
      if (n % 2 == 1) {
        return (double)max(l1, l2);
      }
      return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
    }

    if (l1 > r2) {
      // * Bring more elements from b to left
      r = m1 - 1;
    }
    else { // * l2 > r1
      // * Keep more from a to left
      l = m1 + 1;
    }
  }
  return 0;
}

int main() {
  // * testcase 1
  // vector<int> nums1 = {1, 3, 4, 7, 10, 12}, nums2 = {2, 3, 6, 15};

  // * testcase 2
  vector<int> nums1 = {7, 12, 14, 15}, nums2 = {1, 2, 3, 4, 9, 11};

  // * testcase 3
  // vector<int> nums1 = {1, 2}, nums2 = {3, 4};

  cout << "First Array" << endl;
  printArr(nums1);
  cout << "Second Array" << endl;
  printArr(nums2);


  // double median = bruteForce(nums1, nums2);
  // double median = betterApproach(nums1, nums2);
  double median = findMedian(nums1, nums2);
  cout << "Median of two sorted array is " << median << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-median-of-two-sorted-arrays.cpp -o output && ./output


// * DRY RUN

// * ------ l1 > r2
// * 1 3 4 7 (l1)  -  (r1) 10 12
// * 2       (l2)  -  (r2) 3 6 15

// * ------ l1 <= r2 && l2 <= rq
// * 1 3 4       (l1) - (r1)       7 10 12
// * 2 3         (l2) - (r2)       6 15