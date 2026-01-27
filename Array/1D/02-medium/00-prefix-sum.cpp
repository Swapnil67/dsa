#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

int findPrefixSum(std::vector<int> arr, int l, int r) {
  int n = arr.size();
  if (n == 0)
    return 0; 

  // * Create a prefix sum array
  std::vector<int> prefix_vec; 
  for(auto &x: arr) {
    if (!prefix_vec.size()) {
      prefix_vec.push_back(x);
    } else {
      prefix_vec.push_back(x + prefix_vec.back());
    }
  }
  // printArr(prefix_vec);

  // * Get the prefix sum for given indexes
  int right_prefix_sum = prefix_vec[r];
  int left_prefix_sum = 0;
  if(l > 0) {
    left_prefix_sum = prefix_vec[l - 1];
  }
  
  // std::cout<<"right_prefix_sum "<<right_prefix_sum<<std::endl;
  // std::cout<<"left_prefix_sum "<<left_prefix_sum<<std::endl;
  return right_prefix_sum - left_prefix_sum;
}

int main() {
  // * testcase 1
  // int l = 1, r = 3;
  // std::vector<int> arr = {-2, -1, 3, -3, 4};

  // * testcase 2
  int l = 2, r = 5;
  std::vector<int> arr = {-2, 0, 3, -5, 2, -1};

  std::cout << "Input Array" << std::endl;
  printArr(arr);

  int prefixSum = findPrefixSum(arr, l, r);
  std::cout << "Prefix Sum from " << l << " to " << r << " : " << prefixSum << std::endl;
  return 0;
}

// * Run the code 
// * g++ --std=c++17 00-prefix-sum.cpp -o output && ./output