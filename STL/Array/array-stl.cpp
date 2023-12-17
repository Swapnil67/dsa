#include<iostream>
#include<array>
using namespace std;

int main() {

  // * Static Array
  int arr[4] = { 1,2,3,4 };

  // * Static Array
  array<int, 4> a = { 1,2,3,4 };
  int size = a.size();
  for(int i=0; i<size; i++) {
    cout<<a[i]<<" ";
  }
  cout<<"Element at index 2: "<<a.at(2)<<endl;
  cout<<"Empty of not: "<<a.empty()<<endl;

  cout<<"First element: "<<a.front()<<endl;
  cout<<"Last element: "<<a.back();

  return 0;
}