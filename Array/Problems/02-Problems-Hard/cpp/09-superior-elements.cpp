/*
 * Superior Elements
 * An element is called a Superior Element if it is greater than all the elements present to its right.
 * You must return an array all Superior Elements in the array ‘a’.
 * 
 * Example 1:
 * Input: nums = [1,2,3,2]
 * Output: [3, 2]

 * Example 2:
 * Input: nums = [5,4,3]
 * Output: [5,4,3]
 * 
 * https://www.naukri.com/code360/problems/superior-elements_6783446
*/

#include<set>
#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N^2) + O(NlogN)
// * SPACE COMPLEXITY O(N) // * For Answer
std::vector<int> bruteForce(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> ans;
  // * O(N^2)
  for(int i=0; i<n; i++) {
    int superiorEle = arr[i];
    bool isSuperior = true;
    for(int j=i+1; j<n; j++) {
      if(superiorEle <= arr[j]) {
        isSuperior = false;
        break;
      }
    }
    if(isSuperior) {
      ans.push_back(superiorEle);
    }
  }
  // * O(NlogN)
  std::sort(ans.begin(), ans.end());
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N) + O(NlogN)
// * SPACE COMPLEXITY O(N) // * For Answer
std::vector<int> optimal(std::vector<int> arr) {
  int n = arr.size();
  int r = n-1, maxEl = INT_MIN;
  std::vector<int> ans;

  // * O(N)
  for (int i = r; i >= 0; i--) {
    if(arr[i] > maxEl) {
      maxEl = arr[i];
      // std::cout << "maxEl " << maxEl << std::endl;
      ans.push_back(arr[i]);
    }
  }

  // * O(NlogN)
  std::sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  std::vector<int> arr = {1, 2, 2, 1};
  // std::vector<int> arr = {1, 2, 3, 2};
  printArr(arr);
  std::vector<int> ans = bruteForce(arr);
  // std::vector<int> ans = optimal(arr);
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++17 09-superior-elements.cpp -o 09-superior-elements && ./09-superior-elements