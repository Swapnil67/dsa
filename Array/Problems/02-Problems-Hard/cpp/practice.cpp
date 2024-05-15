#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// * Dutch National Flag Algorithm [Sort 0s, 1s & 2s]
void dutchNationalFlag(std::vector<int> &arr) {
  int n = arr.size();
  int low = 0, mid = 0, high = n-1;

  while(mid <= high) {
    if(arr[mid] == 0)  {
      swap(arr[mid], arr[low]);
      mid++;
      low++;
    }
    else if(arr[mid] == 1) {
      mid++;
    }
    else if(arr[mid] == 2) {
      swap(arr[mid], arr[high]);
      high--;
    }
  }
} 

// * Moore's Voting Algorithm [Majority Element n/2]
int mooreVotingAlgorithm(std::vector<int> &arr) {
  int n = arr.size();
  int cnt = 0, ele = arr[0];
  for(int i=0; i<n; i++) {
    if(cnt == 0) {
      ele = arr[i];
      cnt++;
    }
    else if(arr[i] == ele) {
      cnt++;
    }
    else {
      cnt--;
    }
  }

  return ele;
}

// * Kadanes Algorithm [Max Subarray sum]
int maxSubarraySumV1(std::vector<int> arr) {
  int n = arr.size();
  int curMax = 0, globalMax = arr[0];
  for(int i=0; i<n; i++) {
    curMax = curMax + arr[i];
    std::cout<<"Current Max "<<curMax<<std::endl;
    globalMax = std::max(globalMax, curMax);
    if(curMax < 0) curMax = 0;
  }

  // * OR
  // for(int i=0; i<n; i++) {
  //   curMax = std::max(curMax + arr[i], arr[i]);
  //   std::cout<<"Current Max "<<curMax<<std::endl;
  //   globalMax = std::max(globalMax, curMax);
  // }

  return globalMax;
}

int main() {
  // * Dutch National Flag Algorithm [Sort 0s, 1s & 2s]
  // std::vector<int> arr = { 2, 2, 2, 2, 0, 0, 1, 0 };
  // printArr(arr);
  // dutchNationalFlag(arr);
  // printArr(arr);

  // * Moore's Voting Algorithm [Majority Element n/2]
  // std::vector<int> arr = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
  // // std::vector<int> arr = {58, 58, 28, 95, 58, 15, 58, 58 };
  // printArr(arr);
  // int majorityElement = mooreVotingAlgorithm(arr);
  // std::cout<<"Majority Element "<<majorityElement<<std::endl;

  // * Kadanes Algorithm [Max Subarray sum v1]
  // * testcase 1
  std::vector<int> arr = {-3, -5, -6}; // * -3
  // * testcase 2
  // std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // * 6
  printArr(arr);
  int maxSum = maxSubarraySumV1(arr);
  std::cout<<"Max subarray sum "<<maxSum<<std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice