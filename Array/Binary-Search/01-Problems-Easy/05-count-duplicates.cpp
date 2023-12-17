
/*
 * 
 * 
 * https://www.codingninjas.com/codestudio/problems/occurrence-of-x-in-a-sorted-array_630456?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf 
*/
#include<iostream>
using namespace std;

int returnFirstOccurence(vector<int> &arr, int target) {
    int n = arr.size();
    long long low = 0, high = n-1;
    int first = -1;
    while(low <= high)  {
      long long mid = low + (high - low) / 2;
      if(arr[mid] == target) {
        first = mid;
        high = mid - 1;
      }
      else if(arr[mid] > target) {
        high = mid - 1;
      } 
      else {
        low = mid + 1;
      }
    }
    return first;
}

int returnLastOccurence(vector<int> &arr, int target) {
    int n = arr.size();
    long long low = 0, high = n-1;
    int last = -1;
    while(low <= high)  {
      long long mid = low + (high - low) / 2;
      if(arr[mid] == target) {
        last = mid;
        low = mid + 1;
      }
      else if(arr[mid] > target) {
        high = mid - 1;
      } 
      else {
        low = mid + 1;
      }
    }
    return last;
}

int main() {
  vector<int> arr = { 1,2,5,5,5,7,8 };
  int x = 5;
  int first = returnFirstOccurence(arr, x);
	if(first == -1) return 0;
  int last = returnLastOccurence(arr, x);
	int occurrence = (last - first) + 1;
  cout<<"Total Occurrences: "<<occurrence<<endl;
  return 0;
}