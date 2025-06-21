/*
* Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

* Example 1:
* Input: nums1 = [1,2], nums2 = [3,4]
* Output: 2.5
* Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5

* Example 2:
* Input: nums1 = [1, 3, 4, 7, 10, 12], nums2 = [2, 3, 6, 15]
* Output: 5
* Explanation: merged array = [1,2,3,3,4,6,7,10,12,15] and median is (6 + 4) / 2 = 5

* https://leetcode.com/problems/median-of-two-sorted-arrays/description/ 

*/

#include <iostream>
using namespace std;

// * ------------------------- Utility Functions -------------------------`

void printArr(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}


double bruteForce(vector<int> nums1, vector<int> nums2) {
  vector<int> mergedArr;
  int n1 = nums1.size();
  int n2 = nums2.size();
  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    if (nums1[i] < nums2[j]) {
      mergedArr.push_back(nums1[i++]);
    }
    else {
      mergedArr.push_back(nums2[j++]);
    }
  }

  while (i < n1) {
    mergedArr.push_back(nums1[i++]);
  }

  while (j < n2) {
    mergedArr.push_back(nums2[j++]);
  }

  cout<<"Merged Array"<<endl;
  printArr(mergedArr);

  int n = mergedArr.size();
  cout<<"n = "<<n<<endl;

  if(n % 2 == 1) {
    // * Odd array
    return (double)(mergedArr[n/2]);
  }
  else {
    cout<<"mergedArr[n/2] "<<mergedArr[n/2]<<endl;
    cout<<"mergedArr[n/2] "<<double(mergedArr[n/2-1])<<endl;
    /// * Even Array
    return (double)((double)(mergedArr[n/2]) + (double)(mergedArr[n/2 - 1])) / 2.0;
  }
}

double partiallyOptimal(vector<int> nums1, vector<int> nums2) {
  int n1 = nums1.size(), n2 = nums2.size();
  int n = n1 + n2;
  int firstIdx = n/2;
  int secondIdx = firstIdx - 1;

  int cnt = 0;
  int firstEle = -1, secondEle = -1;

  int i = 0, j = 0;
  while(i<n1 && j<n2) {
    if(nums1[i] < nums2[j]) {
      if(cnt == firstIdx) firstEle = nums1[i];
      if(cnt == secondIdx) secondEle = nums1[i];
      cnt++;
      i++;
    }
    else {
      if(cnt == firstIdx) firstEle = nums2[j];
      if(cnt == secondIdx) secondEle = nums2[j];
      cnt++;
      j++;
    }
  }

  while(i<n1) {
    if(cnt == firstIdx) firstEle = nums1[i];
    if(cnt == secondIdx) secondEle = nums1[i];
    cnt++;
    i++;
  }

  while(j<n2) {
    if(cnt == firstIdx) firstEle = nums2[j];
    if(cnt == secondIdx) secondEle = nums2[j];
    cnt++;
    j++;
  }

  std::cout<<"firstEle "<<firstEle<<std::endl;
  std::cout<<"secondEle "<<secondEle<<std::endl;
  if(n % 2 == 1) {
    // * Odd Arr
    return (double) (firstEle/2.0);
  }

  return (double)((double)(firstEle + secondEle) / 2.0);
}

int main() {
  vector<int> nums1 = {1, 3, 4, 7, 10, 12};
  vector<int> nums2 = {2, 3, 6, 15};

  // vector<int> nums1 = {1, 2};
  // vector<int> nums2 = {3, 4};
  // double median = findMedian(nums1, nums2);
  double median = partiallyOptimal(nums1, nums2);
  cout << "Median of two arrays: " << median << endl;
  return 0;
}