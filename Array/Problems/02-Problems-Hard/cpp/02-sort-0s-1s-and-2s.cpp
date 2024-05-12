/**
 * * Sort An Array of 0s, 1s and 2s
 * * You have been given an array/list 'arr' consisting of 'n' elements.
 * * Each element in the array is either 0, 1 or 2.
 * * Sort this array/list in increasing order.

 * * Do not make a new array/list. Make changes in the given array/list.

 * * Example 1
 * * Input  : arr = [2, 2, 2, 2, 0, 0, 1, 0] 
 * * Output : arr = [0, 0, 0, 1, 2, 2, 2, 2]

 * * https://www.naukri.com/code360/problems/sort-an-array-of-0s-1s-and-2s_892977
 * * https://leetcode.com/problems/sort-colors/
*/

#include<iostream>
using namespace std;

void printArr(vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Merge Sort

// * ------------------------- APPROACH 2: Better FORCE APPROACH -------------------------`
// * Count 0s, 1s and 2s
// * Nested Loop
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
std::vector<int> betterApproach(std::vector<int> arr) {
  int zeroCount = 0, oneCount = 0, twoCount = 0;
  int n = arr.size();

  // * O(N)
  for(int i=0; i<n; i++) {
    if(arr[i] == 0) zeroCount++;
    else if(arr[i] == 1) oneCount++;
    else if(arr[i] == 2) twoCount++;
  }

  // std::cout<<"Zero Count "<<zeroCount<<std::endl;
  // std::cout<<"One Count "<<oneCount<<std::endl;
  // std::cout<<"Two Count "<<twoCount<<std::endl;

  // * O(zeroCount)
  if(zeroCount > 0) {
    for(int i=0; i<zeroCount; i++) {
      arr[i] = 0;
    }
  }
  
  // * O(oneCount)
  if(oneCount > 0) {
    for(int i=zeroCount; i<zeroCount+oneCount; i++) {
      arr[i] = 1;
    }
  }

  // * O(twoCount)
  if(twoCount > 0) {
    for(int i=zeroCount+oneCount; i<n; i++) {
      arr[i] = 2;
    }
  }

  return arr;
}

// * ------------------------- APPROACH 3: Optimal FORCE APPROACH -------------------------`
// * Dutch Flag Algorithm
std::vector<int> optimalApproach(std::vector<int> &arr) {
  int n = arr.size();
  int low = 0, mid = 0, high = n-1;
  while(mid <= high) {
    if(arr[mid] == 0) {
      swap(arr[mid], arr[low]);
      low++;
      mid++;
    }
    else if(arr[mid] == 1) {
      mid++;
    }
    else if(arr[mid] == 2) {
      swap(arr[mid], arr[high]);
      high--;
    }
  }
  return arr;
}


int main() {
  // * testcase 1
  std::vector<int> arr = { 2, 2, 2, 2, 0, 0, 1, 0 };
  // * testcase 2
  // std::vector<int> arr = { 1, 1, 1, 1, 1 };
  // * testcase 3
  // std::vector<int> arr = { 1, 2, 1, 2, 1, 1, 1 };

  std::cout<<" ----- Before Sorting ----- "<<std::endl;
  printArr(arr);

  // std::vector<int> ans = betterApproach(arr);
  std::vector<int> ans = optimalApproach(arr);
  std::cout<<" ----- After Sorting ----- "<<std::endl;
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++17 02-sort-0s-1s-and-2s.cpp -o 02-sort-0s-1s-and-2s && ./02-sort-0s-1s-and-2s