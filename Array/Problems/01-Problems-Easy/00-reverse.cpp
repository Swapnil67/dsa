// * https://www.naukri.com/code360/problems/reverse-the-array_1262298

#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void print(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
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
  vector<int> arr = {1, 2, 3, 4};
  cout<<"Before Reversing"<<endl;
  print(arr);
  reverse(arr);
  cout<<"After Reversing"<<endl;
  print(arr);
  return 0;
}