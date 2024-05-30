/*
* There is an integer array nums sorted in ascending order (with distinct values).
* The array is right rotated 'r' times
* Find the minimum value of 'r'

* Example 1:
* Input: nums = [5,6,0,1,2]
* Output: 2
* Explanation: 2 times rotated

* Example 2:
* Input: nums = [2,3,4,1]
* Output: 3 
* Explanation: 3 times rotated from [1,2,4,4]

* Example 3:
* Input: nums = [1,2,3]
* Explanation: 0 times rotated from [1,2,3]

* https://www.codingninjas.com/codestudio/problems/rotation_7449070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

#include<iostream>
using namespace std;

int findKRotation(vector<int> &arr){
    int n = arr.size(), minVal = INT_MAX;
    long long low = 0, high = n-1;
    int rotation_count = -1;
    while(low <= high)  {
        long long mid = (low + (high-low)/2);

        if(arr[low] == arr[mid] == arr[high]) {
          low = low + 1;
          high = high - 1;
          continue;
        }

        if(arr[low] <= arr[high]) {
            if(arr[low] < minVal) {
                minVal = arr[low];
                rotation_count = low;
            }
            break;
        }
        else if(arr[low] > arr[mid]) {
            if(arr[mid] < minVal) {
                minVal = arr[mid];
                rotation_count = mid;
            } 
            high = mid - 1;
        }
        else {
            if(arr[low] < minVal) {
                minVal = arr[low];
                rotation_count = low;
            } 
            low = mid + 1;
        }
    }
    return rotation_count;
}

int main() {
  vector<int> arr = {1,2,3};
  // vector<int> arr = {2,3,4,1};
  // vector<int> arr = {5,6,0,1,2};
  int r = findKRotation(arr);
  cout<<"Minimum rotation index: "<<r<<endl;
  return 0;
}