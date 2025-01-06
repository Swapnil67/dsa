#include<iostream>
#include <vector>
#include <deque>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

std::vector<int> bruteForce(std::vector<int> arr, int k, int x) {
  std::deque<std::pair<int, int>> dq;
  int n = arr.size();
  for (int i = 0; i < n; ++i) {
    if(dq.size() < k) {
      dq.push_back({arr[i] - x, arr[i]});
    }
  }
  
  std::vector<int> ans;
  for(int i = 0; i < dq.size(); i++) {
    // printf("arr[i] - x: %d \t arr[i]: %d\n", dq[i].first, dq[i].second);
    ans.push_back(dq[i].second);
  }
  return ans;
}

// * f(m) = abs(arr[m] - x)
// * 1st number in window will always be closer to x than the last+1 element
// * g(m) = f(m) <= f(m+k)


std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x) {
  int n = arr.size();
  int l = 0, h = n - k, m;
  while(l < h) {
    m = (l + (h - 1)) / 2; // * m is the starting point of window of size k
    if (x - arr[m] > arr[m + k] - x) {
      l = m + 1;
    }
    else {
      h = m;
    }
  }
  return std::vector(arr.begin() + l, arr.begin() + l + k);
}

int main() {

  // * testcase 1
  // int k = 4, x = 3;
  // std::vector<int> arr = {1, 2, 3, 4, 5};

  // * testcase 2
  // int k = 4, x = -1;
  // std::vector<int> arr = {1, 1, 2, 3, 4, 5};

  // * testcase 2
  int k = 1, x = 9;
  std::vector<int> arr = {1, 1, 1, 10, 10, 10};

  printf("Input Array: ");
  printArr(arr);

  // std::vector<int> ans = bruteForce(arr, k, x);
  std::vector<int> ans = findClosestElements(arr, k, x);
  printArr(ans);
  // std::cout << "Minimum Size Subarray Sum: " << ans << std::endl;
  return 0;
}

// * Run the code
// * $CXX --std=c++20 08-k-closest-ele.cpp -o output && ./output