#include<iostream>
using namespace std;

int first(int arr[], int size, int key) {
}

int last(int arr[], int size, int key) {
}

int main() {
  int size = 8;
  int arr[8] = { 1,2,3,3,4,5,6,7 };
  cout<<"First "<<first(arr, size, 3)<<endl;
  cout<<"Last "<<last(arr, size, 3);
  return 0;
}