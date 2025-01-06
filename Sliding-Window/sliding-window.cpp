#include<vector>
#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void slidingWindowBrute(std::vector<int> &arr, int &window_size) {
  int n = arr.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i; (i + window_size - 1 < n) && j < (i + window_size); ++j) {
      std::cout << arr[j] << " ";
    }
    std::cout << std::endl;
  }
}

void slidingWindow(std::vector<int> &arr, int &window_size) {
  int n = arr.size();
  int i = 0, j = 0;
  while(j < n) {

    if ((j - i + 1) > window_size) {
      std::cout << arr[i] << " ";
      i++;
      std::cout << std::endl;
    }

    j++;

  }
}

int main() {
  int window_size = 3;
  std::vector<int> arr = {1, 2, 3, 1, 2, 3};
  printArr(arr);

  std::cout << "Sliding windows" << std::endl;
  // slidingWindowBrute(arr, window_size);
  slidingWindow(arr, window_size);

  return 0;
}

// * Run the code
// * g++ --std=c++17 sliding-window.cpp -o output && ./output