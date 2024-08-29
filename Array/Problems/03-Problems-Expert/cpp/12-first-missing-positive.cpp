#include<set>
#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool isElementPresent(std::vector<int> arr, int n, int ele) {
  for (int i = 0; i < n; ++i) {
    if(arr[i] == ele)
      return true;
  }
  return false;
}

int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 1; i <= n + 1; ++i) {
    if (!isElementPresent(arr, n, i))
      return i;
  }
  return -1;
}

int betterApproach(std::vector<int> arr) {
  int n = arr.size();

  // * put all elements into hashSet
  std::set<int> hashSet;
  for (int i = 0; i < n; ++i)
    hashSet.insert(arr[i]);

  // * Search missing numbers from [1...n+1]
  for (int i = 1; i <= n + 1; ++i) {
    if(!hashSet.count(i))
      return i;
  }
  return -1;
}

int main() {
  std::vector<int> arr = {1, 2, 0};
  // int ans = bruteForce(arr);
  int ans = betterApproach(arr);
  std::cout << "Missing positive integer " << ans << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 12-first-missing-positive.cpp -o output && ./output