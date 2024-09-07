#include<unordered_map>
#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int minOperations(std::vector<int> arr) {
  int n = arr.size();
  std::unordered_map<int, int> countMap;

  for (int i = 0; i < n; ++i) {
    countMap[arr[i]]++;
  }

  // * count map
  // for(auto it : countMap) {
  //   std::cout << it.first << " => " << it.second << std::endl;
  // }

  int c = 0;
  for(auto it : countMap) {
    if(it.second == 1) 
      return -1;

    c += std::ceil(it.second / 3.0);
  }

  return c;
}

int main() {
  std::vector<int> arr = {3, 3};
  // std::vector<int> arr = {2, 1, 2, 2, 3, 3};
  // std::vector<int> arr = {2, 3, 3, 2, 2, 4, 2, 3, 4};
  // std::vector<int> arr = {14, 12, 14, 14, 12, 14, 14, 12, 12, 12, 12, 14, 14, 12, 14, 14, 14, 12, 12};
  printArr(arr);

  int ans = minOperations(arr);
  std::cout << "Minimum Number of Operations to Make Array Empty " << ans << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 21-make-arr-empty.cpp -o output && ./output