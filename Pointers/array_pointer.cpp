#include<iostream>
using namespace std;

// ! Important Formula
// ! arr[i] = *(arr + i)

int main() {
  int arr[5] = { 1,2,3,4,5 };
  int *ptr = arr;
  int *ptr2 = ptr+3;
  
  cout<<"arr: "<<arr<<endl;
  cout<<"&arr: "<<&arr<<endl;
  cout<<"&arr[0]: "<<&arr[0]<<endl;

  cout<<"--------------------------------------------\n";

  cout<<"arr+2: "<<arr+2<<endl;
  cout<<"*(arr+2): "<<*(arr+2)<<endl;

  cout<<"--------------------------------------------\n";
  
  int i = 4;
  cout<<"i[arr]: "<<i[arr]<<endl;

  cout<<"--------------------------------------------\n";

  cout<<"sizeof(arr): "<<sizeof(arr)<<endl;  // ? 4 * 5 = 20
  cout<<"sizeof(ptr): "<<sizeof(ptr)<<endl;  // * Size of address
  cout<<"sizeof(*ptr): "<<sizeof(*ptr)<<endl;  // * Size of int
  cout<<"sizeof(&arr[0]): "<<sizeof(&arr[0])<<endl;  // * Size of address of first element

  cout<<"--------------------------------------------\n";
  cout<<"ptr2: "<<ptr2<<" | "<<"*ptr2: "<<*ptr2<<endl;
  cout<<"ptr: "<<ptr<<" | "<<"*ptr: "<<*ptr<<endl;
  cout<<"ptr2 - ptr: "<<ptr2 - ptr<<endl;

}