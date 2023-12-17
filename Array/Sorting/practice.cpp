// * Selection Sort

#include<vector>
#include<iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void print(vector<int>arr) {
  for(int i=0; i<arr.size(); i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

//* Logic of inner and outer loop time complexity
// * smallest number is always insignificant and hence discarded
// * i loop took O(n) while j loop took O(n+1) = n , (n-1) (n-2) ... 3 2 1 0 = n(n-1)/2 = n^2/2 - n/2 = n^2
void selectionSort(vector<int> arr) {
// * Smallest element goes to left
}

// void bubbleSort(vector<int> arr) {
// * Largest element goes to right
// * Time Complexity 
/* * 

*/
//   int n = arr.size();
//   for(int i=0; i<n; i++) {
//     bool is_swapp = false;
//     for(int j=i+1; j<n-i; j++) {
//       // cout<<arr[i]<<" "<<arr[j]<<endl;
//       if(arr[i] > arr[j]) {
//         is_swapp = true;
//         swap(arr[i], arr[j]);
//       }
//     }
//     if(is_swapp == false) {
//       break;
//     }
//   }
//   print(arr);
// }

void bubbleSort(vector<int> arr){
  int n = arr.size();
  for(int i = 0; i < n; i++){
    bool is_swap = false;
    for(int j = i + 1; j < n-i; j++){
      if(arr[i] > arr[j]){
        is_swap = true;
        swap(arr[i],arr[j]);
      }

      if(!is_swap) return;
    }
  }
  print(arr);
}


void insertionSort(vector<int> arr) {
}

int main() {
  // vector<int> arr = { 9,7,1,10,5 };
  // vector<int> arr = { 7,5,1,9 };
  // vector<int> arr = { 17,27,9,2,10 };
  vector<int> arr = { 5,2,3,7,1 };
  print(arr);
  selectionSort(arr);
  // bubbleSort(arr);
  // insertionSort(arr);
  return 0;
}