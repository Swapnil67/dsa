// * Insertion Sort
#include<iostream>
using namespace std;

void print(int arr[], int size) {
  for(int i=0; i<size; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// * Dry Run
/*
* temp = i

*  j i
* 17,27,9,2,10
* 17,27,9,2,10 // * arr[j] > temp -- (false)
*       
*     j   i
* 17, 27, 9, 2, 10 -> (arr[j] > temp) arr[j+1] = arr[j] and j--
*  j      i
* 17, 27, 27, 2, 10 -> (arr[j] > temp) arr[j+1] = arr[j] and j--
 
* j         i
*   17, 17, 27, 2, 10 -> Inner loop Ended -> arr[j+1] = temp
* 9, 17, 27, 2, 10

*       j i
* 9,17,27,2,10 -> (arr[j] > temp) arr[j+1] = arr[j] and j--
*    j  
* 9,17,27,27,10 -> (arr[j] > temp) arr[j+1] = arr[j] and j--
* j    
* 9,17,17,27,10 -> (arr[j] > temp) arr[j+1] = arr[j] and j--
*
* 9,9,17,27,10
* 2,9,17,27,10

*         j  i
* 2,9,17,27,10 -> (arr[j] > temp) arr[j+1] = arr[j] and j--
*      j 
* 2,9,17,27,27 -> (arr[j] > temp) arr[j+1] = arr[j] and j--
*   j
* 2,9,17,17,27
* 2,9,10,17,27
*/

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int temp = arr[i];
    int j = i - 1;
    while (j >= 0) {
      // cout<<arr[j]<<" "<<arr[j+1]<<" | ";
      if (arr[j] > temp) {
        // * shift
        arr[j + 1] = arr[j];
      }
      else {
        // * Ruk jao
        break;
      }
      j--;
    }
    arr[j + 1] = temp;
    // cout<<endl;
    // print(arr, n);
  }
}

int main() {
  int size = 5;
  int arr[5] = {17,27,9,2,10};
  cout<<"Insertion Sort"<<endl;
  cout<<"Before Swapping"<<endl;
  print(arr, size);
  insertionSort(arr, size);
  cout<<"After Swapping"<<endl;
  print(arr, size); 
  return 0;
}