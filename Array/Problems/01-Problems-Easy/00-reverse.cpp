/*
 * Leetcode - 344 
 * Write a function that reverses a string. The input string is given as an array of characters s.
 * You must do this by modifying the input array in-place with O(1) extra memory.

 * https://leetcode.com/problems/reverse-string/description/
 * https://www.naukri.com/code360/problems/reverse-the-array_1262298
 */

#include <vector>
#include <iostream>
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

template <typename T>
void reverse(vector<T> &arr) {
  int s = 0, e = arr.size() - 1;
  while (s <= e) {
    swap(arr[s], arr[e]);
    s++;
    e--;
  }
}

void reverseString(std::string &str) {
  int s = 0, e = str.size() - 1;
  while (s <= e) {
    swap(str[s], str[e]);
    s++;
    e--;
  }
}

int main() {
  vector<int> arr = {1, 2, 3, 4};
  cout << "Before Reversing" << endl;
  print(arr);
  reverse(arr);
  cout << "After Reversing" << endl;
  print(arr);

  std::string str = "Hello World";
  cout << "Before Reversing" << endl;
  std::cout << str << std::endl;
  reverseString(str);
  cout << "After Reversing" << endl;
  std::cout << str << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 00-reverse.cpp -o output && ./output