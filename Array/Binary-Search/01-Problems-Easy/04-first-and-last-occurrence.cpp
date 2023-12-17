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
  int first = returnFirstOccurence(arr, k);
  int last = returnLastOccurence(arr, k);
  return 0;
}