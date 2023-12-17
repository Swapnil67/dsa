#include<iostream>
using namespace std;

int peakElement(int arr[], int size) {
}

int main() {
  int size = 4;
  int arr[4] = {0,10,5,0};
  int peak = peakElement(arr, size);
  cout<<"\nPeak element in mountain array is: "<<arr[peak];
  return 0;
}