/*
 * Given a sorted array of distinct integers and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.

 * If all the numbers are smaller than 'x' then 'n' should be the 'lower_bount' of 'x'.
 * 'n' = size of array
 * 
 * Example 1:
 * Input: arr = [1,3,5,6], x = 5
 * Output: 2

 * Example 2:
 * Input: arr = [1,3,5,6], x = 2
 * Output: 1
 * 
 * Example 3:
 * Input: arr = [1,3,5,6], x = 7
 * Output: 4

*/

#include<iostream>
using namespace std;

int searchIndex(vector<int> arr, int target) {
  int n = arr.size();
  long long low = 0, high = n - 1;
  int idx = n;
  while(low <= high) {
    long long mid = low + (high - low)/2;
    if(arr[mid] >= target) {
      idx = mid;
      high = mid-1;
    } 
    else {
      low = mid+1;
    }
  }
  return idx;
}
 
int main() {
  vector<int> arr = { 1, 3, 5, 6 };
  int target;
  cout<<"Enter an number which you would like to insert: ";
  cin>>target;

  cout<<"Searching index position to insert this number..."<<endl;
  int idx = searchIndex(arr, target);
  cout<<"Insert Index: "<<idx<<endl;

  return 0;
}