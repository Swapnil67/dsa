#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

int findSecondLargestEle(std::vector<int> arr) {
  int n = arr.size();
  int maxI = INT_MIN, secondMax = INT_MIN;
  for(int i=0; i<n; i++) {
    if(arr[i] > maxI) {
      secondMax = maxI;
      maxI = arr[i];
    }
    else if(arr[i] > secondMax) {
      secondMax = arr[i];
    }
  }
  return secondMax;
}

int findSecondSmallestEle(std::vector<int> arr) {
  int n = arr.size();
  int minI = INT_MAX, secondMin = INT_MAX;
  for(int i=0; i<n; i++) {
    if(arr[i] < minI) {
      secondMin = minI;
      minI = arr[i];
    }
    else if(arr[i] < secondMin) {
      secondMin = arr[i];
    }
  }
  return secondMin;
}

int removeDuplicates(std::vector<int> &arr) {
  int n = arr.size();
  int i=0;
  for(int j=1; j<n; j++) {
    if(arr[i] != arr[j]) {
      arr[i+1] = arr[j];
      i++;
    }
  }
  return i+1;
}

void rotateByOne(std::vector<int> &arr) {
  int n = arr.size();
  int firstEle = arr[0];
  int i = 1;
  for(i=1; i<n; i++) {
    arr[i-1] = arr[i];
  }
  arr[n-1] = firstEle;
}

void rotateByKPlaces(std::vector<int> &arr, int k) {
  int n = arr.size();
  std::vector<int> temp;
  for(int i=0; i<k; i++) {
    temp.push_back(arr[i]);
  }
  // printArr(temp);

  for(int i=0; i<n-k; i++) {
    // std::cout<<i<<" "<<arr[i]<<" | "<<k+i<<" -> "<<arr[k+i]<<std::endl;
    arr[i] = arr[k+i];
  }

  // int j = 0;
  for(int i=n-k; i<n; i++) {
    // arr[i] = temp[j];
    arr[i] = temp[i-(n-k)];
    // j++;
  }

}

int main() {
  // * Problem 1
  // std::vector<int> arr = {8, 3, 7, 2, 6};
  // int secondLargestEle = findSecondLargestEle(arr);
  // std::cout<<"2nd Largest Element: "<<secondLargestEle<<std::endl;

  // * Problem 2
  // std::vector<int> arr = {8, 3, 7, 2, 6};
  // int secondSmallestEle = findSecondSmallestEle(arr);
  // std::cout<<"2nd Smallest Element: "<<secondSmallestEle<<std::endl;
  
  // * Problem 3
  // std::vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 5, 5};
  // printArr(arr);
  // int uniqueElements = removeDuplicates(arr);
  // std::cout<<"Unique Element: "<<uniqueElements<<std::endl;

  // * Problem 4
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // printArr(arr);
  // rotateByOne(arr);
  // printArr(arr);

  // * Problem 5
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // printArr(arr);
  // rotateByKPlaces(arr, 3);
  // printArr(arr);

}

// * Run the code
// * g++ --std=c++17 practice2.cpp -o practice2 && ./practice2