#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void print(vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void reverse(vector<int> &arr) {
  int s = 0, e = arr.size()-1;
  while(s <= e) {
    swap(arr[s], arr[e]);
    s++;
    e--;
  }
}

int main() {
  vector<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  cout<<"Before Reversing"<<endl;
  print(arr);
  reverse(arr);
  cout<<"After Reversing"<<endl;
  print(arr);
  return 0;
}