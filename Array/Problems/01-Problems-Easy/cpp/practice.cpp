#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// * largest element in array
int largestElement(std::vector<int> arr) {
  int largestEle = INT_MIN;
  int n = arr.size();

  for(int i=0; i<n; i++) {
    largestEle = std::max(largestEle, arr[i]);
  }

  return largestEle;
}

// * 2nd largest element in array
int secondLargestElementInArray(std::vector<int> arr) {
  int slargest = INT_MIN, largest = INT_MIN;
  int n = arr.size();
  for(int i=0; i<n; i++) {
    if(arr[i] > largest) {
      slargest = largest;
      largest = arr[i];
    }
    else if(arr[i] > slargest) {
      slargest = arr[i];
    }
  }
  return slargest;
}

// * 2nd Smallest element in array
int secondSmallestElementInArray(std::vector<int> arr) {
  int sSmallest = INT_MAX, smallest = INT_MAX;
  int n = arr.size();
  for(int i=0; i<n; i++) {
    if(arr[i] < smallest) {
      sSmallest = smallest;
      smallest = arr[i];
    }
    else if(arr[i] > smallest && arr[i] < sSmallest) {
      sSmallest = arr[i];
    }
  }
  return sSmallest;
}

// * Check if array is sorted
bool checkIsSortedArray(std::vector<int> arr) {
  bool isSorted = true;
  int n = arr.size();
  for(int i=0; i<n-1; i++) {
    if (arr[i+1] <= arr[i]) {
      isSorted = false;
      break;
    }
  }
  return isSorted;
}

// * Remove duplicates
int removeDuplicates(std::vector<int> &arr) {
  int i = 0;
  for(int j=1; j<arr.size(); j++) {
    if (arr[i] != arr[j]) {
      arr[i + 1] = arr[j];
      i++;
    }
  }
  return i+1;
}

void kRotateBruteForce(std::vector<int> &arr, int k) {
  k = k-1;
  int n = arr.size();
  int d = k % n; // * Rotation count

  std::cout<<"k: "<<k<<", n "<<n<<std::endl;
  std::cout<<"Rotate: "<<d<<std::endl;

  // * Put d elements into k
  std::vector<int> temp;
  for(int i=0; i<=d; i++) {
    temp.push_back(arr[i]);
  }
  printArr(temp);

  // * Shift elements after d to front
  for(int i=0; i<n-d; i++) {
    arr[i] = arr[(n-d)-i];
  }
  printArr(arr);

  // * arr[0] = arr[0+(7-1)]
  // * arr[0] = arr[6]

  // * arr[0] = arr[1+(7-1)]
  // * arr[0] = arr[7]

  // * Put temp back to array
  int j = 0;
  for(int i=d; i<n; i++) {
    arr[i] = temp[j];
    j++;
  }

  // * arr[0] = arr[0+(7-4)]
  // * arr[0] = arr[3]
  // * arr[0] = arr[1+(7-4)]
  // * arr[0] = arr[4]

  printArr(arr);

}

// * Move zeros to end
void moveZerosToEnd(std::vector<int> &arr) {
  int j = -1, n = arr.size();
  for(int i=0; i<n; i++) {
    if(arr[i] == 0) {
      j = i;
      break;
    }
  }

  for(int i=j+1; i<n; i++) {
    if(arr[i] != 0) {
      swap(arr[i], arr[j]);
      j++;
    }
  }

}

int main() {
  // std::vector<int> arr = {1,2,3,4,5,6,7};
  // std::vector<int> arr = { 1, 1, 2, 3, 3, 4, 5, 5, 5 };
  // std::vector<int> arr = { 3,1,2,7,10 };

  // * Problem 1
  // int largestElementAns = largestElement(arr);
  // std::cout<<"Largest Element = "<<largestElementAns<<std::endl;

  // * Problem 2
  // int secondLargestElementAns = secondLargestElementInArray(arr);
  // std::cout<<"2nd Largest Element: "<<secondLargestElementAns<<std::endl;

  // * Problem 3
  // int secondSmallestElementAns = secondSmallestElementInArray(arr);
  // std::cout<<"2nd Smallest Element: "<<secondSmallestElementAns<<std::endl;
  
  // * Problem 4
  // bool isSortedArray = checkIsSortedArray(arr);
  // std::cout<<"Is Sorted Array: "<<isSortedArray<<std::endl;

  // * Problem 5
  // int uniqueElements = removeDuplicates(arr);
  // std::cout<<"Unique Elements: "<<uniqueElements<<std::endl;

  // * Problem 6
  // std::vector<int> arr = {1, 2, 0, 0, 2, 3};
  // std::vector<int> arr = {0, 0, 0, 1};
  // printArr(arr);
  // moveZerosToEnd(arr);
  // printArr(arr);

  // * Problem 7
  int k = 2;
  std::vector<int> arr = {1,2,3,4,5,6,7};
  // std::vector<int> arr = {0, 0, 0, 1};
  printArr(arr);
  kRotateBruteForce(arr, k);
  printArr(arr);
  
  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice