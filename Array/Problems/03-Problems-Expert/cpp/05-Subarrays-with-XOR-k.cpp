/**
 * * Subarrays with XOR ‘K’
 * * Given an array ‘A’ consisting of ‘N’ integers and an integer ‘B’, find the number of subarrays of array ‘A’
 * * whose bitwise XOR( ⊕ ) of all elements is equal to ‘B’.
 * 
 * * 0 <= a, b, c, d < ‘N’ and a, b, c, and d are distinct.
 * * nums[a] + nums[b] + nums[c] + nums[d] == target

 * * Example 1
 * * Input  :  ‘N’ = 4 ‘B’ = 2 ‘A’ = [1, 2, 3, 2]
 * * Output : 3
 * * Explanation : [1, 2, 3, 2], [2], [2].

 * * https://www.naukri.com/code360/problems/subarrays-with-xor-k_6826258
 * * https://leetcode.com/problems/4sum/
*/


#include<map> 
#include<iostream> 

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: Brute/Better APPROACH -------------------------`
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int b) {
  int n = arr.size();
  int count = 0;
  for(int i=0; i<n; i++) {
    int XOR = 0;
    for(int j=i; j<n; j++) {
      XOR = XOR ^ arr[j];
      // std::cout<<"XOR "<<XOR<<std::endl;
      if(XOR == b) count++;
    }
  }
  return count;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N) + O(logN)
/*
* Best Case => O(N)
* Worst Case => O(NlogN) Depending on map
*/
// * SPACE COMPLEXITY O(N)
int optimalSolution(std::vector<int> arr, int b) {
  int xr = 0, cnt = 0;
  std::map<int, int> xrMap;
  xrMap[xr]++; // * { 0, 1 } Default
  // * O(N) 
  for(int i=0; i<arr.size(); i++) {
    xr = xr ^ arr[i];
    int x = xr ^ b;
    cnt += xrMap[x];
    // * O(logN)
    xrMap[xr]++;
  } 
  return cnt;
}

int main() {
  // int b = 2;
  // std::vector<int> arr = { 1,2,3,2 };
  int b = 6;
  std::vector<int> arr = { 4,2,2,6,4 };

  printArr(arr);

  // int maxSubarrays = bruteForce(arr, b);
  int maxSubarrays = optimalSolution(arr, b);
  std::cout<<"Maximum subarrays "<<maxSubarrays<<std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 05-Subarrays-with-XOR-k.cpp -o 05-Subarrays-with-XOR-k && ./05-Subarrays-with-XOR-k