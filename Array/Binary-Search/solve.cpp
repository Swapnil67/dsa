#include<iostream>

int maxVal(std::vector<int>arr) {
  int maxVal = INT_MIN; 
  for(int i=0; i<arr.size(); i++) {
    maxVal = std::max(maxVal, arr[i]);
  }
  return maxVal;
}

bool isValidDivisior(std::vector<int>arr, int threshold, int divisor) {
  int sum = 0;
  // std::cout<<"divisor "<<divisor<<std::endl;
  for(int i=0;i<arr.size();i++) {
    sum = sum + std::ceil(arr[i]/(float)divisor);
  }
  // std::cout<<"sum "<<sum<<std::endl;
  if(sum <= threshold) {
    return true;
  }
  return false;
}

int bruteForce(std::vector<int>arr, int threshold) {
  int maxArrVal = maxVal(arr);
  for(int i=1; i<maxArrVal; i++) {
    bool isValid = isValidDivisior(arr, threshold, i);
    if(isValid) {
      return i;
    }
  }
  return -1;
}

int main() {
  std::vector<int> arr = { 1,2,5,9 };
  int threshold = 6;
  // std::vector<int> arr = { 1,2,3,4,5 };
  // int threshold = 8;
  int smallestDivisor = bruteForce(arr, threshold);
  std::cout<<"smallest Divisor =  "<<smallestDivisor<<std::endl;
  return 0;
}