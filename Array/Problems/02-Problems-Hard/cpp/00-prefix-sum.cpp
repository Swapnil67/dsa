#include<iostream>

int findPrefixSum(std::vector<int> arr, int l, int r) {
  int n = arr.size();
  
  // * Create a prefix sum array
  std::vector<int> prefixSumArr;
  int total = 0;
  for(int i=0; i<n; i++) {
    total += arr[i];
    prefixSumArr.push_back(total);
  }

  // * Get the prefix sum for given indexes
  int prefixRight = prefixSumArr[r];

  int prefixLeft = 0;
  if(l > 0) {
    prefixLeft = prefixSumArr[l-1];
  }
  // std::cout<<"prefixRight "<<prefixRight<<std::endl;
  // std::cout<<"prefixLeft "<<prefixLeft<<std::endl;
  return prefixRight - prefixLeft;
}

int main() {
  std::vector<int> arr = {-2, -1, 3, -3, 4};
  int l = 1, r = 3;
  int prefixSum = findPrefixSum(arr, l, r);
  std::cout << "Prefix Sum from " << l << " " << r << " : " << prefixSum << std::endl;
  return 0;
}

// * Run the code 
// * g++ --std=c++17 00-prefix-sum.cpp -o 00-prefix-sum && ./00-prefix-sum